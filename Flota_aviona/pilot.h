#ifndef _pilot_h_
#define _pilot_h_
#include <cstring>
#include <iostream>

using namespace std;


class Pilot {
	string ime;
	int sati;
	bool leti = false;
public:
	Pilot(string i, int s, bool l);
	Pilot() = delete;

	string dohvIme() const { return ime; }
	int dohvSati() const { return sati; }
	bool dohvLeti() const { return leti; }

	void povecajSati(int s) { sati += s; }

	void Leti(bool l) {leti = l;}

	void ispis() const;

};
#endif // !_pilot_h_
