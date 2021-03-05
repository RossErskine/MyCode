#include "Chrono.h"
#include <iostream>
using namespace Chrono;

int main()
{
    try
    {
        Date today = { 2020,Month::jul,11 };
        cout << today.getZero() << endl;

        //Date test = { 1969,Month::jul,7 };    // test constructor

        cout << day_one_year(today);
        Date test2 = { 2021,Month::jul,11 };
        cout << day_one_year(test2);
    }
    catch (const char* msg)
    {
        cerr << msg << endl;

    }
}

