#include "Tests.h"
#include <iostream>

int main()
{
	
	try
	{
		runTest();
		return 0;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;

	}
	
	catch (...)
	{
		std::cerr << "exception\n";
	}
	
}