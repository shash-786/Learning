#pragma once
#include <string>
#include "printer.h"

class LocalPrinter : public Printer {
private:
    LocalPrinter() = default;
    static LocalPrinter m_instance;
public:
    void print(const std::string& data);
    static LocalPrinter& getInstance();
};