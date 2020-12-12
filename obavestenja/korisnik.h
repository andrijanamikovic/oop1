#ifndef _korisnik_h_
#define _korisnik_h_
#include "obavestenje.h"
#include <string>
class Korisnik {
	string ime;
protected:
	virtual void pisi(ostream& os, const Korisnik& k) = 0;
	friend ostream& operator<<(ostream& os, const Korisnik& k) { return os; };
public:
	explicit Korisnik(const string s):ime(s){}
	Korisnik(const Korisnik& l) = delete;
	Korisnik(Korisnik&& l) = delete;
	Korisnik& operator=(const Korisnik& l) = delete;
	Korisnik& operator = (Korisnik&& l) = delete;

	string get_name() const { return ime; }


};

#endif //!_korisnki_h_