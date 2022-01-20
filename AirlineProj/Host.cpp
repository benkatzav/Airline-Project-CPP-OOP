#include "Host.h"

CHost::CHost(const char * mName, eHostType eType, int min) : CCrewMember(mName, min)
{
	type = eType;
}

CHost::CHost(CHost & other) : CCrewMember(other)
{
	this->type = other.type;
}

void CHost::CrewGetPresent()
{
	CCrewMember::CrewGetPresent();
	cout << " thanking the company for receiving the holiday gift. I wasn't expecting it" << endl;
}

void CHost::CrewGetUniform()
{
	CCrewMember::CrewGetUniform();
	cout << "I think the new uniform is very nice" << endl;
}

void CHost::Print(ostream & stream) const
{
	if (type == 0)
		stream << "Host Regular ";
	else if (type == 1)
		stream << "Host Super ";
	else
		stream << "Host Economist ";
	CCrewMember::Print(stream);
	stream << endl;
}
