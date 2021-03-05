#include <string>
#include <iostream>
#include <vector>
#include "Drill.h"

using namespace std;

namespace Book_shelf
{
	
	/*
	//=== year class for copyright_date member of class book ===//
	class Year
	{
		static const int min = 1970;	// ISBN started in this year
		static const int max = 2050;	
	public:
		Year(int x);
		int year() const { return y; }
	private:
		int y;
	};*/

	enum class Genre
	{
		fiction = 0, nonfiction, periodical, biography, children
	};
	
	class Book
	{
	public:
		Book(string ISBN, string title, string author, int copyright_date, Genre genre);
		
		// non-modifying operations
		string getISBN() const { return m_ISBN; }
		string getTitle() const { return m_title; }
		string getAuthor() const { return m_author; }
		int getCopyright_date() const { return m_copyright_date; }
		bool getChecked_out() const { return m_avail; }
		Genre getGenre() const { return m_genre; }

		// modifying operations
		void setCheck_out() { m_avail = false;}
		void setCheck_in() { m_avail = true; }
		void setGenre(Genre genre) { m_genre = genre; }
		void setISBN(string ISBN) { m_ISBN = ISBN; }
		void setTitle(string title) { m_title = title; }
		void setAuthor(string author) { m_author = author; }
		void setCopyright_date(int copyright) { m_copyright_date = copyright; }

	private:
		string m_ISBN;
		string m_title;
		string m_author;
		int m_copyright_date;
		bool m_avail = true;
		Genre m_genre;
	};

	
	//=== helper functions ===//
	bool is_ISBN(const string& ISBN);
	bool is_checked_out(const Book& book);

	void check_in_out(Book& book);

	

	//=== Operators ===//
	ostream& operator<<(ostream& os, const Book& book);
	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);
	ostream& operator<<(ostream& os, const Genre genre);
}
