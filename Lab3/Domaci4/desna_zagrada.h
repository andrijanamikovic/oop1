#ifndef _desna_zagrada_h_
#define _desna_zagrada_h_

#include "elementu.h"

class Desna :public Element {
	char getOZnaka() const override { return ')'; }
	string getNatpis() const override { return ")"; }

	Desna* kopija() {
		return this;
	}
};

#endif // !_desna_zagrada_h_