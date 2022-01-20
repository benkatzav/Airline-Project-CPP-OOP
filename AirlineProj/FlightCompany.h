#ifndef CFlightCompany_H_
#define CFlightCompany_H_

#include <iostream>
using namespace std;

#define MAX_CREWS 15
#define MAX_PLANES 15
#define MAX_FLIGHTS 15

#include "CrewMember.h"
#include "FlightInfo.h"
#include "Flight.h"
#include "Plane.h"
#include "Pilot.h"
#include "Host.h"
#include "Cargo.h"

#include <typeinfo.h>
#include <string.h>


class CFlightCompany
{

private:
	char* companyName;
	CCrewMember* membersArray[MAX_CREWS];
	CPlane* planesArray[MAX_PLANES];
	CFlight flightsArray[MAX_FLIGHTS];
	int numOfPlanes;
	int numOfFlights;
	int numOfMembers;
public:
	CFlightCompany(const char* compName);
	CFlightCompany(const CFlightCompany& other);
	//void AddCrewToFlight(int flightNumber, int memberId);
	bool AddCrewMember(CCrewMember& member);
	bool AddPlane(CPlane& plane);
	bool AddFlight(CFlight& flight);
	CPlane* GetPlane(int index);
	CCrewMember* GetCrewMember(int i);
	bool takeOff(int flightNumber);

	void setName(const char* name) { companyName = _strdup(name); }
	const char* getName() const { return companyName; }

	void CrewGetPresent();
	void CrewGetUniform();
	void PilotsToSimulator();
	int GetCargoCount();


	CFlight* GetFlightByNum(int flightNumber);

	void Print(ostream& stream);

	~CFlightCompany()
	{
		delete[]companyName;
	}
};

#endif // !CFlightCompany_H_

