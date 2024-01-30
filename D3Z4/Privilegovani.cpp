#include "Privilegovani.h"



Privilegovani* Privilegovani::kopiraj() const
{
	return new Privilegovani(*this);

}


void Privilegovani::prikljuci(Igrac* igrac, int pozicija)
{
	if (igrac->dohvativrednost() < this->min) throw GMalaVrednostIgraca();
	if (pozicija > this->max) throw GNepostojecaPozicija();
	tim[pozicija] = igrac;
	if (broj_igraca == max) throw GNemaMesta();
	broj_igraca++;
	if (srednja_vrednost == 0) srednja_vrednost += igrac->dohvativrednost();
	else srednja_vrednost = (srednja_vrednost * (broj_igraca - 1) + igrac->dohvativrednost()) / (broj_igraca);
}

ostream& Privilegovani::ispis(ostream& os) const
{
	os << this->dohvatiime();
	os << "(" << this->min << ")";
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

bool operator==(const Privilegovani& p1, const Privilegovani& p2)
{
	if (p1.ime != p2.ime) return 0;
	if (p1.max != p2.max) return 0;
	if (p1.broj_igraca != p2.broj_igraca) return 0;
	if (p1.min != p2.min) return 0;
	for (int i = 0; i < p2.max; i++) {
		if (&p1[i] != nullptr && &p2[i] != nullptr) {
			if (p1[i].dohvativrednost() != p2[i].dohvativrednost()) return 0;
			if (p1[i].dohvatiime() != p2[i].dohvatiime()) return 0;
		}
		else
		{
			if ((&p1[i] != nullptr && &p2[i] == nullptr) || (&p1[i] == nullptr && &p2[i] != nullptr))
			{
				return 0;
			}
		}
	}
	return 1;
}
