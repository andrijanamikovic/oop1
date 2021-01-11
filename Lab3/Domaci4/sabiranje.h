#ifndef _sabiranje_h_
#define _sabiranje_h_

#include "operator.h"

class Sabiranje : public Operator {

public:
	string getNatpis() const override { return "+"; }

	Sabiranje* kopija() {
		return this;
	}

	int getPrioritet() const override { return 1; }
};
#endif // !_sabiranje_h_
