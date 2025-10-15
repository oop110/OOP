#pragma once
#include"IspitniMaterijal.h"
#include<iostream>
using namespace std;

class IspitPriprema
{
private:
	IspitniMaterijal** niz;
	int maxbr;
	int trbr;

public:

	IspitPriprema();
	IspitPriprema(int maxbr);
	IspitPriprema(const IspitPriprema& ip);
	~IspitPriprema();

	void Dodaj(IspitniMaterijal* ip);
	void Obrisi(int br);
	void Savladaj(int br);
	int UkupnoSavladanih();
	float UkupnoVreme(float vr);
	void vratiNaj(float vr, IspitniMaterijal** ptr1, IspitniMaterijal** ptr2);

	friend ostream& operator<<(ostream& os, IspitPriprema& ip);
	ostream& print(ostream& os);


};

