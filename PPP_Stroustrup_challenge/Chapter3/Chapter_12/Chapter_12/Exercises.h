#include "Graph.h"
#include "Simple_window.h"

void exercise_1to5()
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 800, 600, "PPP Chapter 12 exercise #1");
	
	// == exercise 1 == //
	Graph_lib::Rectangle rec1{ Point{250,50}, 100,50 };       //rectangle
	rec1.set_color(Color::red);
	win.attach(rec1);

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.set_color(Color::blue);

	win.attach(poly_rect);

	win.wait_for_button();

	// == exercise 2 == //
	Graph_lib::Rectangle rec2{ Point{100,150}, 100,30 };       //rectangle
	Text t1{ Point{125,170},"Howdy!" };							//text
	rec2.set_color(Color::black);
	win.attach(rec2);
	win.attach(t1);

	win.set_label("PPP Chapter 12 exercise #2");
	win.wait_for_button();

	// == exercise 3 == //
	Text t2{ Point{390,150}, "R" };
	t2.set_font(Font::times_bold);
	t2.set_font_size(150);
	t2.set_color(Color::blue);
	win.attach(t2);

	Text t3{ Point{500,150}, "E" };
	t3.set_font(Font::times_bold);
	t3.set_font_size(150);
	t3.set_color(Color::green);
	win.attach(t3);

	win.set_label("PPP Chapter 12 exercise #3");
	win.wait_for_button();

	// == exercise 4 == //
	Graph_lib::Rectangle a1{ Point{400,400},50,50 };
	a1.set_color(Color::black);
	a1.set_fill_color(Color::red);
	win.attach(a1);

	Graph_lib::Rectangle a2{ Point{450,400},50,50 };
	a2.set_color(Color::black);
	a2.set_fill_color(Color::white);
	win.attach(a2);

	Graph_lib::Rectangle a3{ Point{500,400},50,50 };
	a3.set_color(Color::black);
	a3.set_fill_color(Color::red);
	win.attach(a3);

	Graph_lib::Rectangle b1{ Point{400,450},50,50 };
	b1.set_color(Color::black);
	b1.set_fill_color(Color::white);
	win.attach(b1);

	Graph_lib::Rectangle b2{ Point{450,450},50,50 };
	b2.set_color(Color::black);
	b2.set_fill_color(Color::red);
	win.attach(b2);

	Graph_lib::Rectangle b3{ Point{500,450},50,50 };
	b3.set_color(Color::black);
	b3.set_fill_color(Color::white);
	win.attach(b3);

	Graph_lib::Rectangle c1{ Point{400,500},50,50 };
	c1.set_color(Color::black);
	c1.set_fill_color(Color::red);
	win.attach(c1);

	Graph_lib::Rectangle c2{ Point{450,500},50,50 };
	c2.set_color(Color::black);
	c2.set_fill_color(Color::white);
	win.attach(c2);

	Graph_lib::Rectangle c3{ Point{500,500},50,50 };
	c3.set_color(Color::black);
	c3.set_fill_color(Color::red);
	win.attach(c3);

	win.set_label("PPP Chapter 12 exercise #4");
	win.wait_for_button();

	// == exercise 5 == //
	Graph_lib::Rectangle big{ Point{100,190},600,400 };
	big.set_color(Color::red);
	big.set_style(Line_style(Line_style::solid, 20));
	win.attach(big);

	win.set_label("PPP Chapter 12 exercise #5");
	win.wait_for_button();
}

void exercise_6()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window win(tl, 2000, 1200, "PPP Chapter 12 exercise #6"); //too big for screen

	Graph_lib::Polygon poly;            //a polygon is a kind of shape: Graph_lib stops ambiguous error
	poly.add(Point{ 500,200 });         // three points make a triangle
	poly.add(Point{ 1000,1200 });
	poly.add(Point{ 1500,200 });
	poly.set_color(Color::black);
	poly.set_style(Line_style(Line_style::solid, 4));

	win.attach(poly);
	win.wait_for_button();
}

