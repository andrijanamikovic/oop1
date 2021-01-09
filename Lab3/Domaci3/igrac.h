#ifndef _igrac_h_
#define _igrac_h_
#include <string>
#include <iostream>

using namespace std;

class Igrac {
	string ime;
	int vrednost;
public:
	Igrac(string s, int i = 1000):ime(s), vrednost(i){}
	string getIme() const { return ime; }
	int getVrednost() const { return vrednost; }

	void promeniVrednost(bool povecaj, double procenat);
	friend bool operator==(const Igrac& i1, const Igrac& i2);
	friend ostream& operator<<(ostream& os, const Igrac& i) {
		return os << i.ime << "#" << i.vrednost;
	}
};
#endif // !_igrac_h_
