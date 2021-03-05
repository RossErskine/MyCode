#pragma once
#include "Algorithms.h"

template <typename T>
class Bubble_Sort : public Algorithms
{

public:
	
	void bubble_sort(vector<T>& arrName)
	{
		
		unsigned int i, j;
		for (i = 0; i < arrName.size() - 1; i++)
		{
			m_iterations++;
			for (j = 0; j < arrName.size() - i - 1; j++)
			{
				m_iterations++;
				if (arrName[j] > arrName[j + 1])
				{
					m_iterations++;
					swap(&arrName[j], &arrName[j + 1]);
					m_swaps++;
				}
			}
		}
		
	}
	
	

	
};

