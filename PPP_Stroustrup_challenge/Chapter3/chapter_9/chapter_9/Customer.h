#include <string>

using namespace std;

namespace Customer
{
	class Patron
	{
	public:
		Patron(string name, int library_card_num);

		// non-modifying operations
		string getName() const { return m_name; }
		int getLibrary_card_num() const { return m_library_card_num; }
		double getLibrary_fees() const { return m_library_fees; }

		// modifying operations
		void setName(string name) { m_name = name; }
		void setLibrary_card_num(int lib_card_num) { m_library_card_num = lib_card_num; }
		void setLibrary_fees(double lib_fees) { m_library_fees = lib_fees; }

	private:
		string m_name;
		int m_library_card_num;
		double m_library_fees;
	};

	//=== helper functions ===//
	bool has_lib_fees(const Patron& pat);
	
}
