#pragma once
#include <memory>

class Document {
    public:
    virtual void Read() = 0;
    virtual void Write() = 0;
};

typedef std::unique_ptr<Document> DocumentPtr;