#pragma once
#include "Algorithms.h"
#include "Binary_search.h"



class Delete :
	public Algorithms
{
    Binary_search<int> binarySearch;
public:
    void deleteElement(vector<int>& arr, int key)
    {
      
        // Deleting element  
        arr.erase(arr.begin() + key -1);
 
    }
};

