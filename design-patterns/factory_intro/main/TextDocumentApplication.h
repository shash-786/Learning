#pragma once
#include "application.h"

class TextDocumentApplication: public Application {
    Document* Create() override;
};