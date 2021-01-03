#ifndef _lista_h_
#define _lista_h_
#include "Greske.h"

template <typename T>
class Lista {
	struct Elem {
		T data;
		Elem* next;
		Elem(T& d, Elem* sled = nullptr): data(d), next(sled){} 
	};
	Elem* prvi = nullptr, *posl = nullptr;
	mutable Elem* tek;
	void brisi();
	void kopiraj(const Lista& l);
	void premesti(Lista& l);

public:
	Lista() {
		prvi = posl = tek = nullptr;
	}
	Lista& dodajNaKraj(T d) {
		posl = (!prvi ? prvi : posl->next) = new Elem(d);
		return *this;
	}
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}
	~Lista() {
		brisi();
	}
	int brojElem() const;
	void naPrvi() const {tek = prvi;}
	//const void naPrvi() const { tek = prvi; }
	void naSled() const {
		if (tek) tek = tek->next;
	}
	bool daLiTek() const { return tek != nullptr; }
	T& getPod() const {
		if (!tek) throw GNemaTek();
		return tek->data;
	}

};


template<typename T>
inline void Lista<T>::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->next;
		delete stari;
	}
	posl = tek = nullptr;
}

template<typename T>
inline void Lista<T>::kopiraj(const Lista& l)
{
	prvi = posl = tek = nullptr;
	for (Elem* temp = l.prvi; temp; temp = temp->next) {
		posl = (!prvi ? prvi : posl->next) = new Elem(temp->data);
	}
}


template<typename T>
inline void Lista<T>::premesti(Lista& l)
{
	prvi = l.prvi;
	posl = l.posl;
	tek = l.tek;
	l.prvi = l.posl = nullptr;
}

template<typename T>
inline int Lista<T>::brojElem() const
{
	int br = 0;
	for (Elem* tek = prvi; tek; tek = tek->next) {
		br++;
	}
	return br;
}

#endif // !_lista_h_