#include <iostream>

using namespace std;

namespace _Rational 
{
	class Rational
	{
	public:
		Rational(int num, int den);
		Rational();

		// === non-modifying operations === //
		int getNumerator() const { return m_numerator; }
		int getDenominator() const { return m_denominator; }
		double to_double() const { return double(m_numerator) / m_denominator; }
		bool is_rational();

		// === modifying operations === //
		void setNumerator(int num) { m_numerator = num; }
		void setDenominator(int den) { m_denominator = den; }
		
	private:
		int m_numerator;
		int m_denominator;
	};

	// === helper functions === //
	Rational simplify(const Rational& rat);
	int gcd(int a, int b);

	// === operators === //
	ostream& operator<<(ostream& os, const Rational& rat);
	bool operator==(const Rational& a, const Rational& b);
	bool operator !=(const Rational& a, const Rational& b);
	Rational operator *=(const Rational& a, const Rational& b);
	Rational operator /=(const Rational& a, const Rational& b);
	Rational operator +=(const Rational& a, const Rational& b);
	Rational operator -=(const Rational& a, const Rational& b);
}
