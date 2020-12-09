#ifndef _pozicija_h_
#define _pozicija_h_

class Pozicija{
	int vrsta;
	int kolona;
public:
	Pozicija(int v, int k) :vrsta(v), kolona(k) {}
	int get_vrsta() const { return vrsta; }
	int get_kolona() const { return kolona; }

	friend int operator-(const Pozicija p1, const  Pozicija p2);
};
#endif // !_pozicija_h_

