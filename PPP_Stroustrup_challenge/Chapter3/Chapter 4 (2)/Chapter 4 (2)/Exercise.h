#pragma once
#include "Word_Calculator.h"
#include "myVector.h"
#include "Quadratic_formula.h"

class Exercise
{
public: 
	void runExercises();
	void exercise_6();
	void exercise_11();
	bool find_prime(int n);
	void exercise_18();
	void exercise_19();

	Word_Calculator wc;
	myVector<int> IVector;
	Quadratic_formula qf;
	myVector<string> names;
	myVector<int> scores;
	
};

