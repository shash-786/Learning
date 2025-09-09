#include <iostream>
#include "SpreadSheetApplication.h"
#include "TextDocumentApplication.h"

int main(int argc, char const *argv[]) {
    // Application a;
    TextDocumentApplication a;
    a.New();
    a.Open();
    a.Save();

    SpreadSheetApplication b;
    b.New();
    b.Open();
    b.Save();

    return 0;
}
