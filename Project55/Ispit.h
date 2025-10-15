#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"LekcijaNormalna.h"
using namespace std;

template<typename T>
class Ispit
{
	T* niz;
	int maxbr;
	int trbr;
public:
	Ispit();
	Ispit(int maxbr);
	Ispit(const Ispit& i);
	~Ispit();
	void Dodaj(T is);
	friend ostream& operator<<(ostream& os, Ispit& is) {
		is.Ispisi(os);
		return os;
	}
	ostream& Ispisi(ostream& os);
	void Izbaci(int redbr, int brlek);
	float Ukupno();
	int  UkupniBrVr(float vr, float& ukvr);
	void minmax(int poc, int kraj, T& min, T& max);
	void Sacuvaj(const char* nazivfajla);
	void Ucitaj(const char* nazivfajla);


};

template<typename T>
inline Ispit<T>::Ispit()
{
	niz = nullptr;
	maxbr = 0;
	trbr = 0;
}

template<typename T>
inline Ispit<T>::Ispit(int maxbr)
{
	niz = new T[maxbr];
	trbr = 0;
	this->maxbr = maxbr;
}

template<typename T>
inline Ispit<T>::Ispit(const Ispit& i)
{
	this->maxbr = i.maxbr;
	this->trbr = i.trbr;
	this->niz = new T[maxbr];
	for (int i = 0; i < maxbr; i++)
		this->niz[i] = i.niz[i];

}

template<typename T>
inline Ispit<T>::~Ispit()
{
	delete[]niz;
}

template<typename T>
inline void Ispit<T>::Dodaj(T is)
{
	if (trbr >= maxbr)
		throw runtime_error("nema mesta");
	niz[trbr++] = is;
}

template<typename T>
inline ostream& Ispit<T>::Ispisi(ostream& os)
{
	os << "Ispiti: " << endl;
	for (int i = 0; i < trbr; i++) {
		os << niz[i] << " ";
	}
	os << endl;
	return os;
}

template<typename T>
inline void Ispit<T>::Izbaci(int redbr, int brlek)
{
	if (trbr < 0 || redbr >= trbr)
		throw runtime_error("pogresno unet broj");
	if (redbr + brlek > trbr)
		throw runtime_error("brisete vise elementa nego sto imate");
	for (int i = redbr; i < trbr - brlek; i++)
		niz[i] = niz[i + brlek];
	trbr -= brlek;
}

template<typename T>
float Ispit<T>::Ukupno() {
	float uk = 0;
	for (int i = 0; i < trbr; i++) {
		uk += niz[i];
	}
	return uk;
}
template<>
float Ispit<LekcijaNormalna>::Ukupno() {
	float uk = 0;
	for (int i = 0; i < trbr; i++) {
		uk += niz[i].vratiTez();
	}
	return uk;
}

template<typename T>
inline int Ispit<T>::UkupniBrVr(float vr, float& ukvr)
{
	int bre1 = 0;
	for (int i = 0; i < trbr; i++) 
		if (niz[i] > vr) {
			bre1++;
			ukvr += niz[i];
		}
	return bre1;
}

template<>
int Ispit<LekcijaNormalna>::UkupniBrVr(float vr, float& ukvr)
{
	int bre1 = 0;
	for (int i = 0; i < trbr; i++)
		if (niz[i].vratiTez() > vr) {
			bre1++;
			ukvr += niz[i].vratiTez();
		}
	return bre1;
}

template<typename T>
inline void Ispit<T>::minmax(int poc, int kraj, T& min, T& max)
{
	T minimum = niz[poc];
	T maximum = niz[poc];
	T trenutno;
	for (int i = poc; i < kraj; i++) {
		trenutno = niz[i];
		if (trenutno > maximum) {
			maximum = trenutno;
			max = niz[i];
		}
		if (minimum > trenutno) {
			minimum = trenutno;
			min = niz[i];
		}
	}
}

template<>
void Ispit<LekcijaNormalna>::minmax(int poc, int kraj, LekcijaNormalna& min, LekcijaNormalna& max)
{
	float minimum = niz[poc].vratiTez();
	float maximum = niz[poc].vratiTez();
	float trenutno;
	for (int i = poc; i < kraj; i++) {
		trenutno = niz[i].vratiTez();
		if (trenutno > maximum) {
			maximum = trenutno;
			max = niz[i];
		}
		if (minimum > trenutno) {
			minimum = trenutno;
			min = niz[i];
		}
	}
}

template<typename T>
inline void Ispit<T>::Sacuvaj(const char* nazivfajla)
{
	ofstream fajl(nazivfajla);
	if (!fajl.is_open())
		throw runtime_error("nije dobro otvoren fajl");
	for (int i = 0; i < trbr; i++)
		fajl << niz[i];
	fajl.close();
}

template<typename T>
inline void Ispit<T>::Ucitaj(const char* nazivfajla)
{
	ifstream fajl(nazivfajla);
	if (!fajl.is_open())
		throw runtime_error("nije dobro ucitan fajl");
	trbr = 0;
	T pom;
	while (trbr < maxbr) {
		fajl >> pom;
		if (fajl.fail())
			break;
		niz[trbr++] = pom;
	}
	fajl.close();
}