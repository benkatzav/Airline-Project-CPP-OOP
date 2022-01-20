#define _CRT_SECURE_NO_WARNINGS

#include "FlightInfo.h"

CFlightInfo::CFlightInfo(const char* dest, int fNumber, int min, int km)
{
	setNumber(fNumber);
	setDest(dest);
	setKm(km);
	setMin(min);
}

CFlightInfo::CFlightInfo(const CFlightInfo & other)
{
	flightNumber = other.flightNumber;
	setDest(other.getDest());
	minutes = other.minutes;
	km = other.km;
}

int CFlightInfo::isEqual(CFlightInfo& flight)
{
	return !(flightNumber - flight.getNumber()); // returns 1 if equals
}

void CFlightInfo::printFlight(ostream& stream) const
{
	cout << "Destination: " << destination << " Flight Number: " << flightNumber << " minutes " << minutes << " Km: " << km << endl;
}
