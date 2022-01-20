#define _CRT_SECURE_NO_WARNINGS

#include "FlightCompany.h"

CFlightCompany::CFlightCompany(const char* compName)
{
	numOfPlanes = 0;
	numOfFlights = 0;
	numOfMembers = 0;
	setName(compName);
}

CFlightCompany::CFlightCompany(const CFlightCompany & other)
{
	companyName = new char[strlen(other.companyName) + 1];
	strcpy(companyName, other.companyName);
	numOfFlights = other.numOfFlights;
	numOfMembers = other.numOfMembers;
	numOfPlanes = other.numOfPlanes;
	for (int i = 0; i < MAX_CREWS; i++)
	{
		membersArray[i] = other.membersArray[i];
		planesArray[i] = other.planesArray[i];
		flightsArray[i] = other.flightsArray[i];
	}
}

bool CFlightCompany::AddCrewMember(CCrewMember & member)
{
	for (int i = 0; i < numOfMembers; i++)
		if (membersArray[i]->isEqual(member))
			return false;
	if (numOfMembers < MAX_CREWS)
	{
		if (strcmp(member.getType(), "CPilot") == 0)
		{
			CPilot* p = dynamic_cast<CPilot*>(&member);
			membersArray[numOfMembers] = new CPilot(*p);
		}
		else
		{
			CHost* h = dynamic_cast<CHost*>(&member);
			membersArray[numOfMembers] = new CHost(*h);

		}
		numOfMembers++;
		return true;
	}
	return false;
}

bool CFlightCompany::AddPlane(CPlane & plane)
{
	for (int i = 0; i < numOfPlanes; i++)
	{
		if (plane.getSerial() == planesArray[i]->getSerial())
			return false;
	}
	if (numOfPlanes < MAX_PLANES)
	{
		if (strcmp(plane.getType(), "CCargo") == 0)
		{
			CCargo* tmp = dynamic_cast<CCargo*>(&plane);
			planesArray[numOfPlanes] = new CCargo(*tmp);
		}
		else
			planesArray[numOfPlanes] = new CPlane(plane);
		numOfPlanes++;
		return true;
	}
	return false;
}

bool CFlightCompany::AddFlight(CFlight& flight)
{
	for (int i = 0; i < numOfFlights; i++)
	{
		if (flightsArray[i] == flight)
			return false;
	}
	if (numOfFlights < MAX_FLIGHTS)
	{
		flightsArray[numOfFlights] = flight;
		numOfFlights++;
		return true;
	}
	return false;
}

CPlane* CFlightCompany::GetPlane(int index)
{
	return planesArray[index];
}

CCrewMember* CFlightCompany::GetCrewMember(int i)
{
	return membersArray[i];
}

bool CFlightCompany::takeOff(int flightNumber)
{
	CCargo* tmpCargo;
	for (int i = 0; i < numOfFlights; i++)
	{
		if (flightsArray[i].GetFlightInfo()->getNumber() == flightNumber)
		{
			if (flightsArray[i].pilotCounter() < 1)
				return false;
			tmpCargo = dynamic_cast<CCargo*>(flightsArray[i].getPlane());
			if (tmpCargo)
				return flightsArray[i].getPlane()->takeOff(flightsArray[i].GetFlightInfo()->getMin());
			if(flightsArray[i].pilotCounter() != 1)
				return false;
			cout << "Get ready to take off" << endl;
			return true;
		}
	}
	return false;
}

void CFlightCompany::CrewGetPresent()
{
	for (int i = 0; i < numOfMembers; i++)
	{
		membersArray[i]->CrewGetPresent();
	}
}

void CFlightCompany::CrewGetUniform()
{
	for (int i = 0; i < numOfMembers; i++)
	{
		membersArray[i]->CrewGetUniform();
	}
}

void CFlightCompany::PilotsToSimulator()
{
	CPilot* tmpPilot;
	for (int i = 0; i < numOfMembers; i++)
	{
		tmpPilot = dynamic_cast<CPilot*>(membersArray[i]);
		if(tmpPilot)
			membersArray[i]->PilotsToSimulator();
		tmpPilot = NULL;
	}
}

int CFlightCompany::GetCargoCount()
{
	CCargo* tmpCargo;
	int cargoCounter = 0;
	for (int i = 0; i < numOfPlanes; i++)
	{
		tmpCargo = dynamic_cast<CCargo*>(planesArray[i]);
		if(tmpCargo)
			cargoCounter++;
		tmpCargo = NULL;
	}
	return cargoCounter;
}

CFlight * CFlightCompany::GetFlightByNum(int flightNumber)
{
	for (int i = 0; i < numOfFlights; i++)
	{
		if (flightsArray[i].GetFlightInfo()->getNumber() == flightNumber)
			return &flightsArray[i];
	}
	cout << "NO SUCH FLIGHT" << endl;
	return nullptr;
}

void CFlightCompany::Print(ostream& stream)
{
	cout << "Company name: " << companyName << endl;
	cout << "There are " << numOfMembers << " Crew members:" << endl;
	for (int i = 0; i < numOfMembers; i++)
	{
		membersArray[i]->Print(stream);
	}
	cout << "There are " << numOfPlanes << " Planes:" << endl;
	for (int i = 0; i < numOfPlanes; i++)
	{
		planesArray[i]->printPlane(stream);
	}
	cout << "There are " << numOfFlights << " Flights:" << endl;
	for (int i = 0; i < numOfFlights; i++)
	{
		stream << flightsArray[i];	
	}
}

/*
void CFlightCompany::AddCrewToFlight(int flightNumber, int memberId)
{
	for (int i = 0; i < numOfFlights; i++)
	{
		if (flightNumber == flightsArray[i].getFInfo()->getNumber())
		{
			flightsArray[i] + getMemberById(memberId);
			break;
		}
	}
}*/