#include "Athenaeum.h"
#include <iostream>

namespace Athenaeum
{
	//=== Member functions ===//
	Library::Library()
	{
	}

	Transaction::Transaction(Book book, Patron patron, Date date) 
		: s_book{book}, s_patron{patron}, s_date{date}
	{
	}

	void Library::addBooks(Book& book)
	{
		m_books.push_back(book);
	}

	void Library::addPatrons(Patron& pat)
	{
		m_patrons.push_back(pat);
	}

	void Library::addTransactions(Transaction& trans)
	{
		m_transactions.push_back(trans);
	}
	//=== Helper functions ===//
	bool check_book_in_out(Book& book, Patron& pat)
	{
		
		if (check_patron_details(pat))
		{
			if (is_checked_out(book))
			{
				char ans;
				cout << '\n' << book.getTitle() << ": is available!\n"
					<< "Would you like to check this book out? (y/n): ";
				cin >> ans;

				switch (ans)
				{
				case 'y':
					if (has_lib_fees(pat))
					{
						cout << pat.getName() << ": has outsatnding fees of $" << pat.getLibrary_fees();
						throw "fees must be paid first!";
					}
					else
					{
						book.setCheck_out();
						return true;
						cout << book.getTitle() << " is checked out!" << endl;
					}
					break;
				case 'n':
					cout << " Thank you & goodbye!" << endl;
					return false;
					break;
				default:
					throw "y or n required!";
				}
			}
			else
			{
				char ans;
				cout << "\nSorry " << book.getTitle() << ": is unavailable! \n"
					<< "Would you like to check this book in? (y/n): ";
				cin >> ans;

				switch (ans)
				{
				case 'y':
					book.setCheck_in();
					cout << book.getTitle() << " is checked in!" << endl;
					return false;
					break;
				case 'n':
					cout << " Thank you & goodbye! " << endl;
					return false;
					break;
				default:
					throw "y or n required!";
				}

			}
			return false;
		}
		else
		{
			throw "User details not found";
		}
		return false;


	}
	
	bool check_patron_details(Patron& pat)
	{
		int t_card_num= 0, count = 0;
		while (count < 3)
		{
			cout << pat.getName() << ": please enter your Library card number: " << endl;
			cout << prompt;
			cin >> t_card_num;
			if (!cin)throw "check_patron_details: wrong input!";
			if (pat.getLibrary_card_num() != t_card_num)
			{
				cerr << " number entered does not match our records, try again!" << endl;
				++count;
			}
			else
			{
				return true;
			}
		}
		return false;
		
	}

	vector<Patron> fees_owed(Library& library)
	{
		vector<Patron> pat = library.getPatrons();
		vector<Patron> owed_fees;
		for (int i = 0; i != pat.size(); ++i)
		{
			Patron temp = pat[i];
			if(has_lib_fees(temp))
			{
				owed_fees.push_back(temp);
			}
		}
		return owed_fees;
	}

	//=== operators ===//
	ostream& operator<<(ostream& os, const Transaction& tr)
	{
		return os << tr.s_patron << ": \n"
			<< tr.s_book << ": \n"
			<< tr.s_date;
	}
	
}