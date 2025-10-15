#pragma once
#include"IspitniMaterijal.h"
#include<iostream>
using namespace std;
class Zadatak:
	public IspitniMaterijal
{
private:
	int brLinije;
public:
	Zadatak();
	Zadatak(int oznaka, double tezian, int brLinija);
	Zadatak(const Zadatak& z);
	~Zadatak(){}

	ostream& Prikazi(ostream& izlaz);
	int vratiBrLinija() { return brLinije; }
	void setBrLinija(int l) { brLinije = l; }
	float ukVreme(float proc);
};

