#pragma once
#include "polje.h"
#include "greska.h"
#include <iostream>

class Figura
{
public:
	enum Boja{BELA, CRNA};
protected:
	Boja boja;
	Polje polje;
public:
	Figura(Boja b, Polje p): boja(b), polje(p){}
	virtual char oznaka() const = 0;
	virtual void pomeriNa (const Polje& p) = 0;
	friend std::ostream& operator<<(std::ostream& os, const Figura& f) {
		if (f.boja== Figura::BELA) {
			return os << f.oznaka() << f.polje;
		}
		else {
			return os << (char)(f.oznaka() + 32) << f.polje;
		}
	}

	bool operator>(const Figura& f1) {
		return (*this).vrednost() == f1.vrednost();
	}
	virtual int vrednost()const = 0;
	virtual Figura* kopija()const = 0;

	Boja getBoja() const { return boja; }
	Polje getPolje() const { return polje; }
};

