#include "Challenge.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Challenge::Drill_1()
{
	int t_val1, t_val2;
	bool fin = true;
	while (fin == true)
	{
		cout << "Enter 2 Values: " << endl << endl;
		cin >> t_val1 >> t_val2;
		if (!cin) 
		{
			 fin = false;
		}
		m_Value.SetVal1(t_val1);
		m_Value.SetVal2(t_val2);
		cout << "The values entered was: " << m_Value.GetVal1() << " & " << m_Value.GetVal2() << endl;
	}
	return ;
}

void Challenge::Drill_2()
{
	int t_val1, t_val2;
	cout << "Enter 2 values: " << endl << endl;
	cin >> t_val1 >> t_val2;
	m_Value.SetVal1(t_val1);
	m_Value.SetVal2(t_val2);
	if (m_Value.GetVal1() < m_Value.GetVal2())
	{
		cout << " value: " << m_Value.GetVal2() << " is greater than " << m_Value.GetVal1() << endl;
	}
	else if (m_Value.GetVal1() == m_Value.GetVal2())
	{
		cout << " value: " << m_Value.GetVal1() << " has the same value as: " << m_Value.GetVal2() << endl;
	}
	else if (m_Value.GetVal1() > m_Value.GetVal2())
	{
		cout << " value: " << m_Value.GetVal1() << " is greater than " << m_Value.GetVal2() << endl;
	}
}

void Challenge::Drill_4()
{
	double t_val1, t_val2;
	
	bool fin = true;
	while (fin == true)
	{
		cout << "Enter 2 values: " << endl << endl;
		cin >> t_val1 >> t_val2;
		m_Dvalue.SetVal1(t_val1);
		m_Dvalue.SetVal2(t_val2);
		if (!cin)
		{
			fin = false;
			return;
		}
		else if (m_Dvalue.GetVal1() == m_Dvalue.GetVal2()-1)
		{
			cout << " value: " << m_Dvalue.GetVal1() << " has almost the same value as: " << m_Dvalue.GetVal2() << endl;
		}
		else if (m_Dvalue.GetVal1() == m_Dvalue.GetVal2()+1)
		{
			cout << " value: " << m_Dvalue.GetVal1() << " has almost the same value as: " << m_Dvalue.GetVal2() << endl;
		}
		if (m_Dvalue.GetVal1() < m_Dvalue.GetVal2())
		{
			cout << " value: " << m_Dvalue.GetVal2() << " is greater than " << m_Dvalue.GetVal1() << endl;
		}
		else if (m_Dvalue.GetVal1() == m_Dvalue.GetVal2())
		{
			cout << " value: " << m_Dvalue.GetVal1() << " has the same value as: " << m_Dvalue.GetVal2() << endl;
		}
		else if (m_Dvalue.GetVal1() > m_Dvalue.GetVal2())
		{
			cout << " value: " << m_Dvalue.GetVal1() << " is greater than " << m_Dvalue.GetVal2() << endl;
		}
	}
	return;
}

