#include "piksel.h"
#include "pozicija.h"
#include "slika.h"
int main() {
	Piksel p1(23, 34, 256);
	Piksel p2(25, 156, 49);
	p2 += p1;

	cout << p2;
	cout << p1;
	//cout << (p1 == p2);

	Pozicija po1(3, 4);
	Pozicija po2(5, 4);
	cout << (po1 - po2);
	
	Slika s(5, 4);
}