#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

//================exercise 3&4 =================//
//== prints vector with a label ==//
template <typename T>
void _print(string label, const vector<T>& v)
{
	cout << label << ": ";
	for (T i : v)
	{
		cout << '\t' << i;
	}
	cout << '\n';
}


//==creates fibonacci vectors ==//
vector<int> fibonacci()
{
	vector<int> v{ 1,1 };	//initialise sequence
	int a = 1, b = 1, c = 0;
	do
	{
		c = a + b;
		v.push_back(c);
		a = b;
		b = c;
		
	} while (a < b);	//do until int becomes non-int
	v.pop_back();	//removes non-int
	return v;
}

void exercise_3()
{
	vector<int> vec = fibonacci();
	string fib = " Fibonacci";
	_print(fib, vec);
	cout << "\n\nLast fibonacci element that fits in an 'int' is: " << vec.back() << endl << endl;
	
}
//=====================exercise 5&6 ============================//
//=== reverse that does not change original vector===//
template <typename T>
vector<T> reverse_2(const vector<T>& vec1)
{
	vector<T> vec2;
	for (int i = vec1.size()-1 ;i>=0;--i)
	{
		vec2.push_back(vec1[i]);
	}
	return vec2;	//returns new vector
}
//=== changes original vector===//
template <typename T>
void reverse_1(vector<T>& vec1)
{
	reverse(begin(vec1), end(vec1));
}

void exercise_5()
{
	vector<int> vec1 = fibonacci();
	vector<int> rVec = reverse_2(vec1);
	_print("fib", vec1);
	cout << '\n';
	_print("rev-fib using 2 vec", rVec);
	cout << '\n';
	reverse_1(vec1);
	_print("rev-fib using 1 vec", vec1);
}


void exercise_6()
{
	vector<string> vec1 = { "leo","mike","leonard","zoe","gary","henry" };
	vector<string> rVec = reverse_2(vec1);
	_print("Animals", vec1);
	cout << '\n';
	_print("rev-Animals using 2 vectors", rVec);
	cout << '\n';
	reverse_1(vec1);
	_print("rev-Animals using 1 vector", vec1);
}

//=====================exercise 7 & 8=================//
//===looks for duplicate names===//
template <typename T>
bool duplicates(vector<T> vec, T x)
{
	for (T i : vec) 
	{
		if (i != x)
		{
			return true;
		}
		else {
			return false;
		}
	}
}
//=== sorts vector===//
template <typename T>
vector<T> srtVec(vector<T> vec)
{
	sort(vec.begin(), vec.end());
	return vec;
}

//=== sorts age vector by comparing with name vector ===//
vector<double> srtAge(const vector<string>& sortedName,const vector<string>& name, const vector<double>& age)
{
	vector<double> rVec;
	for (int i = 0; i != sortedName.size(); ++i)
	{
		for (int j = 0; j != name.size(); ++j)
		{
			if (sortedName[i] == name[j])
			{
				rVec.push_back(age[j]);
			}
		}
		
	}
	return rVec;

}
void exercise_7()
{
	vector<string> name,s_name;
	vector<double> age,s_age;
	bool run = true;
	const char prompt = '>';
	const string quit = "q";
	cout << "Enter names please: \n"
		<< "press q to quit." << endl;
	
	//=== gets names from user ===//
	while (run)
	{
		bool not_unique = false;
		cout << prompt;
		string s;
		cin >> s;
		if (s == quit) { run = false; }
		else if (duplicates(name, s)) // searches for duplicate names
		{
			name.push_back(s);
		}
		else
		{
			cout << " name already taken!" << endl;
		}
	}
	
	//=== gets age from users ===//
	cout << "please enter the age of:" << endl;
	for (string i : name)
	{
		double s;
		cout << i << ": ";
		cin >> s;
		if (!cin)throw"age needed!";
		age.push_back(s);
	}
	cout << '\n';
	s_name = srtVec(name);				// sorts name vector using srtVec func
	s_age = srtAge(s_name, name, age);	// sorts age vector using original name vector as comparison
	_print("names", s_name);
	_print("age", s_age);
}

