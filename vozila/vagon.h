#ifndef _vagon_h_
#define _vagon_h_
#include "Greska.h"

#include "apstraktnoVozilo.h"

class Vagon : public Apstraktno {
	static double srednjaSTezina;
	int putnika = 50;
	int brPutnika = 0;
public:
	static const char vrsta = 'P';

	static void postaviSTezinu(double tezina) {
		srednjaSTezina = tezina;
	}
	static double dohvSTezinu() {
		return srednjaSTezina;
	}
	Vagon(int p, int tez) : Apstraktno(tez) {
		this->putnika = p;
	}
	virtual char getId() const {
		return vrsta;
	};
	virtual double dohvUkupnuTez() const { return this->dohvTezinu() + brPutnika * srednjaSTezina; }
	virtual Apstraktno* kopija() const {
		return new Vagon(*this);
	}
	void UlazakPutnika(int broj) {
		if (brPutnika + broj > putnika) throw GPrevisePutnika();
		brPutnika += broj;
	}

	void izlazakPutnika(int broj) {
		putnika -= broj;
		if (putnika < 0) {
			putnika = 0;
		}
	}
	void pisi(ostream& os)const {
		Apstraktno::pisi(os);
		os << " " << putnika <<" "<< brPutnika *srednjaSTezina<<  endl;
	}



};

#endif // !_vagon_h_