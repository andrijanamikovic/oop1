#ifndef _flota_h_
#define _flota_h_
#include "avion.h"

class Flota {
	string nazivFlote;
	struct Elem {
		Avion* avio;
		Elem* sled;
		Elem(Avion* a, Elem* s = nullptr) :avio(a), sled(s) {}
	};
	Elem* prvi = nullptr;
public:
	Flota(string n) :nazivFlote(n){}
	~Flota();
	void dodaj(Avion* a);

	int brojAviona() {
		Elem* tek = prvi;
		int br = 0;
		while (tek) {
			br++;
			tek = tek->sled;
		}
		return br;
	}

	int maxPutnka();

	Avion* dohvNajveci();

	void ispis() const;

	void izbaciAvion(string n);

	Elem* dohvIzm(int min, int m) {
		Elem* p = nullptr;
		Elem* tek = prvi;
		int b;
		while (tek) {
			b = tek->avio->dohvMax();
			if (b > min && b < m) {
				if (!p) {
					p = new Elem(tek->avio);
				}
				else {
					Elem* q = new Elem(tek->avio);
					q->sled = p;
					p = q;
				}
			}
		}
		return p;
	}
};
#endif // !_flota_h_
