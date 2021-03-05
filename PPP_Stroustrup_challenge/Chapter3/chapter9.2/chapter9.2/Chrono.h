#include <iostream>

using namespace std;

namespace Chrono
{

	enum class Month
	{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	enum class Day
	{
		thursday =0,friday,saturday,sunday,monday,tuesday,wednesday
	};

	

	class Date
	{
	public:
		class Invalid {};		//a throw as exception

		Date(int y, Month m, int d);	//check for valid date and initialise
		Date();							//default constructor
		
		// the default copy operations are fine

		// nonmodifying operations:
		long int getZero() const { return m_zero; };

		// modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

	private:
		long int m_zero;
	};

	

	bool is_date(int y, Month m, int d); //true for valid date
	bool leapyear(int y);

	ostream& operator<<(ostream& os, const Day& d);

	Day day_one_year(const Date& dfz);
	int day_of_week(const Date& d);
	void next_workday(const Date& dd);
	void week_of_year(const Date& dd);
	void getWeekOne(const Date& dd);
	void getDayOne(const Date& dd);
	long int dayZero(int year, Month month, int day);
}
