#include "Temperature_Readings.h"
#include <fstream>


namespace Temp_Readings
{
	// === constructors === //
	Reading::Reading(): hour(0),temperature(0), type(temp_type::f)
	{
	}
	Reading::Reading(int h, double t, temp_type tp) : hour(0), temperature(0), type(temp_type::f)
	{
		if (is_hour(h))hour = h;
		if (is_temp(t))temperature = t;
	}
	bool is_hour(int hour)
	{
		if ((hour < 0) || (hour > 23)) throw "is_hour: hour out of range!";
		else return true;
		return false;
	}

	bool is_temp(double temp)
	{
		if (temp < -459.67)throw "is_temp: temp out of range!";
		else return true;
		return false;
	}

	bool buffer(const Reading& reading)
	{
		if ((is_hour(reading.hour)) && (is_temp(reading.temperature)))return true;
		else return false;
	}

	Reading cel_to_feh(const Reading& reading)
	{
		if (reading.type == temp_type::c)
		{
			Reading temp;
			temp.temperature = reading.temperature * 1.8 + 32;  
			return temp;
		}
	}

	// === operators === //
	std::ostream& operator<<(std::ostream& os, Reading& r)
	{
		char type = NULL;
		switch (r.type)
		{
		case temp_type::c:
			type = 'c';
			break;
		case temp_type::f:
			type = 'f';
			break;
		default:
			//throw "op>>: no type detected!";
			break;
		}
		return os << '(' << r.hour
			<< ',' << r.temperature << ',' 
			<< type << ')';
	}

	std::istream& operator>>(std::istream& is, Reading& r)
	{
		int hour;
		double temp;
		char type;
		char ch1, ch2, ch3, ch4;

		is >> ch1 >> hour >> ch2 >> temp >> ch3 >> type >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{
			is.clear(std::ios_base::failbit);
			return is;
		}
		switch (type)
		{
		case 'c':
			r.type = temp_type::c;
			break;
		case 'f':
			r.type = temp_type::f;
			break;
		default:
			throw "operator>>: type not recognised! ";
			break;
		}
		
		r.hour = hour;
		r.temperature = temp;
		return is;
	}

	
	
}


