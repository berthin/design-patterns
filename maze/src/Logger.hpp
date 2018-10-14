#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>       // for std::string
#include <memory>       // for std::unique_ptr
#include <mutex>        // for std::mutex

class Logger final
{

public:
    Logger();

    static Logger* getInstance();

    void log(const std::string& message);

    ~Logger();
private:
    static std::unique_ptr<Logger> instance;
    std::mutex log_mutex;
};

#ifdef ENABLE_LOGGER
    #define LOGINFO(message) Logger::getInstance()->log(message)
#else
    #define LOGINFO(message) do {} while (0)
#endif

#endif // LOGGER_HPP
