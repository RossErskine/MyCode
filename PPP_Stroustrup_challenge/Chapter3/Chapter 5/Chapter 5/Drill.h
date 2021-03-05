#pragma once
#include <iostream>

using namespace std;

int drill() 
{
    try {
        //1) "capital C"
        //cout << "Success!\n";
        //2) missing "
        //cout << "Success!\n";
        //3) << and inside brackets and no ;
        //cout << "success  \n";
        //4) no ""
        //cout << "success" << '\n';
        //5) res  cannot be a string
        /*int res = 7;
        vector<int>v(10);
        v[5] = res;
        cout << "Success!\n";*/
        //6) changesd () - [] and ! =
        /*vector<int>v(10);
        v[5] = 7;
        if (v[5] == 7)
            cout << "Success!\n";*/
            //7) declare cond
            /*if (bool cond = true)
                cout << "Success!\n";
            else
                cout << "fail!\n";*/
                //8) if statement had no condition
                /*bool c = false;
                if (c == false)
                    cout << "Success!\n";
                else
                    cout << "Fail!\n";*/
                    //9) bool to string change condition in if statement
                    /*string s = "ape";
                    string c = "fool" ;
                    if (c > s)
                        cout << "Success!\n";*/
                        //10)  changed '=' to '!'
                        /*string s = "ape";
                        if (s != "fool")
                            cout << "Success!\n";*/
                            //11) missing < changed = to !
                            /*string s = "ape";
                            if (s != "fool")
                                cout << "Success!\n";*/
                                //12) swap + for !=
                                /*string s = "ape";
                                if (s != "fool")
                                    cout << "Success!\n";*/
                                    //13) swap 0 for i
                                    /*vector<char>v(5);
                                    for (int i = 0; i < v.size(); ++i);
                                    cout << "Success!\n";*/
                                    //14) take out =
                                    /*vector<char>v(5);
                                    for (int i = 0; i < v.size(); ++i);
                                    cout << "Success!\n";*/
                                    //15) change 6 to 8
                                    /*string s = "Success!\n";
                                    for (int i = 0; i < 8; ++i)
                                        cout << s[i];*/
                                        //16) remove "then"
                                        /*if (true)
                                             cout << "Success!\n";
                                        else
                                            cout << "Fail!\n";*/
                                            //17)swap char to int
                                            /*int x = 2000;
                                            int c = x;
                                            if (c == 2000)
                                                cout << "Success!\n";*/
                                                //18) swap 10 t0 8
                                                /*string s = "Success!\n";
                                                for (int i = 0; i < 8; ++i)
                                                    cout << s[i];*/
                                                    //19)declare <char> and reduce size to 1
                                                    /*vector<char> v(1);
                                                    for (int i = 0; i < v.size(); ++i)
                                                        cout << "Success!\n";*/
                                                        //20)
                                                        /*int i = 0;
                                                        int j = 9;
                                                        while (i < 10)
                                                            ++i;
                                                        if (j < i)
                                                            cout << "Success!\n";*/
                                                            //21)change int to double and == to >=
                                                            /*double x = 2;
                                                            double d = 5 / (x - 2);
                                                            if (d >= 2 * x + 0.5)
                                                                cout << "Success!\n";*/
                                                                //22)delete <char> and change 10 to 8
                                                                /*string s = "Success!\n";
                                                                for (int i = 0; i <= 8; ++i)
                                                                    cout << s[i];*/
                                                                    //23) declare j =9 and change j to i and 0 to 10
                                                                    /*int i = 0;
                                                                    int j = 9;
                                                                    while (i < 10)
                                                                        ++i;
                                                                    if (j < i)
                                                                        cout << "Success!\n";*/
                                                                        //24)change int to double
                                                                        /*double x = 4;
                                                                        double d = 5 / (x - 2);
                                                                        if (d = 2 * x + 0.5)
                                                                            cout << "Success!\n";*/
                                                                            //25)change cin to cout
        cout << "Success!\n";





        return 0;
    }
    catch (out_of_range) {
        cerr << "Oops! range error\n";
        return 1;
    }
    catch (...) {
        cerr << "Exception: something went wrong\n";
        return 2;
    }
}
