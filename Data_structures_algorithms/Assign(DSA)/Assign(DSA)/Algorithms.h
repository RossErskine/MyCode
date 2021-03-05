#pragma once
#include <vector>
using namespace std;

class Algorithms
{
public:
	int m_iterations = 0;
	int m_swaps = 0;

	template <typename T>
	void swap(T* xp, T* yp)
	{
		T temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	const int& GetIteration() const
	{
		return m_iterations;
	}


	const int& GetSwaps() const
	{
		return m_swaps;
	}

	void clearIteretions()
	{
		m_iterations = 0;
	}
	
	void clearSwaps()
	{
		m_swaps = 0;
	}
	
};

