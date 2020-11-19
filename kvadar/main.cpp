#include <iostream>
#include "kvadar.h"
using namespace std;

int main() {
	cout << "Unesite Vmx";
	double max;
	cin >> max;
	if (!Kvadar::setVmax(max)) cout << "Neuspelo postavljanje Vmax";
	
	struct Elem {
		Kvadar* kvad;
		Elem* next;
		Elem(Kvadar* kv) {
			kvad = kv;
			next = nullptr;
		}
		~Elem() { delete kvad; }
	};
	bool flag = true;
	while (flag) {
		Elem* prvi = nullptr;
		Elem* posl = nullptr;

		while (true) {
			cout << "a,b,c?";
			if (Kvadar* kv = Kvadar::read()) {
				posl= (!prvi ? prvi : posl->next) = new Elem(kv);
			}
			else {
				break;
			}
		}

		cout << "Zapremine: ";
		for (Elem* tek = prvi; tek; tek = tek->next) {
			cout << tek->kvad->getV() << " ";
		}
		cout << endl;
		cout << "Ukupna zapremin: " << Kvadar::getV() << endl;

		while (prvi) {
			Elem* stari = prvi;
			prvi = prvi->next;
			delete prvi;
		}

		cout << "Ukupna zapremina nakon brisanja " << Kvadar::getV() << endl;
		cout << "Ako ne zelite da unosite vize kvadrova unesite 0";
		cin >> flag;
	}
}