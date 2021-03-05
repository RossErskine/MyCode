#include <iostream>
#include <fstream>
#include <string>


namespace _Roman_int
{
	
	class Roman_int
	{
	public:
		// == constructors == //
		Roman_int();

		// == non-modifying == //
		std::string getRomNum() const { return m_romNum; }

		// == modifying == //
		void setRomNum(std::string& rn) { m_romNum = rn; }
		int as_int();

	private:
		std::string m_romNum;
	};

	// == helper functions == //
	bool is_Roman_num(const char&);
	std::string as_Roman_number(const int& num);

	// == operators == //
	std::ostream& operator<<(std::ostream& os, Roman_int& rn);
	std::istream& operator>>(std::istream& is, Roman_int& rn);

	bool operator==(const Roman_int& a, const Roman_int& b);
	bool operator!=(const Roman_int& a, const Roman_int& b);
}
