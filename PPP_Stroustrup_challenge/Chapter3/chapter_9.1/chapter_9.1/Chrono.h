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
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};



	class Date
	{
	public:
		class Invalid {};		//a throw as exception

		Date(int y, Month m, int d);	//check for valid date and initialise
		Date();							//default constructor
		// the default copy operations are fine

		// nonmodifying operations:
		int day() const { return d; };
		Month month() const { return m; };
		int year() const { return y; };

		// modifying operations:
		void add_day(int n);
		void add_month(int m);
		void add_year(int n);

	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Month m, int d); //true for valid date
	bool leapyear(int y);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
	ostream& operator<<(ostream& os, const Day& d);

	Day day_of_week(const Date& d);
	Date next_workday(const Date& dd);
	int week_of_year(const Date& dd);
	bool getWeekOne(const Date& dd);
	Day getDayOne(const Date& dd);
}
