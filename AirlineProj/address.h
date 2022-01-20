#ifndef CADDRESS_H_
#define CADDRESS_H_

#include <iostream>
using namespace std;

#include <string.h>

class CAddress
{
private:
	char* city;
	char* street;
	int houseNumber;

public:
	CAddress(int hNumber, const char* streetName, const char* cityName = "Tel Aviv");
	CAddress(const CAddress& other);

	void setStreet(const char* street) { this->street = _strdup(street); }
	void setCity(const char* city) { this->city = _strdup(city); }
	void setNumber(int number) { this->houseNumber = number; }

	const char* getCityName() const { return city; }
	const char* getStreetName() const { return street; }
	int getHouseNumber() const { return houseNumber; }

	void updateAddress(int hNumber, const char* streetName, const char* cityName);

	void printAddress(ostream& stream) const;
	
	bool operator==(const CAddress& other) const
	{
		return !strcmp(city, other.city) && strcmp(street, other.street) == 0 && houseNumber == other.houseNumber;
	}
	bool operator!=(const CAddress& other) const
	{
		return !(*this == other);
	}

	friend istream& operator>>(istream& in, CAddress& other)
	{
		int houseNum;
		char tempCity[32];
		char tempSt[32];
		in >> houseNum >> tempSt >> tempCity;
		other.setCity(tempCity);
		other.setStreet(tempSt);
		other.houseNumber = houseNum;
		return in;
	}
	/*
	const CAddress& operator=(CAddress&& other)
	{
		if (this != &other)
		{
			delete[]city;
			delete[]street;
			this->houseNumber = other.houseNumber;
			this->setCity(other.city);
			this->setStreet(other.street);
		}
	}*/
	
	friend ostream& operator<<(ostream& os, CAddress& other)
	{
		os << other.houseNumber << " " << other.street << ", " << other.city << endl;
		return os;
	}

	~CAddress()
	{
		delete[]city;
		delete[]street;
	}
};

#endif // !CADDRESS_H_



