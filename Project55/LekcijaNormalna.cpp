#define _CRT_SECURE_NO_WARNINGS
#include "LekcijaNormalna.h"
#include<iostream>
#include <string>
using namespace std;
LekcijaNormalna::LekcijaNormalna()
{
	naziv = new char[1];
	naziv[0] = '\0';
	duzina = 0;
	procTez = 0;
}

LekcijaNormalna::LekcijaNormalna(const char* naz, float duz, float proc)
{
	naziv = new char(strlen(naz) + 1);
	strcpy(naziv, naz);
	duzina = duz;
	procTez = proc;
}

LekcijaNormalna::LekcijaNormalna(const LekcijaNormalna& l)
{
	this->naziv = new char(strlen(l.naziv) + 1);
	strcpy(this->naziv, l.naziv);
	this->duzina = l.duzina;
	this->procTez = l.procTez;
}

LekcijaNormalna::~LekcijaNormalna()
{
	delete[]naziv;
}

ostream& LekcijaNormalna::Prikazi(ostream& izlaz) 
{
	izlaz << naziv << " " << duzina << " " << procTez << endl;
	return izlaz;
}

istream& LekcijaNormalna::Upisi(istream& is)
{
	char tempNaziv[100];
	is >> tempNaziv >> duzina >> procTez;

	delete[] naziv;  // DODAJTE OVO!
	naziv = new char[strlen(tempNaziv) + 1];
	strcpy(naziv, tempNaziv);

	return is;
}

LekcijaNormalna& LekcijaNormalna::operator=(const LekcijaNormalna& other)
{
	if (this != &other) {
		delete[] naziv;
		this->naziv = new char[strlen(other.naziv) + 1];
		strcpy(naziv, other.naziv);
		this->duzina = other.duzina;
		this->procTez = other.procTez;
	}
	return *this;
}

ostream& operator<<(ostream& izlaz, LekcijaNormalna& l)
{
	l.Prikazi(izlaz);
	return izlaz;
}

istream& operator>>(istream& ulaz, LekcijaNormalna& l)
{
	l.Upisi(ulaz);
	return ulaz;
}
