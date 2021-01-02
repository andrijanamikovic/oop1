#ifndef  _skola_h_
#define _skola_h_
#include "lista.h"
#include "djak.h"

class Skola {
	string ime;
	Lista<Djak*> djaci;
public:
	Skola(string i) {
		ime = i;
	}
	Skola(const Skola& s) = delete;
	void operator = (const Skola& s) = delete;
	Skola& operator+=(Djak& dj) {
		djaci.dodaj(&dj);
		return *this;
	}

	const Djak* najbolji() const;
};
#endif // ! _skola_h_
