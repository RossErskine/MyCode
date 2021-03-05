#pragma once
#include <vector>
#include <string>

using namespace std;

class PlayingCards
{
private:
	
	
	vector<string> m_hearts = { "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH" };
	vector<string> m_spades = { "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS" };
	vector<string> m_diamonds = { "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD" };
	vector<string> m_clubs = { "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC" };


	vector<string> t_newDeck1;
	vector<string> t_newDeck2;
	vector<string> newDeck;
	vector<string> playersHand;
	vector<string> computersHand;
	vector<int> t_ply_hnd;
	vector<int> t_com_hnd;

	bool p_pair = false;
	bool p_three_kind = false;
	bool p_four_kind = false;
	bool p_full_house = false;

	bool c_pair = false;
	bool c_three_kind = false;
	bool c_four_kind = false;
	bool c_full_house = false;
public:
	

	void handValue(vector<string> ply_hnd, vector<string> com_hnd);
	void cardsValue(vector<int> ply_hnd, vector<int> com_hnd);
	bool checkPlyHnd(vector<int> vec);
	bool checkComHnd(vector<int> vec);
	//bool checkStraight(vector<int> vec);
	//bool checkFullHouse(vector<int> vec);
	void create_newDeck();
	void dealHands();
	void play();
	void clear();
};

