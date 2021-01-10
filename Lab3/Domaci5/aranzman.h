#ifndef _aranzman_h_
#define _aranzman_h_

#include "datum.h"
#include "smestaj.h"
#include "prevoz.h"

class Aranzman {
	Datum pocetak;
	Datum kraj;
	Destinacija dest;
	Smestaj* smestaj = nullptr;
	Prevoz* prevoz = nullptr;
public:
	Aranzman(Destinacija d,Datum poc, Datum k):pocetak(poc),kraj(k),dest(d){}
	Datum getPocetak() const { return pocetak; }
	Datum getKraj() const { return kraj; }
	Destinacija getDestinacija() const { return dest; }

	int getTrajanje() { return (kraj-pocetak); }

	double getCena();

	void dodeliSmestaj(Smestaj& s);
	void dodelirPrevoz(Prevoz& p);

	friend ostream& operator<<(ostream& os, const Aranzman& a);

};
#endif // !_aranzman_h_
