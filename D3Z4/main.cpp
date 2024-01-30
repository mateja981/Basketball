#include <iostream>
#include <string>
#include <exception>
#include "Igrac.h"
#include "Tim.h"
#include "Privilegovani.h"
#include "Par.h"
#include "Mec.h"
#include <exception>
using namespace std;

int main() {

	try {

		//IGRAC
		Igrac i1("Igrac1",1000), i2("Igrac2", 1000), i3("Igrac3", 1000), i4("Igrac4",1000),i5("Igrac5",900);
		Igrac i6("Igrac6", 1000), i7("Igrac7", 1000), i8("Igrac8", 1000), i9("Igrac9", 1000), i10("Igrac10", 1000);
		/*i1.povecaj(20);
		i1.smanji(20);
		cout << "Igrac:" << i1 << endl;*/

		//TIM
		Tim t1("Tim1", 50);
		t1.prikljuci(&i7, 3);
		t1.prikljuci(&i2, 2);
		t1.prikljuci(&i3, 1);
		//cout <<"Tim: " << t1 ;
		
		Tim t2("Tim2", 5);
		t2.prikljuci(&i4, 0);
		t2.prikljuci(&i5, 1);
		t2.prikljuci(&i6, 3);

		Tim t3("Tim3", 5);
		t3.prikljuci(&i5, 4);
		t3.prikljuci(&i2, 3);
		t3.prikljuci(&i3, 2);

		/*cout << "Tim: " << t2 ;
		cout << "Vrednost tima 1 je" << t1.dohvativrednost()<<endl;
		cout << "Vrednost tima 2 je" << t2.dohvativrednost() << endl;
		cout << "Srednja vrednost tima 2: " << t2.dohvatisrednjuvrednost() << endl;
		cout << "Da li su dva tima jednaka (1=DA : 0=NE)" << (t1 == t2) << endl;*/


		//PRIVILEGOVANI
		Privilegovani p1("PTim1", 5, 500);
		p1.prikljuci(&i1, 0);
		p1.prikljuci(&i2, 2);
		p1.prikljuci(&i7, 1);
		//cout << "Privilegovani tim: " << p1;
		//cout << endl;

		//MECEVI
		Mec m1(&t1,&t2),m2(&p1,&t3),m3(&t1,&p1);
		m1.odigrajmec();
		m2.odigrajmec();
		m3.odigrajmec();
		cout << m1 << endl;
		cout << m2 << endl;
		cout << m3 << endl;
		//cout << m3.dohvatirezultat();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}
// KONACAN KOD

