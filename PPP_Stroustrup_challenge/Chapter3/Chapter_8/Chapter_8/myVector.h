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
	vector<double> m_diff;
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
	void DisplaySumOfSumVec(double n)
	{
		double sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += m_vec[i];
		}
		cout << "The sum of the first " << n << " elements are: " << sum << endl;
	}

	void DisplayVecDiff()
	{
		
		for (int i = 1; i != m_vec.size(); ++i)
		{
			
			m_diff.push_back(m_vec[i] - m_vec[i -1] );

		}
		for (int y = 0; y != m_diff.size(); y++)
		{
			cout << m_diff[y] << '\t';
		}
		cout << endl;

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

