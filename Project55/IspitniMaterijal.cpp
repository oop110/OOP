#include "IspitniMaterijal.h"
#include "Lekcija.h"

IspitniMaterijal::IspitniMaterijal()
{
	oznaka = 0;
	tezina = 0;
	status = false;
}

IspitniMaterijal::IspitniMaterijal(int oznaka, double tezina)
{
	this->oznaka = oznaka;
	this->tezina = tezina;
	this->status = false;
}

IspitniMaterijal::IspitniMaterijal(const IspitniMaterijal& IM)
{
	this->oznaka = IM.oznaka;
	this->tezina = IM.tezina;
	this->status = IM.status;
}

IspitniMaterijal::~IspitniMaterijal()
{
}


ostream& IspitniMaterijal::Prikazi(ostream& izlaz)
{
	izlaz << "oznaka: " << oznaka << " tezina: " << tezina << " status: " << status << endl;
	return izlaz;
}


void IspitniMaterijal::setStatus(bool s) { status = s; }

void IspitniMaterijal::setTezinu(double t) { tezina = t; }

void IspitniMaterijal::setOznaku(int o) { oznaka = o; }

ostream& operator<<(ostream& izlaz, IspitniMaterijal& IM)
{
	IM.Prikazi(izlaz);
	return izlaz;
}