void exercise_7()
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 800, 600, "PPP Chapter 12 exercise #7"); 

	Graph_lib::Rectangle houseFront{ Point{100,200},500,300 };	//house front
	houseFront.set_color(Color::red);
	houseFront.set_fill_color(Color::dark_red);
	houseFront.set_style(Line_style(Line_style::solid, 4));
	win.attach(houseFront);

	Graph_lib::Rectangle chimney{ Point{150,100}, 50,100 };		//chimney
	chimney.set_color(Color::black);
	chimney.set_style(Line_style(Line_style::dash, 4));
	chimney.set_fill_color(Color::dark_magenta);
	win.attach(chimney);

	Closed_polyline smoke;										//smoke
	smoke.add(Point{ 150,100 });
	smoke.add(Point{ 200,100 });
	smoke.add(Point{ 220,10 });
	smoke.add(Point{ 130,10 });
	smoke.set_fill_color(Color::white);
	win.attach(smoke);

	Graph_lib::Polygon roof;									//roof
	roof.add(Point{ 100,200 });         
	roof.add(Point{ 600,200 });
	roof.add(Point{ 350,100 });
	roof.set_color(Color::black);
	roof.set_style(Line_style(Line_style::dash, 4));
	roof.set_fill_color(Color::dark_magenta);
	win.attach(roof);

	Graph_lib::Rectangle frontDoor{ Point{180,380},70,120 };	//front door
	frontDoor.set_color(Color::black);
	frontDoor.set_fill_color(Color::black);
	win.attach(frontDoor);

	Graph_lib::Rectangle ltWindow{ Point{150,250},150,80 };		//left top window
	ltWindow.set_color(Color::black);
	ltWindow.set_fill_color(Color::black);
	win.attach(ltWindow);

	Graph_lib::Rectangle rtWindow{ Point{400,250},150,80 };		//right top window
	rtWindow.set_color(Color::black);
	rtWindow.set_fill_color(Color::black);
	win.attach(rtWindow);

	Graph_lib::Rectangle rbWindow{ Point{400,380},150,80 };		//right bottom window
	rbWindow.set_color(Color::black);
	rbWindow.set_fill_color(Color::black);
	win.attach(rbWindow);

	win.wait_for_button();
}

void exercise_8()
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 800, 600, "PPP Chapter 12 exercise #8");

	Circle c1{ Point{100,200},50 };					//blue ring
	c1.set_color(Color::blue);
	c1.set_style(Line_style(Line_style::solid, 4));
	win.attach(c1);

	Circle c4{ Point{160,260},50 };					//yellow ring
	c4.set_color(Color::yellow);
	c4.set_style(Line_style(Line_style::solid, 4));
	win.attach(c4);

	Circle c2{ Point{220,200},50 };					//black ring
	c2.set_color(Color::black);
	c2.set_style(Line_style(Line_style::solid, 4));
	win.attach(c2);

	Circle c5{ Point{280,260},50 };					//green ring
	c5.set_color(Color::green);
	c5.set_style(Line_style(Line_style::solid, 4));
	win.attach(c5);

	Circle c3{ Point{340,200},50 };					//red ring
	c3.set_color(Color::red);
	c3.set_style(Line_style(Line_style::solid, 4));
	win.attach(c3);

	win.wait_for_button();
}

void exercise_9()
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 500, 700, "Paloo the jungle bum! ");

	Image ii{ Point {50,50}, "paloo.jpg" };
	win.attach(ii);
	Text t{ Point{150,250}, "Oh man! this is living!" };     //text
	t.set_font(Font::times_bold);                           //font
	t.set_font_size(20);
	win.attach(t);
	

	win.wait_for_button();
}

