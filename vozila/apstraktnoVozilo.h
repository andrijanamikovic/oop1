#ifndef _apstraktnoVozilo_h_
#define _apstraktnoVozilo_h_
#include <iostream>
using namespace std;
class Apstraktno {

	double tezina;
public:
	Apstraktno(double t) : tezina(t) {};
	Apstraktno() = default;
	Apstraktno(const Apstraktno& a) = default ;
	Apstraktno(Apstraktno&& a) = default;
	~Apstraktno() = default;

	double dohvTezinu() const { return tezina; }
	virtual char getId() const = 0;
	virtual double dohvUkupnuTez() const = 0;
	virtual Apstraktno* kopija() const = 0;

protected:

	virtual void pisi(ostream& os)const  {
		os << getId() << " " << tezina;
	}
	friend ostream& operator<<(ostream& os, const Apstraktno& a) {
		a.pisi(os);
		return os;
	}

};
#endif // !_apstraktnoVozilo_h_
