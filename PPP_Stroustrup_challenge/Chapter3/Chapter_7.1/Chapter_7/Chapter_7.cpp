#include "SimpleCalc.h"



int main()
{
	try
	{
		// predefined names:
		st.declare("pi", 3.1415926535,true);
		st.declare("e", 2.7182818284,true);
		st.declare("k", 1000,true);

		runCalc();

		return 0;
	}
	catch (runtime_error e)
	{
		cout << e.what() << endl;
		//char c;
		//while (cin >> c && c != ';');
		return 1;
	}
	
	/*catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}*/

}


