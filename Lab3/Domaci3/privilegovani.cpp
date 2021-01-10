#include "privilegovani.h"

void Privilegovani::kopiraj(const Privilegovani& t)
{
	Tim::kopiraj(t);
	min = t.min;
}

void Privilegovani::premesti(Privilegovani& t)
{
	Tim::premesti(t);
	min = t.min;
}
