#pragma once
#include "document.h"

class SpreadSheet: public Document{
public:
    void Read() override;
    void Write() override;
};