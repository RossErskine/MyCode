#include "Shopping_item.h"
#include <iostream>

using namespace _Shopping_item;

bool test_is_quantity(int quantity)
{
	try
	{
		is_quantity(quantity);
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
		return true;
	}
	return false;
	

}

void runTest()
{
	const std::string pass = "test Pass";
	const std::string fail = "test fail";

	Shopping_item ts = { "Tomato Sauce","Heinz","",1,1.75,Size_type::liquid,Shop_categories::cupboard };

	// === test for is_quantity function ===//

	// == test is_quanity for negative numbers == //
	if (test_is_quantity(-1)) std::cout << pass << std::endl;
	else std::cout << fail << std::endl;

	// == test is_quanity for numbers over 100 == //
	if (test_is_quantity(100)) std::cout << pass << std::endl;
	else std::cout << fail << std::endl;
}
