#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Quadratic_formula
{
private:
	double m_a;
	double m_b;
	double m_c;
	double m_plus_x;
	double m_minus_x;
public:
	void quad_Ans_plus(double a, double b, double c)
	{

		double plus_x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		m_plus_x = plus_x;

	}

	void quad_Ans_minus(double a, double b, double c)
	{
		double minus_x = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		m_minus_x = minus_x;
	}

	//==============get x ===============//
	const double& GetPlusX() const
	{
		return m_plus_x;
	}
	const double& GetMinusX() const
	{
		return m_minus_x;
	}
};

