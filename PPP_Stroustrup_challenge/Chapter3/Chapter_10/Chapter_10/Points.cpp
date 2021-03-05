#include "Points.h"
#include <iostream>
#include <fstream>

namespace _Points
{
	// === constructor === //
	Point::Point():m_x(0),m_y(0)
	{
		
	}
	// vector constructor 
	Points::Points()	
	{

	}

	// === member functions === //
	
	// === helper functions === //
	bool is_point(int x)	
	{
		if ((x >= 0) && (x <= 9))return true; 
		else return false;

	}
	void printPoints(const Points& pts)
	{
		for (Point p : pts.getPoints())
		{
			std::cout << p;
		}
	}

	void output_to_file(Points& pts, const std::string& filename)
	{
		std::ofstream ost{ filename };
		if (!ost) throw "can't open output file ", filename;
		for (Point p : pts.getPoints())
		{
			ost << p;
		}
		ost.close();
	}

	Points input_from_file(std::string& filename)
	{
		Points temp;
		std::ifstream ist{ filename };
		if (!ist) throw "can't open output file ", filename;
		for (Point p; ist >> p;)
		{
			temp.addToPoints(p);
		}
		ist.close();
		return temp;
	}

	// === operators === //

	std::ostream& operator<<(std::ostream& os, Point& p)
	{
		const char comma = ',';
		return os << '(' <<  p.getX()
			<< comma << p.getY() << ')';
	}

	
	std::istream& operator>>(std::istream& is, Point& pp)
	{
		int x, y;
		char ch1, ch2, ch3;
		is >> ch1 >> x >> ch2 >> y >> ch3;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ')')
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		if (is_point(x))pp.setX(x); // check is_point before setX
		else throw "op>> x: point not recognised!";
		if(is_point(y))pp.setY(y);	// check is_point before setY
		else throw "op>> y: point not recognised!";
		return is;
	}

	// === compares Point type === //
	bool operator==(const Point& a, const Point& b)
	{
		return a.getX() == b.getX() &&
			a.getY() == b.getY();
	}
	bool operator!=(const Point& a, const Point& b)
	{
		return !(a == b);
	}

	// === compares vector in Points type === //
	bool operator==(const Points& a, const Points& b)
	{
		return a.getPoints() == b.getPoints();
	}
	bool operator!=(const Points& a, const Points& b)
	{
		return !(a == b);
	}
	
}

