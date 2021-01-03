#ifndef _greske_h_
#define _greske_h_

#include <exception>
using namespace std;

class GNemaTek :public exception {
public:
	GNemaTek():exception("Greska: Ne postoji tekuci. ") {}
};

class GKrajPrePoc : public exception {
public:
	GKrajPrePoc() :exception("Greska: Kraj Aranzmana je pre pocetka. ") {}
};

class GNemaArazman : public exception {
public:
	GNemaArazman(): exception("Greska: Nema takav Arazman;"){}
};
#endif // !_greske_h_
