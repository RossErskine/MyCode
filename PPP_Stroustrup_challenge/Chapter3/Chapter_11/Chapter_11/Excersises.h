#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>





void toLower(std::string& s)
{
	for (char& x : s)x = tolower(x);
}

void exercise_1()
{
	// == create and input file == //
	std::vector<std::string> upper_names = { "Leo","Mike","Zoe","Gary","Leonard","Henry" };

	const std::string fu = "fu.text";	// upper case names
	const std::string fl = "fl.text";	// lower case names

	std::ofstream ost1{ fu };			
	if (!ost1)throw"cannot open output file", fu;
	for (std::string i : upper_names)
	{
		ost1 << i << '\t';
	}
	ost1.close();


	std::ifstream ist1{ fu };			//open file for input
	if (!ist1)throw"cannot open input file", fu;

	std::ofstream ost2{ fl };
	if(!ost2)throw"cannot open output file", fl;

	for (std::string st; ist1>>st;) 
	{
		toLower(st);
		ost2 << st << '\t';
	}

	ost2.close();
	ist1.close();
}

void exercise_2()
{
	const std::string para = "Lotr.text";

	std::ifstream ist2{ para };
	if (!ist2)throw"cannot open input file", para;

	std::string line;
	const char stop = '.';

	int line_numb = 0;
	while (std::getline(ist2, line,stop))	// line stops at a '.'
	{
		++line_numb;
		std::stringstream ss{ line };
		for (std::string s; ss >> s;)
		{
			if (s == "Aragorn")
			{
				std::cout << "Line " << line_numb << ": " << line << std::endl;
			}	
		}
	}
	ist2.close();
}

void disemvowels(std::string& st)
{
	std::string str;
	for (char& ch : st)
	{
		switch (ch)
		{
		case 'a':case'e':case'i':case'o':case'u':
			ch = ' ';
		}
		if (ch != ' ')
		{
			str += ch;
		}
	}
	st = str;
}

void exercise_3()
{
	const std::string par = "Lotr.text";
	const std::string newPar = "newLotr.text";

	std::vector<std::string> lines;

	std::ifstream ist3{ par };
	if (!ist3)throw"cannot open input file", par;

	for (std::string s; ist3 >> s;)
	{
		disemvowels(s);
		lines.push_back(s);
	}
	ist3.close();

	std::ofstream ost3{ newPar };
	if (!ost3)throw"cannot open output file", newPar;

	for (std::string st : lines)
	{
		ost3 << st << " ";
	}
	ost3.flush();	//flush the buffer
	ost3.close();
}

enum class Base
{
	decimal, hexadecimal, octal
};

struct Number
{
	Base type;
	int dec;
	Number(int d, Base b) :type(b), dec(d){}
};
std::vector<Number> numbers;	// for collecting inputs

// == adding Number type to numbers vector == //
void addNumb(const int& dec,const Base& b)
{
	Number numb = { dec,b };
	numbers.push_back(numb);
}

