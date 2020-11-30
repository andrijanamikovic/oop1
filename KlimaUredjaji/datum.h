#ifndef _datum_h_
#define _datum_h_
#include <string>
#include <iostream>

using namespace std;

class Datum {
	int dan = 30;
	int mesec = 11;
	int godina = 2019;
public:
	Datum() {};
	Datum(int d, int m, int g);
	int operator[] (string s) const ;
	friend ostream& operator<<(ostream& os, Datum d);
	friend bool operator < (const Datum d1, const Datum d2);

	friend class Kvar;
	friend class Klima;
};
#endif // !_datum_h_