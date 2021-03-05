#include "Draw_Tools.h"
#include "Graph.h"
 

void runExercises()
{
	using namespace Graph_lib;
	using namespace Draw_Tools_lib;

	Point tl(150, 150);
	Simple_window win(tl, 800, 600, "PPP Chapter 13 exercise #1");

	// === exercise 1 === //
	Draw_Tools_lib::Arc arc1(Point(300, 200), 50, 0, 90);
	arc1.set_color(Color::black);
	arc1.draw_lines();

	Draw_Tools_lib::Arc arc2(Point(300, 200), 50, 90, 180);
	arc2.set_color(Color::yellow);
	arc2.draw_lines();

	Draw_Tools_lib::Arc arc3(Point(300, 200), 50, 180, 270);
	arc3.set_color(Color::green);
	arc3.draw_lines();

	win.attach(arc3);
	win.attach(arc1);
	win.attach(arc2);
	win.wait_for_button();

	// === exercise 2 === //
	Draw_Tools_lib::Box box1{ Point {200,150}, 200,100,10 };
	box1.set_color(Color::red);

	Draw_Tools_lib::Box box2{ Point {150,200}, 100,200,20 };
	box2.set_color(Color::blue);

	win.set_label("ppp Chapter 13 exercise #2");
	win.attach(box2);
	win.attach(box1);
	win.wait_for_button();
	
	// === exercise 3 === //
	Draw_Tools_lib::Arrow arrow1{ Point {200,100},Point {200,300} };
	arrow1.set_color(Color::black);
	Draw_Tools_lib::Arrow arrow2{ Point {400,250},Point {200,300} };
	arrow2.set_color(Color::black);
	
	win.set_label("ppp Chapter 13 exercise #3");
	win.attach(arrow1);
	win.attach(arrow2);
	win.wait_for_button();
	
	// === exercise 4 === //
	Graph_lib::Rectangle rec(Point(300, 300), Point(500, 400));
	rec.set_color(Color::dark_blue);
	win.attach(rec);

	Point nPoint = Draw_Tools_lib::nR(rec);
	Mark nMark(nPoint, 'x');
	nMark.set_color(Color::dark_red);
	win.attach(nMark);

	Point sePoint = Draw_Tools_lib::seR(rec);
	Mark seMark(sePoint, 'x');
	seMark.set_color(Color::dark_red);
	win.attach(seMark);

	Point cPoint = Draw_Tools_lib::centerR(rec);
	Mark cMark(cPoint, 'x');
	cMark.set_color(Color::dark_red);
	win.attach(cMark);

	win.set_label("ppp Chapter 13 exercise #4");
	win.wait_for_button();

	// === exercise 5 === //
	Circle cir(Point(500, 200), 50);
	cir.set_color(Color::dark_green);
	win.attach(cir);

	Point nCPoint = Draw_Tools_lib::nC(cir);
	Mark nCMark(nCPoint, 'x');
	nCMark.set_color(Color::red);
	win.attach(nCMark);

	Point eCPoint = Draw_Tools_lib::eC(cir);
	Mark eCMark(eCPoint, 'x');
	eCMark.set_color(Color::red);
	win.attach(eCMark);

	win.set_label("ppp Chapter 13 exercise #5");
	win.wait_for_button();

	// === exercise 6 === //
	TextBox graph(Point{ 100,500 },100,30, "Graph.h");
	graph.set_color(Color::black);
	win.attach(graph);

	win.set_label("ppp Chapter 13 exercise #6");
	win.wait_for_button();

}




void generateVehicles( Simple_window& win, int dir)
{

	Vector_ref<Circle> horde;
	Point start = { 5,5 };
	//int dir = 20;

	for (int i = 0; i < 6; ++i)
	{
		horde.push_back(new Circle(Point{ start.x + dir,start.y + dir }, 5));
		dir += 10;
		horde[horde.size() - 1].set_color(Color::black);
		horde[horde.size() - 1].set_fill_color(Color::yellow);

		win.attach(horde[horde.size() - 1]);

	}
	win.wait_for_button();


}
void moveVehicles(Simple_window& win, int dir)
{

	Vector_ref<Circle> horde2;
	Point start = { 5,5 };
	//int dir = 20;

	for (int i = 0; i < 6; ++i)
	{
		horde2.push_back(new Circle(Point{ start.x + dir,start.y + dir }, 5));
		dir += 10;
		horde2[horde2.size() - 1].set_color(Color::black);
		horde2[horde2.size() - 1].set_fill_color(Color::yellow);

		win.attach(horde2[horde2.size() - 1]);

	}
	win.wait_for_button();


}
void messing()
{
	testWindow tWin{ Point{100,100},800,800,"Test window" };
	
	Draw_Tools_lib::Cell cell(Point{ 100,100 }, 100, 20);
	cell.set_color(Color::black);
	tWin.attach(cell);
	gui_main();
}