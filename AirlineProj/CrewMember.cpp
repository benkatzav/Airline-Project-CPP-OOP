#define _CRT_SECURE_NO_WARNINGS

#include "CrewMember.h"

int CCrewMember::counter = 1000;

CCrewMember::CCrewMember(const char* mName, int min)
{
	mNumber = ++counter;
	setMin(min);
	setName(mName);
}

CCrewMember::CCrewMember(const CCrewMember & other)
{
	mNumber = other.mNumber;
	memberName = new char[strlen(other.memberName) + 1];
	strcpy(memberName, other.memberName);
	minutesInAir = other.minutesInAir;
}

void CCrewMember::CrewGetPresent()
{
	cout << memberName << " ";
}

void CCrewMember::CrewGetUniform()
{
	cout << memberName;
}

void CCrewMember::PilotsToSimulator()
{
	cout << "Pilot " << memberName;
}

bool CCrewMember::setMin(int min)
{
	if (min > 0)
	{
		this->minutesInAir = min;
		return true;
	}
	return false;
}

int CCrewMember::isEqual(CCrewMember& member)
{
	return mNumber == member.mNumber;
}

void CCrewMember::Print(ostream& stream) const
{
	if (memberName != NULL)
		stream << memberName << " minutes: " << minutesInAir;
}
