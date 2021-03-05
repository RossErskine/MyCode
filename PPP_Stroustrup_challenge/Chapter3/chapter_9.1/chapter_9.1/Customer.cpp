#include "Customer.h"
#include <iostream>

namespace Customer
{
	//== member functions ==//
	Patron::Patron(string name, int library_card_num) : m_name{ name }, m_library_card_num{ library_card_num }
	{
		m_library_fees = 0;
	}

	//=== helper functions ===//

	bool has_lib_fees(const Patron& pat)	//checks for outstanding fees
	{
		if (pat.getLibrary_fees() > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	
	//=== Operator ===//
	ostream& operator<<(ostream& os, const Patron& pat)
	{
		return os << pat.getName();
		

	}
	
}