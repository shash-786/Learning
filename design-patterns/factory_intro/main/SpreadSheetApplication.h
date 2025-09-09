#pragma once
#include "application.h"

class SpreadSheetApplication : public Application {
    Document* Create() override;
};