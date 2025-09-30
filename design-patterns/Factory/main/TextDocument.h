#pragma once
#include "document.h"

class TextDocument: public Document{
public:
    void Read() override;
    void Write() override;
};