// Chapter3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Pers_info
{
private:
	string mFirst_name;
	string mSur_name;
	int mAge = 0;
	char mGender = 0;
public:
	void SetFirstName(const string& first_name) { mFirst_name = first_name; }
	const string& GetFirstName() const { return mFirst_name; }
	void SetSurName(const string& sur_name) { mSur_name = sur_name; }
	const string& GetSurName() const { return mSur_name; }
	void SetAge(const int age) { mAge = age; }
	const int GetAge() const { return mAge; }
	void SetGender(const char gender) { mGender = gender; }
	const char GetGender() const { return mGender; }
};

void convo(Pers_info& fName, Pers_info& sName, Pers_info& Age)
{
	string firstName, surName;
	int age;
	cout << "Please enter your first name\n";
	cin >> firstName;
	fName.SetFirstName(firstName);
	cout << "Please enter your last name\n";
	cin >> surName;
	sName.SetSurName(surName);
	cout << "\n" << "Hello" << " " << fName.GetFirstName() << " " << sName.GetSurName() << "\n\n";
	cout << "How old are you? \n";
	cin >> age;
	Age.SetAge(age);

}

void how_old(Pers_info& Age)
{
	if (Age.GetAge() <= 12){
		cout << "Next year you will be " << Age.GetAge() + 1 << endl;
}
	if (Age.GetAge() == 17) {
		cout << "Get to buy beer next year \n";
	}
	if (Age.GetAge() >= 70) {
		cout << " Hope you enjoy your retirement \n";
	}
}

class Measure
{
private:
	double mMeasure = 0;
public:
	void SetMeasure(const double measure) { mMeasure = measure; }
	const double GetMeasure() const { return mMeasure; }
};

void convert(Measure& measure)
{
	double cvt;
	cout << "Please enter the miles you would like to convert \n";
	cin >> cvt;
	measure.SetMeasure(cvt);
	
	cout << "\n" << " your conversion is: " << measure.GetMeasure() * 1.609 << " Kilometers \n";
}

class Value
{
private:
	double mVal1 = 0;
	double mVal2 = 0;
public:
	void SetVal1(const double val1) { mVal1 = val1; }
	const double GetVal1() const { return mVal1; }
	void SetVal2(const double val2) { mVal2 = val2; }
	const double GetVal2() const { return mVal2; }
};

void avg(Value& val1, Value& val2)
{
	float tVal1, tVal2;
	cout << " Please enter 2 int values \n";
	cin >> tVal1 >> tVal2;
	val1.SetVal1(tVal1);
	val2.SetVal2(tVal2);

	//size
	if (val1.GetVal1() < val2.GetVal2()) { cout << val1.GetVal1() << " is smaller number than " << val2.GetVal2() << endl; }
	if (val1.GetVal1() > val2.GetVal2()) { cout << val1.GetVal1() << " is bigger number than " << val2.GetVal2() << endl; }
	//sum
	double sum=0;
	sum = val1.GetVal1() + val2.GetVal2();
	cout << "the sum of " << val1.GetVal1() << " & " << val2.GetVal2() << " is: " << sum << endl;
	//difference
	double diff;
	if (val1.GetVal1() < val2.GetVal2()) { diff = val2.GetVal2() - val1.GetVal1(); }
	else { diff = val1.GetVal1() - val2.GetVal2(); }
	cout << "the difference between " << val1.GetVal1() << " & " << val2.GetVal2() << " is: " << diff << endl;
	//product
	double prod = 0;
	prod = val1.GetVal1() * val2.GetVal2();
	cout << " the product of " << val1.GetVal1() << " & " << val2.GetVal2() << "is: " << prod << endl; 
	//ratio 
	double ratio = 0;
	if (val1.GetVal1() < val2.GetVal2()) { ratio = val2.GetVal2() / val1.GetVal1(); }
	else { ratio = val1.GetVal1() / val2.GetVal2(); }
	cout << "the ratio of " << val1.GetVal1() << " & " << val2.GetVal2() << " is: " << ratio << endl;
}

class Value345
{
private:
	int mSml ;
	int mMid ;
	int mLrg ;
	
public:
	void SetSml(const int sml) { mSml = sml; }
	const int GetSml()const { return mSml; }
	void SetMid(const int mid) { mMid = mid; }
	const int GetMid()const { return mMid; }
	void SetLrg(const int lrg) { mLrg = lrg; }
	const int GetLrg()const { return mLrg; }
	
};

