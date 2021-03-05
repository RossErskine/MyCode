#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename T>
class myVector
{
private:
	vector<T> m_vec;

public:
	
	const T& vec_size() const
	{
		return m_vec.size();
	}


	const T& GetVec(int i) const
	{
		return m_vec[i];
	}

	void add_vec(T vec)
	{
		m_vec.push_back(vec);
	}

	
	void display_vec()
	{
		sort(m_vec.begin(), m_vec.end());
		for (int i = 0; i < m_vec.size(); i++)
		{
			cout << m_vec[i] << '\t';
		}
		cout << endl;
	}
	
	void DisplaySumOfVec()
	{
		cout << "The sum of all elements are: ";
		cout << accumulate(m_vec.begin(), m_vec.end(), 0) << endl;
	}
	
	void DisplayMaxElement()
	{
		cout << "Max Elememnt: ";
		cout << *max_element(m_vec.begin(), m_vec.end()) << endl;
	}
	
	void DisplayMinElement()
	{
		cout << "Min Elememnt: ";
		cout << *min_element(m_vec.begin(), m_vec.end()) << endl;
	}
	
	void DisplayMean()
	{
		double sum = accumulate(m_vec.begin(), m_vec.end(), 0);
		double mean = sum / m_vec.size();
		cout << "Mean of Elements: " << mean << endl;
	}



};

