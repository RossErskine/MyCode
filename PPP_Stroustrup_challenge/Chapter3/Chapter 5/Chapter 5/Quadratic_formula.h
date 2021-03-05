#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Quadratic_formula
{
private:
	double m_a = 0;
	double m_b = 0;
	double m_c =0;
	double m_plus_x=0;
	double m_minus_x=0;
	
public:
	double mid = 0;
	void quad_Ans_plus(double a, double b, double c)
	{
		mid = b * b - 4 * a * c;
		if (mid < 0)
		{
			throw "no root!";
		}
		else
		{
			double plus_x = (-b + sqrt(mid)) / (2 * a);
			m_plus_x = plus_x;
		}

	}

	void quad_Ans_minus(double a, double b, double c)
	{
		mid = b * b - 4 * a * c;
		if (mid < 0)
		{
			throw "no root!";
		}
		double minus_x = (-b - sqrt(mid)) / (2 * a);
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

