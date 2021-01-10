#ifndef _destinacija_h_
#define _destinacija_h_
#include <string>
#include <iostream>

using namespace std;

class Destinacija {
	string naziv;
	string opis;
	double prosecna_ocena = 0;
	int br = 0;
public:
	Destinacija(string n, string o):naziv(n),opis(o){}
	void oceni(unsigned int i);
	string getNaziv() const { return naziv; }
	string getOpis() const { return opis; }
	double prosecnaOcena() const { return prosecna_ocena; }

	friend bool operator>(const Destinacija d1, const Destinacija d2) {
		return d1.prosecna_ocena > d2.prosecna_ocena;
	}

	friend ostream& operator<<(ostream& os, const Destinacija& d) {
		return os << "[" << d.prosecnaOcena() << "]" << d.getNaziv() << "(" << d.opis << ")";
	}

};
#endif // !_destinacija_h_
