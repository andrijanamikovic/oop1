#ifndef _list_h_
#define _lista_h_

#include "obavestenje.h"

class Lista {
	struct Elem {
		Obavestenje* o;
		Elem* sled;
		Elem(Obavestenje* oo, Elem* s = nullptr) : o(oo), sled(s) {}
	};
	Elem* prvi = nullptr;
	void brisi();
public:
	Lista() {}
	Lista(const Lista& l) = delete;
	Lista(Lista&& l) = delete;
	Lista& operator=(const Lista& l) = delete;
	Lista& operator = (Lista&& l) = delete;
	~Lista();

	Lista& operator+=(Obavestenje* o);
	void operator() () const;
	int operator+() const;
	void operator!();
	void operator~() {brisi();}
	Obavestenje* operator[](int id);
	friend ostream& operator << (ostream& os, const Lista& l);

};
#endif // !_list_h_
