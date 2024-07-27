#pragma once
#include "Base.h"
#include "Date.h"

class Der1 : virtual public Base
{
public:
	Der1()
	{}

	Der1(const char* name, int day, int month, int year) : Base(name), date(day,month,year)
	{}

	virtual Base* clone() const override
	{
		return new Der1(*this);
	}

private:
	Date date;
};

class Creator1 : public Creator
{
public:
	virtual bool check(const char* str) const override;
	virtual Base* create(std::istream& is) const override;
};