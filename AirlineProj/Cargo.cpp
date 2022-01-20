#include "Cargo.h"

CCargo::CCargo(int chairAmt, const char * brand, int mKg, int mVol) : CPlane(chairAmt, brand)
{
	maxKg = mKg;
	maxVol = mVol;
	currKg = 0;
	currVol = 0;
}

CCargo::CCargo(CCargo & other) : CPlane(other)
{
	this->maxVol = other.maxVol;
	this->maxKg = other.maxKg;
	this->currKg = other.currKg;
	this->currVol = other.currVol;
}

bool CCargo::Load(int kg, int vol)
{
	if ((kg + currKg) < maxKg && (vol + currVol) < maxVol)
	{
		currVol = currVol + vol;
		currKg = currKg + kg;
		return true;
	}
	return false;
}

bool CCargo::takeOff(int min)
{
	cout << "Need to add " << min << " minutes to my log book" << endl;
	return true;
}

void CCargo::printPlane(ostream & stream) const
{
	CPlane::printPlane(stream);
	stream << "Cargo M_vol " << maxVol << " M_Kg " << maxKg << " C_vol " << currVol << " C_Kg " << currKg << endl;
}
