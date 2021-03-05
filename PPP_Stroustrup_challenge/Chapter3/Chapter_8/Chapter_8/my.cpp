#include "my.h"
#include <iostream>

using namespace std;

int foo;

void print_foo()
{
	cout << foo << endl;
}

void print(int i)
{
	cout << i << endl;
}

void run()
{
	foo = 7;
	print_foo();
	print(99);
}
