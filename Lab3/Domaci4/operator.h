#ifndef _operator_h_
#define _operator_h_
#include "elementu.h"

class Operator : public Element {
	
public:
	

	char getOZnaka() const override { return 'O'; }
	virtual string getNatpis() const = 0;

	virtual Operator* kopija() = 0;

	virtual int getPrioritet() const = 0;
	
	friend bool operator>(const Operator& op1, const Operator& op2);
};
#endif // !_operator_h_