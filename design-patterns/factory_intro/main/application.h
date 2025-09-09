#pragma once
#include "document.h"

class Application {
private:
    Document* m_pdocument;
public:
    void New();
    void Open();
    void Save();
    virtual Document* Create() {
        return nullptr;
    }
};