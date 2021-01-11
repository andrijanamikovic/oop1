#ifndef _izraz_h_
#define _izraz_h_

#include "lista.h"
#include "elementu.h"

class Izraz :public Lista<Element> {

public:
	Izraz():Lista<Element>() {}


	Izraz* kopija() {
		return this;
	}

};
#endif // !_izrz_h_