void exercise_4()
{
	std::cout << "Enter hexadecimal, octal or decimal numbers: finish with ctrl 'z'" << std::endl;
	
	for (char ch; std::cin >> ch;)
	{	
		int dec;
		if (ch == '0')
		{
			std::cin.get(ch);
			if (ch == 'x')
			{
				std::cin >> std::hex >> dec;	// reads hexadecimal 
				addNumb(dec, Base::hexadecimal); // adds decimal to vector
			}
			else
			{
				std::cin.unget();				// puts char back in the stream
				std::cin >> std::oct >> dec;	// reads octal
				addNumb(dec, Base::octal);		// adds decimal to vector
			}
		}
		else if(isdigit(ch))
		{
			std::cin.unget();					// puts char back in the stream
			std::cin >> std::dec >> dec;		//reads decimal
			addNumb(dec, Base::decimal);		// adds decimal to vector
		}	
	}

	for (Number n : numbers)
	{
		switch (n.type)			// writes decimal depending on Number type
		{
		
		case Base::octal:
			std::cout << std::setw(6) << std::showbase << std::oct << n.dec << std::setw(12) << " Octal "
				<< " converts to " << std::setw(6) << std::dec << n.dec << " decimal " << std::endl;
			break;
		case Base::hexadecimal:
			std::cout << std::setw(6) << std::showbase << std::hex << n.dec << std::setw(12) << " Hexdecimal "
				<< " converts to " << std::setw(6) << std::dec << n.dec << " decimal " << std::endl;
			break;
		case Base::decimal:
			std::cout << std::setw(6) << n.dec << std::setw(12) << " Decimal "
				<< " converts to " << std::setw(6) << std::dec << n.dec << " decimal " << std::endl;
			break;
		default:
			throw "No numbers found!";
			break;

		}
		
	}

}
enum class Char_class
{
	space,digit,alpha,hex,upper,lower,control,punct,graph,
};
struct Character
{
	char ch;
	Char_class type;
	
};
std::vector<Character> char_classification()
{
	std::string line;
	std::getline(std::cin, line);
	std::vector<Character> cc;
	Character chara;
	for (char ch: line)
	{
		if (isspace(ch)) {
			chara.ch = ch;
			chara.type = Char_class::space;
			cc.push_back(chara);
		}
		if (isdigit(ch)) {
			chara.ch = ch;
			chara.type = Char_class::digit;
			cc.push_back(chara);
		}
		if (isalpha(ch)) {
			chara.ch = ch;
			chara.type = Char_class::alpha;
			cc.push_back(chara);
		}
		if (isxdigit(ch)) {
			chara.ch = ch;
			chara.type = Char_class::hex;
			cc.push_back(chara);
		}
		if (isupper(ch)) {
			chara.ch = ch;
			chara.type = Char_class::upper;
			cc.push_back(chara);
		}
		if (islower(ch)) {
			chara.ch = ch;
			chara.type = Char_class::lower;
			cc.push_back(chara);
		}
		if (iscntrl(ch)) {
			chara.ch = ch;
			chara.type = Char_class::control;
			cc.push_back(chara);
		}
		if (ispunct(ch)) {
			chara.ch = ch;
			chara.type = Char_class::punct;
			cc.push_back(chara);
		}
		if (isgraph(ch)) {
			chara.ch = ch;
			chara.type = Char_class::graph;
			cc.push_back(chara);
		}
	}return cc;
}
void exercise_5()
{
	
	std::cout << "Enter a word or words for Character classifictaion:  " << std::endl;
	std::vector<Character> chrs = char_classification();
	std::cout << '|' << std::setw(10) << "Character" << '|' << std::setw(12) << "Type" << '|' << std::endl;
	std::cout << "-------------------------" << std::endl;
	for (Character c : chrs)
	{
		switch (c.type)
		{
		case Char_class::alpha:
			std::cout <<'|'<<std::setw(10)<< c.ch <<'|'<<std::setw(12)<< "alphanumeric" << '|' << std::endl;
			break;
		case Char_class::control:
			std::cout << '|' << std::setw(10) << c.ch << '|' << std::setw(12) << "control" << '|' << std::endl;
			break;
		case Char_class::digit:
			std::cout << '|' << std::setw(10) << c.ch << '|' << std::setw(12) << "digit" << '|' << std::endl;
			break;
		case Char_class::graph:
			std::cout << '|' << std::setw(10) << c.ch << '|' << std::setw(12) << "graph" << '|' << std::endl;
			break;
		case Char_class::hex:
			std::cout << '|' << std::setw(10) << c.ch << '|' << std::setw(12) << "hexadecimal" << '|' << std::endl;
			break;
		case Char_class::lower:
			std::cout << '|' << std::setw(10) << c.ch << '|' << std::setw(12) << "lowercase" << '|' << std::endl;
			break;
		case Char_class::punct:
			std::cout << '|' << std::setw(10) << c.ch << '|' << std::setw(12) << "punctuation" << '|' << std::endl;
			break;
		case Char_class::space:
			std::cout << '|' << std::setw(10) << c.ch << '|' << std::setw(12) << "whitespace" << '|' << std::endl;
			break;
		case Char_class::upper:
			std::cout << '|' << std::setw(10) << c.ch << '|' << std::setw(12) << "uppercase" << '|' << std::endl;
			break;
		default:
			throw " no type found!";
			break;
		}
	}
}

void punct_rep(std::string& st)
{
	std::string str;
	for (char ch : st)
	{
		if (ispunct(ch))
		{
			ch = ' ';
			
		}
		else
		{
			str += ch;
		}
	}
	st = str;
}

