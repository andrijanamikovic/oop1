#ifndef _racun_h_
#define _racun_h_

#include "osoba.h"
#include "Greska.h"

class Racun {
	Osoba& vlasnik;
	int brojRacuna;
	int iznos = 0;
public:
	Racun (Osoba& o, int b):vlasnik(o), brojRacuna(b){}
	Racun(const Racun&) = delete;
	Racun& operator= (const Racun&) = delete;

	virtual string valuta() const = 0;
	int getBrojRacuna() const { return brojRacuna; }
	int getIznos() const { return iznos; }

	bool prenos(int i, Racun& r1) { 
		if (i > iznos) return false;
		r1.iznos += i;
		iznos -= i;
		return true;
	}

	Racun& operator+=(int i) {
		iznos += i;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Racun& r) {
		return os << "R:" << r.brojRacuna << ":=:" << r.iznos << "-" << r.valuta();
	}
};
#endif // !_racun_h_
