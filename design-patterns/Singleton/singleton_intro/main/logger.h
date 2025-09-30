#pragma once
#include <iostream>

class Logger {
    FILE* m_pstream;
    std::string m_tag;

    Logger();
    static Logger m_instance;

public:
    static Logger& GetInstance();
    ~Logger();

    Logger(const Logger&) = delete;
    Logger& operator= (const Logger&) = delete;

    void write_log(const char* logs);
    void add_tag(const std::string tag);
};