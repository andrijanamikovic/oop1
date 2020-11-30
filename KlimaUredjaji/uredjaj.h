#ifndef  _uredjaj_h_
#define _redjaj_h_
#include "garancija.h"

class Uredjaj {
	string Proizvodjac;
	static int current_id;
	int id;
	Garancija gar;
	int novi=5;

public:
	//Uredjaj(const Uredjaj& u) = delete;

	Uredjaj(string p) :Proizvodjac(p), id(current_id++) {};
	void set_garaniciju(Datum poc);
	Garancija get_garanciju()const { return gar; }

	int broj_kvarova() const { return novi; }

	friend bool operator == (Uredjaj u1, Uredjaj u2);

	friend ostream& operator << (ostream& os, Uredjaj u);

};
#endif // ! _uredjaj_h_
