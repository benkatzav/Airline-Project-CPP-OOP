#define _CRT_SECURE_NO_WARNINGS

#include "Plane.h"
int CPlane::count = 99;

CPlane::CPlane(int chairAmt, const char * brand)
{
	serial = ++count;
	setBrand(brand);
	setChairs(chairAmt);
}

CPlane::CPlane(const CPlane & other)
{
	setSerial(other.serial);
	brandName = new char[strlen(other.brandName) + 1];
	strcpy(brandName, other.brandName);
	setChairs(other.numOfChairs);
}


bool CPlane::takeOff(int min)
{
	return false;
}

void CPlane::printPlane(ostream& stream) const
{
	if (this == NULL)
		stream << "No plane assign yet" << endl;
	else
		stream << "Plane: " << serial << " Brand: " << brandName << " Seats: " << numOfChairs << endl;
}

int CPlane::isEqual(CPlane& plane)
{
	return !(serial - plane.serial); // returns 1 if equals
}
