#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Temperature_Readings.h"
#include <algorithm>
#include <numeric>
//#include "Roman_int.h"
#include "SimpleCalc.h"

void exercise_1()
{
	std::vector<int> numbers = { 9,7,8,5,6,3,2,9,11,56,7,99,109 };

	const std::string afile = "afile";
	std::ofstream ost{ afile };
	if (!ost)throw"cannot openotput file", afile;
	for (int i : numbers)
	{
		ost << i << '\t';
	}
	ost.close();

	std::ifstream ist{ afile };
	int sum = 0;

	for (int i; ist >> i;)
	{
		sum += i;
	}
	ist.close();

	std::cout << "Sum of afile is: " << sum << std::endl;

}

const std::string raw_temps = "raw_temps.txt";
using namespace Temp_Readings;

void exercise_2()	//store_temps.cpp
{
	
	std::ofstream ost{ raw_temps };
	if (!ost)throw" writeTo: cannot open output file!", raw_temps;

	std::cout << "Enter readings (hour,temperature): " << std::endl;
	
	for (int i =0;i<10;++i)
	{
		Reading r;
		std::cin >> r;
		if (buffer(r))				//checks input in buffer before entry to file
		{
			ost << r;				// writes to file	
		}
		else {
			throw "buffer: Someting went wrong!";
		}
			
	}
	ost.close();
}

// == swaps positions of Reading vector in buuble sort == //
template <typename T>
void swap(T* xp, T* yp)
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// == bubble sorts Reading vectors temperatures == //
void bubble_sort(std::vector<Reading>& v)
{

	unsigned int i, j;
	for (i = 0; i < v.size() - 1; i++)
	{
		for (j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j].temperature > v[j + 1].temperature)
			{
				swap(&v[j].temperature, &v[j + 1].temperature);
			}
		}
	}

}

void exercise_3()	//temp_stats.cpp
{
	
	std::vector<Reading> temp_stats;
	double sum=0, mean=0, median=0;

	std::ifstream ist{ raw_temps };
	if (!ist) throw "can't open output file ", raw_temps;
	for (Reading p; ist >> p;)
	{
		if (p.type == temp_type::c)
		{
			Reading temp = (cel_to_feh(p));
			temp_stats.push_back(temp); //converts celsius to fahrenheit
			sum += temp.temperature;	//adds all temperatures
		}
		else
		{
			temp_stats.push_back(p);
			sum += p.temperature;	//adds all temperatures
		}
				
	}
	ist.close();

	mean = sum / temp_stats.size();

	bubble_sort(temp_stats);		//sorts temp_stats temperatures
	for (int i = 0; i != temp_stats.size(); ++i)
	{
		double s = (temp_stats.size() - 1) / 2;
		median = double(temp_stats[i].temperature);
	}

	std::cout << "The Mean of " << raw_temps << " is: " << mean << std::endl;
	std::cout << "The Median of " << raw_temps << " is: " << median << std::endl;
	
	
}

void exercise_6()
{
	using namespace _Roman_int;
	Roman_int test1;
	std::cout << "Please enter roman number: " << std::endl;
	std::cin >> test1;
	
	std::cout << "Roman: " << test1 << " equals " << test1.as_int() << '\n';
}

void exercise_7()
{
	runCalc();
}

void exercise_8()
{
	// == create file one == //
	std::vector<int> num1 = { 1,2,3,4,5,6,7,8,9,10 };

	const std::string f1 = "f1";
	std::ofstream ost1{ f1 };
	if (!ost1)throw"cannot openotput file", f1;
	for (int i : num1)
	{
		ost1 << i << '\t';
	}
	ost1.close();

	// == create file two == //
	std::vector<int> num2 = { 11,12,13,14,15,16,17,18,19,20 };

	const std::string f2 = "f2";
	std::ofstream ost2{ f2 };
	if (!ost2)throw"cannot openotput file", f2;
	for (int i : num2)
	{
		ost2 << i << '\t';
	}
	ost2.close();

	// == concatenates two files == //
	const std::string concat = "concat";
	std::ofstream ost3{ concat };			//open file to concatenate too
	if (!ost3)throw"cannot openotput file", concat;

	std::ifstream ist1{ f1 };				//open file 1
	if (!ist1)throw"cannot openotput file", f1;

	std::ifstream ist2{ f2 };				//open file 2
	if (!ist2)throw"cannot openotput file", f2;

	for (int i; ist1 >> i;)					//input file 1 to concat file
	{
		ost3 << i << '\t';
	}

	for (int j; ist2 >> j;)					//input file 2 to concat file
	{
		ost3 << j << '\t';
	}

	ost3.close();							//close files
	ist1.close();
	ist2.close();

}

