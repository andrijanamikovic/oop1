#ifndef _nutritivnaVrednost_h_
#define _nutritivnaVrednost_h_
#include <iostream>

class NutritivnaVrednost {
	double ugljeniHidrati;
	double mast;
	double proteini;
public:
	NutritivnaVrednost(double u, double m, double p):ugljeniHidrati(u),mast(m),proteini(p){}
	double getUgljene() const { return ugljeniHidrati; }
	double getMasti() const { return mast; }
	double getProtein() const { return proteini; }

	friend NutritivnaVrednost operator+(const NutritivnaVrednost& n1, const NutritivnaVrednost& n2);
	double kalorije();

	friend std::ostream& operator<<(std::ostream& os, const NutritivnaVrednost& n) {
		return os << "[uh: " << n.getUgljene() << ", ma: " << n.getMasti() << ", pr: " << n.getProtein()<<"]";
	}
};
#endif // !_nutritivnaVrednost_h_
