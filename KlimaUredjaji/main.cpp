#include "kvar.h"

int main() {
	Datum d1(1, 3, 2012);
	Datum d2(5, 43, 2349);
	cout << (d1 < d2)<<endl;
	cout << d1["mesec"]<<endl;
	cout << d2<<endl;

	Kvar k(d1, "crko brale");
	cout << k.get_datum() << " " << k.get_opis();
	k.set_otklonjen(true);
	cout << k;

}