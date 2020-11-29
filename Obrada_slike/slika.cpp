#include "slika.h"

Piksel Slika::get_piksel(Pozicija p) const
{
	return this->mat[p.get_kolona()][p.get_vrsta()];
}

void Slika::set_piksel(Piksel p, Pozicija poz)
{
	mat[poz.get_kolona()][poz.get_vrsta()] = p;
}

int Slika::size()
{
	return visina * sirina * sizeof(Piksel);
}

ostream& operator<<(ostream& os, Slika s)
{
	os << s.size();
	for (int i = 0; i < s.get_visina(); i++) {
		for (int j = 0; j < s.get_sirina(); j++) {
			os << s.mat[i][j];
		}
		os << endl;
	}
	return os;
	// TODO: insert return statement here
}
