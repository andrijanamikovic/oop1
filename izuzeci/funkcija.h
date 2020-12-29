#ifndef _funkcija_h_
#define _funkcija_h_
class Funkcija {
public:
	virtual double operator()(double x) const = 0;
	virtual double I(double x) const = 0;
};
#endif // !_funkcija_h_
