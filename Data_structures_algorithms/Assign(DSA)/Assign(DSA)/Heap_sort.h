#pragma once
#include "Algorithms.h"

using namespace std;
template <typename T>
class Heap_sort : public Algorithms
{

public:

    void heapify(vector<T>& arr, int size, int i) 
    {
        
        int max = i; // initialize max as root
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // if left child is larger than root
        if (left < size && arr[left] > arr[max])
        {
            max = left;
            m_iterations++;
        }

        // if right child is larger than max
        if (right < size && arr[right] > arr[max])
        {
            max = right;
            m_iterations++;
        }

        // if max is not root
        if (max != i) {
            // swap
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            m_iterations++;
            m_swaps++;
            // recursively heapify the affected sub-tree
            heapify(arr, size, max);
        }
        
    }

    void heapSort(vector<T>& arr)
    {
        int size = arr.size();

        // build heapSort (rearrange array)
        for (int i = size / 2 - 1; i >= 0; i--) 
        {
            heapify(arr, size, i);
            m_iterations++;
        }

        // one by one extract an element from heapSort
        for (int i = size - 1; i >= 0; i--) 
        {
            // move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            m_iterations++;
            m_swaps++;
            // call max heapify on the reduced heapSort
            heapify(arr, i, 0);
        }
    }

    
    
};

