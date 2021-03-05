#include "Exercises.h"
#include "drills.h"
#include <iostream>

int main()
{
	try
	{
		//runDrills();
		runExercises();
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

