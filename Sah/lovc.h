#pragma once
#include "figura.h"
#include "polje.h"
#include "greska.h"

class Lovac :public Figura
{
public:
	Lovac(Boja b, Polje p) : Figura(b, p) {}
	char oznaka() const override { return 'L'; };
	void pomeriNa(const Polje& p) override {
		if (!(p / this->polje)) throw GPogresanPotez();
		this->polje = p;
	}
	int vrednost()const override { return 3; }
	Figura* kopija() const override {
		return new Lovac(*this);
	}
};

