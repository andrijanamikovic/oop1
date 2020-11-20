#ifndef _avion_h_
#define _avion_h_
#include "pilot.h"

class Avion {
	string naziv;
	Pilot* kapetan = nullptr;
	Pilot* kopilot = nullptr;
	int max;

public:

	Avion(string n, int m) {
		naziv = n;
		max = m;
	} 
	int dohvMax() const { return max; }
	string dohvNaziv() const { return naziv; }
	bool setKapetan(Pilot* k) { 
		if (k->dohvSati() >= 100 && !k->dohvLeti()) {
			kapetan = k;
			k->Leti(true);
			return true;
		}
		return false;
	}
	bool SetKopilot(Pilot* k) {
		if (!k->dohvLeti()) {
			kopilot = k;
			k->Leti(true);
			return true;
		}
		return false;
	}

	Avion() = delete;

	void ispis() {
		cout << naziv << " - " << max << endl;
	}

};

#endif // !_avion_h_

