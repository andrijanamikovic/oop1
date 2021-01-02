#ifndef  _osoba_h_
#define _osoba_h_
#include "datum.h"
#include <string>
class Osoba {
	string ime;
	Datum rodjenje;
public:
	Osoba (string i, Datum& r):ime(i),rodjenje(r){}
	Osoba (const Osoba& o) = delete;
	//Osoba(Osoba&& o) = delete;
	virtual ~Osoba() { } //ako imam klasu koja se izvodi iz nje
	Osoba& operator=(const Osoba& o) = delete;
	string getIme() const { return ime; }
	Datum getRodj() const { return rodjenje; }
	Osoba& promeniIme(string i) {
		ime = i;
		return *this;
	}
	Osoba& promeniRodj(Datum r) {
		rodjenje = r;
		return *this;
	}
protected:
	virtual void pisi(ostream& os) const {
		os << ime << " (" << rodjenje<<")";
	}
	friend ostream& operator<<(ostream& os, Osoba& o) {
		o.pisi(os);
		return os;
	}
};
#endif // ! _osoba_h_