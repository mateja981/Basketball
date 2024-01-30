#include "Tim.h"
#include <exception>

Tim* Tim::kopiraj() const
{
	return new Tim(*this);
}

void Tim::prikljuci(Igrac* igrac, int pozicija)
{
	if (pozicija > this->max ) throw GNepostojecaPozicija();
	tim[pozicija] = igrac;
	if (broj_igraca == max) throw GNemaMesta();
	++broj_igraca;
	vrednost += igrac->dohvativrednost();
	if (broj_igraca==1) srednja_vrednost += igrac->dohvativrednost();
	else srednja_vrednost = (srednja_vrednost * (broj_igraca-1) + igrac->dohvativrednost()) / (broj_igraca);
}

Igrac& Tim::operator[] (int i) const
{
	return *tim[i];
}

ostream& Tim::ispis(ostream& os) const
{
	os << this->dohvatiime();
	os << "[";
	int brojac = 0;
	for (int i = 0; i < this->max; i++) {
		if (tim[i] != nullptr) {
			brojac++;
			os << *tim[i];
			if (brojac != this->broj_igraca) os << ",";
		}

	}
	os << "]" << endl;
	return os;
}



bool operator==(const Tim& t1,const Tim& t2)
{

	if (t1.ime != t2.ime) return 0;
	if (t1.max != t2.max) return 0;
	if (t1.broj_igraca != t2.broj_igraca) return 0;
	for (int i = 0; i < t1.max; i++) {
		if (&t1[i] != nullptr && &t2[i] != nullptr) {
		if (t1[i].dohvativrednost() != t2[i].dohvativrednost()) return 0;
		if (t1[i].dohvatiime() != t2[i].dohvatiime()) return 0;
	}
		else
		{
			if ((&t1[i] != nullptr && &t2[i] == nullptr) || (&t1[i] == nullptr && &t2[i] != nullptr))
			{ return 0; }
		}
	}
	return 1;
}

ostream& operator<<(ostream& os, const Tim& t)
{
	return t.ispis(os);
}
