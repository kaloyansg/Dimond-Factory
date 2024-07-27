#include "Base.h"
#include "Factory.h"

Base::Base() : name(nullptr)
{
	setName("Name");
}

Base::Base(const char* name) : name(nullptr)
{
	setName(name);
}

Base::Base(const Base& other) : name(nullptr)
{
	setName(other.name);
}

Base& Base::operator=(const Base& other)
{
	if (this == &other)
		return *this;

	throw "aaa";////////////////////////////////////

	setName(other.name);

	return *this;
}

Base::~Base()
{
	delete[] name;
	name = nullptr;
}

void Base::setName(const char* str)
{
	char* temp = new char[strlen(str) + 1];
	strcpy(temp, str);
	delete[] name;
	name = temp;
}

Creator::Creator()
{
	Factory::getFactory().registerCreatoer(this);
}
