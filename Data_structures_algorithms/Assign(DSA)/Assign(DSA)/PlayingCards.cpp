#include "PlayingCards.h"
#include "Vector.h"
#include "Shuffle.h"
#include "Bubble_Sort.h"
#include "Merge.h"
#include "Binary_search.h"

#include <iostream>
#include <unordered_map>
#include <time.h>

using namespace std;

//==========declorations============//
myVector<string> vc;
Shuffle<string> sh;
Bubble_Sort<string> bs;
Merge<string> mg;
Binary_search<string> bns;

void PlayingCards::create_newDeck()
{
	t_newDeck1 = mg.merge_vectors(m_clubs, m_diamonds);
	t_newDeck2 = mg.merge_vectors(m_hearts, m_spades);
	newDeck = mg.merge_vectors(t_newDeck1, t_newDeck2);
	cout << "new deck created: " << endl;
	//vc.display_vec(newDeck);
}

void PlayingCards::dealHands()
{
	//===========deal hands============//
	// == "back"points to last element in new deck and"push_back" coppies it into players hand ==//
	//== "pop_back" deletes last element in newDeck ==//
	playersHand.push_back(newDeck.back());
	newDeck.pop_back();
	computersHand.push_back(newDeck.back());
	newDeck.pop_back();
	playersHand.push_back(newDeck.back());
	newDeck.pop_back();
	computersHand.push_back(newDeck.back());
	newDeck.pop_back();
	playersHand.push_back(newDeck.back());
	newDeck.pop_back();
	computersHand.push_back(newDeck.back());
	newDeck.pop_back();
	playersHand.push_back(newDeck.back());
	newDeck.pop_back();
	computersHand.push_back(newDeck.back());
	newDeck.pop_back();
	playersHand.push_back(newDeck.back());
	newDeck.pop_back();
	computersHand.push_back(newDeck.back());
	newDeck.pop_back();
}

void PlayingCards::play()
{
	int rnd = 0;
	srand((unsigned int)time(NULL));
	//=======new deck===========//
	create_newDeck();
	//cout << "new deck:" << endl;
	//vc.display_vec(newDeck);
	//============shuffle deck=======//
	sh.std_shuffle(newDeck);
	cout << "\nshuffled Deck " << endl;
	//vc.display_vec(newDeck);

	while (rnd < 5)
	{
		cout << "\nround: " << rnd + 1 << endl;
		
		//======= deal hands=============//
		dealHands();

		/*cout << "\nplayers hand " << endl;
		vc.display_vec(playersHand);
		cout << "\ncomputers hand " << endl;
		vc.display_vec(computersHand);
		cout << "\n Deck:" << endl;
		//vc.display_vec(newDeck);
		cout << "new deck size: " << newDeck.size() << endl;*/
		//== sort players hand ==//
		cout << " players sorted hand " << endl;
		bs.bubble_sort(playersHand);
		vc.display_vec(playersHand);

		cout << " computers sorted hand " << endl;
		bs.bubble_sort(computersHand);
		vc.display_vec(computersHand);

		handValue(playersHand, computersHand);
		//handValue(computersHand);
		//bns.binarySearch(m_clubs, 0, m_clubs.size() - 1, playersHand[0]);
		rnd++;
		clear();
	}
}

void PlayingCards::handValue(vector<string> ply_hnd, vector<string> com_hnd)
{
	
	//myVector<int> ivc;
	for (int i = 0; i != ply_hnd.size(); ++i)
	{
		for (int j = 0; j <= 12; ++j) {
			
			if (ply_hnd[i] == m_clubs[j]) { t_ply_hnd.push_back(j+1); }
			if (ply_hnd[i] == m_diamonds[j]) { t_ply_hnd.push_back(j+1); }
			if (ply_hnd[i] == m_hearts[j]) { t_ply_hnd.push_back(j+1); }
			if (ply_hnd[i] == m_spades[j]) { t_ply_hnd.push_back(j+1); }
		}
	}
	//cout << crd2 << endl;
	//ivc.display_vec(t_ply_hnd);
	for (int i = 0; i != com_hnd.size(); ++i)
	{
		for (int j = 0; j <= 12; ++j) {

			if (com_hnd[i] == m_clubs[j]) { t_com_hnd.push_back(j+1); }
			if (com_hnd[i] == m_diamonds[j]) { t_com_hnd.push_back(j+1); }
			if (com_hnd[i] == m_hearts[j]) { t_com_hnd.push_back(j+1); }
			if (com_hnd[i] == m_spades[j]) { t_com_hnd.push_back(j+1); }
		}
	}
	//ivc.display_vec(t_com_hnd);
	cardsValue(t_ply_hnd, t_com_hnd);
	//checkPairs(t_ply_hnd);
}

