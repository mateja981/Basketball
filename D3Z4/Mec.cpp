#include "Mec.h"

void Mec::odigrajmec()
	{
		boolmec = true;
		int jedan = 1;
		int tri = 3;
		int nula = 0;

		// domacin je pobedio
		if (timovi.dohvati1().dohvativrednost() > timovi.dohvati2().dohvativrednost()) {
			ishod = POBEDA_DOMACIN;
			for (int i = 0; i < timovi.dohvati1().dohvatimax(); i++) {
				if (&(timovi.dohvati1())[i] != nullptr) {
					timovi.dohvati1()[i].povecaj(10);
				}
			}
			for (int j = 0; j < timovi.dohvati2().dohvatimax(); j++) {
				if (&(timovi.dohvati2())[j] != nullptr) {
					timovi.dohvati2()[j].smanji(10);
				}
			}
			rezultat = { &tri , &nula };
		}


		// gost je pobedio
		if (timovi.dohvati1().dohvativrednost() < timovi.dohvati2().dohvativrednost()) {
			ishod = POBEDA_GOST;
			for (int i = 0; i < timovi.dohvati2().dohvatimax(); i++) {
				if (&(timovi.dohvati2())[i] != nullptr) {
					timovi.dohvati2()[i].povecaj(10);
				}
			}
			for (int j = 0; j < timovi.dohvati1().dohvatimax(); j++) {
				if (&(timovi.dohvati1())[j] != nullptr) {
					timovi.dohvati1()[j].smanji(10);
				}
			}
			rezultat = { &nula ,&tri };
		}


		// nereseno
		if (timovi.dohvati1().dohvativrednost() == timovi.dohvati2().dohvativrednost()) {
			ishod = NERESENO;
			rezultat = { &nula,&nula };
		}
	}


ostream& Mec::ispis(ostream& os) const
{
	os << timovi;

	if (boolmec) {
		if (ishod == 0) cout << "POBEDA_DOMACIN" << endl;
		if (ishod == 1) cout << "NERESENO" << endl;
		if (ishod == 2) cout << "POBEDA_GOST" << endl;
	}
	return os;
}
