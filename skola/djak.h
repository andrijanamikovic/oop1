#ifndef _djak_h_
#define _djak_h_

#include "ispit.h"
#include "osoba.h"
#include "lista.h"

class Djak : public Osoba {

	Lista<Ispit*> ispiti;
	void pisi(ostream& os) const  override {
		Osoba::pisi(os);
		os << " Srednja ocena: " << srOcena();
	}
	

public:
	Djak(string i, Datum& d): Osoba(i,d){}
	Djak& operator+=(Ispit* i) {
		ispiti.dodaj(i);
		return *this;
	}

	double srOcena() const;
	~Djak();
	friend ostream& operator<< (ostream & os, const Djak& dj) {
		if (&dj)
			dj.pisi(os);
		return os;
	}
};

#endif // !_djak_h_
