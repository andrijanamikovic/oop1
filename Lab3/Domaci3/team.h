#ifndef _tim_h_
#define _tim_h_
#include "greske.h"
#include "igrac.h"

class Tim {
protected:
	int trenutno;
	int duzina;
	string naziv;
	Igrac** niz;
	virtual void kopiraj(const Tim& t);
	virtual void premesti(Tim& t);
	void brisi();
	virtual void pisi(ostream& os) const {
		for (int i = 0; i <duzina; i++) {
			if (niz[i] != nullptr)
			{
				os << (*niz[i]);
				if (i != (duzina - 1)) os << ",";
			}
		}
		os << "]";
	}
public:
	Tim(int d, string n) {
		trenutno = 0;
		naziv = n;
		duzina = d;
		niz = new Igrac * [d];
		for (int i = 0; i < d; i++) {
			niz[i] = nullptr;
		}
	}
	Tim(const Tim& t) {
		kopiraj(t);
	}
	Tim(Tim&& t) {
		premesti(t);
	}
	~Tim() { brisi(); }

	Tim& operator=(const Tim& t) {
		if (this != &t) {
			brisi();
			kopiraj(t);
		}
		return *this;
	}
	
	Tim& operator=(Tim&& t) {
		if (this != &t) {
			brisi();
			premesti(t);
		}
		return *this;
	}
	virtual void dodajIgraca(int pozicija, Igrac& i) {
		if (pozicija > duzina) {
			throw GNemaMesta();
		}
		niz[pozicija-1] = new Igrac(i);
		trenutno++;
	}
	int brojIgracauTimu() const { return trenutno; }

	Igrac* operator[] (int i);
	const Igrac* operator[] (int i)const;

	double vrednostTima() const;

	friend bool operator==(const Tim& t1, const Tim& t2);
	friend ostream& operator<<(ostream& os, const Tim& t);
};
#endif // !_tim_h_
