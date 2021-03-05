#pragma once
#include "Algorithms.h"
#include <algorithm>
#include <iostream>

using namespace std;
template <typename T>
class Merge :
	public Algorithms
{
public:
    
    vector<T> std_merge_vectors(vector<T> arr1, vector<T> arr2)
    {
        vector<T> arr3;
        merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(arr3));
        m_iterations++;
        return arr3;
    }
   
    vector<T> merge_vectors(vector<T>& arr1, vector<T>& arr2)
    {

        int n1 = arr1.size();
        int n2 = arr2.size();
       
        vector<T> arr3;
        //arr3.reserve(n1 + n2);
        int n3 = n1 + n2;
        int i = 0, j =0,k=0;
        
        while (k < n3)
        {
            if (i <= j) {
                arr3.push_back(arr1[i++]);
                k++;
                m_iterations++;
            }
            if(j<=i)
            {
                arr3.push_back(arr2[j++]);
                k++;
                m_iterations++;
            }   
        }
        return arr3;
    }
};

