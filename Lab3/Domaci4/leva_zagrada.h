#ifndef _leva_zagrada_h_
#define _leva_zagrada_h_

#include "elementu.h"

class Leva: public Element {
public:

	char getOZnaka() const override { return '('; }
	string getNatpis() const override { return "("; }

	virtual Leva* kopija() = 0;


};
#endif // !_leva_zagrada_h_
