#ifndef _datum_h_
#define _datum_h_
#include "greske.h"
#include <iostream>

class Datum {
	int dan;
	int mesec;
	int godina;
public:
	Datum(int d, int m, int g);

	int getDan() const { return dan; }
	int getMesec() const { return mesec; }
	int getGodina() const { return godina; }

	int operator-(Datum d2);


	friend std::ostream& operator<<(std::ostream& os, const Datum& d)
	{
		return os << d.dan << "." << d.mesec << "." << d.godina << ".";
	}

};
#endif // !_datum_h_
