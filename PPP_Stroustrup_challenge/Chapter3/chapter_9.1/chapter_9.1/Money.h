#include <iostream>

namespace _Money
{
	using namespace std;

	class Money
	{
	public:
		Money(int dollar, int cent);

		// === non-modifying operations === //
		long int getCents() const { return m_cents; }
		double convert_to_dollar() const;

		// === modifying operations === //
		void setCents(int cents){ m_cents = cents; }
		long int convert_to_cent(int dollar, int cent);
		void addMoney(int dollar, int cent);
		void subtractMoney(int dollar, int cent);
		
	private:
		long int m_cents;
	};

	// === helper functions === //

	// === operators === //
	ostream& operator<<(ostream& os, const Money& mon);
	Money operator+=(const Money& a, const Money& b);
}
