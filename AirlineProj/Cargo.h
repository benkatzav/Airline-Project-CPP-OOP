#ifndef CARGO_H_
#define CARGO_H_
#include <iostream>
using namespace std;
#include "Plane.h"
#include "FlightCompany.h"

class CCargo : public CPlane
{
private:
	int serial;
	int maxVol;
	int maxKg;
	int currVol;
	int currKg;

public:
	CCargo(int chairAmt, const char* brand, int mKg, int mVol);
	CCargo(CCargo& other);
	bool Load(int kg, int vol);
	virtual const char* getType() const { return "CCargo"; }
	bool takeOff(int min);
	void printPlane(ostream& stream) const;

};

#endif // !CARGO_H_

