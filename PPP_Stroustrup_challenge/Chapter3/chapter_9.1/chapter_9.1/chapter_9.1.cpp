#include "Athenaeum.h"
#include "Rational.h"
#include "Money.h"


void exercise_5_to_9()
{
	using namespace Book_shelf;
	using namespace Customer;
	using namespace Chrono;
	using namespace Athenaeum;

	Library library;	//== create library ==//
	Date today = { 2020,Month::jun,30 };
	
	//== create and add books to library ==//
	Book book1 = { "0321992784","Programming principles and pracice", "Bjarne Stroustrup",2004,Genre::nonfiction };
	library.addBooks(book1);
	Book book2 = { "0134997832", "A Tour of C++", "Bjarne Stroustrup", 2018, Genre::nonfiction };
	library.addBooks(book2);

	//== create and add Patrons to libary ==//
	Patron pat1 = { "Mike the Monkey", 123 };
	library.addPatrons(pat1);
	Patron pat2 = { "Leo the Lion", 456 };
	pat2.setLibrary_fees(1.00);
	library.addPatrons(pat2);
	Patron pat3 = { "Zoe the Zebbra", 789 };
	pat3.setLibrary_fees(2.00);
	library.addPatrons(pat3);
	

	if (check_book_in_out(book1, pat1))
	{
		Transaction tr1 = { book1,pat1,today };
		library.addTransactions(tr1);
	}
	if (check_book_in_out(book2, pat1))
	{
		Transaction tr2 = { book2,pat1,today };
		library.addTransactions(tr2);
	}
	vector<Transaction> tempTran = library.getTransactions();
	cout << "\nlatest transactions are: " << endl;
	for (Transaction t : tempTran)
	{
		cout << t << endl << endl;
	}

	
	vector<Patron> temp = fees_owed(library);
	cout << "\nPatrons owing Fess are:" << endl;
	for (Patron p : temp)
	{
		cout << p.getName() << '\t';
	}
	cout << '\n' << endl;

}

void exercise_10()
{
	int year = 2000;
	if (leapyear(year))
		cout << "is Leap year\n";
	else
		cout << "is not leap year\n";
}

void exercise_11()
{
	Date today = { 2020,Month::jul,7 };
	cout <<today << "day is: "<< day_of_week(today) << endl;
	Date nextWrkDy = next_workday(today);
	cout << "next work day is: " << nextWrkDy << " which is a " << day_of_week(nextWrkDy) << endl;
	int firstWeek = getWeekOne(today);
	cout << "first week is: " << firstWeek << endl;
	cout << "Week number is: " << week_of_year(today) << endl;
}
void test()
{
	Date zero = { 1970,Month::jan,1 };
	cout << day_of_week(zero) << endl;

}
void exercise_13()
{
	using namespace _Rational;
	Rational rat1 = { 2,5 };
	Rational rat2 = { 3,6 };

	Rational ans1 = rat1 *= rat2;
	cout << rat1 << " * " << rat2 << "= " << simplify(ans1);

	Rational ans2 = rat1 /= rat2;
	cout <<'\n'<< rat1 << " / " << rat2 << "= " << simplify(ans2);

	Rational ans3 = rat1 += rat2;
	cout << '\n' << rat1 << " + " << rat2 << "= " << simplify(ans3);

	Rational ans4 = rat1 -= rat2;
	cout << '\n' << rat1 << " - " << rat2 << "= " << simplify(ans4);

	
}

void exercise_14()
{
	using namespace _Money;
	Money myMoney = { 5,75 };
	cout << myMoney << endl;
	myMoney.addMoney(2, 5);
	cout << myMoney << endl;
}
int main()
{
	try
	{
		//exercise_5_to_9();
		//exercise_10();
		//exercise_11();
		//test();
		//exercise_13();
		exercise_14();
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



