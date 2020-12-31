#include "sah.h"
#include "greska.h"

void Sah::kopiraj(const Sah& sah)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			if (sah.figure[i][j]) {
				figure[i][j] = sah.figure[i][j]->kopija();
			}
			else {
				figure[i][j] = nullptr;
			}
		}
	}
	naPotezu = sah.naPotezu;
}

void Sah::premesti(Sah& sah)
{
	naPotezu = sah.naPotezu;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			figure[i][j] = sah.figure[i][j];
			sah.figure[i][j] = nullptr;
		}
	}
}

void Sah::brisi()
{
	for (int i = 0; i < 8; i++) {
		delete[] figure[i];
	}
	delete[] figure;
}

Sah::Sah()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			figure[i][j] = nullptr;
		}
	}
}

Figura*& Sah::operator[](const Polje& p)
{
	return figure[p.getKolona() - 'A'][p.getRed() - 1];
}

Figura* Sah::operator[](const Polje& p) const
{
	return figure[p.getKolona() - 'A'][p.getRed() - 1];
}


Sah& Sah::operator+=(Figura& f)
{
	if ((*this)[f.getPolje()] != nullptr) throw GZauzetoPolje();
	(*this)[f.getPolje()] = f.kopija();
	return *this;
}

void Sah::pomeri(const Polje& sa, const Polje& na)
{
	Figura* f = (*this)[sa];
	if (f == nullptr) throw GPraznoPolje();
	if (f->getBoja() != naPotezu) throw GIgracNijeNaPotezu();
	
	Figura *fna = (*this)[na];

	if (fna != nullptr) {
		if (fna->getBoja() == f->getBoja()) throw GPogresanPotez();
	}

	f->pomeriNa(na);

	if (fna != nullptr) {
		delete (*this)[na];
	}
	(*this)[na] = f;
	(*this)[sa] = nullptr;

	naPotezu = naPotezu == Figura::BELA ? Figura::CRNA : Figura::BELA;
}

std::ostream& operator<<(std::ostream& os, Sah& s)
{
	for (int i = 8; i > 0; i--) {
		os << "\033[1;43m " << i << " \033[0m";
		for (char j = 'A'; j <='H'; j++) {
			if ((i + j) % 2 == 0) os << "\033[1;40m";
			else os << "\033[1;47m";

			Polje p(j, i);
			Figura* f = s[p];

			bool bela = true;
			char figura = ' ';
			if (f != nullptr) {
				bela = f->getBoja() == Figura::Boja::BELA;
				figura = f->oznaka();
			}
	

			if (bela) os << "\033[1;37m";
			else os << "\033[1;31m";
			os << " " << figura << " \033[0m";
		}
		os << endl;
	}
	os << "\033[1;43m   \033[0m";
	for (char j = 'A'; j <= 'H'; j++) {
		os << "\033[1;43m " << j << " \033[0m";
	}
	return os;
}
