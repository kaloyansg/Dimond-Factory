#include "Der1.h"

bool Creator1::check(const char* str) const
{
    return strcmp(str, "1") == 0;
}

Base* Creator1::create(std::istream& is) const
{
    char nameBuff[32];
    is >> nameBuff;
    int day = 1, month = 1, year = 2010;
    is >> day >> month >> year;
    return new Der1(nameBuff, day, month, year);
}

static Creator1 __;