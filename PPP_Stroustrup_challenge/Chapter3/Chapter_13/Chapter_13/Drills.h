#include "Graph.h"
#include "Simple_window.h"

void Drills()
{
	using namespace Graph_lib;

	// == drill #1 == //
	Point tl(150, 150);
	Simple_window win(tl, 800, 1000, "PPP Chapter 13 Drill");

	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;

	// == drill #2 == //
	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)		// vertical lines
		grid.add(Point{ x,0 }, Point{ x,y_size });
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point{ 0,y }, Point{ x_size,y });		//horizontal lines

	grid.set_color(Color::black);
	win.attach(grid);
	win.wait_for_button();

	// == drill #3 == //
	Vector_ref<Graph_lib::Rectangle> vr;			// Vecter_ref holds unnamed objects
	for (int i = 0; i < x_size; i += x_grid)
	{
		vr.push_back(new Graph_lib::Rectangle{ Point{i,i}, Point{i + x_grid,i + x_grid} });
		vr[vr.size() - 1].set_fill_color(Color::red);
		win.attach(vr[vr.size() - 1]);
	}
	win.wait_for_button();

	// == drill #4 == //
	Image alex1{ Point{0,200}, "Alex.jpg" };
	alex1.set_mask(Point{ 50,0}, 200, 200);
	Image alex2{ Point{300,0}, "Alex.jpg" };
	alex2.set_mask(Point{ 50,0 }, 200, 200);
	Image alex3{ Point{600,400}, "Alex.jpg" };
	alex3.set_mask(Point{ 50,0 }, 200, 200);

	win.attach(alex1);
	win.attach(alex2);
	win.attach(alex3);
	win.wait_for_button();

	// == drill #5 == //
	for (int i = 0; i < x_size; i += x_grid)
	{
		for (int j = 0; j < y_size; j += y_grid)
		{
			Image kingLuis{ Point{i,j}, "king_luis.jpg" };
			kingLuis.set_mask(Point{ 110,30 }, 100, 100);
			win.attach(kingLuis);
			win.wait_for_button();
		}
	}
	
}

void runDrills()
{
	Drills();
}
