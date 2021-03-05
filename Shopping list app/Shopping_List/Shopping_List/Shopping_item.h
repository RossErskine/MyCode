#include <string>

namespace _Shopping_item
{
	enum class Size_type
	{
		weight,liquid,
	};

	enum class Shop_categories
	{
		unCookedMeat,cookedMeat,fish,vegetables,fruit,frozen,cupboard,bread,
		cleaning,bathroom,baking,other,
	};

	class Shopping_item
	{
	public:
		Shopping_item(std::string,std::string,std::string,int,double, Size_type,Shop_categories );

		// === non-modifying operations === //
		std::string getName() const { return mName; }
		std::string getBrand() const { return mBrand; }
		std::string getImage() const { return mImage; }
		int getQuantity() const { return mQuantity; }
		double gePrice() const { return mPrice; }
		Size_type getSizeType() const { return mSizeType; }
		Shop_categories getShopCategory() const { return mShopCategory; }

		// === modifying operations === //
		void setName(std::string name) { mName = name; }
		void setBrand(std::string brand) { mBrand = brand; }
		void setImage(std::string image) { mImage = image; }
		void setQuantity(int quantity) { mQuantity = quantity; }
		void setPrice(double price) { mPrice = price; }
		void setSizeType(Size_type sizeType) { mSizeType = sizeType; }
		void setShopCategory(Shop_categories shopCategory) { mShopCategory = shopCategory; }


	private:
		std::string mName;
		std::string mBrand;
		std::string mImage;
		int mQuantity;
		double mPrice;
		Size_type mSizeType;
		Shop_categories mShopCategory;

	};

	// === helper functions === //
	bool is_price(double);
	bool is_quantity(int);
	bool is_image_name(std::string);


	// == operators == //
	std::ostream& operator<<(std::ostream& os, Shopping_item si);
	std::istream& operator>>(std::istream& is, Shopping_item si);
}
