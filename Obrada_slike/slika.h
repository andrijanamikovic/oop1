#ifndef _slika_h_
#define _slika_h_
#include "piksel.h"
#include "pozicija.h"

class Slika {
	int sirina = 0;
	int visina = 0;
	Piksel** mat = {};

public:
	Slika() {};
	Slika(int s, int v) {
		sirina = s;
		visina = v;
		mat = new Piksel* [visina];
		for (int i = 0; i < visina; i++) {
			mat[i] = new Piksel[sirina];
		}
	}
	int get_sirina() const { return sirina; }
	int get_visina() const { return visina; }

	Piksel get_piksel(Pozicija p) const;
	void set_piksel(Piksel p, Pozicija poz);
	int size();

	friend ostream& operator<<(ostream& os, Slika s);

	friend class CrnoBelaSlika;

};
#endif // !_slika_h_