void reorder(Value345& sml, Value345& mid, Value345& lrg )
{
	int tVal3, tVal4, tVal5;
	cout << "Please enter 3 values \n";
	cin >> tVal3 >> tVal4 >> tVal5;
	if (tVal3 <= tVal4 && tVal4 <= tVal5)
	{
		sml.SetSml(tVal3);
		if (tVal3 <= tVal5)
		{
			mid.SetMid(tVal4);
			lrg.SetLrg(tVal5);
		}
		else
		{
			mid.SetMid(tVal5);
			lrg.SetLrg(tVal4);
		}
	}
	else if (tVal4 <= tVal3 && tVal4 <= tVal5)
	{
		sml.SetSml(tVal4);
		if (tVal3 <= tVal5)
		{
			mid.SetMid(tVal3);
			lrg.SetLrg(tVal5);
		}
		else
		{
			mid.SetMid(tVal5);
			lrg.SetLrg(tVal3);
		}
	}
	else 
	{
		sml.SetSml(tVal5);
		if (tVal3 <= tVal4)
		{
			mid.SetMid(tVal3);
			lrg.SetLrg(tVal4);
		}
		else
		{
			mid.SetMid(tVal4);
			lrg.SetLrg(tVal3);
		}
	}
	
	cout << " Values in ascending order: " << sml.GetSml() << " " << mid.GetMid() << " " << lrg.GetLrg() << endl;
	
}

class strVal
{
private:
	string m_sml;
	string m_mid;
	string m_lrg;
public:
	void SetSml(const string sml) { m_sml = sml; }
	const string GetSml()const { return m_sml; }
	void SetMid(const string mid) { m_mid = mid; }
	const string GetMid()const { return m_mid; }
	void SetLrg(const string lrg) { m_lrg = lrg; }
	const string GetLrg()const { return m_lrg; }

};

void stringVal(strVal& sml, strVal& mid, strVal& lrg)
{
	string val1, val2, val3;
	cout << "Please enter 3 string values: \n";
	cin >> val1 >> val2 >> val3;
	if (val1.length() < val2.length() && val2.length() < val3.length())
	{
		sml.SetSml(val1);
		if (val1.length() <= val3.length())
		{
			mid.SetMid(val2);
			lrg.SetLrg(val3);
		}
		else
		{
			mid.SetMid(val3);
			lrg.SetLrg(val2);
		}
	}
	else if (val2.length() <= val1.length() && val2.length() <= val3.length())
	{
		sml.SetSml(val2);
		if (val1.length() <= val3.length())
		{
			mid.SetMid(val1);
			lrg.SetLrg(val3);
		}
		else
		{
			mid.SetMid(val3);
			lrg.SetLrg(val1);
		}
	}
	else
	{
		sml.SetSml(val3);
		if (val1.length() <= val2.length())
		{
			mid.SetMid(val1);
			lrg.SetLrg(val2);
		}
		else
		{
			mid.SetMid(val2);
			lrg.SetLrg(val1);
		}
	}

	cout << " Values in ascending order: " << sml.GetSml() << " " << mid.GetMid() << " " << lrg.GetLrg() << endl;


}
class Digit
{
private:
	int mDigit;
public:
	void SetDgt(const int dgt) { mDigit = dgt; }
	const int GetDgt()const { return mDigit; }
};

void oddDgt(Digit& dgt)
{
	int tDgt;
	cout << "Please enter a digit: \n";
	cin >> tDgt;
	dgt.SetDgt(tDgt);
	if (dgt.GetDgt() % 2 == 0)
		cout << dgt.GetDgt() << " is even";
	else
		cout << dgt.GetDgt() << " is odd";
}

class Numbers
{
private:
	string mNumb;
public:
	void SetNumb(const string numb) { mNumb = numb; }
	const string GetNumb() const { return mNumb; }
};

