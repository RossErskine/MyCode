#pragma once
#include <vector>
#include <string>
#include "Name_value.h"
#include "EnglishGrammer.h"

using namespace std;

//====declarations=====//

//display vector
template <typename T>
void displayVec(vector<T> v)
{
	for (int i = 0; i != v.size(); i++)
	{
		cout << v[i] << '\t';
	}
	cout << endl;
}

void exercise_3()
{
	string t_name;
	int t_val;
	bool play = true;
	vector<Name_value> nv;

	cout << "Please write name and score: " << endl;
	cout << "Finish with 'stop' " << endl;

	while (play == true)
	{
		cin >> t_name >> t_val;
		if (!cin)
		{
			throw "\nunrecognised input";
		}
		if (t_name != "stop")
		{
			for (Name_value NV : nv)
			{
				if (NV.m_name == t_name)
				{
					throw "Name already taken! ";
				}
			}
			nv.push_back(Name_value{ t_name, t_val });
		}
		else {
			play = false;
		}
			
	}
	for (Name_value NV : nv)
		cout << NV.m_name << ": (" << NV.m_value << ")" << endl;
		
	
}

void exercise_6()
{
	Word w;
	w.is_noun();
	
}
void runExercises()
{
	//exercise_3();
	exercise_6();
}
