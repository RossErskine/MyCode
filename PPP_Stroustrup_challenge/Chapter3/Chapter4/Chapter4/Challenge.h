#pragma once
#include "MyValue.h"
#include "DoubleValue.h"
#include "LastDouble.h"
#include "DoubleVec.h"
#include "Currency.h"
#include "Sentence.h"

class Challenge
{
private:
	MyValue m_Value;
	DoubleValue m_Dvalue;
	LastDouble m_lastVal;
	DoubleVec m_DoubleVec;
	Currency m_Currency;
	Sentence m_Sentence;

	void Drill_1();
	void Drill_2();
	void Drill_4();
	void Drill_6();
	void Exercise_1();
	void TryThis();
	void bleep();
public:
	void RunChallenges();
};

