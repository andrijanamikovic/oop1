#include "voz.h"
#include "lokomotiva.h"

Voz& Voz::operator+=(const Lokomotiva& l)
{
	if (prvi) throw GDveLokomotive();
	posl = prvi = new Elem(l.kopija());
	return *this;
}

Voz& Voz::operator+=(const Vagon& v)
{
	if (!prvi) throw GNemaLokomotive();
	if (ukupnaTezina() + v.dohvUkupnuTez() > ((Lokomotiva*)(prvi->v))->dohvVucnu()) throw GPreopterecenVoz();

	posl = posl->sled = new Elem(v.kopija());
	return *this;
}

double Voz::ukupnaTezina() const
{
	double t = 0;
	for (Elem* tek = prvi; tek; tek = tek->sled) {
		t += tek->v->dohvUkupnuTez();
	}

	return t;

}
