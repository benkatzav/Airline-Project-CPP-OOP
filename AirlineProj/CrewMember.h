#ifndef CCrewMember_H_
#define CCrewMember_H_

#include <iostream>
using namespace std;

#define MAX_CREW 10

#include <string.h>
#include <typeinfo.h>

class CCrewMember
{
protected:
	static int counter;
	int mNumber;
	char* memberName;
	int minutesInAir;

public:
	CCrewMember()
	{
		mNumber = ++counter;
		minutesInAir = 0;
		memberName = NULL;
	}
	CCrewMember(const char* mName, int min = 0);
	CCrewMember(const CCrewMember& other);

	virtual void CrewGetPresent();
	virtual void CrewGetUniform();
	virtual void PilotsToSimulator();
	virtual const char* getType() const { return "CCrewMember"; }


	void setName(const char* name) { this->memberName = _strdup(name); }
	bool setMin(int min);

	int getMin() { return minutesInAir; }
	int getId() { return mNumber; }
	const char* getName() const { return memberName; };

	int isEqual(CCrewMember& member);

	virtual void Print(ostream& stream) const;

	virtual bool operator+=(int addedTime)
	{
		if (addedTime >= 0)
		{
			minutesInAir += addedTime;
			return true;
		}
		return false;
	}

	~CCrewMember()
	{
		memberName = NULL;
		delete[]memberName;
	}
};



#endif // !CCrewMember_H_