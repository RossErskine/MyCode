#include "Window.h"
#include "Graph.h"
#include "GUI.h"

namespace Graph_lib {

	Window::Window(int ww, int hh, const string& title)
		:Fl_Window(ww, hh, title.c_str()), w(ww), h(hh)
	{
		init();
	}

	Window::Window(Point xy, int ww, int hh, const string& title)
		: Fl_Window(xy.x, xy.y, ww, hh, title.c_str()), w(ww), h(hh)
	{
		init();
	}

	void Window::init()
	{
		resizable(this);
		show();
	}

	//---------------------------------------------------- 

	void Window::draw()
	{
		Fl_Window::draw();
		for (unsigned int i = 0; i < shapes.size(); ++i) shapes[i]->draw();
	}

	void Window::attach(Widget& w)
	{
		begin();			// FTLK: begin attaching new Fl_Wigets to this window
		w.attach(*this);	// let the Widget create its Fl_Wigits
		end();				// FTLK: stop attaching new Fl_Wigets to this window
	}

	void Window::detach(Widget& b)
	{
		b.hide();
	}

	void Window::attach(Shape& s)
	{
		shapes.push_back(&s);
		//		s.attached = this;
	}
	void Window::detach(Shape& s)
	{
		for (unsigned int i = shapes.size(); 0 < i; --i)	// guess last attached will be first released
			if (shapes[i - 1] == &s)
				shapes.erase(shapes.begin() + (i - 1));//&shapes[i-1]);
	}


	void Window::put_on_top(Shape& p) {
		for (int i = 0; i < shapes.size(); ++i) {
			if (&p == shapes[i]) {
				for (++i; i < shapes.size(); ++i)
					shapes[i - 1] = shapes[i];
				shapes[shapes.size() - 1] = &p;
				return;
			}
		}
	}

	int gui_main() { return Fl::run(); }

	testWindow::testWindow(Point xy, int w, int h, const string& title)
		: Window{ xy,w,h,title }
	{
		//p.set_color(Color::black);
		//p.set_fill_color(Color::yellow);
		//attach(p);
		Fl::add_timeout(1.0 / 24.0, next);
		end();
	}

	

	void testWindow::next(void* userdata)
	{
		testWindow *tw = (testWindow*)userdata;
		Vector_ref<Circle> horde;
		Point start = { 5,5 };
		int dir = 20;


		for (int j = 0; j < 8; j++)
		{
			horde.push_back(new Circle(Point{ start.x + dir,start.y + dir }, 5));
			dir += 10;
			horde[horde.size() - 1].set_color(Color::black);
			horde[horde.size() - 1].set_fill_color(Color::yellow);

			tw->attach(horde[horde.size() - 1]);
		}
		tw->redraw();
		
		
		Fl::repeat_timeout(1.0 / 24.0, next);
		gui_main();
		
	}
		
	

	

	

} // Graph
