#pragma once
#include <iostream>
class Date
{
public:
	Date() : date(0)
	{
		date |= (2010 - 2010);
		date |= (1 << 5);
		date |= (1 << 9);
	}

	Date(int day, int month, int year) : date(0)
	{
		if (day > 30)
			throw std::invalid_argument("invalid day");
		if (month > 12)
			throw std::invalid_argument("invalid month");
		if (year > 2030 || year < 2010)
			throw std::invalid_argument("invalid year");

		date |= (year-2010);
		date |= (month << 5);
		date |= (day << 9);
	}

	int getDay() const
	{
		return (date >> 9);
	}

	int getMonth() const
	{
		return (date >> 5) & 15;
	}

	int getYear() const
	{
		return (date & 31) + 2010;
	}

private:
	uint16_t date; // 00dddddm mmmyyyyy
	//32 16 8 4 2 1
};

