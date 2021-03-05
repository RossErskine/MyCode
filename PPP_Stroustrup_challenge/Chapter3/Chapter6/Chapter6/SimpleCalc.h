#pragma once
#include <iostream>

using namespace std;

class Token 
{
public:
	char kind;
	double value;
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

class Token_stream
{
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer{ 0 };
};



void Token_stream::putback(Token t)
{
	if (full) throw("putback() into full buffer");
	buffer = t;
	full = true;
}
Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;

	switch (ch)
	{
	case'=':
	case'x':
	case'(':case')': case'{':case'}': case '£':
	case'+': case'-': case'*': case'/':
		return Token{ ch };
	case'.':
	case'0': case'1': case'2': case'3': case'4':
	case'5':case '6':case '7':case '8': case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8',val };
	}
	default:
		throw("Bad Token");
	}
}

Token_stream ts;
double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case'(':
			{
				double d = expression();
				t = ts.get();
				if (t.kind != ')') throw ("')' expected ");
				return d;
			}
		case'{':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != '}') throw ("'}' expected ");
			return d;
		}
		case '8':
		{
			return t.value;
		}
		default:
		{
			throw "primary expected";
			
		}
	
	}
}

double factorial()
{
	double left = primary();
	Token t = ts.get();
	
	while (true)
	{
		if (t.kind == '£')
		{
			for (int i = left - 1; i > 0; --i)
			{
				left *= i;
			}
			t = ts.get();
		}
		else
		{
			ts.putback(t);
			return left;
		}
	}

}

double term()
{
	double left = factorial();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= factorial();
			t = ts.get();
			break;
		case '&':
			if (left == 0)
			{

			}
			left *= factorial();
			t = ts.get();
			break;
		case '/':
		{
			double d = factorial();
			if (d == 0) throw("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		
		default:
			ts.putback(t);
			return left;
		}
	}

}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		case '!':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}

}

void runCalc()
{
	double val = 0;
	cout << "Welcome to our simple calculator " << endl;
	cout << " Please enter expressions using floating-point numbers" << endl;
	cout << " You can use add, subtract, multiply and divide " << endl;
	cout << "Print by using '=' and use 'x' to quit " << endl;
	while (cin)
	{
		Token t = ts.get();

		if (t.kind == 'x') break;
		if (t.kind == '=')
			cout << "=" << val << endl;
		else
			ts.putback(t);
		val = expression();
	}
	
}
