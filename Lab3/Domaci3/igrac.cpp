#include "igrac.h"

void Igrac::promeniVrednost(bool povecaj, double procenat)
{
		if (povecaj) vrednost += vrednost * (procenat / 100);
		else vrednost -= vrednost * (procenat / 100);
}

bool operator==(const Igrac& i1, const Igrac& i2)
{
	if (i1.ime == i2.ime && i1.vrednost == i2.vrednost) return true;
	return false;
}