void exercise_6()
{
	std::string line;
	getline(std::cin, line);	// get whole line from cin
	bool ignore = false;
	for (char& ch : line)
	{
		if (ch == '"')		//when " is found changes from not-ignore to ignore
		{
			if (ignore)ignore = false;
			else ignore = true;
		}
		if(!ignore)
		{
			switch (ch)		//if punctuation found changed to whitspace
			{
			case';':case'.':case'?':case',':case'!':case'-':case'\'':
				ch = ' ';
			}
		}
	}

	std::stringstream ss(line);		// turns line into seperate strings
	std::vector<std::string> vs;
	for (std::string word; ss >> word;)		//puts words into vector 
	{
		vs.push_back(word);
	}
	for (std::string st : vs)				//prints vector input
	{
		std::cout << st << " ";
	}
}
/*== 

rather than modify exercise_6 that works,
created a funct for exercise_7 that can use 
again in exercise_8

== */
void replace_punct(std::string& line)
{
	bool ignore = false;
	for (int i =0; i < line.length();++i)	// changed to i iterator to look after '-'
	{
		if (line[i] == '"')
		{
			if (ignore)ignore = false;
			else ignore = true;
		}
		if (line[i] == '-')
		{
			/*looked after line[i] for space could have 
			looked before, but, out of range not necessary 
			for this exercise.
			*/
			if (isspace(line[i+1]))	//look after '-' for space 
			{
				line[i] = ' ';
			}
		}
		if (!ignore)
		{
			switch (line[i])
			{
			case';':case'.':case'?':case',':case'!':case'\'':
				line[i] = ' ';
			}
		}
	}
}
// == replaces bad-grammer with good-grammer == //
void replace_words(std::string& str)
{
	std::vector<std::string> poor_grammer{ "don't","can't" };
	std::vector<std::string> good_grammer{ "do not","cannot" };

	for (int i = 0; i < poor_grammer.size(); ++i)
	{
		if (str == poor_grammer[i])
		{
			str = good_grammer[i];
		}
	}
}
void exercise_7()
{
	std::string line;
	getline(std::cin, line);
	replace_punct(line);

	std::stringstream ss(line);
	std::vector<std::string> vs;
	for (std::string word; ss >> word;)
	{
		replace_words(word);
		vs.push_back(word);
	}
	for (std::string st : vs)
	{
		std::cout << st << " ";
	}
}

void exercise_8()
{
	const std::string par = "Lotr.text";
	const std::string newPar = "punctLessLotr.text";

	std::vector<std::string> lines;

	std::ifstream ist5{ par };
	if (!ist5)throw"cannot open input file", par;

	for (std::string s; ist5 >> s;)
	{
		replace_punct(s);	//replace punctuation
		replace_words(s);	//replace words
		lines.push_back(s);
	}
	ist5.close();

	sort(lines.begin(), lines.end());	//sort words alphabetically
	std::ofstream ost5{ newPar };
	if (!ost5)throw"cannot open output file", newPar;

	for (std::string st : lines)
	{
		ost5 << st << " ";
	}
	ost5.flush();	//flush the buffer
	ost5.close();
}
// == function needed to get address of first byte of an objects represention ==//
template<class T>
char* as_bytes(T& i)
{
	void* addr = &i;

	return static_cast<char*>(addr);
}
// == not finished keep coming back to it == //
/*
void exercise_9()
{
	// == part 1 write in binary == //
	const std::string lotr = "Lotr.text";
	const std::string binLotr = "binLotr.text";

	std::ifstream istLotr{ lotr, std::ios_base::binary };		//opens human readable lotr file 
	if (!istLotr)throw"cannot open input file", lotr;

	std::ofstream ostBinLotr{ binLotr, std::ios_base::binary };	//opens for binary to be inputted into
	if (!ostBinLotr)throw"cannot open output file", ostBinLotr;

	char ch;
	while (istLotr.get(ch))
	{
		ostBinLotr.write(as_bytes(ch), sizeof(char));
	}
	istLotr.close();
	ostBinLotr.close();
}
*/
std::vector<std::string> split(const std::string& s,std::string& w)
{
	std::vector<std::string> temp;
	std::stringstream ss(s);

	for (std::string word; ss >> word;)
	{
		if (word == w)word = "";
		temp.push_back(word);
	}
	return temp;

}
void exercise_10_11()
{

	std::string line;
	std::cout << "Enter words here: " << std::endl;
	std::getline(std::cin, line);
	std::string omitWord;
	std::cout << "Word you want to omit:" << std::endl;
	std::cin >> omitWord;
	std::vector<std::string> lines = split(line,omitWord);

	for (std::string ss : lines)
	{
		std::cout << ss << ' ' << std::endl;
	}


}

void reverseString(std::string& st)
{
	std::string s;
	for (int i = st.length(); i >= 0;--i)
	{
		s += st[i];
	}
	st = s;
}
void exercise_12()
{
	const std::string Lotr = "Lotr.text";
	const std::string reverseLotr = "reverseLotr.text";

	std::vector<std::string> lines;

	std::ifstream ist7{ Lotr };
	if (!ist7)throw"cannot open input file", Lotr;

	for (std::string s; ist7 >> s;)
	{
		reverseString(s);
		lines.push_back(s);
	}
	ist7.close();

	std::ofstream ost7{ reverseLotr };
	if (!ost7)throw"cannot open output file", reverseLotr;

	for (std::string ss : lines)
	{
		ost7 << ss << " ";
	}
	ost7.close();
}


