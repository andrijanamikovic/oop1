#ifndef  _voz_h_
#define _voz_h_
#include "apstraktnoVozilo.h"
#include "Greska.h"
#include "lokomotiva.h"
#include "vagon.h"

class Voz : public Apstraktno {
	string s;
	struct Elem {
		Apstraktno* v;
		Elem* sled;
		Elem(Apstraktno* a) {
			v = a;
			sled = nullptr;
		}
	};
	Elem* prvi = nullptr, * posl = nullptr;
public:
	static const char vrsta = 'v';
	Voz(string ime) : s(ime) {}
	Voz& operator+=(const Lokomotiva& l);
	Voz& operator+=(const Vagon& v);

	double ukupnaTezina() const;
	char getId() const {
		return vrsta;
	}
	double dohvUkupnuTez() const {
		return this->ukupnaTezina();
	}
	Apstraktno* kopija() const {
		return new Voz(*this);
	}
	void pisi(ostream& os)const {
		Apstraktno::pisi(os);
		os << s << endl;
	}
};
#endif // ! _voz_h_