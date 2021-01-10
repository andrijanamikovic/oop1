#ifndef _prevoz_h_
#define _prevoz_h_

#include "destinacija.h"

class Prevoz {
	Destinacija d;
	double cena;
public:
	Prevoz(Destinacija des, double c) : d(des), cena(c){}
	Destinacija getDestinaciju() const { return d; }
	double getCenu() const { return cena; }
};
#endif // !_prevoz_h_