void words2numb(Numbers& numb)
{
	string tNumb;
	cout << "Please enter a number in words upto 4: \n";
	cin >> tNumb;
	numb.SetNumb(tNumb);
	if (numb.GetNumb() == "zero") {
		cout << "The number was: " << 0 << endl;
	}
	else if (numb.GetNumb() == "one") {
		cout << "The number was: " << 1 << endl;
	}
	else if (numb.GetNumb() == "two") {
		cout << "The number was: " << 2 << endl;
	}
	else if (numb.GetNumb() == "three") {
		cout << "The number was: " << 3 << endl;
	}
	else if (numb.GetNumb() == "four") {
		cout << "The number was: " << 4 << endl;
	}
	else {
		cout << "Not a number i know \n";
	}
}

class Operation 
{
private:
	char mOp;
	double mNumb1;
	double mNumb2;
public:
	void SetOp(const char op) { mOp = op; }
	const char GetOp() const { return mOp; }
	void SetNumb1(const double numb1) { mNumb1 = numb1; }
	const double GetNumb1() const { return mNumb1; }
	void SetNumb2(const double numb2) { mNumb2 = numb2; }
	const double GetNumb2() const { return mNumb2; }
};

void calc(Operation& op, Operation& numb1, Operation& numb2)
{
	char tOp;
	double tNumb1, tNumb2;
	cout << " Enter an operation followed by 2 numbers: \n";
	cin >> tOp >> tNumb1 >> tNumb2;
	op.SetOp(tOp);
	numb1.SetNumb1(tNumb1);
	numb2.SetNumb2(tNumb2);
	switch (op.GetOp()) {
	case '+':
		cout << numb1.GetNumb1() + numb2.GetNumb2() << endl;
		break;
	case '-':
		cout << numb1.GetNumb1() - numb2.GetNumb2() << endl;
		break;
	case '/':
		cout << numb1.GetNumb1() / numb2.GetNumb2() << endl;
		break;
	case '*':
		cout << numb1.GetNumb1() * numb2.GetNumb2() << endl;
		break;
	default:
		cout << " sorry something went wrong \n";
		break;
	}
}

class Money
{
private:
	double mPennies = 0.01;
	double m2Pence = 0.02;
	double m5Pence = 0.05;
	double m10Pence = 0.10;
	double m50Pence = 0.50;
	double mPound = 1.00;
public:
	const double GetPennies() const { return mPennies; }
	const double Get2Pence() const { return m2Pence; }
	const double Get5pence() const { return m5Pence; }
	const double Get10Pence() const { return m10Pence; }
	const double Get50Pence() const { return m50Pence; }
	const double GetPound() const { return mPound; }
};

void moneyInPocket(Money& pennies, Money& _2Pence, Money& _5Pence, Money& _10Pence, Money& _50Pence, Money& Pound)
{
	double one, two, five, ten, fifty, pound, sum;
	cout << "How many pennies? \n";
	cin >> one;
	one *= pennies.GetPennies();
	cout << "How many 2 pences? \n";
	cin >> two;
	two *= _2Pence.Get2Pence();
	cout << "How many 5 pences? \n";
	cin >> five;
	five *= _5Pence.Get5pence();
	cout << "How many 10 pences? \n";
	cin >> ten;
	ten *= _10Pence.Get10Pence();
	cout << "How many 50 pences? \n";
	cin >> fifty;
	fifty *= _50Pence.Get50Pence();
	cout << "How many pounds? \n";
	cin >> pound;
	pound *= Pound.GetPound();
	sum = one + two + five + ten + fifty + pound;
	cout << "The value of all your coins is: £" << sum << endl;
}

void play()
{
	Pers_info fName;
	Pers_info sName;
	Pers_info age;
	convo(fName, sName, age);
	how_old(age);
	//Ex 3
	Measure measure;
	convert(measure);
	//Ex 4&5
	Value value1;
	Value value2;
	avg(value1, value2);
	//Ex 6
	Value345 sml;
	Value345 mid;
	Value345 lrg;
	reorder(sml, mid, lrg);
	//Ex 7
	strVal sml1;
	strVal mid2;
	strVal lrg3;
	stringVal(sml1, mid2, lrg3);
	//Ex 8
	Digit dgt;
	oddDgt(dgt);
	//Ex 9
	Numbers numb;
	words2numb(numb);
	//Ex 10
	Operation op, numb1, numb2;
	calc(op, numb1, numb2);
	//Ex 11
	Money pennies, _2pence, _5pence, _10pence, _50pence, pound;
	moneyInPocket(pennies, _2pence, _5pence, _10pence, _50pence, pound);
}

int main()
{
	play();
	

	return 0;
}
