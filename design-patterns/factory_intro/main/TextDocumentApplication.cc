#include "TextDocumentApplication.h"
#include "TextDocument.h"

Document* TextDocumentApplication::Create() {
    return new TextDocument(); 
}
