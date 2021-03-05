/*

		Simplle Calculator

		---Grammer:---

		runCalc:
			Statement
			help

			Print
			Quit
			Calculation statment

		Statement:
			declaration
			Expression

		Declaration:
			"let" name "=" expresion

		Expression:
			Term
			Expression + Term
			Expression - Term

		Term:
			Primary
			Term * primary
			Term / primary
			Term % primary

		Primary:
			Number
			(Expression)
			- Primary

		Number:
			floating-point-literal

*/
#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>


using namespace std;

class Token 
{
public:
	char kind;
	double value;
	string name;
	Token() : kind{0}{}
	Token(char ch)  :kind(ch) { }
	Token(char ch, double val) :kind(ch), value(val) { }

	Token(char ch, string n) :kind{ch}, name{n}{}
};

class Token_stream
{
public:
	//=========Constructors==========//
	Token get();	//get a Token
	void putback(Token t);	//put Token back
	void ignore(char c);	//discard characters upto and including a c
	Token_stream(istream& ist) : is{ist}{}
private:
	bool full{ false };	//is there a token in the buffer
	Token buffer{ 0 };	//keep a Token using putback()
	istream& is;
};

//===symbolic constants===//
const char number = '8';
const char quit = 'q';
const char prnt = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';			// name Token
const char let = 'L';			//declaration token
const string declkey = "let";	 //declaration keyword;
const char sqr = 'v';			//square_root token
const string sqroot = "sqrt";		//square_root keyword
const char pw = '^';				//power token
const string pwr = "pow";			//power keyword
const char con = 'c';				//const token
const string cnst = "const";		//const keyword
const char hlp = 'h';				// help token
const string hp = "help";			// help keyword



void Token_stream::putback(Token t)
{
	if (full) throw("putback() into full buffer");
	buffer = t;
	full = true;
}

//==read from cin and create Token==/
Token Token_stream::get()
{
	//==check buffer==//
	if (full) 
	{
		full = false;
		return buffer;
	}
	//==sort next token==//
	char ch =' ';
	

	do {
		if(ch == '\n') return Token{prnt};	//prints answer when enter is presssed
		is.get(ch);
	} while (isspace(ch));

	

	switch (ch)
	{
	
	case quit:
	case prnt:
	case'(':
	case')': 
	case'{':
	case'}':
	case'+': 
	case'-': 
	case'*': 
	case'/':
	case '%':
	case '=':
	case ',':
		return Token{ ch };//let character represent themselves
	case'.':		 // a floating-point-literal can start with a dot
	case'0': 
	case'1': 
	case'2': 
	case'3': 
	case'4':
	case'5':
	case '6':
	case '7':
	case '8': 
	case'9':
	{
		is.putback(ch);	//put digit into the input stream
		double val;
		is >> val;			//read a floating-point number
		return Token{ number,val };
	}
	
	default:
		//== is 'ch' a letter?==//
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			is.putback(ch);
			
			if (s == declkey) return Token{ let };
			else if (s == sqroot) return Token{ sqr };
			else if (s == pwr) return Token{ pw };
			else if (s == cnst) return Token{ con };
			else if (s == hp) return Token{ hlp };
			return Token{name,s };
		}
		
		throw("Bad Token");
	}
}

//===looks in token stream buffer ==//
//==if c is found ignore for error recovery==//
//=== c represents the kind of token===//
void Token_stream::ignore(char c)
{
	//==check buffer==//
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (is >> ch)
		if (ch == c)return;
}

//==allows variable names==//
class Variable	
{
public:
	string name;
	double value;
	bool constant;
};

class Symbol_table
{
private:
	vector<Variable> var_table;
public:
	double get(string );
	void set(string , double , bool );
	bool is_declared(string );
	double declare(string , double , bool );

};


//==looks for a given name and returns corresponding value==//
double Symbol_table::get(string s)
{
	for(Variable v : var_table)
		if (v.name == s)
		{
			return v.value;
		}
		throw "get: undefined variable", s;
	
}

//===set variable named s to d===//
void Symbol_table::set(string s, double d,bool c)
{
	for(Variable& v : var_table)
		if (v.name == s)
		{
			if (v.constant != 0)
			{
				throw "set: cannot change a const";
			}
			else
			{
				v.value = d;
				return;
			}
			v.value = d;
			return;
		}
	throw "set: undefined name", s;
}

//== is variable already in names ==//
bool Symbol_table::is_declared(string var)
{
	for (Variable& v : var_table)
	{
		if (v.name == var)return true;
		return false;
	}
}

double Symbol_table::declare(string var, double val,bool con)
{
	
	//if (is_declared(var)) { throw "declared twice"; }			//always throws exception -- so taken out
	var_table.push_back(Variable{ var,val,con });
	/*for (Variable v : var_table)
		cout << v.name << ": (" << v.value << " : "<< v.constant << ")" << endl;	*/	//for debugging
	
	return val;
}

//===declaration===//
//Token_stream ts;
Symbol_table st;
double expression(Token_stream&);//so primary() can find expression()





