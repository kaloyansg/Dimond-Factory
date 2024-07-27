#include <iostream>
#include "Factory.h"
#include "Base.h"

int main()
{
	char type[2];

	try
	{
		for (size_t i = 0; i < 3; ++i)
		{
			std::cin.getline(type, 2);
			Base* ptr = Factory::getFactory().createElement(type);
			delete ptr;
			//std::cin.ignore();
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cout << err.what();
	}
	
}