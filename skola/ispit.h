#ifndef _ispit_h_
#define _ispit_h_
#include "datum.h"

class Ispit {
	char sifra;
	int ocena;
	Datum datPolaganja;
public:

	Ispit(char s, Datum& d, int o) : sifra(s), ocena(o), datPolaganja(d){} //mozda ovde treba d da se salje kao referenca zato sto je zabranjeno kopiranje? ali onda mora i u osoba.h
	Ispit(const Ispit&) = delete;
	void operator= (const Ispit&) = delete;

	char getSifra() const { return sifra; }
	int getOcena() const { return ocena; }
	Datum getDat() const { return datPolaganja; }

};
#endif // !_ispit_h_