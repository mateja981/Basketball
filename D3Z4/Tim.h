#pragma once
#include "Igrac.h"
#include "Greske.h"

class Tim
{
protected:
	string ime;
	int max, broj_igraca = 0, vrednost = 0, srednja_vrednost = 0;
	Igrac** tim = new Igrac* [max];
	virtual Tim* kopiraj() const;
	void brisi() { delete[] tim; }
public:
	
	Tim(string i, int m) : ime(i), max(m) { for (int i = 0; i < max; i++) tim[i] = nullptr; };
	Tim(const Tim& t) { kopiraj(); }
	~Tim() { brisi(); }
	
	virtual void prikljuci(Igrac* igrac, int pozicija) ;
	int dohvatibrojigraca() const { return broj_igraca; }
	int dohvatimax() const { return max; }
	string dohvatiime() const { return ime; }
	Igrac& operator [] (int i)const;
	int dohvativrednost() const { return vrednost; }
	int dohvatisrednjuvrednost() const { return srednja_vrednost; }
	virtual ostream& ispis(ostream& os) const;
	friend bool operator == (const Tim& t1, const Tim& t2);
	friend ostream& operator << (ostream& os, const Tim& t);

};

