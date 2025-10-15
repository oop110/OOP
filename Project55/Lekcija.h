#pragma once
#include"IspitniMaterijal.h"
#include<iostream>
using namespace std;
class Lekcija :
	public IspitniMaterijal
{
private:
	double duzinaStranica;
public:

	Lekcija();
	Lekcija(int oznaka, double tezina, double duzina);
	Lekcija(const Lekcija& l);
	~Lekcija(){}

	ostream& Prikazi(ostream& izlaz);
	double vratiDuzinu() { return duzinaStranica; }
	void setDuzinu(double d) { duzinaStranica = d; }
	float ukVreme(float proc);
};

