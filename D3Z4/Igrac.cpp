#include "Igrac.h"

void Igrac::smanji(int procenat) {
	try {
		vrednost_igraca -= vrednost_igraca * procenat / 100;
		if (vrednost_igraca < 0) throw this;
	}
	catch (Igrac* i) { i->vrednost_igraca = 0; cout << "Vrednost igraca " << this->dohvatiime() <<" je restartovana na 0" << endl; }
}
Igrac& Igrac::operator=(Igrac& i)
{
	return i;
}
