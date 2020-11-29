#ifndef _crnobelaslika_h_
#define _crnobelaslika_h_
#include "slika.h"

class CrnoBelaSlika : public Slika {
	int sirina = 0;
	int visina = 0;
	Piksel** mat = {};

public:
	CrnoBelaSlika(Slika s) {
		sirina = s.sirina;
		visina = s.visina;
		mat = s.mat;
	}
	void set_piksel(Piksel p, Pozicija poz);
};
#endif // !_crnobelaslika_h_
