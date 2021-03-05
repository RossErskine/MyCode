#pragma once
#include <vector>
#include <iostream>

using namespace std;

void test(vector<int> v, vector<int>& rv)
{
	v[1] = 99;
	rv[2] = 66;
}

void fib()
{
	vector<int> fib = { 1,1,2,3,5,8,13,21 };
	test(fib, fib);
	cout << fib[1] << ' ' << fib[2] << endl;
}

void messingPlay()
{
	fib();
}