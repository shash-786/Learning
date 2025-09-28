#pragma once
#include "cursor.h"

class MySQLCursor : public Cursor {
    private:
    std::vector< std::string > MySQLdb {
        "A",
        "B",
        "C",
        "D",
        "E",
    };

    std::vector< std::string >::const_iterator it;

    public:
    MySQLCursor();
    const std::string& Get() override;
    bool HasNext() override;

    ~MySQLCursor() = default;
};