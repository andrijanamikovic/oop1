#include "crnobelaslika.h"

void CrnoBelaSlika::set_piksel(Piksel p, Pozicija poz)
{
	if (poz.get_kolona() <= visina && poz.get_vrsta() <= sirina) {
		if (((p.get_blue() + p.get_green() + p.get_red()) / 3) >= 127) {
			mat[poz.get_kolona()][poz.get_vrsta()] = Piksel(255, 255, 255);
		}
		else
			mat[poz.get_kolona()][poz.get_vrsta()] = Piksel(0, 0, 0);
	}
}

CrnoBelaSlika::CrnoBelaSlika(int v, int s) :Slika(s,v)
{
}

CrnoBelaSlika::CrnoBelaSlika(CrnoBelaSlika&& cbs) : Slika(cbs)
{
}

CrnoBelaSlika::~CrnoBelaSlika()
{
}


CrnoBelaSlika::CrnoBelaSlika(const CrnoBelaSlika& cbs) :Slika(cbs)
{
	for (int i = 0; i < cbs.visina; i++) {
		cout << "in";
		for (int j = 0; j < cbs.sirina; j++) {
			Piksel p = cbs.get_piksel(Pozicija(i, j));
			if (((p.get_blue() + p.get_green() + p.get_red()) / 3) >= 127) {
				cout << "in belo";
				mat[i][j] = Piksel(255, 255, 255);
			}
			else
				mat[i][j] = Piksel();
		}
	}
}


