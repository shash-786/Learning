#include "TextDocumentApplication.h"
#include "TextDocument.h"

DocumentPtr TextDocumentApplication::Create() {
    return std::make_unique<TextDocument>();
}
