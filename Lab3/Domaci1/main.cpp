#include <iostream>
#include "Greska.h"
#include "datum.h"
#include "osoba.h"
#include "dinarski.h"

using namespace std;

int main() {
	try {
		Datum d1(29, 2, 2020);
		Datum d2(31, 4, 2020);
		cout << "Da li su datumi: " << d1 << " i " << d2 << "jednaki?" << endl;
		cout << (d1 == d2) << endl;


		Osoba osoba1("Mika", "023432494", d1);
		Osoba osoba2("Zika", "023432494", d2);

		cout << osoba1 << endl;
		cout << "Maticni broj osobe2 je: " << osoba2.getJMBG() << "ime " << osoba2.getIme() << " i datum " << osoba2.getDatum() << endl;
		Dinarski din1(osoba1, 1);
		Dinarski din2(osoba2, 2);
		din1 += 100;
		din2 += 50;
		cout << din1 << " " << din2<<endl;
		if (din1.prenos(50, din2))
			cout << din1 << " " << din2<<endl;
	}
	catch (exception e) {
		cout << e.what();
	}
}