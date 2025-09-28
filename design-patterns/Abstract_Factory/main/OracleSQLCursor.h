#pragma once
#include "cursor.h"

class OracleSQLCursor: public Cursor {
    private:
    std::vector< std::string > OracleSQLdb {
        "V",
        "W",
        "X",
        "Y",
        "Z",
    };

    std::vector< std::string >::const_iterator it;

    public:
    OracleSQLCursor();
    const std::string& Get() override;
    bool HasNext() override;

    ~OracleSQLCursor() = default;
};