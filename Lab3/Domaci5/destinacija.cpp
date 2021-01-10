#include "destinacija.h"

void Destinacija::oceni(unsigned int i)
{
	if (i <= 5) {
		double o = prosecna_ocena * br;
		br++;
		o += i;
		prosecna_ocena = o / br;
	}
}
