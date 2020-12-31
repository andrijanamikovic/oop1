#pragma once
#include "figura.h"
#include <iostream>

class Sah
{
	Figura* figure[8][8];
	Figura::Boja naPotezu = Figura::Boja::BELA;
	void kopiraj(const Sah& sah);
	void premesti(Sah& sah);
	void brisi();
public:
	Sah();
	Sah(const Sah& sah) { kopiraj(sah); }
	Sah(Sah&& sah) { premesti(sah); }
	~Sah() { brisi(); }
	Sah& operator=(const Sah& sah) {
		if (this != &sah) { brisi(); kopiraj(sah); }
		return *this;
	}
	Sah& operator=(Sah&& sah) {
		if (this != &sah) { brisi(); kopiraj(sah); }
		return *this;
	}
	Figura*& operator[] (const Polje& p);
	Figura* operator[] (const Polje& p) const;	
	Sah& operator+=(Figura& f);

	friend std::ostream& operator<<(std::ostream& os, Sah& s);

	void pomeri(const Polje& sa, const Polje& na);
	
};

