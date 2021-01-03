#ifndef _zimovanje_h_
#define _zimovanje_h_

#include "Aranzman.h"

class Zimovanje : public Aranzman {
	bool ski;
public:
	Zimovanje(string s, double c, Datum p, Datum k, bool skipas) :Aranzman(s, c, p, k) {
		ski = skipas;
	}

	char getOznaku() const override { return 'Z'; }
	virtual double izrCenu() const override {
		if (ski) return 1.1 * cena;
		return cena;
	}

};

#endif // !_zimovanje_h_