#ifndef _greske_h_
#define _greske_h_

#include <exception>

using namespace std;

class GPostfiks :public exception {
public:
	GPostfiks() :exception("Nije moguce generisati ispravni izraz u postfiksnom obliku") {}
};
#endif // !_greske_h_
