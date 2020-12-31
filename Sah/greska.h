#pragma once
#include <exception>
using namespace std;

class GPogresnoPolje: public exception
{
public:
	GPogresnoPolje() :exception("Greska: Pogresno zadato polje. ") {}
};

class GPogresanPotez : public exception
{
public:
	GPogresanPotez() :exception("Greska: Pogresan potez. ") {}
};

class GZauzetoPolje : public exception {
public:
	GZauzetoPolje() :exception("Greska: Polje je zauzeto. ") {}
};

class GPraznoPolje : public exception {
public:
	GPraznoPolje() :exception("Greska: Polje je prazno. ") {}
};

class GIgracNijeNaPotezu : public exception {
public:
	GIgracNijeNaPotezu() :exception("Greska: Igrac nije na potezu. ") {}
};