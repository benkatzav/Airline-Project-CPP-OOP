#ifndef HOST_H_
#define HOST_H_
#include <iostream>
using namespace std;
#include "CrewMember.h"

class CHost : public CCrewMember
{
public:
enum eHostType { eRegular, eSuper, eCalcelan };
eHostType getType() { return type; }
CHost(const char* mName,eHostType eType, int min = 0);
CHost(CHost& other);
void CrewGetPresent();
void CrewGetUniform();
void Print(ostream& stream) const;


virtual const char* getType() const { return "CHost"; }

private:
	int mNumber;
	eHostType type;

};


#endif // !HOST_H_

