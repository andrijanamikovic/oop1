#ifndef _leva_zagrada_h_
#define _leva_zagrada_h_

#include "elementu.h"

class Leva: public Element {
public:
	Leva():Element(){}
	char getOZnaka() const override { return '('; }
	string getNatpis() const override { return "("; }

	Leva* kopija() {
		return this;
	}


};
#endif // !_leva_zagrada_h_
