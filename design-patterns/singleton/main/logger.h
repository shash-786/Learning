#pragma once
#include <iostream>

class Logger {
    FILE* m_pstream;
    std::string m_tag;

public:
    void write_log(const char* logs);
    void add_tag(const std::string tag);
    Logger();
    ~Logger();
};