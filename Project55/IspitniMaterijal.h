#pragma once
#include<iostream>
using namespace std;

class IspitniMaterijal
{
protected:

	int oznaka;
	double tezina;
	bool status;

public:
	IspitniMaterijal();
	IspitniMaterijal(int oznaka, double tezina);
	IspitniMaterijal(const IspitniMaterijal& im);
	virtual ~IspitniMaterijal();
	friend ostream& operator<<(ostream& izlaz, IspitniMaterijal& IM);
	virtual ostream& Prikazi(ostream& izlaz);

	virtual bool vratiStatus() { return status; }
	virtual void setStatus(bool s);
	virtual double vratiTezinu() { return tezina; }
	virtual void setTezinu(double t);
	virtual int vratiOznaku() { return oznaka; }
	virtual void setOznaku(int o);
	virtual float ukVreme(float proc) = 0;

};

