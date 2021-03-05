#include "Exercise.h"

#include <string>

using namespace std;

void Exercise::runExercises()
{
	//exercise_6();
	//exercise_11();
	exercise_18();
	//exercise_19();
}

void Exercise::exercise_6()
{
	string t_val1, t_val2, t_val3;

	cout << "write a sum:  " << endl;
	cin >> t_val1 >> t_val2 >> t_val3;
	wc.findFirstWord(t_val1);
	wc.findExp(t_val2);
	wc.findSeocndWord(t_val3);
	wc.GetSum();
	
}


void Exercise::exercise_11()
{
	
	IVector.add_vec(2);
	for (int i = 3; i < 100; ++i)
	{

		find_prime(i);
		if (find_prime(i))
		{
			IVector.add_vec(i);
		}

	}
	IVector.display_vec();
}
bool Exercise::find_prime(int n)
{
	for (int i = 0; i < IVector.vec_size(); ++i)
	{
		if (n % IVector.GetVec(i) == 0) {
			return false;
		}

	}return true;
}

void Exercise::exercise_18()
{
	double t_a, t_b, t_c;
	cout << "Enter Quadratic Formula: A, B & C " << endl;
	cin >> t_a >> t_b >> t_c;
	qf.quad_Ans_plus(t_a, t_b, t_c);
	qf.quad_Ans_minus(t_a, t_b, t_c);
	cout << "+X = " << qf.GetPlusX() << endl;
	cout << "-X = " << qf.GetMinusX() << endl;
}

void Exercise::exercise_19()
{
	string t_name;
	int t_score;
	bool play = true;
	while (play == true)
	{
		cout << "please write name and score: " << endl;
		cin >> t_name >> t_score;
		if (t_name == "Q")
		{
			play = false;
		}
		else {
			for (int i = 0; i < scores.vec_size(); i++)
			{
				if (t_name == names.GetVec(i))
				{
					cout << " sorry that name is taken!" << endl;
					play = false;
				}
			}
			names.add_vec(t_name);
			scores.add_vec(t_score);

		}

	}
	for (int i = 0; i < scores.vec_size(); i++)
	{
		cout << names.GetVec(i) << '\t';
		cout << scores.GetVec(i) << '\t';
	}

	//====exercise 20 - 21 ===========//
	int menu, score, count = 0;
	string name;
	bool play2 = true;
	while (play2 == true)
	{
	
		cout << " \nmenu: 1 = names, 2 = scores, 0 = quit " << endl;
		cin >> menu;
		switch (menu)
		{
		case 0:
			play2 = false;
		case 1:
			cout << "what name please:" << endl;
			cin >> name;

			for (int i = 0; i < scores.vec_size(); i++)
			{
				if (name == names.GetVec(i))
				{
					count++;
					cout << names.GetVec(i) << '\t';
					cout << scores.GetVec(i) << '\t';
				}

			}
			if (count == 0) {
				cout << " no names found" << endl;
			}

			break;
		case 2:
			cout << "what score please:" << endl;
			cin >> score;

			for (int i = 0; i < scores.vec_size(); i++)
			{
				if (score == scores.GetVec(i))
				{
					count++;
					cout << names.GetVec(i) << '\t';
					cout << scores.GetVec(i) << '\t';
				}

			}
			if (count == 0) {
				cout << " no scores found" << endl;
			}
			break;
		default:
			cout << "sorry try again " << endl;
			break;

		}
	}
}