#ifndef _let_h_
#define _let_h_
#include "avion.h"

class Let {
	string polaziste;
	string dolaziste;
	int id;
	static int current_id;
	Avion* av;
public:
	Let(string p, string d, Avion* a) :polaziste(p), dolaziste(d), av(a), id(current_id++) {};
	
	string dohvPol() const { return polaziste; }
	string dohvDol() const { return dolaziste; }
	int dohvID() const { return id; }
	Avion* dohvAvio() const { return av; }

	void ispis() {
		cout << "LET-" << dohvPol() << ":" << dohvDol() << endl;
	}
};
#endif // !_let_h_
