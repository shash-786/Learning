#pragma once
#include <string>

class Printer {
protected:
    Printer() = default;    

public:
    Printer(const Printer&) = delete;
    Printer& operator= (const Printer&) = delete;

    virtual void print(const std::string& data) = 0;
    static Printer& getInstance(const std::string& type);
};