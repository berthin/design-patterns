#include "Logger.hpp"

#include <iostream>     // for std::cout, std::endl
#include <thread>       // for std::unique_lock

using namespace std;


unique_ptr<Logger> Logger::instance = nullptr;

Logger::Logger():
    log_mutex()
{}


Logger* Logger::getInstance()
{
    if (instance == nullptr) {
        instance = make_unique<Logger>();
    }
    return instance.get();
}


void Logger::log(const string& message)
{
    unique_lock<mutex> lock_(log_mutex);
    cout << message << endl;
}

Logger::~Logger()
{
    LOGINFO("+----------------------------+");
    LOGINFO("| Logger constructor called! |");
    LOGINFO("+----------------------------+");

}
