#pragma once
#include "Base.h"

class Der2 : virtual public Base
{
public:
	Der2();
	Der2(const char* name, const char* brand, const char* model);
	Der2(const Der2& other);
	Der2& operator=(const Der2& other);
	~Der2();

	virtual Base* clone() const override;

private:
	char* brand;
	char* model;
};

class Creator2 : public Creator
{
public:
	virtual bool check(const char* str) const override;
	virtual Base* create(std::istream& is) const override;
};