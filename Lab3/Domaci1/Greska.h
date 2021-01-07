#ifndef _Greska_h_
#define _Greska_h_

#include <exception>

using namespace std;

class GNemateSredstva :public exception {
public:
	GNemateSredstva() :exception("Greska: Nemate sredstva da izvrsite zeljeni prenos.") {}
};

#endif // !_Greska_h_
