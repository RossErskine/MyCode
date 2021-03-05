#pragma once
#include <iostream>
#include <vector>

using namespace std;

int exceptions()
{
	try {
		vector<int> v;
		for (int x; cin >> x;)
			v.push_back(x);
		for(unsigned int i = 0; i< v.size();++i)
			cout<< "v["<<i<<"]=="<<v[i]<<'\n';
		return 0;
	}
	catch (out_of_range) {
		cerr << "Oops! Range error\n";
		return 1;
	}
	catch (...) {
		cerr << "Exception: something went wrong\n";
		return 2;
	}
}

void exception_2()
{

		try
		{
			vector<int> v;
			for (int x; cin >> x;)
			{
				if (!cin) cerr << "Exception: something went wrong\n";
				if (x == 20)
				{
					throw 20;
				}
				v.push_back(x);
				
			}
			for (unsigned int i = 0; i < v.size(); ++i)
				cout << "v[" << i << "]==" << v[i] << '\n';

			
		}
		//==exception handler==//
		catch (int e)
		{
			cout << "An exception occurred. Exception Nr. " << e << '\n';
		}
		
	

}


	

