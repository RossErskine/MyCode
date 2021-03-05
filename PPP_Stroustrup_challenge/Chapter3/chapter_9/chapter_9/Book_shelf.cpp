#include "Book_shelf.h"

namespace Book_shelf
{
	//=== Member functions for Book, Year & Patron ===//
	Book::Book(string ISBN, string title, string author, int copyright_date, Genre genre)
		: m_ISBN{ ISBN }, m_title{ title }, m_author{ author }, m_copyright_date{ copyright_date }, m_genre {genre}
	{
		if (!is_ISBN(ISBN)) throw "constructor: not compatible ISBN number!";
	}
	
	//=== Helper functions for Book, Year & Patron===//
	bool is_ISBN(const string& ISBN)
	{
		int n = ISBN.length();
		if (n != 10)
		{
			cerr << "is_ISBN: not long enougth \n";
			return false;
		}

		for (int i = 0; i != ISBN.length() -1; ++i)
		{
			if (isalpha(ISBN[i]))
			{
				cerr << "is_ISBN: digits needed in first 9\n";
				return false;
			}
		}

		char last = ISBN[9];
		if (last != 'x' && (last < '0' || last > '9'))
		{
			cerr << "is_ISBN: last digit not an x or number\n";
			return false;
		}

		return true;
	}

	bool is_checked_out(const Book& book)
	{
		if (book.getChecked_out() == true)
		{
			return true;
		}
		else 
		{
			return false;
		}

	}

	void check_in_out(Book& book)
	{
		//Book bk;
		if (is_checked_out(book))
		{
			char ans;
			cout << '\n' << book.getTitle() << ": is available!\n"
				<< "Would you like to check this book out? (y/n): ";
			cin >> ans;
			
			switch (ans)
			{
			case 'y':
				book.setCheck_out();
				cout << book.getTitle() << " is checked out!" << endl;
				break;
			case 'n':
				cout << " Thank you & goodbye!" << endl;
				return;
				break;
			default:
				throw "y or n required!";
			}
		}
		else
		{
			char ans;
			cout << "\nSorry " << book.getTitle()<< ": is unavailable! \n" 
				<< "Would you like to check this book in? (y/n): ";
			cin >> ans;
			
			switch (ans)
			{
			case 'y':
				book.setCheck_in();
				cout << book.getTitle() << " is checked in!" << endl;
				break;
			case 'n':
				cout << " Thank you & goodbye! " << endl;
				return;
				break;
			default:
				throw "y or n required!";
			}
			
		}
		
	}

	
	//=== operators ===//
	
	ostream& operator<<(ostream&  os, const Genre genre)
	{
		vector<string> genre_tbl = { "fiction","nonfiction","periodic","biography","children" };	// needs moving back to library.h
		return os << genre_tbl[int(genre)];
	}
	ostream& operator<<(ostream& os, const Book& book)
	{
		return os << "ISBN: " << book.getISBN()
			<< "\nTitle: " << book.getTitle()
			<< "\nAuthor: " << book.getAuthor()
			<< "\nCopyright: " << book.getCopyright_date()
			<< "\nGenre: " << book.getGenre();

	}

	bool operator==(const Book& a, const Book& b)
	{
		return a.getISBN() == b.getISBN();
	}

	bool operator!=(const Book& a, const Book& b)
	{
		return !(a.getISBN() == b.getISBN());
	}
	
	

}