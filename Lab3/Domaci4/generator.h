#ifndef _generator_h_
#define _generator_h_
#include "izraz.h"

class Generator {
	Generator() {}
public:

	Generator(const Generator&) = delete;
	Generator& operator=(const Generator&) = delete;

	static Generator& get() {
		static Generator pom;
		return pom;
	}

	void operator() (Izraz& i);
};
#endif // !_generator_h_
