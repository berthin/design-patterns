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

    // @TODO: Remove this function
    void log(const std::string& message);

    void log(const std::string& message,
             const std::string& file,
             const std::string& function,
             int line);

    ~Logger();

private:
    const int MAX_LENGTH_FILE_NAME      = 20;
    const int MAX_LENGTH_FUNCTION_NAME  = 20;
    const int MAX_LENGTH_LINE_NUMBER    = 10;
    const int MAX_LENGTH_LOG_METADATA; // sum of previous lengths

    static std::unique_ptr<Logger> instance;
    std::mutex log_mutex;
};

#ifdef ENABLE_LOGGER
    #define LOGINFO(message)            \
        Logger::getInstance()->log(     \
            message,                    \
            __FILE__,                   \
            __FUNCTION__,               \
            __LINE__)
#else
    #define LOGINFO(message) do {} while (0)
#endif

#endif // LOGGER_HPP
