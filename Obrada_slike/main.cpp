#include "piksel.h"
#include "pozicija.h"
#include "slika.h"
#include "crnobelaslika.h"

int main() {
	Piksel p1(3, 4, 6);
	Piksel p2(25, 156, 49);
	Piksel p3 = p1 + p2;

	/*cout << p1;
	cout << p2;
	cout << p3;
	//cout << (p1 == p2);
	*/
	Pozicija po1(3, 3);
	Pozicija po2(4, 3);
	//cout << (po1 - po2);
	Pozicija po3(0, 2);
	Slika s(5, 4);
	s.set_piksel(p1,po1);
	s.set_piksel(p2, po2);
	s.set_piksel(p3, po3);
	//cout << "S:" << s;

	//cout << s.get_piksel(po1);
	cout << endl;

	CrnoBelaSlika cbs(5, 4);
	cbs.set_piksel(Piksel(230,230,230), po1);
	cbs.set_piksel(Piksel(240, 230, 230), po2);
	cbs.set_piksel(Piksel(180, 230, 230), po3);


	cout << "CBS" << cbs;
}