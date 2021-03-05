#include "Rational.h"

namespace _Rational
{
	// === constructor === //
	Rational::Rational(int num, int den):m_numerator{num},m_denominator{den}
	{
		if (!is_rational()) throw "constructor: error";
	}

	Rational::Rational()
	{
		m_numerator = 0;
		m_denominator = 0;
	}

	// === member functions === //
	bool Rational::is_rational()
	{
		
		if (m_denominator <= 0) return false;
		if (to_double() * m_denominator != double(m_numerator))return false;

		return true;
	}

	// === helper functions === //

	Rational simplify(const Rational& rat)
	{
		Rational temp;
		int d;
		d = gcd(rat.getNumerator(), rat.getDenominator());
		
		

		temp.setNumerator(rat.getNumerator() / d);
		temp.setDenominator(rat.getDenominator() / d);
		return temp;
		
	}

	int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		if (b == 0)
			return a;

		// base case 
		if (a == b)
			return a;

		if (a < 0)
		{
			 a += a + a;
		}
		
		// a is greater 
		if (a > b)
			return gcd(a - b, b);
		return gcd(a, b - a);
	}
	// === operators === //
	ostream& operator<<(ostream& os,const Rational& rat)
	{
		return os << '(' << rat.getNumerator()
			<< '/' << rat.getDenominator()
			<< ')';
	}

	bool operator==(const Rational& a, const Rational& b)
	{
		if (a.getNumerator() != b.getNumerator()) return false;
		if (a.getDenominator() != b.getDenominator()) return false;

		return true;
	}

	bool operator !=(const Rational& a, const Rational& b)
	{
		return !(a == b);
	}

	Rational operator *=(const Rational& a, const Rational& b)
	{
		Rational temp;
		temp.setNumerator(a.getNumerator() * b.getNumerator());
		temp.setDenominator(a.getDenominator() * b.getDenominator());
		return temp;
	}

	Rational operator /=(const Rational& a, const Rational& b)
	{
		Rational temp;
		temp.setNumerator(a.getNumerator() * b.getDenominator());
		temp.setDenominator(b.getNumerator() * a.getDenominator());
		return temp;
	}

	Rational operator +=(const Rational& a, const Rational& b)
	{
		Rational temp;
		temp.setNumerator((a.getNumerator() * b.getDenominator()) + (b.getNumerator() * a.getDenominator()));
		temp.setDenominator(a.getDenominator() * b.getDenominator());
		return temp;

	}

	Rational operator -=(const Rational& a, const Rational& b)
	{
		Rational temp;
		temp.setNumerator((a.getNumerator() * b.getDenominator()) - (b.getNumerator() * a.getDenominator()));
		temp.setDenominator(a.getDenominator() * b.getDenominator());
		return temp;
	}
}