#include "garancija.h"

void Garancija::dodaj_kvar(Kvar kv)
{
	Elem* pom = new Elem(kv);
	if (kv.get_datum() < kraj) {
		if (prvi) {
			if (prvi->k.otklonjen) {
				if (prvi) {
					pom->sled = prvi;
				}
			}
		}
		prvi = pom;
	}
}

int Garancija::broj_kvarova() const
{
	if (!prvi)  return 0;
	Elem* pom = prvi;
	int br = 0;
	while (pom) {
		pom = pom->sled;
		br++;
	}
}

ostream& operator<<(ostream& os, Garancija g)
{
	return os << g.poc << "-" << g.kraj << "-broj kvarova" << g.broj_kvarova();
}
