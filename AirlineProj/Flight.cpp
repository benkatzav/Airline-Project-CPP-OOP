#include "Flight.h"

CFlight::CFlight()
{
	plane = NULL;
	*members = NULL;
	numOfMembers = 0;
}

CFlight::CFlight(CFlightInfo& flightInfo, CPlane* planeInfo)
{
	numOfMembers = 0;
	fInfo = flightInfo;
	plane = planeInfo;
}

CFlight::CFlight(CFlightInfo& flightInfo)
{
	numOfMembers = 0;
	fInfo = flightInfo;
	plane = NULL;
}



void CFlight::SetPlane(CPlane* planeInfo)
{
	plane = planeInfo;
}

bool CFlight::TakeOff()
{
	if (plane->takeOff(this->GetFlightInfo()->getMin()))
	{
		for (int i = 0; i < numOfMembers; i++)
		{
			*members[i] += (this->GetFlightInfo()->getMin());
		}
		return true;
	}
		return false;
}


int CFlight::pilotCounter()
{
	int count = 0;
	for (int i = 0; i < numOfMembers; i++)
	{
		if (strcmp(members[i]->getType(), "CPilot") == 0)
			count++;
	}
	return count;
}

CFlightInfo * CFlight::GetFlightInfo()
{
	return &fInfo;
}

