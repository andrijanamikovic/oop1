#include <iostream>
#include "red.h"

using namespace std;

int main() {
	Red* r = new Red(6);
	bool kraj = false;
	while (!kraj) {
		while (!kraj) {
			cout << "\n1. Stvaranje reda\n"
				"2. Stavljanje podatka u red\n"
				"3. Uzimanje podatka iz reda\n"
				"4. Ispisivanje sadrzaja reda\n"
				"5. Praznjenje reda\n"
				"0. Zavrsetak rada\n\n"
				"Vas izobr? ";

			int izbor;
			cin >> izbor;

			switch (izbor) {
			case 1:
				cout << "Kapacitet? "; int k;
				cin >> k;
				if (k > 0) {
					delete r;
					r = new Red(k);
				}
				else {
					cout << "Greska!" << endl;
				}
				break;

			case 2:
				if (!r->full()) {
					cout << "Broj? "; int b;
					cin >> b;
					r->full();
				}
				else {
					cout << "Greska!" << endl;
				}
				break;

			case 3:
				if (!r->empty()) {
					cout << "Broj= " << r->get() << endl;
				}
				else {
					cout << "Greska!" << endl;
				}
				break;

			case 4:
				cout << "Red= "; r->print();
				cout << endl;
				break;

			case 5:
				r->emp();
				break;

			case 0:
				kraj = true;
				break;

			default:
				cout << "Greska!" << endl;
				break;
			}
		}
	}


}