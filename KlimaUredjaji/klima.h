#ifndef _klima_h_
#define _klima_h_
#include "garancija.h"
#include "uredjaj.h"

class Klima: public Uredjaj{
	int kvadrata;

public:
	Klima(string ime, int k);
	void set_garancija(Datum poc);
	
	 friend bool operator == (Klima k1, Klima k2); 
	 friend ostream& operator << (ostream& os, Klima& k);

};
#endif // !_klima_h_