void PlayingCards::cardsValue(vector<int> ply_hnd, vector<int> com_hnd)
{
	bool ply = false, com = false;
	cout << "players hand has:";
	ply = checkPlyHnd(ply_hnd);
	
	cout << "computers hand has: ";
	com = checkComHnd(com_hnd);

	if ((ply == true) && (com == false))
	{
		cout << "player wins" << endl;
	}
	if ((ply == false) && (com == true))
	{
		cout << "computer wins" << endl;
	}

	if ((ply == true) && (com == true)) 
	{

	}
}

bool PlayingCards::checkPlyHnd(vector<int> vec)
{
	unordered_map<unsigned, size_t> counts;
	//int cardcount;
	
	for (int i : vec)
	{
		++counts[i];
		for (auto const& p : counts)
		{
			if (counts[i] != 0)
			{
				if (counts[i] == 2)
				{
					//cout << counts[i] << endl;
					p_pair = true;
				}
				else if (counts[i] == 3)
				{
					cout << counts[i] << endl;
					p_pair = false;
					p_three_kind = true;
				}
				else if (counts[i] == 4)
				{
					cout << counts[i] << endl;
					p_three_kind = false;
					p_four_kind = true;
				}
				
			}
			
		}
	}
	if (p_pair == true)
	{
		cout << " pair" << endl;
	}
	if (p_three_kind == true)
	{
		cout << " pair" << endl;
	}
	if (p_four_kind == true)
	{
		cout << " pair" << endl;
	}
	if ((p_pair == true) && (p_three_kind == true))
	{
		p_full_house = true;
		cout << " full house!" << endl;
	}
	if ((p_pair == true) || (p_three_kind == true) || (p_four_kind == true) || (p_full_house == true))
	{
		return true;
	}
	else {
		cout << "nothing " << endl;
		return false;
	}
}
bool PlayingCards::checkComHnd(vector<int> vec)
{
	unordered_map<unsigned, size_t> counts;
	//int cardcount;
	
	for (int i : vec)
	{
		++counts[i];
		if (counts[i] != 0)
		{
			if (counts[i] == 2)
			{
				c_pair = true;
			}
			if (counts[i] == 3)
			{
				c_pair = false;
				c_three_kind = true;	
			}
			if (counts[i] == 4)
			{
				c_three_kind = false;
				c_four_kind = true;	
			}
		}	
	}
	if (c_pair == true)
	{
		cout << " pair" << endl;
	}
	if (c_three_kind == true)
	{
		cout << " pair" << endl;
	}
	if (c_four_kind == true)
	{
		cout << " pair" << endl;
	}
	if ((c_pair == true) && (c_three_kind == true))
	{
		c_full_house = true;
		cout << " full house!" << endl;
	}
	if ((c_pair == true) || (c_three_kind == true) || (c_four_kind == true) || (c_full_house == true))
	{
		return true;
	}
	else {
		cout << "nothing " << endl;
		return false;
	}
}
void PlayingCards::clear()
{
	playersHand.clear();
	computersHand.clear();
	t_ply_hnd.clear();
	t_com_hnd.clear();

	bool p_pair = false;
	bool p_three_kind = false;
	bool p_four_kind = false;
	bool p_full_house = false;

	bool c_pair = false;
	bool c_three_kind = false;
	bool c_four_kind = false;
	bool c_full_house = false;
}
/*bool PlayingCards::checkStraight(vector<int> vec)
{

}
bool PlayingCards::checkFullHouse(vector<int> vec)
{

}*/