#include "Roman_int.h"
#include <vector>

namespace _Roman_int
{
	// == constructors == //
	Roman_int::Roman_int()
	{
	}

	// == member functions == //
	int Roman_int::as_int()
	{
		int sum = 0;
		for (char ch : m_romNum)
		{
			switch (ch)
			{
			case 'I':
				sum += 1;
				break;
			case 'V':
				sum += 5;
				break;
			case 'X':
				sum += 10;
				break;
			case 'L':
				sum += 50;
				break;
			case 'C':
				sum += 100;
				break;
			case 'D':
				sum += 500;
				break;
			case 'M':
				sum += 1000;
				break;
			default:
				throw " as_int: roman numeral not recognised!";
				break;
			}
		}
		return sum;
	}

	// == helper functions == //
	bool is_Roman_num(const char& ch)
	{
		std::vector<char> romanNumbers = { 'I','V','X','L','C','D','M' };
		
		for (char j : romanNumbers)
		{
			if (ch == j)
			{
				return true;
			}
		}
		
		return false;
	}

	std::string as_Roman_number(const int& numb)
	{
		int number = numb;
		std::string romNum;
		std::vector<int> num = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
		std::vector<std::string> sym = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
		int i = 12;
		while (number > 0)
		{
			int div = number / num[i];
			number = number % num[i];
			while (div--)
			{
				romNum += sym[i];
			}
			i--;
		}
		return romNum;
	}

	

	// == operators == //
	std::ostream& operator<<(std::ostream& os, Roman_int& rn)
	{
		return os << rn.getRomNum();
	}

	std::istream& operator>>(std::istream& is, Roman_int& rn)
	{
		std::string romInt;
		char ch;
		
		while (is.get(ch))
		{
			if (is_Roman_num(ch)) romInt += ch;
			else {
				is.putback(ch);
				break;
			}
		}
		
		rn.setRomNum(romInt);
		return is;
	}

	bool operator==(const Roman_int& a, const Roman_int& b)
	{
		return a.getRomNum() == b.getRomNum();
	}
	bool operator!=(const Roman_int& a, const Roman_int& b)
	{
		return !(a == b);
	}
}