#pragma once
#include "Par.h"
#include "Tim.h"
#include "Privilegovani.h"
class Mec
{
	Par<Tim> timovi;
	Par<int> rezultat;
	bool boolmec;
	int nula = 0;
	int pobednik;
	enum  moguciishod { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };
	moguciishod ishod;
public:
	Mec(Tim* t1, Tim* t2) : timovi(t1, t2), rezultat(&nula, &nula) {}
	Par<Tim> dohvatitim() { return timovi; }
	void odigrajmec();
	bool proverameca() { return boolmec; }
	Par<int>& dohvatirezultat() { if (boolmec) return rezultat; throw GNeodigranMec(); }
	ostream& ispis(ostream& os) const;
	friend ostream& operator << (ostream& os,Mec& m) { return m.ispis(os); }
};

