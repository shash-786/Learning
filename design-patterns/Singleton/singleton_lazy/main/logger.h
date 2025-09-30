#pragma once
#include <string>
#include <memory>

class Logger {
    struct deleter{
        void operator()(Logger* p) {
            delete p;
        }
    };

    std::string m_tag;
    FILE *m_pstream;
    inline static std::unique_ptr<Logger, deleter> m_lptr;

    Logger();
   ~Logger();
    
    public:
    Logger(const Logger&) = delete;
    Logger& operator= (const Logger&) = delete;

    static Logger& getInstanceLazily();
    void writeLog(const char* log);
    void setTag(std::string tag);
};