#pragma once
#include "figura.h"
#include "polje.h"
#include "greska.h"

class Top:public Figura
{
public:
	Top(Boja b, Polje p) : Figura(b,p){}
	char oznaka() const override { return 'T'; };
	void pomeriNa(const Polje& p) override {
		if (!(p + this->polje)) throw GPogresanPotez(); 
		this->polje = p;
	}
	int vrednost()const override { return 5; }
	Figura* kopija() const override {
		return new Top(*this);
	}
	
};

