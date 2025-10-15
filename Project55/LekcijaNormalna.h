#pragma once
#include<iostream>
using namespace std;

class LekcijaNormalna
{
private:
	char* naziv;
	float duzina;
	float procTez;
public:
	LekcijaNormalna();
	LekcijaNormalna(const char* naz, float duz, float proc);
	LekcijaNormalna(const LekcijaNormalna& l);
	~LekcijaNormalna();
	friend ostream& operator<<(ostream& izlaz, LekcijaNormalna& l);
	friend istream& operator>>(istream& ulaz, LekcijaNormalna& l);
	ostream& Prikazi(ostream& izlaz);
	istream& Upisi(istream& is);
	float vratiTez()const { return procTez; }
	void setTez(float t) { this->procTez = t; }
	float vratiDuz()const { return duzina; }
	void setDuz(float d) { this->duzina = d; }
	bool operator>(const LekcijaNormalna& lek) { return this->procTez > lek.procTez; }
	LekcijaNormalna& operator=(const LekcijaNormalna& other);

};

