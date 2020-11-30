#include "klima.h"

int main() {
	Datum d1(1, 3, 2012);
	Datum d2(5, 43, 2349);
	//cout << (d1 < d2)<<endl;
	//cout << d1["mesec"]<<endl;
	//cout << d2<<endl;

	Kvar k(d1, "crko brale");
	//cout << k.get_datum() << " " << k.get_opis();
	k.set_otklonjen(true);
	//cout << k;
	Datum d3(4, 2, 2340);
	Kvar k1(d3, "ne radi");
	Garancija g(d1, d2);
	g.dodaj_kvar(k);
	g.dodaj_kvar(k1);
	//cout << g.poslednji() << endl;
	//cout << g;
	Uredjaj u("Mile");
	Uredjaj u2("Mile");
	u.set_garaniciju(d1);
	//cout << u.get_garanciju();
	//cout << u;	
	Klima klima(24);

	klima.set_garancija(d2);
	cout << klima;
}