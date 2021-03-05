#include <string>
#include <vector>
#include <iostream>

namespace Temp_Readings
{
	enum class temp_type
	{
		c,f
	};
	struct Reading
	{
		int hour;
		double temperature;
		temp_type type;		// c = celsius, f = fahrenheit
		Reading();
		Reading(int h, double t, temp_type tp);
		
	};

	bool is_hour(int);
	bool is_temp(double);
	bool buffer(const Reading&);
	Reading cel_to_feh(const Reading&);
	
	// === operators === //
	std::ostream& operator<<(std::ostream& os, Reading& r);
	std::istream& operator>>(std::istream& is, Reading& r);
	
}






























