#define _CRT_SECURE_NO_WARNINGS

#include "address.h"

CAddress::CAddress(int hNumber, const char* streetName, const char* cityName)
{
	setNumber(hNumber);
	setCity(cityName);
	setStreet(streetName);
}

CAddress::CAddress(const CAddress & other)
{
	city = new char[strlen(other.city)];
	strcpy(city, other.city);
	street = new char[strlen(other.street)];
	strcpy(street, other.street);
	houseNumber = other.houseNumber;
}

void CAddress::updateAddress(int hNumber, const char* streetName, const char* cityName)
{
	setNumber(hNumber);
	setCity(cityName);
	setStreet(streetName);
}

void CAddress::printAddress(ostream& stream) const
{
	cout << houseNumber << " " << street << ", " << city << endl;
}
