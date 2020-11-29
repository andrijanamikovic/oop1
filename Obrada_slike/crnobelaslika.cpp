#include "crnobelaslika.h"

void CrnoBelaSlika::set_piksel(Piksel p, Pozicija poz)
{
	if ((p.get_blue() + p.get_green() + p.get_red() / 3) >= 127) {
		mat[poz.get_kolona()][poz.get_vrsta()] = Piksel (255,255,255);
	}
	else 
		mat[poz.get_kolona()][poz.get_vrsta()] = Piksel(0, 0, 0);

}
