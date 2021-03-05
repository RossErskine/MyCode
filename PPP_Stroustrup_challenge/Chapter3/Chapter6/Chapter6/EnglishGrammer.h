#pragma once
#include <iostream>
#include <vector>


using namespace std;

class Word
{
public:
	vector<string> article = { "the" };
	vector<string> conjunction = { "and","or","but" };
	vector<string> noun = { "birds","fish","C++" };
	vector<string> verb = { "rules", "fly", "swim" };
	
	void is_noun();
	void is_verb();
	void is_conjunction();
};


void Word::is_noun()
{
	Word w;
	string wn1;
	cin >> wn1;
	for (int i = 0; i != noun.size(); ++i)
	{
		if (wn1 == noun[i])
		{
			w.is_verb();
		}
		
	}
	
}

void Word::is_verb()
{
	Word w;
	string wv1;
	cin >> wv1;
	for (int i = 0; i != verb.size(); ++i)
	{
		if (wv1 == verb[i])
		{
			w.is_conjunction();
		}
		
	}
	
}
void Word::is_conjunction()
{
	Word w;
	string wc1;
	cin >> wc1;
	for (int i = 0; i != conjunction.size(); ++i)
	{
		if (wc1 == conjunction[i])
		{
			w.is_noun();
		}
		else if (wc1 == ".")
		{
			throw "sentence ok!";
		}
		
	}
	
}
	
