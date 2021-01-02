#ifndef _datum_h_
#define _datum_h_

#include <iostream>
using namespace std;

class Datum {
	int dan, mesec, godina;
public:
	Datum(int d, int m, int g):dan(d),mesec(m),godina(g){}

	int getDan() const { return dan; }
	int getMesec() const { return mesec; }
	int getGodina() const { return godina; }

	friend ostream& operator<<(ostream& os, const Datum& d) {
		return os << d.dan << "." << d.mesec << "." << d.godina << ".";
	}
};
#endif // !_datum_h_
