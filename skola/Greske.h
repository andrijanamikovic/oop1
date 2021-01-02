#ifndef _greske_h_
#define _greske_h_

#include <exception>
using namespace std;

class  GNemaTek: public exception{
public:
	GNemaTek() :exception("Greska nema tekuceg elementa "){}
};
#endif // !_greske_h_