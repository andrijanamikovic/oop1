#include "garancija.h"

void Garancija::brisi()
{
	while (prvi) {
		Elem* tek = prvi;
		prvi = prvi->sled;
		delete tek;
	}
	posl = nullptr;
}

void Garancija::kopiraj(const Garancija& g)
{
	Elem* tek = g.prvi;
	while (tek) {
		Elem* novi = new Elem(tek->k);
		if (prvi == nullptr) {
			prvi = novi;
		}
		else
			posl->sled = novi;
		posl = novi;
		tek = tek->sled;
	}

}

void Garancija::premesti(Garancija& g)
{
	prvi = g.prvi;
	posl = g.posl;
	g.prvi = g.posl = nullptr;
}

Garancija::Garancija(const Garancija& g)
{
	kopiraj(g);
}

Garancija::Garancija(Garancija&& g)
{
	premesti(g);
}

Garancija::~Garancija()
{
	brisi();
}

Garancija& Garancija::operator=(const Garancija& g)
{
	if (this != &g) {
		brisi();
		kopiraj(g);
	}
	return *this;
}

Garancija& Garancija::operator=(Garancija&& g)
{
	if (this != &g) {
		brisi();
		premesti(g);
	}
	return *this;
}

void Garancija::dodaj_kvar(Kvar kv)
{
	if (kv.get_datum() < kraj) {
		Elem* pom = new Elem(kv);
		if (posl != nullptr) {
			if (posl->k.otklonjen) {
					posl->sled = pom;
				}
			}
		prvi = posl = pom;
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
