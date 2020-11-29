#include "kvar.h"

Kvar::Kvar(Datum d, string o)
{
	datum = Datum(d.dan, d.mesec, d.godina);
	opis = o;
	otklonjen = false;
}

ostream& operator<<(ostream& os, Kvar k)
{
	return os << k.datum << "-" << k.opis;
}
