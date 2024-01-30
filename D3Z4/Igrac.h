#pragma once
#include <iostream>
using namespace std;

class Igrac
{
private:
	string ime;
	int vrednost_igraca;

public:
	Igrac(string i, int v = 1000) : ime(i) {(v > 0) ? vrednost_igraca = v : vrednost_igraca = 0; };
	void povecaj(int procenat) { vrednost_igraca += vrednost_igraca * procenat / 100; };
	void smanji(int procenat);
	int dohvativrednost() const { return vrednost_igraca; }
	string dohvatiime() const { return ime; }
	Igrac& operator =(Igrac& i);
	friend bool operator ==(const Igrac i1, const Igrac i2)
	{ return ((i1.vrednost_igraca == i2.vrednost_igraca) && (i1.ime == i2.ime)); };
	friend ostream& operator << (ostream& os, const Igrac& i) { os << i.ime << "#" << i.vrednost_igraca; return os; };
};

