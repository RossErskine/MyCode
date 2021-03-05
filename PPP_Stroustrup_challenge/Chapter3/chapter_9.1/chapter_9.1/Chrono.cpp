#include "Chrono.h"
#include <vector>
#include <numeric>

using namespace std;

namespace Chrono
{
	// member function definitions:

	Date::Date(int yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}

	const Date& default_date()
	{
		static Date dd{ 2001,Month::jan,1 };	//start of 21st century
		return dd;
	}

	Date::Date() :y{ default_date().year() }, m{ default_date().month() }, d{ default_date().day() }
	{

	}

	void Date::add_day(int n)
	{
		d += n;
		if (d < 1 || d > 31) throw "add_day: within day range!"; //incase someone enters minus numbers

	}

	void Date::add_month(int n)
	{
		//...
	}

	void Date::add_year(int n)
	{
		if (m == Month::feb && d == 29 && !leapyear(y + n))	//beware of leap years!
		{
			m = Month::mar;
			d = 1;
		}
		y += n;
	}

	// helper functions: 

	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid

		if (d <= 0) return false;			// d must be positive
		if (m < Month::jan || Month::dec < m) return false;

		int days_in_month = 31;				// most months have 31 days

		switch (m) 
		{
		case Month::feb:
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30;
			break;

		}
		if (days_in_month < d)return false;

		return true;
	}

	bool leapyear(int y)
	{
		if (y % 400 == 0)
			return true;
		if (y % 100 == 0)
			return false;
		if (y % 4 == 0)
			return true;
		return false;
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}

	bool operator !=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	
	ostream& operator<<(ostream& os, const Date& d)
	{
		return os <<'('<<d.year()
			<<','<<int(d.month())
			<< ','<<d.day()<<')';
	}
	
	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{
			is.clear(ios_base::failbit);
			return is;
		}
	}

	ostream& operator<<(ostream& os, const Day& d)
	{
		vector<string> day_tbl = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return os << day_tbl[int(d)];
	}

	

	Day day_of_week(const Date& dd)
	{
		int month = int(dd.month());
		int day = dd.day();
		int year = dd.year();
		int arr[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };
		if (month < 3)year--;
		return Day((year+year/4-year/100+year/400+arr[month-1]+day)%7);
	}

	Date next_workday(const Date& dd)
	{
		Date nextWorkday = dd;
		int day = int(day_of_week(dd));
		if (day <= 4) 
		{
			nextWorkday.add_day(1);
			return nextWorkday;
		}
		else if (day == 5)
		{
			nextWorkday.add_day(3);
			return nextWorkday;
		}
		else if (day == 6)
		{
			nextWorkday.add_day(2);
			return nextWorkday;
		}
		else 
		{
			throw "next_workday: something went wrong!";
		}
	}

	bool getWeekOne(const Date& dd)
	{
		int y = dd.year();			//get year from date
		Date fdiy = { y,Month::jan,1 };	//create first date of that year
		int day = int(day_of_week(fdiy));	//get day of the week of first day
		if (day == 0) { return 0; }
		if ((day >= 1) && (day <= 4))
		{
			return 1;
		}if ((day >= 5)||(day <= 6))
		{
			return 0;
		}
		else {
			throw"getWeekOne: return out of range!";
		}
		 
	}

	Day getDayOne(const Date& dd)
	{
		int y = dd.year();			//get year from date
		Date fdiy = { y,Month::jan,1 };	//create first date of that year
		Day day = day_of_week(fdiy);
		return day;
	}

	int week_of_year(const Date& dd)
	{
		int year = dd.year();
		int month = int(dd.month());
		int day = dd.day();


		int sum = 0, week_num;

		vector<int> month_size = { 31,28,31,30,31,30,31,31,30,31,30,31 }; 
		if (leapyear(year))
		{
			month_size[1] = 29;
		}
		for (int i = 0; i < month -1; ++i)  //sum of all months berfore not present 
		{
			sum += month_size[i];
		}
		int dayOne = int(getDayOne(dd));	//get day of the week 1/1/that year
		sum += day - dayOne + 10;		//sum days of present month subtract overhang days +10
		week_num = sum / 7;				// divide by seven 
		if(!getWeekOne(dd))week_num -= 1;	//find out if week one is not week 52/53 of previous year 
		return week_num;
	}
	
	
	

	
	

}