#ifndef _datum_h_
#define _datum_h_
#include <iostream>
class Datum {
	int dan = 1;
	int mesec = 1;
	int godina = 2021;
public:
	Datum(int d , int m , int g);
	friend bool operator==( const Datum d1,const  Datum d2);
	friend std::ostream& operator<< (std::ostream& os, const Datum& d);
};

#endif // !_datum_h_
