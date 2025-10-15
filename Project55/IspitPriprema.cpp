#include "IspitPriprema.h"

IspitPriprema::IspitPriprema()
{
	niz = nullptr;
	maxbr = 0;
	trbr = 0;
}

IspitPriprema::IspitPriprema(int maxbr)
{
	trbr = 0;
	this->maxbr = maxbr;
	niz = new IspitniMaterijal * [maxbr];
	for (int i = 0; i < maxbr; i++) {
		niz[i] = nullptr;
	}
}

IspitPriprema::IspitPriprema(const IspitPriprema& ip)
{
	this->trbr = ip.trbr;
	this->maxbr = ip.maxbr;
	niz = new IspitniMaterijal * [this->maxbr];
	for (int i = 0; i < this->trbr; i++) {
		this->niz[i] = ip.niz[i];
	}
	for (int i = trbr; i < maxbr; i++) {
		this->niz[i] = nullptr;
	}
}

IspitPriprema::~IspitPriprema()
{
	for (int i = 0; i < trbr; i++) {
		delete niz[i];
	}
	delete[]niz;
}

void IspitPriprema::Dodaj(IspitniMaterijal* ip)
{
	if (trbr >= maxbr) {
		return;
	}
	for (int i = 0; i < trbr; i++) {
		if (niz[i]->vratiOznaku() == ip->vratiOznaku()) {
			cout << "Ne sme biti ista oznaka!" << endl;
			return;
		}
	}
	niz[trbr++] = ip;
}

void IspitPriprema::Obrisi(int br)
{
	if (br < 0) {
		return;
	}
	int indeks = 0;
	for (int i = 0; i < trbr; i++) {
		if (niz[i]->vratiOznaku() == br && !niz[i]->vratiStatus()) {
			delete niz[i];
			indeks = i;
		}
	}
	for (int i = indeks; i < maxbr - 1; i++) {
		niz[i] = niz[i + 1];
	}
	trbr--;
}

void IspitPriprema::Savladaj(int br)
{
	if (br < 0) {
		return;
	}
	for (int i = 0; i < trbr; i++) {
		if (niz[i]->vratiOznaku() == br) {
			niz[i]->setStatus(true);
		}
	}
}

int IspitPriprema::UkupnoSavladanih()
{
	int ukSv = 0;
	for (int i = 0; i < trbr; i++) {
		if (niz[i]->vratiStatus()) {
			ukSv++;
		}
	}
	return ukSv;
}

float IspitPriprema::UkupnoVreme(float vr)
{
	float Ukvr = 0;
	for (int i = 0; i < trbr; i++) {
		Ukvr = niz[i]->ukVreme(vr);
	}
	return Ukvr;
}

void IspitPriprema::vratiNaj(float vr, IspitniMaterijal** ptr1, IspitniMaterijal** ptr2)
{
	float vrMax = niz[0]->ukVreme(vr);
	float vrMin = niz[0]->ukVreme(vr);
	float trVr = 0;

	for (int i = 1; i < trbr; i++) {
		trVr = niz[i]->ukVreme(vr);
		if (trVr > vrMax) {
			vrMax = trVr;
			*ptr1 = niz[i];
		}
		if (trVr < vrMin) {
			vrMin = trVr;
			*ptr2 = niz[i];
		}
	}
}

ostream& operator<<(ostream& os, IspitPriprema& ip) {
	ip.print(os);
	return os;
}
ostream& IspitPriprema::print(ostream& os) {
	os << "Sadrzaj IspitPriprema: " << endl;
	for (int i = 0; i < trbr; i++) {
		niz[i]->Prikazi(os);
	}
	return os;
}
