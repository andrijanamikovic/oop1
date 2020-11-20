#ifndef _arhiva_h_
#define _arhiva_h_
#include "let.h"

class Arhiva {
	struct ElemArhive {
		Let* let;
		ElemArhive* sled;
		ElemArhive(Let* l = nullptr, ElemArhive* s = nullptr) :let(l), sled(s) {};
	};
	ElemArhive* prvia = nullptr;
public:
/*	ElemArhive* dohvLetovePol(string p) {
		ElemArhive* teka = prvia;
		ElemArhive* q = nullptr;
		while (teka) {
			if (teka->let->dohvPol() == p) {
				if (!q) {
					q = teka;
				}
				else {
					ElemArhive* pomocni;
					pomocni = new ElemArhive(teka->let,q);
					q = pomocni;
				}
			}
		}
		return q;
	}
	ElemArhive* dohvLetoveDol(string p) {
		ElemArhive* teka = prvia;
		ElemArhive* q = nullptr;
		while (teka) {
			if (teka->let->dohvDol() == p) {
				if (!q) {
					q = teka;
				}
				else {
					ElemArhive* pomocni;
					pomocni = new ElemArhive(teka->let, q);
					q = pomocni;
				}
			}
		}
		return q;
	}*/
	ElemArhive* dohvLetove(string p ="", string d="") {
		ElemArhive* teka = prvia;
		ElemArhive* q = nullptr;
		while (teka) {
			if (teka->let->dohvDol() == p|| teka->let->dohvDol() == d) {
				if (!q) {
					q = teka;
				}
				else {
					ElemArhive* pomocni;
					pomocni = new ElemArhive(teka->let, q);
					q = pomocni;
				}
			}
		}
		return q;
	}
	void dodaj(Let* l) {
		ElemArhive* pom = new ElemArhive(l);
		if (prvia) {
			pom->sled = prvia;
		}
		prvia = pom;
	}
	~Arhiva() {
		ElemArhive* tek;
		while (prvia) {
			tek = prvia;
			delete[]tek;
			prvia = prvia->sled;
		}
	}
};
#endif // !_arhiva_h_
