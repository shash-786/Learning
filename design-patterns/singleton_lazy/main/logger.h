#pragma once
#include <string>
#include <memory>

class Logger {
    std::string m_tag;
    FILE *m_pstream;
    inline static std::unique_ptr<Logger> m_lptr;

    Logger();
    
    public:
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator= (const Logger&) = delete;

    static Logger& getInstanceLazily();
    void writeLog(const char* log);
    void setTag(std::string tag);
};