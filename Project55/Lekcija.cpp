#include "Lekcija.h"
#include<iostream>
#include "Zadatak.h"
using namespace std;

Lekcija::Lekcija() :IspitniMaterijal()
{
	duzinaStranica = 0;
}

Lekcija::Lekcija(int oznaka, double tezina, double duzina):IspitniMaterijal(oznaka,tezina)
{
	this->duzinaStranica = duzina;
}

Lekcija::Lekcija(const Lekcija& l)
{
	this->oznaka = l.oznaka;
	this->tezina = l.tezina;
	this->status = l.status;
	this->duzinaStranica = l.duzinaStranica;
}


float Lekcija::ukVreme(float proc)
{
	float ukVr = 0;
	ukVr = duzinaStranica * tezina * proc;
	return ukVr;
}

ostream& Lekcija::Prikazi(ostream& izlaz) {
	izlaz << "Oznaka: " << oznaka << " Tezina: " << tezina << " Status: " << status << " Duzina: " << duzinaStranica << endl;
	return izlaz;
}