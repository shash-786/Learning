#pragma once
#include <string>
#include <iostream>

class Connection{
    private:
    std::string m_ConnectionStr;

    public:
    const std::string& GetConnectionStr() const {
        return m_ConnectionStr;
    }

    void SetConnectionStr(const std::string& ConnectionStr) {
        this->m_ConnectionStr = ConnectionStr;
    }

    Connection() = default;

    virtual ~Connection() = default;
    virtual void Open() = 0;
};