void exercise_9()
{
	// == create file one == //
	std::vector<std::string> word1 = { "Leo","Mike","Zoe","Gary","Leonard","Henry" };
	sort(word1.begin(), word1.end());

	const std::string f5 = "f5";
	std::ofstream ost5{ f5};
	if (!ost5)throw"cannot openotput file", f5;
	for (std::string i : word1)
	{
		ost5 << i << '\t';
	}
	ost5.close();

	// == create file two == //
	std::vector<std::string> word2 = { "Reginald","Baghera","Balhoo","Mowgli","Pingoo","Fred" };
	sort(word2.begin(), word2.end());

	const std::string f6 = "f6";
	std::ofstream ost6{ f6 };
	if (!ost6)throw"cannot openotput file", f6;
	for (std::string j : word2)
	{
		ost6 << j << '\t';
	}
	ost6.close();

	// == concatenates two files == //
	const std::string concat = "concat";
	std::ofstream ost7{ concat };			//open file to concatenate too
	if (!ost7)throw"cannot openotput file", concat;

	std::ifstream ist8{ f5 };				//open file 1
	if (!ist8)throw"cannot openotput file", f5;

	std::ifstream ist9{ f6 };				//open file 2
	if (!ist9)throw"cannot openotput file", f6;

	std::vector<std::string> convec;		// vector for sorting words

	for (std::string i; ist8 >> i;)			// input to vector from f1
	{
		convec.push_back(i);
	}
	for (std::string j; ist9 >> j;)			// input to vector from f2
	{
		convec.push_back(j);
	}

	sort(convec.begin(), convec.end());		//sort vector

	for (std::string k : convec)			//input to concat file
	{
		ost7 << k << '\t';
	}


	ost7.close();							//close files
	ist8.close();
	ist9.close();

	

}

/*	
	Using C++ File Streams 
	David Kieras, 
	EECS Dept., 
	Univ. of Michigan Revised for EECS 381, 
	9/20/2012
*/
bool get_int(istream& in_strm, bool& good_flag, int& x)
{
	bool continue_flag;

	in_strm >> x;
	if (in_strm.good()) {
		good_flag = true;
		continue_flag = true;
	}
	else if (in_strm.eof()) {
		std::cout << "End of file encountered." << std::endl; 
		good_flag = false;						// input value was not obtained 
		continue_flag = false;					// time to stop 
	} 
	else if (in_strm.bad()) {
		std::cout << "Hard I/O error" << std::endl; 
		good_flag = false; 
		continue_flag = false;					// give up! 
	} 
	else if (in_strm.fail()) {
		std::cout << "Invalid input - skipping rest of line" << std::endl; 
		in_strm.clear();						// don't forget! Must clear the stream to read it! 
		char c; 
		while (in_strm.get(c) && c != '\n');	// may hit eof while skipping 
		good_flag = false;						// value is not good 
		if (in_strm.good())						// did we hit eof or something else? 
			continue_flag = true;				//  no - can keep going 
		else { continue_flag = false;			// yes - time to stop 
		std::cout << "End of file or error while skipping rest of line." << std::endl; 
		} 
	} 
	else {
		std::cout << "Should be impossible to be here!" << endl; // for demo only! 
		good_flag = false; 
		continue_flag = false; 
	} 
	return continue_flag;
}

void testGet_int()
{
	const std::string data = "data.input";
	std::ofstream ost{ data };
	if (!ost)throw"cannot openotput file", data;
	for (string s; std::cin >> s;)
	{
		if (s == "f")break;
		ost << s << '\t';
		
	}
	
	ost.close();

	int datum; 
	bool value_is_good = false; 
	ifstream input_file(data); // open the input file 
	if (!input_file.is_open()) { // check for successful opening 
		std::cout << "File could not be opened! Terminating!" << std::endl; 
		return ; 
	} 
	// continue reading integer values as long as get_int returns true 
	// but don't use the value unless value_is_good is true 
	while (get_int(input_file, value_is_good, datum)) 
		if (value_is_good) 
			std::cout << "value read is " << datum << std::endl; 
	input_file.close(); 
	std::cout << "Done!" << std::endl; 
	return ; 
}
void exercise_11()
{

}


void runExercises()
{
	//exercise_1();

	//exercise_2();
	//exercise_3();
	//exercise_6();
	//exercise_7();
	//exercise_8();
	//exercise_9();
	testGet_int();
}
