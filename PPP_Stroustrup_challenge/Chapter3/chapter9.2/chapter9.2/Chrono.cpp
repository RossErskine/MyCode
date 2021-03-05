#include "Chrono.h"
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

namespace Chrono
{
	// member function definitions:

	Date::Date(int yy, Month mm, int dd)
	{
		long int temp;
		if (!is_date(yy, mm, dd)) throw Invalid{};
		temp = dayZero(yy,mm,dd);
		if(temp < 0)
		{
			throw"constructor: no date allowed before 1/1/1970";
		}
		else
		{
			m_zero = temp;
		}
	}


	void Date::add_day(int n)
	{
		m_zero += n;

	}

	void Date::add_month(int n)
	{
		//...
	}

	void Date::add_year(int n)
	{
		
	}

	// ====== helper functions ======== //

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

	long int dayZero(int year, Month month, int day)
	{
		int yearZero = 1970;

		int diffYear = year - yearZero;
		long int sumDays = diffYear * 365;
		long int sum = 0;
		int leapYears = diffYear / 4;


		vector<int> month_size = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (leapyear(year))
		{
			month_size[1] = 29;
		}
		for (int i = 0; i < int(month) - 1; ++i)  //sum of all months berfore not present 
		{
			sum += month_size[i];
		}
		sum += day;
		sum += sumDays;
		sum += leapYears;

		return sum - 1;

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

	

	Day day_one_year(const Date& dfz)
	{
		int a = dfz.getZero(), b = 365, d = 7, l = 4, c = 0, e = 0;
		double temp = a / b;
		c = temp;
		e = (c/d) + (c/l);
		int ans = e / d;
		if (ans < 0)
		{
			ans += 7;
		}
		if (ans > 7)
		{
			ans -= 7;
		}

		return Day(ans);
	}
	

	int day_of_week(const Date& dd)
	{
		int year = dd.getZero() / 365;
		int leapYear = dd.getZero() % 365;
		int yDay = year / 7;
		return year;
		
	}

	void next_workday(const Date& dd)
	{
		
	}

	void getWeekOne(const Date& dd)
	{
		
		 
	}

	void getDayOne(const Date& dd)
	{
		
	}

	void week_of_year(const Date& dd)
	{
		


		
	}
	
	// ===== operators ===== //
	ostream& operator<<(ostream& os, const Day& d)
	{
		vector<string> day_tbl = { "Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday" };
		return os << day_tbl[int(d)];
	}
	

	
	

}