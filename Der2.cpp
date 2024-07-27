#include "Der2.h"

Der2::Der2() : brand(nullptr), model(nullptr)
{
	brand = new char[strlen("Brand") + 1];
	model = new (std::nothrow) char[strlen("Model") + 1];
	if (!model)
	{
		delete[] brand;
		throw std::bad_alloc();
	}
	strcpy(brand, "Brand");
	strcpy(model, "Model");
}

Der2::Der2(const char* name, const char* brand, const char* model)
	: Base(name), brand(nullptr), model(nullptr)
{
	this->brand = new char[strlen(brand) + 1];
	this->model = new (std::nothrow) char[strlen(model) + 1];
	if (!this->model)
	{
		delete[] this->brand;
		throw std::bad_alloc();
	}
	strcpy(this->brand, brand);
	strcpy(this->model, model);
}

Der2::Der2(const Der2& other) : Base(other), brand(nullptr), model(nullptr)
{
	this->brand = new char[strlen(other.brand) + 1];
	this->model = new (std::nothrow) char[strlen(other.model) + 1];
	if (!this->model)
	{
		delete[] this->brand;
		throw std::bad_alloc();
	}
	strcpy(this->brand, other.brand);
	strcpy(this->model, other.model);
}

Der2& Der2::operator=(const Der2& other)
{
	if (this == &other)
		return *this;

	char* tempBrand = new char[strlen(other.brand) + 1];
	char* tempModel = new (std::nothrow) char[strlen(other.model) + 1];
	if (!tempModel)
	{
		delete[] tempBrand;
		throw std::bad_alloc();
	}

	try
	{
		Base::operator=(other);
	}
	catch (...)
	{
		delete[] tempBrand;
		delete[] tempModel;
		throw;
	}

	strcpy(tempBrand, other.brand);
	strcpy(tempModel, other.model);

	delete[] this->brand;
	this->brand = tempBrand;
	delete[] this->model;
	this->model = tempModel;
}

Der2::~Der2()
{
	delete[] brand;
	brand = nullptr;
	delete[] model;
	model = nullptr;
}

Base* Der2::clone() const
{
	return new Der2(*this);
}

bool Creator2::check(const char* str) const
{
	return strcmp(str, "2") == 0;
}

Base* Creator2::create(std::istream& is) const
{
	char name[32], brand[32], model[32];
	is.getline(name, 31);
	is.getline(brand, 31);
	is.getline(model, 31);
	return new Der2(name, brand, model);
}

static Creator2 __;