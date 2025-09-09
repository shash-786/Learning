#include "SpreadSheetApplication.h"
#include "SpreadSheet.h"

Document* SpreadSheetApplication::Create()  {
    return new SpreadSheet(); 
}
