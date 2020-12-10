#ifndef _garancija_h_
#define _garancija_h_
#include "kvar.h"

class Garancija {
	struct Elem {
		Kvar k;
		Elem* sled;
		Elem(Kvar kv,Elem* s = nullptr):k(kv), sled(s){}
	};
	Datum poc;
	Datum kraj;
	Elem* prvi = nullptr;
	Elem* posl = nullptr;
	

	void brisi();
	void kopiraj(const Garancija& g);
	void premesti(Garancija& g);
public:
	Garancija(){}
	Garancija(Datum p, Datum k) :poc(p), kraj(k) {}
	Garancija(const Garancija& g);
	Garancija(Garancija&& g);
	~Garancija();
	Garancija& operator = (const Garancija& g);
	Garancija& operator = (Garancija&& g);

	void dodaj_kvar(Kvar kv);
	Kvar poslednji() const {
		return posl->k;
	}
	int broj_kvarova() const;
	friend ostream& operator << (ostream& os, Garancija g);


};
#endif // !_garancija_h_