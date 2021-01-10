#ifndef _greske_h_
#define _greske_h_

#include <exception>

using namespace std;

class GNeZvezdice : public exception {
public:
	GNeZvezdice() :exception("Greska: Broj zvezdica je izvan opsega [1,5]") {}
};


class GNeIspravanDatum : public exception {
public:
	GNeIspravanDatum() :exception("Greska: Ne ispravan datum. ") {}
};
class GNeIspravanSmestaj : public exception {
public:
	GNeIspravanSmestaj() :exception("Greska: Zeljeni smestaj nije za ovu destinaciju ") {}
};
class GNeIspravanPrevoz : public exception {
public:
	GNeIspravanPrevoz() :exception("Greska: Zelejeni prevoz nije za ovu destinaciju ") {}
};
class GNemaCena : public exception {
public:
	GNemaCena() :exception("Greska: Ne moze da se dohvati cena zato sto nisu dodeljeni smestaj ili prevoz. ") {}
};
#endif // !_greske_h_
