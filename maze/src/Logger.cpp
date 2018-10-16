#include "Logger.hpp"

#include <iostream>     // for std::cout, std::endl
#include <thread>       // for std::unique_lock, std::this_thread
#include <chrono>       // for std::chrono
#include <iomanip>      // for std::put_time
#include <sstream>      // for std::stringstream

using namespace std;


unique_ptr<Logger> Logger::instance = nullptr;

Logger::Logger():
    MAX_LENGTH_LOG_METADATA(MAX_LENGTH_FUNCTION_NAME + MAX_LENGTH_FILE_NAME + MAX_LENGTH_LINE_NUMBER + 10),
    log_mutex()
{}


Logger* Logger::getInstance()
{
    if (instance == nullptr) {
        instance = make_unique<Logger>();
    }
    return instance.get();
}


ostream& currentTime(ostream& os)
{
    using namespace chrono;

    auto cur_time = system_clock::now();
    auto cur_time_c = system_clock::to_time_t(cur_time);
    auto time_since_epoch = cur_time.time_since_epoch();

    auto cur_time_ms  = duration_cast<milliseconds>(time_since_epoch);
    auto cur_time_sec = duration_cast<seconds>(time_since_epoch);
    auto rem_time_ms = (cur_time_ms - cur_time_sec).count();

    os << put_time(localtime(&cur_time_c), "%F %T")
       << "." << setfill('0') << setw(3) << rem_time_ms;

    return os;
}


ostream& getHeader(ostream& os)
{
    auto thread_id = this_thread::get_id();
    os << "[" << setfill(' ') << setw(10)
       << thread_id
       << "][";
    currentTime(os);
    os << "]";
    return os;
}


void Logger::log(const string& message)
{
    unique_lock<mutex> lock_(log_mutex);
    stringstream ss;
    getHeader(ss);
    cout << ss.str() << '\n';
    cout << message << endl;
}


static const char* trimString(
    const char* str,
    int size,
    int max_length)
{
    return str + max(0, size - max_length);
}


void Logger::log(const string& message,
                 const string& file,
                 const string& function,
                 int line)
{
    unique_lock<mutex> lock_(log_mutex);
    stringstream ss;
    ss << "(" << trimString(file.c_str(), file.size(), MAX_LENGTH_FILE_NAME) << ")["
       << trimString(function.c_str(), function.size(), MAX_LENGTH_FUNCTION_NAME) << ":"
       << line << "]";
    getHeader(ss);
    cout << setw(MAX_LENGTH_LOG_METADATA) << ss.str();
    cout << ' ' << message << endl;
}


Logger::~Logger()
{
    LOGINFO("+----------------------------+");
    LOGINFO("| Logger constructor called! |");
    LOGINFO("+----------------------------+");

}
