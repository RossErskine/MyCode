#include "Graph.h"
#include "Simple_window.h"

double sgn(double d)
{
	if (d > 0) return 1;
	else if (d < 0) return -1;
	else return 0;
}

void draw_sup_elips(Open_polyline& se, double n)
{
	const double pi = (22.0 / 7.0);
	int a = 100;
	int b = 100;

	for (double angle = 0.0; angle < 2 * pi; angle += 2 * pi / 50)
	{
		double na = 2 / n;
		double x = pow(abs(cos(angle)), na) * a * sgn(cos(angle));
		double y = pow(abs(sin(angle)), na) * b * sgn(sin(angle));
		se.add(Point(x + 200, y + 200));
	}
}
void exercise_12()
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 800, 600, "PPP Chapter 12 exercise #12");

	Open_polyline se2;
	draw_sup_elips(se2, 2);
	se2.set_color(Color::black);
	se2.set_style(Line_style(Line_style::solid, 2));
	win.attach(se2);
	win.wait_for_button();
	
	Open_polyline se3;
	draw_sup_elips(se3, 4);
	se3.set_color(Color::red);
	se3.set_style(Line_style(Line_style::solid, 2));
	win.attach(se3);
	win.wait_for_button();

	Open_polyline se4;
	draw_sup_elips(se4, 6);
	se4.set_color(Color::blue);
	se4.set_style(Line_style(Line_style::solid, 2));
	win.attach(se4);
	win.wait_for_button();
}

void runExercise_12()
{
	exercise_12();
}