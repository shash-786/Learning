#pragma once
#include <string>
#include <vector>

class Cursor{
    public:
    virtual const std::string& Get() = 0;
    virtual bool HasNext() = 0;
    virtual ~Cursor() = default;
};