void Challenge::Drill_6()
{
	
	double t_val1, t_val2;
	bool fin = true;
	string t_unit1, t_unit2;
	
	
	cout << "Enter a Values: " << endl << endl;
	cin >> t_val1 >> t_unit1;
	if (!cin)
	{
		fin = false;
	}
	m_lastVal.SetHighVal(t_val1);
	m_lastVal.SetHighUnit(t_unit1);
	
	
	
	if (m_lastVal.GetHighUnit() == "m")
	{
		m_lastVal.SetHighVal(m_lastVal.GetHighVal() * 100);
	}
	else if (m_lastVal.GetHighUnit() == "in")
	{
		m_lastVal.SetHighVal(m_lastVal.GetHighVal() * 2.54);
	}
	else if (m_lastVal.GetHighUnit() == "ft")
	{
		m_lastVal.SetHighVal(m_lastVal.GetHighVal() * 30.48);
	}
	
	while (fin == true)
	{
		cout << "Enter a Values: " << endl << endl;
		cin >> t_val2 >> t_unit2;
		if (!cin)
		{
			fin = false;
		}
		m_lastVal.SetCurrVal(t_val2);
		m_lastVal.SetCurrUnit(t_unit2);
		
		
		//check unit in loop
		if (m_lastVal.GetCurrUnit() == "m")
		{
			m_lastVal.SetCurrVal(m_lastVal.GetCurrVal() * 100);
		}
		else if (m_lastVal.GetCurrUnit() == "in")
		{
			m_lastVal.SetCurrVal(m_lastVal.GetCurrVal() * 2.54);
		}
		else if (m_lastVal.GetCurrUnit() == "ft")
		{
			m_lastVal.SetCurrVal(m_lastVal.GetCurrVal() * 30.48);
		}
		
		//check high number
		if (m_lastVal.GetCurrVal() < m_lastVal.GetHighVal())
		{
			cout << " value: " << m_lastVal.GetHighVal() << " cm " << " is greater than " << m_lastVal.GetCurrVal() << " cm " << endl;
			m_lastVal.SetLowVal(m_lastVal.GetCurrVal());
			m_DoubleVec.AddLowVec(m_lastVal.GetCurrVal());
			cout << "High value is: " << m_lastVal.GetHighVal() << endl << endl;
			cout << "Low value is: " << m_lastVal.GetLowVal() << endl;
			m_DoubleVec.DisplayHighVec();
			m_DoubleVec.DisplayLowVec();
		}
		
		else if (m_lastVal.GetCurrVal() > m_lastVal.GetHighVal())
		{
			
			cout << " value: " << m_lastVal.GetCurrVal() << " cm " << " is greater than " << m_lastVal.GetHighVal() << " cm " << endl << endl;
			m_lastVal.SetHighVal(m_lastVal.GetCurrVal());
			m_DoubleVec.AddHighVec(m_lastVal.GetCurrVal());
			cout << "High value is: " << m_lastVal.GetHighVal() << endl << endl;
			cout << "Low value is: " << m_lastVal.GetLowVal() << endl;
			m_DoubleVec.DisplayHighVec();
			m_DoubleVec.DisplayLowVec();
			
		}
	}
	return;
}
void Challenge::Exercise_1()
{
	double t_val;
	char t_unit;
	cout << "Enter the value followed by the currency Y = yen, E = Euro, D = dollers: " << endl << endl;
	cin >> t_val >> t_unit;
	m_Currency.SetVal(t_val);
	m_Currency.SetUnit(t_unit);

	switch (m_Currency.GetUnit())
	{
	case 'Y':
		cout << "the conversion is: " << m_Currency.GetVal() * m_Currency.GetYen() << " in pounds" << endl;
		break;
	case 'E':
		cout << "the conversion is: " << m_Currency.GetVal() * m_Currency.GetEuro() << " in pounds " << endl;
		break;
	case 'D':
		cout << "the conversion is: " << m_Currency.GetVal() * m_Currency.GetUSDoller() << " in pounds " << endl;
		break;
	default:
		cout << "Sorry thats not a currency we can convert: " << endl;
		break;
	}
}
void Challenge::TryThis()
{
	char character = 'A';
	while (character != 'z' + 1)
	{
		int integer = character;
		cout << character << '\t' << integer << '\n';
		++character;
	}
}

void Challenge::bleep()
{
	/*
	vector<int>v = { 5,7,9,4,6,8 };
	for (int x : v)		//for x in v
		cout << x << '\n';
		*/
	
	cout << "input sentance: " << endl;
	for (string t_word; cin >> t_word;) 
	{
		m_Sentence.SetWord(t_word);
		//m_Sentence.AddSentences(m_Sentence.GetWord());
		if (m_Sentence.GetWord() == m_Sentence.GetBadWord())
		{
			m_Sentence.AddSentences(m_Sentence.GetBleep());
			
		}
		else if (m_Sentence.GetWord() == m_Sentence.GetReallybadword())
		{
			m_Sentence.AddSentences(m_Sentence.GetBleeper());
		}
		else
		{
			m_Sentence.AddSentences(m_Sentence.GetWord());
		}
			
	}
	
	m_Sentence.DisplaySentences();
	
}




void Challenge::RunChallenges()
{
	//Drill_1();
	//Drill_2();
	//Drill_4();
	//Drill_6();
	//Exercise_1();
	//TryThis();
	//bleep();
}