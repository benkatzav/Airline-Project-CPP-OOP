#ifndef Pilot_H_
#define Pilot_H_

#include <iostream>
using namespace std;

#include "CrewMember.h"
#include "Address.h"

class CPilot : public CCrewMember
{
private:
	int mNumber;
	bool isCapitan;
	CAddress* address;
public:
	CPilot(const char* mName, bool isCap , CAddress* pAddress = NULL, int min = 0);
	CPilot(const CPilot& other);
	virtual const char* getType() const { return "CPilot"; }
	void PilotsToSimulator();
	void CrewGetPresent();
	void CrewGetUniform();
	void Print(ostream& stream) const;

	bool operator+=(int addedTime)
	{
		if (addedTime >= 0)
		{
			minutesInAir += addedTime;
			if(isCapitan)
				minutesInAir = (int)(minutesInAir*1.1);
			return true;
		}
		return false;
	}

};


#endif // !Pilot_H_

