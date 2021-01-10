#ifndef _privilegovani_h_
#define _privilegovani_h_
#include "team.h"

class Privilegovani :public Tim {
	double min;
	void pisi(ostream& os) const override {
		os << "(" << min << ")";
		os << naziv << "[";
		Tim::pisi(os);
	}
protected:
	void kopiraj(const Privilegovani& t);
	void premesti(Privilegovani& t);
public:
	Privilegovani(int d, string n, int m):Tim(d,n),min(m){}
	void dodajIgraca(int pozicija, Igrac& i) override {
		if (pozicija > duzina) {
			throw GNemaMesta();
		}
		if (i.getVrednost() < min) {
			throw GNijeKvalifikovan();
		}
		niz[pozicija-1] = new Igrac(i);
		trenutno++;
	}
	friend ostream& operator<<(ostream& os, const Privilegovani& p) {
		if (&p)
			p.pisi(os);
		return os;
	}
};

#endif // !_privilegovani_h_
