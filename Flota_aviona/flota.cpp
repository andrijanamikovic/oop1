#include "flota.h"

void Flota::dodaj(Avion* a)
{
	Elem* pom = new Elem(a);
	if (prvi) {
		pom->sled = prvi;
	}
	prvi = pom;
}

int Flota::maxPutnka() {
	Elem* tek = prvi;
	int max = 0;
	while (tek) {
		max += tek->avio->dohvMax();
		tek = tek->sled;
	}
	return max;
}

	
Avion* Flota::dohvNajveci()
{
	Elem* tek = prvi->sled;
	Avion* max = prvi->avio;
	int max1;
	while (tek) {
		max1 = tek->avio->dohvMax();
		if (max1 > max->dohvMax()) {
			max = tek->avio;
		}
	}
    return max;
}

void Flota::ispis() const
{
	cout << nazivFlote << endl;
	Elem* tek = prvi;
	while (tek) {
		tek->avio->ispis();
		tek = tek->sled;
	}
}

void Flota::izbaciAvion(string n)
{
	Elem* tek = prvi;
	Elem* prethodni = nullptr;

	while (tek) {
		if (tek->avio->dohvNaziv() == n) {
			if (tek == prvi) {
				prvi = prvi->sled;
			}
			else {
				prethodni->sled = tek->sled;
				delete[] tek;
			}
			prethodni = tek;
			tek = tek->sled;
		}
	}
}
