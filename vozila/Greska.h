#pragma once
#include <exception>
using namespace std;
class GPrevisePutnika: public exception
{
public:
	GPrevisePutnika():exception("Greska: Previse putnika u vagonu. "){}

};
class GDveLokomotive : public exception
{
public:
	GDveLokomotive() :exception("Greska: Dve lokomotive ") {}

};
class GNemaLokomotive : public exception
{
public:
	GNemaLokomotive() :exception("Greska: Voz ne moze biti bez lokomotive") {}
};
class GPreopterecenVoz : public exception
{
public:
	GPreopterecenVoz() :exception("Greska: Preopterecen voz") {}
};


