#pragma once
#include "Algorithms.h"
template <typename T>
class Quick_Sort : public Algorithms
{

public:
   
    int partition(vector<T>& values, int left, int right) {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = values[pivotIndex];
        int i = left, j = right;
        int temp;
        while (i <= j) {
            while (values[i] < pivotValue) {
                i++;
                m_iterations++;
            }
            while (values[j] > pivotValue) {
                j--;
                m_iterations++;
            }
            if (i <= j) {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
                i++;
                j--;
                m_swaps++;
            }
        }
        return i;
    }

    void quickSort(vector<T>& values, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(values, left, right);
            quickSort(values, left, pivotIndex - 1);
            quickSort(values, pivotIndex, right);
        }
    }
    

   
};

