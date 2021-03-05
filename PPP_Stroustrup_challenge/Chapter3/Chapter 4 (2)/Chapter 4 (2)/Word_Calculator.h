#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Word_Calculator
{
private:
	vector<string> m_Ten = { "zero","one","two","three","four","five",
								"six","seven","eight","nine","ten" };

	vector<string> m_WordExp = { "plus", "minus", "divide", "times" };
	int m_sum;
	int m_first_num;
	int m_second_num;
	int m_exp;
public:
	void findFirstWord(string word)
	{
		for (int i = 0; i != m_Ten.size(); ++i)
		{
			if (word == m_Ten[i])
			{
				int num = i;
				m_first_num = num;
			}
		}
	}
	void findExp(string word)
	{
		for (int i = 0; i != m_WordExp.size(); ++i)
		{
			if (word == m_WordExp[i])
			{
				int num = i;
				m_exp = num;
			}
		}
	}
	void findSeocndWord(string word)
	{
		for (int i = 0; i != m_Ten.size(); ++i)
		{
			if (word == m_Ten[i])
			{
				int num = i;
				m_second_num = num;
			}
		}
	}


	void GetSum()
	{
		switch (m_exp)
		{
		case 0:
			m_sum = m_first_num + m_second_num;
			cout << m_first_num << " + " << m_second_num << " = " << m_sum << endl;
			break;

		case 1:
			m_sum = m_first_num - m_second_num;
			cout << m_first_num << " - " << m_second_num << " = " << m_sum << endl;
			break;
		case 2:
			m_sum = m_first_num / m_second_num;
			cout << m_first_num << " / " << m_second_num << " = " << m_sum << endl;
			break;
		case 3:
			m_sum = m_first_num * m_second_num;
			cout << m_first_num << " * " << m_second_num << " = " << m_sum << endl;
			break;
		default:
			cout << " something went wrong sorry" << endl;
		}



	}

};

