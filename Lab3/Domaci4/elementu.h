#ifndef _elemntu_h_
#define _elemntu_h_
#include <iostream>
#include <iostream>

using namespace std;

class Element{
public:

	virtual ~Element() {}

	virtual char getOZnaka() const  = 0;
	virtual string getNatpis() const = 0;

	virtual Element* kopija() = 0;
	
	friend ostream& operator<<(ostream& os, const Element& e) {
		return os << e.getNatpis();
	}

};

#endif // !_elemntu_h_
