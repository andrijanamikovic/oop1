#ifndef _turisticka_h_
#define _turisticka_h_

#include "lista.h"
#include "Aranzman.h"

class Turisticka :public Lista<Aranzman*> {
	string ime;
public:
	Turisticka(string s) :Lista<Aranzman*>(), ime(s) {}
	Turisticka(const Turisticka&) = delete;
	Turisticka& operator=(const Turisticka&) = delete;
	Lista<string>* nadjiOdDo(const Datum& d1, const Datum& d2, char tip);
	string nadjiMin();
	friend ostream& operator<<(ostream& os, const Turisticka& t);
};


#endif // !_turisticka_h_
