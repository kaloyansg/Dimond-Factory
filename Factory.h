#pragma once
#include "Base.h"

class Factory
{
public:
	static Factory& getFactory()
	{
		static Factory fact;
		return fact;
	}
	void registerCreatoer(const Creator* ctr)
	{
		if (count >= size)
			throw std::invalid_argument("Not enough space in the factory for the creator");

		arr[count] = ctr;
		count++;
	}
	Base* createElement(const char* str) const
	{
		for (size_t i = 0; i < count; ++i)
		{
			if (arr[i])
				if (arr[i]->check(str))
					return arr[i]->create(std::cin);
		}

		throw std::invalid_argument("invalid type");
	}

	Factory(const Factory&) = delete;
	Factory& operator=(const Factory&) = delete;
	~Factory() = default;

private:
	Factory() : count(0)
	{
		for (size_t i = 0; i < size; ++i)
			arr[i] = nullptr;
	}

private:
	static const size_t size = 3;
	const Creator* arr[size];
	size_t count;
};

