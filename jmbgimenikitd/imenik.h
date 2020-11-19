#ifndef _imenik_h_
#define _imenik_h_

#include "osoba.h"

class Imenik {
	struct Elem
	{
		Osoba data;
		Elem* sled; 
		Elem(Osoba* o, Elem* s = nullptr) : data(o), sled(s) {};
	};
	Elem *prvi;
public:
	Imenik () { prvi = nullptr; }
	Imenik (Imenik& i);
	~Imenik();
	Imenik dodaj(const Osoba& oso);
	void ispis(Imenik& i);

};
#endif // !_imenik_h_
