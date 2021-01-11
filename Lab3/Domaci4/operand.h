#ifndef _operand_h_
#define _operand_h_

#include "elementu.h"

class Operand : public Element {
	
	string natpis;
public:
	
	Operand (string n):natpis(n){}

	char getOZnaka() const override {
		return 'D';
	}


	string getNatpis() const override {
		return natpis;
	}

	Operand* kopija() override {
		return new Operand(*this);
	}

};
#endif // !_operand_h_
