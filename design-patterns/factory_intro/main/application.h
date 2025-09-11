#pragma once
#include "document.h"

class Application {
private:
    DocumentPtr m_pdocument;
public:
    void New();
    void Open();
    void Save();
    virtual DocumentPtr Create() {
        return nullptr;
    }
};