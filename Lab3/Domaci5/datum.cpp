#include "datum.h"

Datum::Datum(int d, int m, int g)
{
	if (m > 0 && m < 13) mesec = m;
	else {
		throw GNeIspravanDatum();
	}
	godina = g;
	const int DaniUMesecu[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (d > 0 && d < 32) {
		if (mesec == 2) {
			if (godina % 100 == 0) {
				if (godina % 400 == 0 && d < 30) dan = d;
				else
					if (d < 29) dan = d;
					else throw GNeIspravanDatum();
			}
			else
				if (godina % 4 == 0 && d < 30) dan = d;
				else
					if (d < 29) dan = d;
					else throw GNeIspravanDatum();
		}
		else if (d < DaniUMesecu[m - 1]) dan = d;
			else {
				throw GNeIspravanDatum();
			}
		}
	else throw GNeIspravanDatum();
	}

int Datum::operator-(Datum d2)
{
	const int DaniUMesecu[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long int br1 = this->godina * 365 + this->dan;
	long int br2 = d2.godina * 365 + d2.dan;
	for (int i = 0; i < this->mesec - 1; i++) {
		br1+= DaniUMesecu[i];
	}
	for (int i = 0; i < d2.mesec - 1; i++) {
		br2 += DaniUMesecu[i];
	}
	int god = this->godina;
	if (this->mesec <= 2) god--;
	god = (int)(god / 4 - god / 100 + god / 400);
	br1 += god;
	god = d2.godina;
	if (d2.mesec <= 2) god--;
	god = (int)(god / 4 - god / 100 + god / 400);
	br2 += god;
	return (br1 - br2);
}
