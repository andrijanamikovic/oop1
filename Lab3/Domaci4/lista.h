#ifndef _lista_h_
#define _lista_h_
#include <exception>

#include <iostream>

using namespace std;

class GPrazna :public exception {
public:
	GPrazna () :exception("Greska: List je prazna. ") {}
};

template <typename T>
class Lista {
	struct Elem {
		T* data;
		Elem* next;
		Elem(T* d, Elem* n = nullptr):data(d),next(n){}
	};
	Elem* prvi = nullptr, * posl = nullptr;
	int br = 0;

	virtual void kopiraj(const Lista& l);
	virtual void premesti(Lista& l);
	virtual void brisi();


public:


	Lista() {};
	Lista(const Lista& l) {
		kopiraj(l);
	}
	Lista(Lista&& l) {
		premesti(l);
	}
	~Lista() { brisi(); }

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

	int getBr() const { return br; }

	Lista& operator+=(T* dat) {
		posl = (!prvi ? prvi : posl->next) = new Elem(dat); //new Elem(dat->kopija()); //
		br++;
		return *this;
	}

	T* operator-() {
		if (posl == nullptr) throw GPrazna();
		T* d = posl->data;
		br--;
		Elem* pom = prvi;
		if (prvi == posl) prvi = posl = nullptr;
		else {
			while (pom->next != posl) {
				pom = pom->next;
			}
			pom->next = nullptr;
			posl = pom;
		}
		if (!posl) prvi = nullptr;
		return d;
	}


	T* operator*() {
		if (prvi == nullptr) throw GPrazna();
		br--;
		T* d = prvi->data;
		prvi = (prvi == posl ? nullptr : prvi->next);
		return d;
	}

	friend ostream& operator<<(ostream& os, const Lista& l) {
		if (!l.prvi) throw GPrazna();
		for (Elem* pom = l.prvi; pom; pom = pom->next) {
			os << *(pom->data);
			if (pom != l.posl) os << " ";
		}
		return os;
	}
};




template<typename T>
void Lista<T>::kopiraj(const Lista<T>& l)
{
	br = l.br;
	prvi = posl = nullptr;
	Elem* pom = l.prvi;
	while (pom) {
		posl = (!prvi ? prvi : posl->next) = new Elem(pom->data->kopija());
		pom = pom->next;
	}

}

template<typename T>
void Lista<T>::premesti(Lista<T>& l)
{
	prvi = l.prvi;
	posl = l.posl;
	br = l.br;
	l.prvi = l.posl = nullptr;
}

template<typename T>
void Lista<T>::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->next;
		delete stari;
	}
	posl = nullptr;
	br = 0;
}

#endif // !_lista_h_