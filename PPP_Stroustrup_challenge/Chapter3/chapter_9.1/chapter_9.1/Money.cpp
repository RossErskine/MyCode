#include "Money.h"

namespace _Money
{
	// === constructors === //
	Money::Money(int dollar, int cent)
	{
		if ((dollar < 0) || (cent < 0))
		{
			throw " constructor: cannot have negative money!";
		}
		m_cents = convert_to_cent(dollar, cent);
	}

	

	// === member functions === //
	long int Money::convert_to_cent(int dollar, int cent)
	{
		dollar *= 100;
		return dollar + cent;
	}

	double Money::convert_to_dollar() const
	{
		double dollar = m_cents;
		dollar /= 100;
		return dollar;
	}
	void Money::addMoney(int dollar, int cent)
	{
		m_cents += convert_to_cent(dollar, cent);
	}

	void Money::subtractMoney(int dollar, int cent)
	{
		m_cents -= convert_to_cent(dollar, cent);
	}
	// === helper functions === //

	// === operators === //
	ostream& operator<<(ostream& os, const Money& mon)
	{
		return os << '$' << mon.convert_to_dollar();
	}
	
	Money operator+=(const Money& a, const Money& b)
	{
		return a += b;
	}
}