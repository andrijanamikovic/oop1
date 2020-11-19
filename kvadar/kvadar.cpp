#include "kvadar.h"
#include <iostream>

using namespace std;
double Kvadar::maxvolume = 0;
double Kvadar::volume = 0;
Kvadar::Kvadar(double a1, double b1, double c1)
{
	a = a1; b = b1; c = c1;
}

Kvadar::~Kvadar()
{
	volume -= a * b * c;
}

Kvadar* Kvadar::make(double a1, double b1, double c1)
{
	double V = a1 * b1 * c1;
	if (a1<=0 || b1<=0 || c1<=0 || V+volume>maxvolume) 
		return nullptr;
	volume += V;
	return new Kvadar(a1, b1, c1);
}

void Kvadar::pisi() const
{
	cout << "kvadar[" << a << ", " << b << ", " << c << "]";
}
