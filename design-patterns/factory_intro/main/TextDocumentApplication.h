#pragma once
#include "application.h"

class TextDocumentApplication: public Application {
    DocumentPtr Create() override;
};