void exercise_10()
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 1200, 1000, "PPP Chapter 12 exercise #10 ");

	Graph_lib::Rectangle pointh{ Point{100,100}, 125,25 };			//Point.h
	pointh.set_color(Color::black);
	pointh.set_fill_color(Color::yellow);
	Text pointhTitle{ Point{100,95}, "Point.h:" };					//Point.h title
	pointhTitle.set_color(Color::black);
	pointhTitle.set_font(Font::times_bold);
	Text pointhLine1{ Point{110,115}, "struct Point {...};" };		//point.h line 1
	pointhLine1.set_color(Color::black);
	pointhLine1.set_font(Font::times_bold);
	win.attach(pointh);
	win.attach(pointhLine1);
	win.attach(pointhTitle);

	Graph_lib::Rectangle graphh{ Point{100,200}, 150,65 };			//Graph.h
	graphh.set_color(Color::black);
	graphh.set_fill_color(Color::yellow);
	Text graphhTitle{ Point{100,195}, "Graph.h:" };					//Graph.h title
	graphhTitle.set_color(Color::black);
	graphhTitle.set_font(Font::times_bold);
	Text graphhLine1{ Point{110,215}, "// graphing interface:" };	//graph.h line 1
	graphhLine1.set_color(Color::black);
	Text graphhLine2{ Point{110,235}, "struct Shape {...};" };		//graph.h line 2
	graphhLine2.set_color(Color::black); 
	graphhLine2.set_font(Font::times_bold);
	Text graphhLine3{ Point{110,255}, "..." };						//graph.h line 3
	graphhLine3.set_color(Color::black);
	win.attach(graphh);
	win.attach(graphhLine1);
	win.attach(graphhLine2);
	win.attach(graphhLine3);
	win.attach(graphhTitle);

	Open_polyline gtop;												// line Graph.h to Point.h
	gtop.add(Point{ 170,200 });
	gtop.add(Point{ 170,125 });
	gtop.set_color(Color::black);
	win.attach(gtop);
	
	Graph_lib::Rectangle windowh{ Point{320,160}, 150,65 };			//window.h
	windowh.set_color(Color::black);
	windowh.set_fill_color(Color::yellow);
	Text windowhTitle{ Point{320,155}, "Window.h:" };				//Window.h title
	windowhTitle.set_color(Color::black);
	windowhTitle.set_font(Font::times_bold);
	Text windowhLine1{ Point{330,175}, "// window interface:" };	//window.h line 1
	windowhLine1.set_color(Color::black);
	Text windowhLine2{ Point{330,195}, "class Window {...};" };		//window.h line 2
	windowhLine2.set_color(Color::black);
	windowhLine2.set_font(Font::times_bold);
	Text windowhLine3{ Point{330,215}, "..." };						//window.h line 3
	windowhLine3.set_color(Color::black);
	win.attach(windowh);
	win.attach(windowhLine1);
	win.attach(windowhLine2);
	win.attach(windowhLine3);
	win.attach(windowhTitle);

	Open_polyline wtop;												// line window.h to Point.h
	wtop.add(Point{ 340,160 });
	wtop.add(Point{ 190,125 });
	wtop.set_color(Color::black);
	win.attach(wtop);

	Graph_lib::Rectangle fltk_headers1{ Point{330,65}, 110,30 };			//fltk headers
	fltk_headers1.set_color(Color::black);
	fltk_headers1.set_fill_color(Color::yellow);
	Graph_lib::Rectangle fltk_headers2{ Point{335,70}, 110,30 };			//fltk headers
	fltk_headers2.set_color(Color::black);
	fltk_headers2.set_fill_color(Color::yellow);
	Graph_lib::Rectangle fltk_headers3{ Point{340,75}, 110,30 };			//fltk headers
	fltk_headers3.set_color(Color::black);
	fltk_headers3.set_fill_color(Color::yellow);
	Text fltkhLine1{ Point{350,90}, "FLTK headers" };						//fltk line 3
	fltkhLine1.set_color(Color::black);
	win.attach(fltk_headers1);
	win.attach(fltk_headers2);
	win.attach(fltk_headers3);
	win.attach(fltkhLine1);

	Open_polyline gtof;												// line graph.h to fltk headers
	gtof.add(Point{ 170,200 });
	gtof.add(Point{ 360,105 });
	gtof.set_color(Color::black);
	win.attach(gtof);

	Open_polyline wtof;												// line window.h to fltk headers
	wtof.add(Point{ 390,160 });
	wtof.add(Point{ 390,105 });
	wtof.set_color(Color::black);
	win.attach(wtof);

	Graph_lib::Rectangle guih{ Point{450,260}, 150,65 };			//GUI.h
	guih.set_color(Color::black);
	guih.set_fill_color(Color::yellow);
	Text guihTitle{ Point{450,255}, "GUI.h:" };						//GUI.h title
	guihTitle.set_color(Color::black);
	guihTitle.set_font(Font::times_bold);
	Text guihLine1{ Point{460,275}, "// GUI interface:" };			//GUI.h line 1
	guihLine1.set_color(Color::black);
	Text guihLine2{ Point{460,295}, "struct ln_box {...};" };		//GUI.h line 2
	guihLine2.set_color(Color::black);
	guihLine2.set_font(Font::times_bold);
	Text guihLine3{ Point{460,315}, "..." };						//GUI.h line 3
	guihLine3.set_color(Color::black);
	win.attach(guih);
	win.attach(guihLine1);
	win.attach(guihLine2);
	win.attach(guihLine3);
	win.attach(guihTitle);

	Open_polyline gutow;												// line GUI.h to window.h
	gutow.add(Point{ 550,260 });
	gutow.add(Point{ 440,225 });
	gutow.set_color(Color::black);
	win.attach(gutow);

	Open_polyline gutof;												// line GUI.h to fltk headers
	gutof.add(Point{ 550,260 });
	gutof.add(Point{ 430,105 });
	gutof.set_color(Color::black);
	win.attach(gutof);

	Graph_lib::Rectangle simp_winh{ Point{250,370}, 210,65 };				//Simple_window.h
	simp_winh.set_color(Color::black);
	simp_winh.set_fill_color(Color::yellow);
	Text simp_winhTitle{ Point{250,365}, "Simple_window.h:" };				//simple_window.h title
	simp_winhTitle.set_color(Color::black);
	simp_winhTitle.set_font(Font::times_bold);
	Text simp_winhLine1{ Point{260,385}, "// window interface:" };			//simple_window.h line 1
	simp_winhLine1.set_color(Color::black);
	Text simp_winhLine2{ Point{260,405}, "class Simple_window {...};" };	//simple_window.h line 2
	simp_winhLine2.set_color(Color::black);
	simp_winhLine2.set_font(Font::times_bold);
	Text simp_winhLine3{ Point{260,425}, "..." };							//simple_window.h line 3
	simp_winhLine3.set_color(Color::black);
	win.attach(simp_winh);
	win.attach(simp_winhLine1);
	win.attach(simp_winhLine2);
	win.attach(simp_winhLine3);
	win.attach(simp_winhTitle);

	Open_polyline swtogu;												// line Simple_window.h to GUI.h
	swtogu.add(Point{ 400,370 });
	swtogu.add(Point{ 460,325 });
	swtogu.set_color(Color::black);
	win.attach(swtogu);

	Open_polyline swtow;												// line Simple_window.h to window.h
	swtow.add(Point{ 400,370 });
	swtow.add(Point{ 400,225 });
	swtow.set_color(Color::black);
	win.attach(swtow);

	Graph_lib::Rectangle chap12cpp{ Point{110,480}, 210,65 };				//chapter12.cpp
	chap12cpp.set_color(Color::black);
	chap12cpp.set_fill_color(Color::yellow);
	Text chap12cppTitle{ Point{110,475}, "chapter12.cpp:" };				//chapter12.cpp title
	chap12cppTitle.set_color(Color::black);
	chap12cppTitle.set_font(Font::times_bold);
	Text chap12cppLine1{ Point{120,495}, "#include \"Graph.h\"" };			//chapter12.cpp line 1
	chap12cppLine1.set_color(Color::black);
	chap12cppLine1.set_font(Font::times_bold);
	Text chap12cppLine2{ Point{120,515}, "#include \"Simple_window.h\"" };	//chapter12.cpp line 2
	chap12cppLine2.set_color(Color::black);
	chap12cppLine2.set_font(Font::times_bold);
	Text chap12cppLine3{ Point{120,535}, "int main(){... }" };				//chapter12.cpp line 3
	chap12cppLine3.set_color(Color::black);
	chap12cppLine3.set_font(Font::times_bold);
	win.attach(chap12cpp);
	win.attach(chap12cppLine1);
	win.attach(chap12cppLine2);
	win.attach(chap12cppLine3);
	win.attach(chap12cppTitle);

	Open_polyline chtosw;												// line chapter12.cpp to simple_window.h
	chtosw.add(Point{ 220,480 });
	chtosw.add(Point{ 280,435 });
	chtosw.set_color(Color::black);
	win.attach(chtosw);

	Open_polyline chtog;												// line chapter12.cpp to Graph.h
	chtog.add(Point{ 220,480 });
	chtog.add(Point{ 170,265 });
	chtog.set_color(Color::black);
	win.attach(chtog);

	win.wait_for_button();
}

