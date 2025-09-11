#include "SpreadSheetApplication.h"
#include "SpreadSheet.h"

DocumentPtr SpreadSheetApplication::Create()  {
    return std::make_unique<SpreadSheet>();
}
