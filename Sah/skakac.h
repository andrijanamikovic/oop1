#pragma once
#include "figura.h"
#include "polje.h"
#include "greska.h"

class Skakac :public Figura
{
public:
	Skakac(Boja b, Polje p) : Figura(b, p) {}
	char oznaka() const override { return 'S'; };
	void pomeriNa(const Polje& p) override {
		if (abs(p.getRed() - this->polje.getRed())+abs(p.getKolona()-this->polje.getKolona())==3
			&& p.getKolona()!=this->polje.getKolona() && p.getRed() != this->polje.getRed()) this->polje = p; 
		else
			throw GPogresanPotez();
		
	}
	int vrednost()const override { return 2; }

	Figura* kopija() const override {
		return new Skakac(*this);
	}
};

