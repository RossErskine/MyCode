#include "drill.h"
#include <iostream>

using namespace std;

//========drill 2 ==========//
void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << " : " << b << endl;
}
void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << " : " << b << endl;
}
void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	//a = b;
	//b = temp;		// cannot change a constant
	cout << a << " : " << b << endl;
}
void drill_2()
{
	int x = 7;
	int y = 9;
	swap_v(x, y);
	swap_v(7, 9);
	swap_r(x, y);
	//swap_r(7, 9); need a variable to reference
	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	swap_v(7.7, 9.9);
	//swap_r(cx, cy); cannot change a const
	//swap_r(7.7, 9.9); need a variable to reference
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	swap_v(7.7, 9.9);
	//swap_r(dx, dy);only take ref int
	//swap_r(7.7, 9.9); need a variable to reference

}

//===============drill 3============//
namespace X 
{
	int var;
	void print()
	{
		cout << var << endl;
	}
}
namespace Y
{
	int var;
	void print()
	{
		cout << var << endl;
	}
}
namespace Z
{
	int var;
	void print()
	{
		cout << var << endl;
	}
}
void drill_3()
{
	X::var = 7;
	X::print();			//print X's var
	using namespace Y;
	var = 9;
	print();			//print Y's var
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();		//print Z's var
	}
	print();			//print Y's var
	X::print();			//print X's var
}



void runDrill()
{
	drill_2();
	drill_3();
}