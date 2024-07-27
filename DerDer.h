#pragma once
#include "Der1.h"
#include "Der2.h"

class DerDer : public Der1, public Der2
{
public:
	DerDer();
	DerDer(const char* str, const char* name, int day, int month, int year, 
		const char* brand, const char* model);
	DerDer(const DerDer& other);
	DerDer& operator=(const DerDer& other);
	~DerDer();

	virtual Base* clone() const override;

private:
	char* id;
};

class CreatorCreator : public Creator
{
public:
	virtual bool check(const char* str) const override;
	virtual Base* create(std::istream& is) const override;
};