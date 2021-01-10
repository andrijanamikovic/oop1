#include "aranzman.h"

int Aranzman::getCena() 
{
	if (smestaj == nullptr || prevoz == nullptr) throw GNemaCena();
	return (prevoz->getCenu() + (smestaj->getCenu() * (kraj - pocetak)));
}

void Aranzman::dodeliSmestaj(Smestaj& s)
{
	if (s.getDestinacija().getNaziv() != dest.getNaziv()) throw GNeIspravanSmestaj();
	smestaj = &s;
}

void Aranzman::dodelirPrevoz(Prevoz& p)
{
	if (p.getDestinaciju().getNaziv() != dest.getNaziv()) throw GNeIspravanPrevoz();
	prevoz = &p;
}

ostream& operator<<(ostream& os, const Aranzman& a)
{
	os << a.getDestinacija();
	os << endl;
	os << (*a.smestaj) << endl;
	os << const_cast<Aranzman&>(a).getCena();
	return os;
}