//=================Grammers========================//
//===primary grammer==//
double primary(Token_stream& ts)

{
	Token t = ts.get();
	switch (t.kind)
	{
		case'(':
			{
				double d = expression(ts);
				t = ts.get();
				if (t.kind != ')') throw ("')' expected ");
				return d;
			}
		case'{':
		{
			double d = expression(ts);
			t = ts.get();
			if (t.kind != '}') throw ("'}' expected ");
			return d;
		}
		case number:
			return t.value;
		case name:
		{
			Token t2 = ts.get();
			if (t2.kind == '=')
			{
				double d = expression(ts);
				st.set(t.name, d,false);
				return d;
			}
			else
			{
				ts.putback(t2);
				return st.get(t.name);
			}
		}
			
		case '-':
			return -primary(ts);
		case '+':
			return +primary(ts);
		
		default:
		{
			throw "primary expected";
			
		}
	
	}
}


//== Term grammer ==//
double term(Token_stream& ts)
{
	double left = primary(ts);
	Token t = ts.get();
	
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary(ts);
			t = ts.get();
			break;
		
		case '/':
		{
			double d = primary(ts);
			if (d == 0) throw("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary(ts);
			if (d == 0) throw"%: divide by zero";
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		
		default:
			ts.putback(t);
			return left;
		}
	}

}

//== expression grammer ==//
double expression(Token_stream& ts)
{
	double left = term(ts);
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term(ts);
			t = ts.get();
			break;
		case '-':
			left -= term(ts);
			t = ts.get();
			break;
		
		default:
			ts.putback(t);
			return left;
		}
	}

}

void help()
{
	cout << " *************************  HELP  ******************************" << endl
		<< " *** Please enter expressions using floating-point numbers" << endl
		<< " *** You can use add, subtract, multiply, divide and remainder" << endl
		<< " *** create variables by using 'let' word followed with a '=' " << endl
		<< " *** make variable constant by following with word 'const'" << endl
		<< " *** example: let const x = 3.2;" << endl
		<< " *** change variable using '=' " << endl
		<< " *** example x = 3.3 " << endl
		<< " *** build in keywords such as:" << endl
		<< " ***	pow() = power numbers \n	sqrt() = sqaure root numbers" << endl
		<< " *** Print by using ';' and use 'q' to quit " << endl;
	

}

//=== square root function===//
double square_root(Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind != '(') throw " missing '(' :";
	double d = expression(ts);
	if (d < 0)throw "sqrt: no negative value";
	return sqrt(d);
}

//=== power function===//
double power(Token_stream& ts)

{
	Token t = ts.get();
	if (t.kind != '(') throw "pwr:'(' expected";
	double b = expression(ts);
	t = ts.get();
	if (t.kind != ',') throw "pwr: ',' expected";
	int p = static_cast<int>(expression(ts));
	t = ts.get();
	return pow(b, p);
}

//==makes sure what comes after 'let' is a name ==//
double declaration(Token_stream& ts)
{
	bool c = false;
	string var_name;
	Token t = ts.get();
	if (t.kind != con) {
		
		if (t.kind != name)throw "name expected in declaration";
		var_name = t.name;
	}
	else
	{
		c = true;
		Token t1 = ts.get();
		if (t1.kind != name)throw "name expected in declaration";
		var_name = t1.name;	
	}
	Token t2 = ts.get();
	if (t2.kind != '=')throw "= missing in declaration of ", var_name;

	double d = expression(ts);
	st.declare(var_name, d, c);
	return d;
	
}


//===handles declarations and expressions===//
double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration(ts);
	case sqr:
		return square_root(ts);
	case pw:
		return power(ts);
	
	default:
		ts.putback(t);
		return expression(ts);
	}
}

//==allows recovery after exceptions==//
void clean_up_mess(Token_stream& ts)
{
	ts.ignore(prnt);
}

//===interface===//
void calculate(Token_stream& ts)
{
		cout << " Welcome to our simple calculator " << endl;
		cout << " type 'help' for assistance" << endl;
		
		while (cin) 
		{
			try
			{
				cout << prompt;
				Token t = ts.get();
				while (t.kind == prnt)t = ts.get();
				if (t.kind == hlp) { help(); }
				else 
				{
					if (t.kind == quit)
					{
						cout << "Goodbye!";
						return;
					}
					ts.putback(t);
					cout << result << statement(ts) << '\n';
				}
			}
			catch (const char* msg)
			{
				cerr << msg << endl;
				clean_up_mess(ts);
			}
		}
	
	
}
int runCalc()
{
	try
	{
		// predefined names:
		st.declare("pi", 3.1415926535, true);
		st.declare("e", 2.7182818284, true);
		st.declare("k", 1000, true);

		Token_stream ts{ cin };

		calculate(ts);

		return 0;
	}
	catch (runtime_error e)
	{
		cout << e.what() << endl;
		//char c;
		//while (cin >> c && c != ';');
		return 1;
	}

	/*catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}*/

}