#pragma once
#include <string>

using namespace std;

class Currency
{
private:
	double m_val;
	char m_unit;
	double m_Yen = 0.007;
	double m_Euro = 0.84;
	double m_USdoller = 0.76;
public:
	//value
	void SetVal(const double& val)
	{
		m_val = val;
	}
	const double& GetVal() const
	{
		return m_val;
	}
	//unit
	void SetUnit(const char& unit)
	{
		m_unit = unit;
	}
	const char& GetUnit() const
	{
		return m_unit;
	}
	//Yen
	void SetYen(const double& Yen)
	{
		m_Yen = Yen;
	}
	const double& GetYen() const
	{
		return m_Yen;
	}
	//Euro
	void SetEuro(const double& Euro)
	{
		m_Euro = Euro;
	}
	const double& GetEuro() const
	{
		return m_Euro;
	}
	//USdoller
	void SetUSdoller(const double& USdoller)
	{
		m_USdoller = USdoller;
	}
	const double& GetUSDoller() const
	{
		return m_USdoller;
	}
};

