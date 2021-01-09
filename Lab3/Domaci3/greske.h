#ifndef _greske_h_
#define _greske_h_

#include <exception>

using namespace std;

class GNemaMesta :public exception {
public:
	GNemaMesta() :exception("Greska: ne moze da se ubaci igrac na trazenu poziciju u timu.") {}
};

class GNijeKvalifikovan : public exception {
public:
	GNijeKvalifikovan():exception("Greska: igrac nije dovoljno kvalifikovan za zeljeni tim. "){}
};

class GNijeOdigranMec : public exception {
public:
	GNijeOdigranMec() :exception("Greska: mec nije odigran. ") {}
};
#endif // !_greske_h_