void exercise_11()
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 800, 600, "PPP Chapter 12 exercise #11 ");

	Graph_lib::Polygon poly3;				// triangle
	poly3.add(Point{ 300,500 });         
	poly3.add(Point{ 500,500 });
	poly3.add(Point{ 400,330 });

	poly3.set_color(Color::red);
	poly3.set_style(Line_style::solid);
	win.attach(poly3);
	win.wait_for_button();

	Graph_lib::Polygon poly4;				//quadrilaterals
	poly4.add(Point{ 300,500 });
	poly4.add(Point{ 500,500 });
	poly4.add(Point{ 500,300 });
	poly4.add(Point{ 300,300 });

	poly4.set_color(Color::blue);
	poly4.set_style(Line_style::solid);
	win.attach(poly4);
	win.wait_for_button();

	Graph_lib::Polygon poly5;				//pentagon
	poly5.add(Point{ 300,500 });
	poly5.add(Point{ 500,500 });
	poly5.add(Point{ 560,320 });
	poly5.add(Point{ 400,210 });
	poly5.add(Point{ 240,320 });

	poly5.set_color(Color::green);
	poly5.set_style(Line_style::solid);
	win.attach(poly5);
	win.wait_for_button();

	Graph_lib::Polygon poly6;				//hexagon
	poly6.add(Point{ 300,500 });
	poly6.add(Point{ 500,500 });
	poly6.add(Point{ 600,340 });
	poly6.add(Point{ 500,160 });
	poly6.add(Point{ 300,160 });
	poly6.add(Point{ 200,340 });

	poly6.set_color(Color::yellow);
	poly6.set_style(Line_style::solid);
	win.attach(poly6);
	win.wait_for_button();
}


void runExercises()
{
	//exercise_1to5();
	//exercise_6();
	//exercise_7();
	//exercise_8();
	//exercise_9();
	//exercise_10();
	exercise_11();
	
}
