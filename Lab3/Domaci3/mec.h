#ifndef _mec_h_
#define _mec_h_

#include "greske.h"
#include "par.h"
#include "team.h"

enum ishod_meca{POBEDA_DOMACINA, NERESENO, POBEDA_GOSTA};
class Mec {
	Par<Tim> timovi;
	ishod_meca ishod;
	bool odigran_mec = false;
	Par<int>poeni;
public:
	Mec(Tim* t1, Tim* t2) :timovi(t1, t2),poeni(new int(0),new int(0)) {
		//int b = 0;
		//poeni.setPrvi(&b);
		//poeni.setDrugi(&b);
		//poeni = Par<int>::Par(&b, &b);
		//ishod = ishod_meca::POBEDA_DOMACINA;
	}
	void odigrati();//Tim& t1, Tim& t2);
	bool mecOdigran() const { return odigran_mec; }
	Par<int> getPoeni() {
		if (!odigran_mec) throw GNijeOdigranMec();
		return poeni;
	}
	friend ostream& operator<<(ostream& os, const Mec& m) {
		os << m.timovi;
		if (m.odigran_mec) os << m.ishod;
		return os;
	}
};
#endif // !_mec_h_
