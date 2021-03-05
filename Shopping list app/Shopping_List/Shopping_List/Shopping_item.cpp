#include "Shopping_item.h"
#include <iostream>

namespace _Shopping_item
{
	const std::string unknown = "unknown";
	// === constructors === //
	Shopping_item::Shopping_item(std::string name, std::string brand,std::string image, 
		int quantity, double price, Size_type sizeType, Shop_categories shopCategory)
		: mName(name),mBrand(brand), mPrice(0),mQuantity(0),mSizeType(sizeType),
		mShopCategory(shopCategory)
	{
		if (is_price(price)) mPrice = price;
		if (is_quantity(quantity)) mQuantity = quantity;
		
	}

	// === helper functions === //

	bool is_image_name(std::string image)
	{
		for (char ch : image)
		{

		}
		return true;
	}

	bool is_price(double price)
	{
		if (price < 0 || price >= 1000) throw "is_price: out of range!";
		else return true;
		return false;
	}

	bool is_quantity(int quantity)
	{
		if (quantity < 0 || quantity > 100) throw "is_quantity: out of range!";
		else return true;
		return false;
	}

	// === operators === //
}

