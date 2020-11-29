#ifndef _pozicija_h_
#define _pozicija_h_

class Pozicija{
	int vrsta;
	int kolona;
public:
	Pozicija(int v, int k) :vrsta(v), kolona(k) {}
	int get_vrsta() { return vrsta; }
	int get_kolona() { return kolona; }

	friend int operator-(Pozicija p1, Pozicija p2);
};
#endif // !_pozicija_h_

