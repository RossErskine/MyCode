#include "Book_shelf.h"
#include "Customer.h"
#include "Chrono.h"
#include <vector>

using namespace std;
using namespace Book_shelf;
using namespace Customer;
using namespace Chrono;

namespace Athenaeum
{
	struct Transaction
	{
		Book s_book;
		Patron s_patron;
		Date s_date;
		Transaction(Book book, Patron patron, Date date);
	};

	class Library
	{
	public:
		Library();

		//===non-modifying operations===//
		vector<Book> getBooks() const { return m_books; }
		vector<Patron> getPatrons() const { return m_patrons; }
		vector<Transaction> getTransactions() const { return m_transactions; }

		//=== modifying operations ===//
		void addBooks(Book& book);
		void addPatrons(Patron& pat);
		void addTransactions(Transaction& trans);
	private:
		vector<Book> m_books;
		vector<Patron> m_patrons;
		vector<Transaction> m_transactions;
	};

	const char prompt = '>';
	//===helper functions===//
	bool check_patron_details(Patron& pat);
	bool check_book_in_out(Book& book, Patron& pat);
	vector<Patron> fees_owed(Library& library);

	//=== operators ===//
	ostream& operator<<(ostream& os, const Transaction& tr);
}
