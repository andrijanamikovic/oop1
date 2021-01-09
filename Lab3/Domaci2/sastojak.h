#ifndef _sastojak_h_
#define _sastojak_h_
#include "namernica.h"

class Sastojak {
	Namernica nam;
	double kolicina;
public:
	Sastojak(Namernica n, double g):nam(n),kolicina(g){}
	Namernica getNamernicu() const { return nam; }
	double getKolicinu() const { return kolicina; }

	NutritivnaVrednost odreditiNutritivnu()const {
	return NutritivnaVrednost(nam.getNutritivnu().getUgljene() / 100 * kolicina, nam.getNutritivnu().getMasti() / 100 * kolicina, nam.getNutritivnu().getProtein() / 100 * kolicina);
	}
	double KalorijeNamernice() const { return nam.getNutritivnu().kalorije(); }

	friend ostream& operator<<(ostream & os, const Sastojak & s) {
		return os << "[" << s.KalorijeNamernice() << "kcal]" << s.kolicina << "g x" << s.nam;
	}
};

#endif // !_sastojak_h_
