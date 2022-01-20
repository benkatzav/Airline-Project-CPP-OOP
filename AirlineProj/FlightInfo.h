#ifndef CFlight_H_
#define CFlight_H_

#include <iostream>
using namespace std;

#include <string.h>

#define MAX 32

class CFlightInfo
{
private:
	int flightNumber;
	char destination[MAX];
	int minutes;
	int km;

public:
	CFlightInfo() = default;
	CFlightInfo(const char* dest, int flightNumber, int min, int km);
	CFlightInfo(const CFlightInfo& other);

	void setNumber(int number) { this->flightNumber = number; }
	void setMin(int min) { this->minutes = min; }
	void setKm(int kmAmt) { this->km = kmAmt; }
	void setDest(const char* dest) { strcpy_s(this->destination, dest); }

	int getNumber() const { return flightNumber; }
	int getMin() const { return minutes; }
	int getKm() const { return km; }
	const char* getDest() const { return destination; }

	int isEqual(CFlightInfo& flight);
	void printFlight(ostream& stream) const;

	operator int() const { return minutes; }

	bool operator!=(const CFlightInfo& other) const
	{
		return !(flightNumber == other.flightNumber && minutes == other.minutes && km == other.km && strcmp(destination,other.destination) == 0);
	}

	friend ostream& operator<<(ostream& os, CFlightInfo* other)
	{
		os << "Flight Info - Destination: " << other->getDest() << " Flight Number: " << other->getNumber() << " minutes " << other->getMin() << " Km: " << other->getKm() << endl;
		return os;
	}

};

#endif // !CFlight_H_