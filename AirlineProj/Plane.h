#ifndef CPlane_H_
#define CPlane_H_

#include <iostream>
using namespace std;

#include <string.h>
class CPlane
{
protected:
	static int count;
	int serial;
	char* brandName;
	int numOfChairs;

public:
	CPlane()
	{
		serial = ++count;
		brandName = NULL;
		numOfChairs = 0;
	}
	CPlane(int chairAmt, const char* brand);
	CPlane(const CPlane& other);

	void setSerial(int serNumber) { this->serial = serNumber; }
	void setBrand(const char* brand) { this->brandName = _strdup(brand); }
	void setChairs(int chairAmt) { this->numOfChairs = chairAmt; }
	virtual const char* getType() const { return "CPlane"; }
	virtual bool takeOff(int min);

	virtual void printPlane(ostream& stream) const;

	int isEqual(CPlane& plane);

	int getSerial() { return serial; }
	const char* getBrand() const { return brandName; }
	int getChairs() { return numOfChairs; }

	const CPlane& operator++()
	{
		numOfChairs++;
		return *this;
	}
	const CPlane operator++(int)
	{
		CPlane temp(*this);
		numOfChairs++;
		return temp;
	}


	friend ostream& operator<<(ostream& os, CPlane& other)
	{
		if (strcmp(other.getType(), "CCargo") == 0)
			other.printPlane(os);
		else
			os << "Serial Number: " << other.getSerial() << " Brand: " << other.getBrand() << " Seats: " << other.getChairs() << endl;
		return os;
	}


	~CPlane()
	{
		brandName = NULL;
		delete[]brandName;
	}
};

#endif // !CPlane_H_
