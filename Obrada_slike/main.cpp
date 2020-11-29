#include "piksel.h"
#include "pozicija.h"
#include "slika.h"
#include "crnobelaslika.h"

int main() {
	Piksel p1(23, 34, 256);
	Piksel p2(25, 156, 49);
	p2 += p1;

	cout << p2;
	cout << p1;
	//cout << (p1 == p2);

	Pozicija po1(3, 3);
	Pozicija po2(4, 3);
	cout << (po1 - po2);
	
	Slika s(5, 4);
	s.set_piksel(p1,po1);
	s.set_piksel(p2, po2);

	cout << s.get_piksel(po1);
	cout << endl;
	CrnoBelaSlika c = CrnoBelaSlika(s);
	cout << c;
}