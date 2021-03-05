//#include "Exercises.h"
#include "Book_shelf.h"
#include "Customer.h"

void exercise_5_6()
{
	using namespace Book_shelf;
	using namespace Customer;

	Book book1 = { "0321992784","Programming principles and pracice", "Bjarne Stroustrup",2004,Genre::nonfiction };
	Book book2 = book1;
	if (book2 == book1)cout << "Operator(==): test pass" << endl;
	Book book3 = { "0134997832", "A Tour of C++", "Bjarne Stroustrup", 2018, Genre::nonfiction };
	if (book3 != book1) cout << "Operator(!=): test pass" << endl;

	cout << '\n' << book1 << endl;
	cout << '\n' << book3 << endl;
	book1.setCopyright_date(2014);
	cout << '\n' << book1 << endl;

	check_in_out(book1);
	check_in_out(book1);
	check_in_out(book1);

	Patron pat = { "Mike The Monkey", 1234 };
	pat.setLibrary_fees(1.00);
	if (has_lib_fees(pat))
	{
		cout << pat.getName() << "'s has $" << pat.getLibrary_fees() << " outstanding " << endl;
	}
	else
	{
		cout << pat.getName() << "'s has no fees outstanding! " << endl;
	}



}
int main()
{
	try
	{
		exercise_5_6();
		//runExercises();
		return 0;
	}
	catch (const char* msg)
	{
		cerr << msg << endl;

	}
	catch (...)
	{
		cerr << "exception\n";
	}
		
}

