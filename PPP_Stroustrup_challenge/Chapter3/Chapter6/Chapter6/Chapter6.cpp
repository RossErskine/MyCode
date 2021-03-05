#include "SimpleCalc.h"
#include "exercises.h"
#include "Messing.h"


int main()
{
    try
    {
		runCalc();
		//runExercises();
		//messingPlay();
		
	}
	catch (runtime_error e)
	{
		cout << e.what() << endl;
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}
}

