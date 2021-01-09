#include "mec.h"

void Mec::odigrati()//Tim& t1, Tim& t2)
{
	double v1 = timovi.getDomaci()->vrednostTima(); //t1.vrednostTima();
	double v2 = timovi.getGost()->vrednostTima(); //t2.vrednostTima();
	if (v1 > v2 ) {
		ishod = ishod_meca::POBEDA_DOMACINA;
		/*for (int i = 0; i < timovi.getDomaci()->brojIgracauTimu(); i++) {
			if (timovi.getDomaci()->operator[](i) != nullptr)
				timovi.getDomaci()->operator[](i)->promeniVrednost(true, 10);
			//t1[i].promeniVrednost(true, 10);
		}
		/*for (int i = 0; i < t2.brojIgracauTimu(); i++) {
			t2[i].promeniVrednost(false, 10);
		}*/
		/*for (int i = 0; i < timovi.getGost()->brojIgracauTimu(); i++) {
			if (timovi.getGost()->operator[](i) != nullptr)
				timovi.getGost()->operator[](i)->promeniVrednost(false, 10);
			//t1[i].promeniVrednost(true, 10);
		}*/
		poeni.setPrvi(new int(3));
		poeni.setDrugi(new int (0));
	}
	else
		if (v1 == v2) {
			ishod = ishod_meca::NERESENO;
			poeni.setDrugi(new int(1));
			poeni.setPrvi(new int (1));
		}
		else {
			ishod = ishod_meca::POBEDA_GOSTA;
			/*for (int i = 0; i < t2.brojIgracauTimu(); i++) {
				if (t2[i]!=nullptr)
					t2[i].promeniVrednost(true, 10);
			}
			for (int i = 0; i < t1.brojIgracauTimu(); i++) {
				t1[i].promeniVrednost(false, 10);
			}*/
		/*	for (int i = 0; i < timovi.getDomaci()->brojIgracauTimu(); i++) {
				if (timovi.getDomaci()->operator[](i) != nullptr)
					timovi.getDomaci()->operator[](i)->promeniVrednost(false, 10);
			}
			for (int i = 0; i < timovi.getGost()->brojIgracauTimu(); i++) {
				if (timovi.getGost()->operator[](i) != nullptr)
					timovi.getGost()->operator[](i)->promeniVrednost(true, 10);
			}*/
				poeni.setPrvi(new int(0));
				poeni.setDrugi(new int(3));
			
		}
	odigran_mec = true;
}