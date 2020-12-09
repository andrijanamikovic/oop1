#include "slika.h"

void Slika::brisi()
{
	for (int i = 0; i < visina; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	mat = nullptr;
}

void Slika::kopiraj(const Slika& s)
{
	visina = s.visina;
	sirina = s.sirina;

	mat = new Piksel * [visina];

	for (int i = 0; i < visina; i++) {
		mat[i] = new Piksel[sirina];
		for (int j = 0; j < sirina; j++) {
			mat[i][j] = s.mat[i][j];
		}
	}
}

void Slika::premesti(Slika& s)
{
	visina = s.visina;
	sirina = s.sirina;

	mat = s.mat;
	s.mat = nullptr;
}

Slika::Slika(const Slika& s)
{
	kopiraj(s);
}

Slika::Slika(Slika&& s)
{
	premesti(s);
}

Slika::~Slika()
{
	brisi();
}

Slika::Slika(int s, int v)
{
	sirina = s;
	visina = v;
	mat = new Piksel * [visina];
	for (int i = 0; i < visina; i++) {
		mat[i] = new Piksel[sirina];
	}
}

Piksel Slika::get_piksel(Pozicija p) const
{
	return this->mat[p.get_kolona()][p.get_vrsta()];
}

void Slika::set_piksel(Piksel p, Pozicija poz)
{
	if (poz.get_kolona() <= visina && poz.get_vrsta() <= sirina) {
		mat[poz.get_kolona()][poz.get_vrsta()] = p;
	}
}

int Slika::size() const
{
	//return visina * sirina * sizeof(Piksel);
	return visina * sirina * 24;
}

Piksel Slika::operator[](Pozicija poz) const
{
	return mat[poz.get_vrsta()][poz.get_kolona()];
}

ostream& operator<<(ostream& os, Slika s)
{
	os << s.size();
	os << endl;
	for (int i = 0; i < s.get_visina(); i++) {
		for (int j = 0; j < s.get_sirina(); j++) {
			os << s.mat[i][j];
		}
		os << endl;
	}
	return os;
}
Slika& Slika::operator=(const Slika& s)
{
	if (this != &s)
	{
		brisi();
		kopiraj(s);
	}

	return *this;
}

Slika& Slika::operator=(Slika&& s)
{
	if (this != &s)
	{
		brisi();
		premesti(s);
	}

	return *this;
}