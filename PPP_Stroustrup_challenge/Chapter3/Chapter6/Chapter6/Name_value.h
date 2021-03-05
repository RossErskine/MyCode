#pragma once
#include  <string>

using namespace std;

class Name_value
{
public:
	string m_name;
	int m_value;
	
	Name_value(string name, int value) : m_name(name), m_value(value){}
};

