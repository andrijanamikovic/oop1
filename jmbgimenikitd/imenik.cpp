#include "imenik.h"

Imenik::Imenik(Imenik& i)
{
	prvi = nullptr;
	for (Elem* tek = i.prvi, *posl = nullptr; tek; tek = tek->sled) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(tek->data);
	}
}

Imenik::~Imenik() {
	while (prvi) {
		Elem* tek = prvi;
		prvi = prvi->sled;
		delete tek;
	}
}

Imenik Imenik::dodaj(const Osoba& oso)
{
	Elem *tek = prvi, *pret = nullptr;
	while (tek && veci(oso.dohvatijmbg(),tek->data.dohvatijmbg())) {
		pret = tek;  tek = tek->sled;
	}
	(!tek ? prvi : pret->sled) = new Elem (oso, tek);

	
	//return Imenik();
}

