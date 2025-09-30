#pragma once
#include "application.h"

class SpreadSheetApplication : public Application {
    DocumentPtr Create() override;
};