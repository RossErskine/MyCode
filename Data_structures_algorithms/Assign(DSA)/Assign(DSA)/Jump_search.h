#pragma once
#include <algorithm>
#include "Algorithms.h"
//#include <minwindef.h>
using namespace std;

template <typename T>
class Jump_search : public Algorithms
{
public:
    
    int jumpSearch(vector<T> arr, int x, int n)
    {
        // Finding block size to be jumped 
        int step = sqrt(n);

        // Finding the block where element is 
        // present (if it is present) 
        int prev = 0;
        while (arr[min(step, n) - 1] < x)
        {
            m_iterations++;
            prev = step;
            step += sqrt(n);
            if (prev >= n)
                return -1;
        }

        // Doing a linear search for x in block 
        // beginning with prev. 
        while (arr[prev] < x)
        {
            prev++;
            m_iterations++;
            // If we reached next block or end of 
            // array, element is not present. 
            if (prev == min(step, n))
                return -1;
        }
        // If element is found 
        if (arr[prev] == x)
            m_iterations++;
            return prev;

        return -1;
    }
   
};

