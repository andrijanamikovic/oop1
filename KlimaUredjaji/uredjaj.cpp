#include "uredjaj.h"

int Uredjaj::current_id = 1;

void Uredjaj::set_garaniciju(Datum poc)
{
	gar = Garancija(poc, Datum(0,0,0));
}

bool operator==(Uredjaj u1, Uredjaj u2)
{
	return u1.Proizvodjac == u2.Proizvodjac;
}

ostream& operator<<(ostream& os, Uredjaj& u)
{
	string s = u.Proizvodjac + ":" + to_string(u.id);
	return os << s;
}
