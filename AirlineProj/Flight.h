#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "FlightInfo.h"
#include "Plane.h"
#include "CrewMember.h"

#include <string.h>
class CFlight
{
private:
	CFlightInfo fInfo;
	CPlane* plane;
	CCrewMember* members[MAX_CREW];
	int numOfMembers;

public:
	CFlight();
	CFlight(CFlightInfo& flightInfo, CPlane* planeInfo = NULL);
	CFlight(CFlightInfo& flightInfo);

	CPlane* getPlane() { return plane; }
	int getNumOfMembers() { return numOfMembers; }
	void SetPlane(CPlane* plane);

	bool TakeOff();
	
	int pilotCounter();
	CFlightInfo* GetFlightInfo();

	bool operator+(CCrewMember* member)
	{
		for (int i = 0; i < numOfMembers; i++)
		{
			if (members[i]->isEqual(*member))
				return false;
		}
		if (numOfMembers <= MAX_CREW)
		{
			members[numOfMembers] = member;
			numOfMembers++;
			return true;
		}
		return false;
	}

	bool operator==(const CFlight& other) const
	{
		return fInfo == other.fInfo;
	}

	friend ostream& operator<<(ostream& os, CFlight& other)
	{
		os << &other.fInfo;
		other.getPlane()->printPlane(os);
		os << "There are " << other.getNumOfMembers() << " Crew members in flight:" << endl;
		for (int i = 0; i < other.getNumOfMembers(); i++)
		{
			other.members[i]->Print(os);
		}
		return os;
	}



};


#endif // !FLIGHT_H_

