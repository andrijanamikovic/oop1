#ifndef _aranzman_h_
#define _aranzman_h_
#include "Datum.h"
#include <string>
#include "Greske.h"

class Aranzman {
protected:
	string naziv;
	double cena;
	Datum poc;
	Datum kraj;
	int broj = 0;
public:
	Aranzman(string s, double c, Datum p, Datum k):poc(p),kraj(k) {
		if (k < p) throw GKrajPrePoc();
		naziv = s;
		cena = c;
	}
	int operator~() { return broj; }
	void operator++() { broj++; }
	Datum getPoc() const { return poc; }
	Datum getKraj() const { return kraj; }
	string getNaziv() const { return naziv; }
	virtual char getOznaku() const = 0;
	virtual double izrCenu() const = 0;
	virtual ~Aranzman() {}

	friend ostream& operator<< (ostream& os, const Aranzman& a) {
		return os << a.getOznaku() << "|" << a.poc << "-" << a.kraj << "|" << a.naziv << "-" << a.izrCenu() << "." << endl;
	}
};
#endif // !_aranzman_h_
