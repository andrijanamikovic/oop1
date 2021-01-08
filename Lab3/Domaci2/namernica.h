#ifndef _namernica_h_
#define _namernica_h_
#include "nutritivnaVrednost.h"
#include <string>

using namespace std;

class Namernica {
	string naziv;
	NutritivnaVrednost n;
	bool posna;
public:
	Namernica(string naziv, NutritivnaVrednost n, bool p):naziv(naziv),n(n),posna(p){}
	string getNaziv() const { return naziv; }
	NutritivnaVrednost getNutritivnu() const { return n; }
	bool DaLijePosna() const { return posna; }

	friend bool operator==(const Namernica n1, const Namernica n2) {
		return n1.naziv == n2.naziv;
	}
	friend ostream& operator<<(ostream& os, const Namernica& n) {
		return os << n.naziv << "-" << n.n;
	}
};
#endif // !_namernica_h_