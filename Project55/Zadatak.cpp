#include "Zadatak.h"
#include<iostream>
using namespace std;
Zadatak::Zadatak():IspitniMaterijal()
{
	brLinije = 0;
}

Zadatak::Zadatak(int oznaka, double tezian, int brLinije):IspitniMaterijal(oznaka,tezina)
{
	this->brLinije = brLinije;
}

Zadatak::Zadatak(const Zadatak& z)
{
	this->oznaka = z.oznaka;
	this->tezina = z.tezina;
	this->status = z.status;
	this->brLinije = z.brLinije;
}

ostream& Zadatak::Prikazi(ostream& izlaz) {
	izlaz << "oznaka: " << oznaka << " tezian: " << tezina << " status: " << status << " brlinija: " << brLinije << endl;
	return izlaz;
}

float Zadatak::ukVreme(float proc){
	float ukVr = 0;
	ukVr = brLinije * tezina * proc * 0.05;
	return ukVr;
}
