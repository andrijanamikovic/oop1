#include "obavestenje.h"
#include "korisnik.h"

int Obavestenje::current_id = 0;

ostream& operator<<(ostream& os, const Obavestenje& o)
{
	os << o.id << "|" << o.koris->get_name() << "-" << o.h << ":" << o.m << ":" << o.s << endl;
	o.pisi(os);
	//os << specificno;
	return os;
}
