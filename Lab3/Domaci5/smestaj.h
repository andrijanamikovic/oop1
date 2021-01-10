#ifndef _smestaj_h_
#define _smestaj_h_

#include "destinacija.h"
#include "greske.h"

enum TIP {HOTEL, APARTMAN };
const string nizSmestaja[2] = { "HOTEL","ARANZMAN" };
class Smestaj {
	Destinacija d;
	string naziv;
	TIP tip;
	int broj_zvezdica;
	double cena;
public:
	Smestaj(Destinacija des, TIP t, string n, int br, double c) :d(des) {
		if (br < 1 || br > 5)  throw GNeZvezdice();
		broj_zvezdica = br;
		naziv = n;
		cena = c;
		tip = t;
	}

	Destinacija getDestinacija() const { return d; }
	string getNaziv() const { return naziv; }
	string getTip() const { return nizSmestaja[tip]; }
	int getBrojZvezdica() const { return broj_zvezdica; }
	double getCenu() const { return cena; }

	friend ostream& operator<<(ostream& os, const Smestaj& s);

};
#endif // !_smestaj_h_
 