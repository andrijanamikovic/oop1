#ifndef  _uredjaj_h_
#define _redjaj_h_
#include "garancija.h"

class Uredjaj {
private:
	static int current_id;
protected:
	string Proizvodjac;
	int id;
	Garancija gar;
	int max_kvarova;
public:
	Uredjaj(string p, int max) :Proizvodjac(p), max_kvarova(max), id(current_id++){};
	Uredjaj(const Uredjaj& u) = delete;
	Uredjaj(Uredjaj&& u) = delete;
	Uredjaj& operator = (const Uredjaj& u) = delete;
	Uredjaj& operator = (Uredjaj&& u) = delete;

	void set_garaniciju(Datum poc);
	Garancija get_garanciju()const { return gar; }

	int broj_kvarova() const { return max_kvarova; }

	friend bool operator == (Uredjaj u1, Uredjaj u2);

	friend ostream& operator << (ostream& os, Uredjaj& u);

};
#endif // ! _uredjaj_h_
