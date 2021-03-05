#include "fltk.h"
#include "Graph.h"

namespace Draw_Tools_lib
{
	using namespace Graph_lib;

	class Arc : public Shape
	{
	public:
		Arc(Point p, int radius, int width, int height ) : mRadius(radius), mWidth(width), mHeight(height)
		{
			add(Point(p.x - mRadius, p.y - mRadius));
		};
		void draw_lines() const
		{
			if (color().visibility())
				fl_arc(point(0).x, point(0).y, mRadius + mRadius, mRadius + mRadius, mWidth, mHeight);
		}

	private:
		int mWidth;
		int mHeight;
		int mRadius;
	};

	class Box : public Shape
	{
	public:
		Box(Point p, int width, int height, int radius) : mWidth(width), mHeight(height), mRadius(radius)
		{
			mSides.add(Point{ p.x + mRadius, p.y }, Point{ p.x + mWidth - mRadius, p.y });						// top
			mSides.add(Point{ p.x + mWidth - mRadius, p.y + mHeight }, Point{ p.x + mRadius, p.y + mHeight }); // bottom
			mSides.add(Point{ p.x + mWidth, p.y + mRadius }, Point{ p.x + mWidth , p.y + mHeight - mRadius }); // right
			mSides.add(Point{ p.x , p.y + mHeight - mRadius }, Point{ p.x, p.y + mRadius });					//left

			mCorners.push_back(new Arc{ Point{p.x + mWidth - mRadius,p.y + mRadius}, mRadius, 0 , 90 });				//top-right
			mCorners.push_back(new Arc{ Point{p.x + mRadius,p.y + mRadius}, mRadius, 90, 180 });						//top-left
			mCorners.push_back(new Arc{ Point{p.x + mWidth - mRadius, p.y + mHeight - mRadius}, mRadius, 270 , 360 }); //bottom-right
			mCorners.push_back(new Arc{ Point{p.x + mRadius,p.y + mHeight - mRadius}, mRadius, 180 , 270 });			//bottom-left
			

		}

		void draw_lines() const
		{
			for (int i = 0; i < mCorners.size(); ++i)
			{
				mCorners[i].draw_lines();
			}
			mSides.draw_lines();
		}
	private:
		Vector_ref<Arc> mCorners;
		Lines mSides;
		int mWidth;
		int mHeight;
		int mRadius;
	};

	class Arrow : public Shape
	{
	public:
		Arrow(Point bot, Point top)
		{
			add(bot);
			add(top);
		}

		void draw_lines() const
		{
			const double pi = 3.142;
			
			int back_x = point(1).x - point(0).x;
			int back_y = point(1).y - point(0).y;
			double angle = atan2(back_y, back_x) * 180 / pi;

			double xa = point(1).x - cos((angle - iso) * pi / 180) * size;
			double ya = point(1).y - sin((angle - iso) * pi / 180) * size;

			double xb = point(1).x - cos((angle + iso) * pi / 180) * size;
			double yb = point(1).y - sin((angle + iso) * pi / 180) * size;

			Graph_lib::Polygon head;
			head.add(point(1));
			head.add(Point{ int(xa), int(ya) });
			head.add(Point{ int(xb), int(yb) });
			head.set_fill_color(Color::black);

			
			head.draw_lines();
			Shape::draw_lines();
		}
	private:
		
		int size = 12;
		int iso = 20;

	};

	// == rectangle points == //
	Point nR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x + r.width() / 2;
		int y = r.point(0).y;
		return Point{ x,y };
	}

	Point sR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x + r.width() / 2;
		int y = r.point(0).y + r.height();
		return Point{ x, y };
	}

	Point eR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x + r.width() ;
		int y = r.point(0).y + r.height() / 2;
		return Point{ x, y };
	}
	
	Point wR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x;
		int y = r.point(0).y + r.height() / 2;
		return Point{ x, y };
	}

	Point centerR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x + r.width() / 2;
		int y = r.point(0).y + r.height() / 2;
		return Point{ x, y };
	}

	Point neR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x + r.width();
		int y = r.point(0).y;
		return Point{ x, y };
	}

	Point seR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x + r.width();
		int y = r.point(0).y + r.height();
		return Point{ x, y };
	}

	Point swR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x;
		int y = r.point(0).y + r.height();
		return Point{ x, y };
	}

	Point nwR(Graph_lib::Rectangle& r)
	{
		int x = r.point(0).x;
		int y = r.point(0).y;
		return Point{ x, y };
	}

	// == circle or eclipse points == //
	Point nC(Graph_lib::Circle& c)
	{
		int x = c.point(0).x + c.radius();
		int y = c.point(0).y;
		return { x, y };
	}

	Point sC(Graph_lib::Circle& c)
	{
		int x = c.point(0).x + c.radius();
		int y = c.point(0).y + c.radius() * 2;
		return { x, y };
	}

	Point eC(Graph_lib::Circle& c)
	{
		int x = c.point(0).x + c.radius() *2;
		int y = c.point(0).y + c.radius() ;
		return { x, y };
	}

	class TextBox :  public Rectangle 
	{
	public:
		TextBox(Point p, int h, int w, std::string label)
			:Rectangle (p, h, w), mLabel(label)
		{
			mPoint = p;
			add(p);
		}

		void draw_lines() const
		{
			Rectangle::draw_lines();
			Text label(Point{ mPoint.x + 15,mPoint.y + 15 }, mLabel);
			label.set_color(Color::black);
			label.draw_lines();

		}

	private:
		std::string mLabel;
		Point mPoint;
		
	};

	struct Cell : Rectangle
	{
		Cell(Point p, int w, int h) :
			Rectangle(p, w, h), mX(p.x), mY(p.y)
		{
			set_color(Color::black);
			set_fill_color(Color::yellow);
		}

	private:
		int mX;
		int mY;

	};
}
