#ifndef _dinarski_h_
#define _dinarski_h_

#include "racun.h"

class Dinarski :public Racun {
public:
	Dinarski (Osoba& o1, int i):Racun(o1,i){}
	virtual string valuta() const { return "RSD"; }
};
#endif // !_dinarski_h_
