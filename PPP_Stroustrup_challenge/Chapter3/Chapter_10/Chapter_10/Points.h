#include <iostream>
#include <vector>
#include <string>

namespace _Points
{
	class Point
	{
	public:
		Point();

		// === non-modifying operations === //
		int getX() const { return m_x; }
		int getY() const { return m_y; }

		// === modifying operations === //
		void setX(int x) { m_x = x; }
		void setY(int y) { m_y = y; }

	private:
		int m_x;
		int m_y;
	};

	class Points
	{
	public:
		Points();

		// === non-modifying operations === //
		std::vector<Point> getPoints() const { return m_points; }
		int pointsSize() const { return m_points.size(); }

		// === modifying operations === //
		void addToPoints(Point p){ m_points.push_back(p); }
		
	private:
		std::vector<Point> m_points;
	};

	// === helper fuctions === //
	bool is_point(int x);
	void printPoints(const Points& pts);
	void output_to_file(Points& pts, const std::string& filename);
	Points input_from_file(std::string& filename);

	// == operators == //
	std::ostream& operator<<(std::ostream& os, Point& p);
	std::istream& operator>>(std::istream& is, Point& pp);

	// === compares Point type === //
	bool operator==(const Point& a, const Point& b);
	bool operator!=(const Point& a, const Point& b);

	// === compares vector in Points type === //
	bool operator==(const Points& a, const Points& b);
	bool operator!=(const Points& a, const Points& b);
	
}
