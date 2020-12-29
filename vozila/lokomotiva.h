#ifndef _lokomotiva_h_
#define _lokomotiva_h_
#include "apstraktnoVozilo.h"

class Lokomotiva : public Apstraktno {
	double vucnaSila;
public:
	static const char vrsta = 'L';

	Lokomotiva(double s, double tez) : vucnaSila(s), Apstraktno(tez) {};
	double dohvVucnu() const { return vucnaSila; }
	virtual char getId() const {
		return vrsta;
	}
	virtual double dohvUkupnuTez() const { return this->dohvTezinu(); }
	virtual Apstraktno* kopija() const { return new Lokomotiva(*this); }
	void pisi(ostream& os)const {
		Apstraktno::pisi(os);
		os << " " << dohvVucnu() << endl;
	}

};
#endif // !_lokomotiva_h_