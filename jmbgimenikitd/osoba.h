#ifndef _osoba_h_
#define _odoba_h_

#include "jmbg.h"

class Osoba {
	string ime;
	JMBG jmbg;
public:
	Osoba(string i, JMBG j) :ime(i), jmbg(j) {};
	string dohvime() const { return ime; }
	JMBG dohvatijmbg() const { return jmbg; }
	void pisi() {
		cout << ime << "("; jmbg.ispis(); cout << ")" << endl;
	}

};
#endif // !_osoba_h_
