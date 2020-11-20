#include "pilot.h"

Pilot::Pilot(string i, int s, bool l)
{
	ime = i;
	sati = s;
	leti = l;
}

void Pilot::ispis() const
{
	cout << ime << "( " << sati << " )-" << leti ? "L":"N";
	cout << endl;
}
