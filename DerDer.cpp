#include "DerDer.h"

DerDer::DerDer() : id(nullptr)
{
	id = new char[strlen("ID") + 1];
	strcpy(id, "ID");
}

DerDer::DerDer(const char* str, const char* name, int day, int month, int year, 
	const char* brand, const char* model)
	: id(nullptr), Base(name), Der1(name, day, month, year), Der2(name, brand, model)
{
	id = new char[strlen(str) + 1];
	strcpy(id, str);
}

DerDer::DerDer(const DerDer& other) : Base(other), Der1(other), Der2(other), id(nullptr)
{
	id = new char[strlen(other.id) + 1];
	strcpy(id, other.id);
}

DerDer& DerDer::operator=(const DerDer& other)
{
	if (this == &other)
		return *this;

	char* temp = new char[strlen(other.id) + 1];
	strcpy(temp, other.id);

	try
	{
		Base::operator=(other);
		Der1::operator=(other);
		Der2::operator=(other);
	}
	catch (...)
	{
		delete[] temp;
		throw;
	}

	delete[] id;
	id = temp;

	return *this;
}

DerDer::~DerDer()
{
	delete[] id;
	id = nullptr;
}

Base* DerDer::clone() const
{
	return new DerDer(*this);
}

bool CreatorCreator::check(const char* str) const
{
	return strcmp(str, "3") == 0;
}

Base* CreatorCreator::create(std::istream& is) const
{
	char nameBuff[32], id[32];
	is >> id >> nameBuff;
	int day = 1, month = 1, year = 2010;
	is >> day >> month >> year;

	char brand[32], model[32];
	is.getline(brand, 31);
	is.getline(model, 31);

	return new DerDer(id, nameBuff, day, month, year, brand, model);
}

static CreatorCreator __;