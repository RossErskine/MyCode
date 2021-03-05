#include "Book_shelf.h"

namespace Book_shelf
{
	//=== Member functions  ===//
	Book::Book(string ISBN, string title, string author, int copyright_date, Genre genre)
		: m_ISBN{ ISBN }, m_title{ title }, m_author{ author }, m_copyright_date{ copyright_date }, m_genre {genre}
	{
		if (!is_ISBN(ISBN)) throw "constructor: not compatible ISBN number!";
	}
	
	//=== Helper functions ===//
	bool is_ISBN(const string& ISBN)	//checks ISBN number 
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
	bool is_checked_out(const Book& book)	//checks avilability of book
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
	//=== operators ===//
	ostream& operator<<(ostream&  os, const Genre genre)
	{
		vector<string> genre_tbl = { "fiction","nonfiction","periodic","biography","children" };
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