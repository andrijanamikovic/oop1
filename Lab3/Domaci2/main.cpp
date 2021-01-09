#include <iostream>
#include "nutritivnaVrednost.h"
#include "namernica.h"
#include "sastojak.h"
#include "lista.h"
using namespace std;

int main() {
	NutritivnaVrednost n1(10, 20, 40.6);
	NutritivnaVrednost n2(10, 20, 40.6);

	cout << (n1 + n2) << endl;
	cout << n1.kalorije()<<endl;

	Namernica nam("cips", n1, false);
	Namernica nam2("cips", n2, true);

	cout << (nam == nam2)<<endl;
	cout << nam2;

	Sastojak s(nam, 10);
	cout << s.odreditiNutritivnu() << endl << s.KalorijeNamernice() << endl;
	cout << s;
}