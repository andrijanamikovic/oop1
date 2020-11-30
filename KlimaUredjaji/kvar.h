#ifndef _kvar_h_
#define _kvar_h_
#include "datum.h"

class Kvar {
	Datum datum;
	string opis;
	bool otklonjen;

public:
	Kvar(Datum d, string o);
	Datum get_datum() const { return datum; }
	string get_opis() const { return opis; }
	void set_otklonjen(bool o) { otklonjen = o; }
	friend ostream& operator << (ostream& os, Kvar k);
	friend class Garancija;
};
#endif // !_kvar_h_