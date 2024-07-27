#pragma once
#include <iostream>
#pragma warning (disable : 4996)

class Base
{
public:
	Base();
	Base(const char* name);
	Base(const Base& other);
	Base& operator=(const Base& other);
	virtual ~Base();

	virtual Base* clone() const = 0;

private:
	void setName(const char* str);

private:
	char* name;
};

class Creator
{
public:
	Creator();
	virtual ~Creator() = default;
	virtual bool check(const char* str) const = 0;
	virtual Base* create(std::istream& is) const = 0;
};