//================exercise 9, 10, 11 =================//
//=== find a vectors smallest, largest, mean & median elements through reference ===//
void find_r(double& sml, double& lrg, double& mean, double& med, vector<double> v)
{
	sml = *min_element(v.begin(), v.end());
	lrg = *max_element(v.begin(), v.end());
	double sum = accumulate(v.begin(), v.end(), 0);
	mean = sum / v.size();
	sort(v.begin(), v.end());
	for (double i = 0; i != v.size(); ++i)
	{
		double s = (v.size()-1) / 2;
		med = v[s];
	}

}
//=== struct for find_s func ===//
struct results
{
	double sml=0, lrg=0, mean=0, med=0;
};
//=== find a vectors smallest, largest, mean & median elements through a struct ===//
results find_s(vector<double> v)
{
	results res;
	res.lrg = *max_element(v.begin(), v.end());
	res.sml = *min_element(v.begin(), v.end());
	double sum = accumulate(v.begin(), v.end(), 0);
	res.mean = sum / v.size();
	sort(v.begin(), v.end());
	for (double i = 0; i != v.size(); ++i)
	{
		double s = (v.size()-1) / 2;
		res.med = v[s];
	}
	return res;
}
//== return max element of a vector==//
template <typename T>
T maxv(const vector<T>& v)
{
	T maxElement;
	maxElement = *max_element(v.begin(), v.end());
	return maxElement;
}
//=== returns index of elements of a pair vectors ===//
double _index( const vector<double>& p, const vector<double>& w)
{
	double sum = 0;
	if (p.size() != w.size())throw "index: equal size needed!";
	for (int i =0; i != p.size();++i)
	{
		sum += p[i] * w[i];
	}
	return sum;

}
void exercise_9()
{
	vector<double> price{ 1.2,0.9,1.5,2.1,0.75,1.01 };
	vector<double> weight{ 3, 2.4,3.5,5.8,1.9,2.8 };
	results res = find_s(price);
	double sml = 0, lrg = 0, mean = 0, med = 0;

	cout << "index of price and weight is: " << _index(price, weight) << endl;
	cout << "Max element in price is: " << maxv(price) << endl;
	cout << "Max element in weight is: " << maxv(weight) << endl;
	cout << "\nfind avg price through struct: " << endl
		<< "smallest: " << res.sml << endl
		<< "largest: " << res.lrg << endl
		<< "mean: " << res.mean << endl
		<< "median: " << res.med << endl;
	find_r(sml, lrg, mean, med, price);
	cout << "\nfind avg price through reference: " << endl
		<< "smallest: " << sml << endl
		<< "largest: " << lrg << endl
		<< "mean: " << mean << endl
		<< "median: " << med << endl;
}

//============ exercise 12 ==============//
//=== prints vector until 'mike' is found twice ===//
void print_until_ss(const vector<string>& v, const string& quit)
{
	int count = 0;
	for (string s : v)
	{
		if (s == quit)++count;
		if (count == 2)
		{
			cout << "two " << quit << "'s found!" << endl;
			return;
		}
		cout << s << '\n';
	}
}
void exercise_12()
{
	vector<string> v = { "leo","mike","leonard","zoe","gary","henry","mike","chris" };
	print_until_ss(v, "mike");
}
//=============exercise 13 ===============//
//== struct variables for lex and vecsize functions ==//
struct AnimalNames
{
	string smlLen, lrgLen, lastLex, firstLex;
};
//=== finds first and last lexicographical strings in vector ===//
AnimalNames lex(vector<string> sVec)
{
	AnimalNames an;
	sort(sVec.begin(),sVec.end());
	an.firstLex = sVec[0];
	an.lastLex = sVec[sVec.size() - 1];
	return an;
}
//=== finds longest and shortest string in vector ===//
AnimalNames vecSize(const vector<string>& sVec)
{
	AnimalNames an;
	an.smlLen = sVec[0];
	an.lrgLen = sVec[0];
	for (string s : sVec)
	{
		if(s.length() > an.lrgLen.length())an.lrgLen = s;
		if (s.length() < an.smlLen.length())an.smlLen = s;
	}
	return an;
	
}
//===finds length of strings in vector ===//
vector<int> numChar(const vector<string>& vec)
{
	vector<int> num_of_char;
	for (int i =0;i!=vec.size();++i)
	{
		int s = vec[i].length();
		num_of_char.push_back(s);
	}
	return num_of_char;

}
void exercise_13()
{
	vector<string> vec = { "leo","mike","leonard","zoe","gary","henry","mike","chris" };
	AnimalNames an1, an2;
	vector<int> num_of_chars = numChar(vec);
	_print("Animal name vectors", vec);
	_print("length of words in vector", num_of_chars);
	an1 = vecSize(vec);
	cout << "largest name is: " << an1.lrgLen
		<< "\nsmallest name is: " << an1.smlLen << endl;
	an2 = lex(vec);
	cout << "The first lexicographically name is: " << an2.firstLex
		<< "\nthe last lexicographically name is: " << an2.lastLex << endl;
}

void runExercises()
{
	try
	{
		//exercise_3();
		//exercise_5();
		//exercise_6();
		//exercise_7();
		//exercise_9();
		//exercise_12();
		exercise_13();
	}
	catch (const char* msg)
	{
		cerr << msg << endl;

	}
}