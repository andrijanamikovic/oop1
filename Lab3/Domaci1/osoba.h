#ifndef _osoba_h_
#define _osoba_h_
#include "datum.h"
#include <string>

using namespace std;

class Osoba {
	string ime;
	string jmbg;
	Datum d;
public:
	Osoba(string i, string j, Datum dat):ime(i),jmbg(j),d(dat){}
	Osoba(const Osoba&) = delete;
	Osoba& operator=(const Osoba&) = delete;

	string getIme() const { return ime; }
	string getJMBG() const { return jmbg; }
	Datum getDatum() const { return d; }


	friend ostream& operator<<(ostream& os, const Osoba& o) {
		return os << "O(" << o.ime << "," << o.jmbg << "," << o.d << ")";
	}

};

#endif // !_osoba_h_
