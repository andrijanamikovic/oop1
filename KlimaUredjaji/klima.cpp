#include "klima.h"

void Klima::set_garancija(Datum poc)
{
	Datum kraj(poc.dan, poc.mesec, poc.godina + 5);
	g = Garancija(poc, kraj);
}
int Klima::novi = 2;

bool operator==(Klima k1, Klima k2)
{
	return k1.kvadrata == k2.kvadrata;
}

ostream& operator<<(ostream& os, Klima k)
{
	return os << k.Proizvodjac << ":" << k.id << "#klima#" << "-" << k.kvadrata;
}
