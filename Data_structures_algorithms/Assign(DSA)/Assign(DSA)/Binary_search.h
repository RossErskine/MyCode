#pragma once
#include "Algorithms.h"


using namespace std;
template <typename T>
class Binary_search : public Algorithms
{
    
public:
    int binarySearch_vec(vector<T>& arr, int l, int r, int x)
    {
        while (l <= r) {
            m_iterations++;
            int m = l + (r - l) / 2;

            // Check if x is present at mid 
            if (arr[m] == x)
                return m;

            // If x greater, ignore left half 
            if (arr[m] < x)
                l = m + 1;

            // If x is smaller, ignore right half 
            else
                r = m - 1;
        }

        // if we reach here, then element was 
        // not present 
        return -1;
    }

    int binarySearch_C_arr(T arr[], int l, int r, int x)
    {
        while (l <= r) {
            m_iterations++;
            int m = l + (r - l) / 2;

            // Check if x is present at mid 
            if (arr[m] == x)
                return m;

            // If x greater, ignore left half 
            if (arr[m] < x)
                l = m + 1;

            // If x is smaller, ignore right half 
            else
                r = m - 1;
        }

        // if we reach here, then element was 
        // not present 
        return -1;
    }

    template <size_t t>
    int binarySearch_std_arr(array<int, t> arr, int l, int N, int x)
    {

        while (l <= N) {
            m_iterations++;
            int m = l + (N - l) / 2;

            // Check if x is present at mid 
            if (arr[m] == x)
                return m;

            // If x greater, ignore left half 
            if (arr[m] < x)
                l = m + 1;

            // If x is smaller, ignore right half 
            else
                N = m - 1;
        }

        // if we reach here, then element was 
        // not present 
        //return -1;
       
    }


    
    


    

   
};

