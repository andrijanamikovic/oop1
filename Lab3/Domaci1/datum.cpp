#include "datum.h"

Datum::Datum(int d, int m, int g)
{
	if (m > 0 && m < 13) mesec = m;
	godina = g;
	if (d > 0 && d < 32) {
		if (mesec == 1 || mesec == 3  || mesec == 5 || mesec == 7 || mesec == 8 || mesec ==10 || mesec ==12) dan = d;
		if ((mesec == 4 || mesec == 6 || mesec == 9 || mesec == 11) && d < 31) dan = d;
		if (mesec == 2) {
			if (godina % 4 == 0 && d < 30) dan = d;
			else
				if (d < 29) dan = d;
		}
	}
}

bool operator==(const Datum d1, const Datum d2)
{
	if (d1.dan == d2.dan && d1.mesec == d2.mesec && d1.godina == d2.godina) return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Datum& d)
{
	return os << d.dan << "." << d.mesec << "." << d.godina << ".";
}
