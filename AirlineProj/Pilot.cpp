#include "Pilot.h"

CPilot::CPilot(const char * mName, bool isCap, CAddress* pAddress, int min) : CCrewMember(mName, min)
{
	address = pAddress;
	isCapitan = isCap;
}

CPilot::CPilot(const CPilot & other) : CCrewMember(other)
{	
	this->isCapitan = other.isCapitan;
	this->address = other.address;
}

void CPilot::PilotsToSimulator()
{
	CCrewMember::PilotsToSimulator();
	cout << " got the message will come soon" << endl;
}

void CPilot::CrewGetPresent()
{
	CCrewMember::CrewGetPresent();
	cout << " thanking the company for receiving the holiday gift" << endl;
}

void CPilot::CrewGetUniform()
{
	CCrewMember::CrewGetUniform();
	cout << "this is the fifth time I get a new uniform – this is a waste of money!" << endl;
}

void CPilot::Print(ostream & stream) const
{
	stream << "Pilot ";
	CCrewMember::Print(stream);
	if (address != NULL)
		stream << " " << *address;
	if (isCapitan)
		stream << " Capitan" << endl;
	else
		stream << " Not Capitan" << endl;
}
