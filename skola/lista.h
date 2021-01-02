#ifndef  _lista_h_
#define _lista_h_
#include "Greske.h" 

template <typename T>
class Lista {
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr) {
			pod = p;
			sled = s;
		}
	};
	Elem* prvi = nullptr, * posl = nullptr;
	mutable Elem* tek, * pret;
	void kopiraj(const Lista& l);
	void premesti(Lista& l) {
		prvi = l.prvi;
		posl = l.posl;
		l.prvi = nullptr;
		l.posl = nullptr;
	}
	void isprazni();
public:
	Lista() {
		prvi = posl = tek = pret = nullptr;
	}
	Lista(const Lista& l) {
		kopiraj(l);
	}
	Lista(Lista&& l)
	{
		premesti(l);
	}
	~Lista() {
		isprazni();
	}
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			isprazni();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(const Lista&& l) {
		if (this != &l) {
			isprazni();
			premesti(l);
		}
		return *this;
	}
	Lista& dodaj(const T& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		return *this;
	}
	Lista& naPrvi() {
		tek = prvi;
		pret = nullptr;
		return *this;
	}
	const Lista& naPrvi() const {
		tek = prvi;
		pret = nullptr;
		return *this;
	}
	Lista& naSled() {
		pret = tek;
		if (tek)
			tek = tek->sled;
		return *this;
	}
	const Lista& naSled() const {
		pret = tek;
		if (tek)
			tek = tek->sled;
		return *this;
	}
	bool imaTek() const {
		return tek != nullptr;
	}

	T& dohvTek() {
		if (!tek) {
			throw GNemaTek();
		}
		return tek->pod;
	}

	const T& dohvTek() const {
		if (!tek) {
			throw GNemaTek();
		}
		return tek->pod;
	}

	Lista& izbciTek() {
		if (!tek) throw GNemaTek();
		Elem* stari = tek;
		tek = tek->sled;
		(!pret ? prvi : pret->sled) = tek;
		if (!tek) posl = pret;
		delete stari;
		return *this;
	}

};

template<typename T>
void Lista<T>::kopiraj(const Lista& l)
{
	prvi = posl = tek = pret = nullptr;
	for (Elem* pok = prvi; pok; pok = pok->sled) {
		Elem* novi = new Elem(pok->pod);
		posl = (!prvi ? prvi : posl->sled) = novi;
		if (pok == l.tek) tek = novi;
		if (pok == l.pret) pret = novi;
		delete novi;
	}
}

template<typename T>
void Lista<T>::isprazni()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = pret = nullptr;
}

#endif // ! _lista_h_

