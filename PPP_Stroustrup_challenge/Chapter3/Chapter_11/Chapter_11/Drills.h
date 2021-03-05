#include <iostream>
#include <iomanip>

void tryThis()
{
	std::cout << 1234 << '\t' << std::hex << 1234 << '\t' << std::oct << 1234 << '\n';
	std::cout << std::showbase << std::dec;
	std::cout << 1234 << '\t' << std::hex << 1234 << '\t' << std::oct << 1234 << '\n';

	std::cout << 1234567.89 << '\t'
		<< std::fixed << 1234567.89 << '\t'
		<< std::scientific << 1234567.89 << '\n';
	std::cout << std::defaultfloat << std::setprecision(5)
		<< 1234.56789 << '\t'
		<< std::fixed << 1234.56789 << '\t'
		<< std::scientific << 1234.56789 << '\n';
	std::cout << std::defaultfloat << std::setprecision(8)
		<< 1234.56789 << '\t'
		<< std::fixed << 1234.56789 << '\t'
		<< std::scientific << 1234.56789 << '\n';

	std::cout << "---------------------------------------------------------" << '\n';
	std::cout << '|' << std::setw(10) << "First name" <<
		'|' << std::setw(10) << "Last Name" <<
		'|' << std::setw(12) << "Phone number" <<
		'|' << std::setw(20) << "Email address" << '|' << '\n';
	std::cout << "---------------------------------------------------------" << '\n';
	std::cout << '|' << std::setw(10) << "Dave" <<
		'|' << std::setw(10) << "Henderson" <<
		'|' << std::setw(12) << "0788997766" <<
		'|' << std::setw(20) << "dv@yahoo.co.uk" << '|' << '\n';
	std::cout << '|' << std::setw(10) << "Zoe" <<
		'|' << std::setw(10) << "Metcarf" <<
		'|' << std::setw(12) << "0707080995" <<
		'|' << std::setw(20) << "ZF@Gmail.co.uk" << '|' << '\n';
	std::cout << '|' << std::setw(10) << "Frank" <<
		'|' << std::setw(10) << "Smith" <<
		'|' << std::setw(12) << "0707080996" <<
		'|' << std::setw(20) << "frank@Gmail.co.uk" << '|' << '\n';
	std::cout << '|' << std::setw(10) << "Paul" <<
		'|' << std::setw(10) << "Hunter" <<
		'|' << std::setw(12) << "0777567990" <<
		'|' << std::setw(20) << "Hunter@Gmail.co.uk" << '|' << '\n';
	std::cout << '|' << std::setw(10) << "Henry" <<
		'|' << std::setw(10) << "Strenstrom" <<
		'|' << std::setw(12) << "0707080977" <<
		'|' << std::setw(20) << "strenty@Gmail.co.uk" << '|' << '\n';
	std::cout << "---------------------------------------------------------" << '\n';
}

void test_output()
{
	int birth_year = 1982;
	int age = 38;
	std::cout << "-----------------------------" << std::endl;
	std::cout << '|' << std::setw(12) << "Base" << '|' << std::setw(8) << "Year" << "|" << std::setw(5) << "Age" << '|' << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << '|' << std::setw(12) << "Decimal" << '|' << std::setw(8) << std::dec << birth_year << "|" << std::setw(5) << age << '|' << std::endl;
	std::cout << '|' << std::setw(12) << "Hexadecimal" << '|' << std::setw(8) << std::hex << birth_year << "|" << std::setw(5) << age << '|' << std::endl;
	std::cout << '|' << std::setw(12) << "Octal" << '|' << std::setw(8) << std::oct << birth_year << "|" << std::setw(5) << age << '|' << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

void messing()
{
	std::cout << "Enter numbers on seperate lines to add. "
		<< "Use contol+z to finish. " << std::endl;
	int sum = 0;

	if (!std::cin.good())
	{
		std::cerr << "Standard input is in a bad state! " << std::endl;
		return;
	}
	int number;
	while (!std::cin.bad())
	{
		std::cin >> number;
		if (std::cin.good())
		{
			sum += number;
		}
		else if(std::cin.eof())
		{
			break;
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::string bad_Token;
			std::cin >> bad_Token;
			std::cerr << "WARNING: bad input encountered: " << bad_Token << std::endl;
		}
	}
}

void runDrills()
{
	//tryThis();
	//test_output();
	messing();
	
}
