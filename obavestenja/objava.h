#ifndef _objava_h_
#define _objava_h_
#include <string>
#include "obavestenje.h"

using namespace std;

class Objava: public Obavestenje {
	string tekst;
public:
	Objava(Korisnik* k, const string t):Obavestenje(k), tekst(t){}
private:
	void pisi(ostream& os) const override {
		os << tekst << endl;
	}
};
#endif // !_objava_h_
