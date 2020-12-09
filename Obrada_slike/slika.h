#ifndef _slika_h_
#define _slika_h_
#include "piksel.h"
#include "pozicija.h"

class Slika {
protected:

	int sirina = 0;
	int visina = 0;
	Piksel** mat = nullptr;
	void brisi();
	void kopiraj(const Slika& s);
	void premesti(Slika& s);

public:
	//Slika() {};
	Slika(const Slika& s);
	Slika(Slika&& s);
	~Slika();

	Slika(int s, int v);

	int get_sirina() const { return sirina; }
	int get_visina() const { return visina; }

	Piksel get_piksel(Pozicija p) const;
	void set_piksel(Piksel p, Pozicija poz);
	int size() const;

	friend ostream& operator<<(ostream& os, Slika s);
	Piksel operator [](Pozicija poz) const;

	Slika& operator=(const Slika& s);
	Slika& operator=(Slika&& s);

	//friend class CrnoBelaSlika;

};
#endif // !_slika_h_