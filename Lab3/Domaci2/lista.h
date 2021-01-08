#ifndef _lista_h_
#define _lista_h_
#include <exception>

using namespace std;

class GNemaTek :public exception {
public:
	GNemaTek() :exception("Greska: Nema tekuceg elementa. "){}
};


template <typename T>
class Lista {
	int duzina = 0;
	struct Elem {
		T data;
		Elem* next;
		Elem(T& d, Elem* sled = nullptr): data(d), next(sled){}
	};
	Elem* prvi, * posl;
	mutable Elem* tek;
	void brisi();
public:
	Lista() { prvi = tek = posl = nullptr; duzina = 0; }
	Lista(const Lista& l) = delete;
	Lista& operator= (const Lista& l) = delete;
	~Lista() { brisi(); }


	Lista& dodajNaKraj(T d) {
		posl = (!prvi ? prvi : posl->next) = new Elem(d);
		duzina++;
		return *this;
	}
	void naPrvi() const { tek = prvi; }
	void naSled() const {
		if (tek) {
			tek = tek->next;
		}
	}
	bool Tek() const {
		return tek != nullptr;
	}

	T& getData() const {
		if (!tek) throw GNemaTek();
		return tek->data;
	}

};

template<typename T>
void Lista<T>::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->next;
		delete stari;
	}
	posl = tek = nullptr;
}



#endif // !_lista_h_