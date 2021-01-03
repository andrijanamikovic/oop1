#include "Turisticka.h"
#include "zimovanje.h"
#include "letovanje.h"

int main() {
	try {
		Datum d1(1, 1, 2021), d2(10, 1, 2021), d3(15, 1, 2021);
		Aranzman* l1 = new Letovanje("Neos Marmaros", 300, d1, d2);
		Aranzman* z1 = new Zimovanje("Kopaonik", 300, d1, d3, true);
		Aranzman* z2 = new Zimovanje("Jahorina", 80, d2, d3, true);
		Turisticka a("Sunce");
		a.dodajNaKraj(l1).dodajNaKraj(z1).dodajNaKraj(z2);
		cout << a;

		Datum d4(31, 12, 2020), d5(13, 1, 2021);
		Lista<string>* l = a.nadjiOdDo(d4, d5, 'Z');
		for (l->naPrvi(); l->daLiTek(); l->naSled())
			cout << l->getPod() << endl;

		cout << "Najjeftiniji: " << a.nadjiMin();
		delete l1; delete z1; delete z2;
		delete l;
	}
	catch (exception& e) {
		cout << e.what();
	}
}