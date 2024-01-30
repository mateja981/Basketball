#pragma once
#include "Tim.h"

class Privilegovani: public Tim
{
	int min;
	Privilegovani* kopiraj() const override;

public:
	Privilegovani(string i, int kapacitet, int min) : Tim(i, kapacitet), min(min) {};
	void prikljuci(Igrac* igrac, int pozicija) override;
	ostream& ispis(ostream& os) const override;
	friend bool operator == (const Privilegovani& p1, const Privilegovani& p2);
};

