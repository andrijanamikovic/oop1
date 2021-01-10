
#include <iostream>
#include "destinacija.h"
#include "smestaj.h"
#include "prevoz.h"
#include "datum.h"
#include "aranzman.h"

using namespace std;

int main() {
	try {
		Destinacija d1("Zakintos", "Grcka");
		Destinacija d2("Kusadasi", "Turska");
		d1.oceni(5);
		d1.oceni(6);
		d1.oceni(4);
		d2.oceni(3);
		cout << (d1 > d2) << endl;
		cout << d1 << " " << d2 << endl;
		Smestaj s(d1, TIP::HOTEL, "Atina", 3, 2);
		cout << s << endl;
		Prevoz p(d1, 50.5);
		cout << p.getDestinaciju() << " " << p.getCenu() << endl;
		Datum datum1(2, 5, 2020);
		Datum datum2(29, 2, 2020);
		cout << datum1 << " " << (datum1 - datum2) << endl << endl;
		Aranzman a(d1, datum2, datum1);
	
		a.dodeliSmestaj(s);
		a.dodelirPrevoz(p);
		cout << a.getCena();
		cout << a;
	}
	catch (exception& e) {
		cout << e.what();
	}
	
}