void exercise_13()
{
	const std::string Lotr = "Lotr.text";
	const std::string reverseLotr2 = "reverseLotr2.text";

	std::vector<std::string> lines;

	std::ifstream ist8{ Lotr };
	if (!ist8)throw"cannot open input file", Lotr;

	for (std::string s; ist8 >> s;)
	{
		lines.push_back(s);
	}
	ist8.close();

	reverse(lines.begin(), lines.end());	// reverse vector

	std::ofstream ost8{ reverseLotr2 };
	if (!ost8)throw"cannot open output file", reverseLotr2;

	for (std::string ss : lines)
	{
		ost8 << ss << " ";
	}
	ost8.close();
}




void exercise_14()
{
	const std::string Lotr = "Lotr.text";

	std::ifstream ist9{ Lotr };
	if (!ist9)throw"cannot open input file", Lotr;

	std::string line;
	int space = 0, digit = 0, alpha = 0, hex = 0, upper = 0, lower = 0, control = 0, punct = 0, graph = 0;
	
	while (std::getline(ist9, line))
	{
		for (char ch : line)
		{
			if (isspace(ch)) {
				space++;	
			}
			if (isdigit(ch)) {
				digit++;
			}
			if (isalpha(ch)) {
				alpha++;
			}
			if (isxdigit(ch)) {
				hex++;
			}
			if (isupper(ch)) {
				upper++;
			}
			if (islower(ch)) {
				lower++;
			}
			if (iscntrl(ch)) {
				control++;
			}
			if (ispunct(ch)) {
				punct++;
			}
			if (isgraph(ch)) {
				graph++;
			}
		}
	}
	ist9.close();

	std::cout << "The file: " << Lotr << '\n'
		<< "----------------------" << '\n'
		<< '|' << std::setw(12) << "char class" << '|' << std::setw(7) << "Amount" << '|' << '\n'
		<< "----------------------" << '\n'
		<< '|' << std::setw(12) << "Spaces" << '|' << std::setw(7) << space << '|' << '\n'
		<< '|' << std::setw(12) << "Digits" << '|' << std::setw(7) << digit << '|' << '\n'
		<< '|' << std::setw(12) << "Alphanumeric" << '|' << std::setw(7) << alpha << '|' << '\n'
		<< '|' << std::setw(12) << "Hexadecimal" << '|' << std::setw(7) << hex << '|' << '\n'
		<< '|' << std::setw(12) << "Uppercase" << '|' << std::setw(7) << upper << '|' << '\n'
		<< '|' << std::setw(12) << "Lowercase" << '|' << std::setw(7) << lower << '|' << '\n'
		<< '|' << std::setw(12) << "Control" << '|' << std::setw(7) << control << '|' << '\n'
		<< '|' << std::setw(12) << "Punctuation" << '|' << std::setw(7) << punct << '|' << '\n'
		<< '|' << std::setw(12) << "Graph" << '|' << std::setw(7) << graph << '|' << std::endl;

	
}

void exercise_15()
{
	const std::string numb = "numbers.text";
	const std::string scien_num = "scientific_numbers.text";

	std::vector<double> buffer;

	std::ifstream ist9{ numb };
	if (!ist9)throw"cannot open input file", numb;

	for (double x; ist9 >> x;)
	{
		buffer.push_back(x);
	}
	ist9.close();

	std::ofstream ost9{ scien_num };
	if (!ost9)throw"cannot open output file", scien_num;

	for (double x : buffer)
	{
		ost9 << std::setprecision(8) << std::scientific << x << '\n';
	}
	ost9.close();
}


void exercise_16()
{
	const std::string numb = "numbers.text";
	
	std::vector<int> buffer;

	std::ifstream ist9{ numb };			// opens file
	if (!ist9)throw"cannot open input file", numb;

	for (double x; ist9 >> x;)		// puts numbers into vector buffer
	{
		buffer.push_back(x);
	}
	ist9.close();
	
	sort(buffer.begin(), buffer.end());		// sorts buffer lowest first
	
	int count = 0;
	int last =0;
	for (int i = 0; i < buffer.size(); i++)
	{
		if (i == 0)		//outputs first number because nothing to compare to yet
		{
			std::cout << buffer[i];
			last = buffer[i];		// to compare to, on next iteration
			count = 1;
		}
		else if (buffer[i] == last)		// if current iteration equals last count increases
		{
			count++;
			last = buffer[i];		// to compare to, on next iteration
		}
		else
		{
			if (count > 1) std::cout << '\t' << count;		//outputs total count of last number if count is more than 1
			std::cout << '\n' << buffer[i];				// prints current number
			last = buffer[i];						// to compare to, on next iteration
			count = 1;								//resets count to 1 as there will always be one of...
		}
		
	}
}
void runExercises()
{
	//exercise_1();
	//exercise_2();
	//exercise_3();
	//exercise_4();
	//exercise_5();
	//exercise_6();
	//exercise_7();
	//exercise_8();
	//exercise_9();
	//exercise_10_11();
	//exercise_12();
	//exercise_13();
	//exercise_14();
	//exercise_15();
	exercise_16();
}
