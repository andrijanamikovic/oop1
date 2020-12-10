#include "klima.h"

Klima::Klima(string ime, int k):Uredjaj(ime,2),kvadrata(k)
{
}

void Klima::set_garancija(Datum poc)
{
	Datum kraj(poc.dan, poc.mesec, poc.godina + 5);
	gar = Garancija(poc, kraj);
}


bool operator==(Klima k1, Klima k2)
{
	return k1.kvadrata == k2.kvadrata;
}

ostream& operator<<(ostream& os, Klima& k)
{
	return os << k.Proizvodjac << ":" << k.id << "#klima#" << "-" << k.kvadrata;
}
