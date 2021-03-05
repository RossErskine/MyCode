
#include <vector>
#include <array>
#include <iostream>
#include <Windows.h>

using namespace std;

class ContVsArrayTest
{

public:
    LONGLONG startTime = 0, endTime = 0, m_freqCount = 0;

    void containerVsArray();
    void create_test1(vector<int>& vec, int vecSize)
    {
        for (int i = 1; i <= vecSize; i++)
        {
            vec.push_back(i);
        }
    }
    template <size_t t>
    void create_test2(array<int, t>& std_arr)
    {
        for (int i = 1; i <= t; i++)
        {
            std_arr[i] = i++;
        }
    }
    void clearTime()
    {
        startTime = 0;
        endTime = 0;
        m_freqCount = 0;
    }
};

