#ifndef _letovanje_h_
#define _letovanje_h_

#include "Aranzman.h"

class Letovanje : public Aranzman {
public:
	Letovanje(string s, double c, Datum p, Datum k) :Aranzman(s, c, p, k) {}

	char getOznaku() const override { return 'L'; }
	virtual double izrCenu() const override {
		if (broj % 5 == 0) return 0.9 * cena;
		return cena;
	}
};

#endif // !_letovanje_h_