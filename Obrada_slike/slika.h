#ifndef _slika_h_
#define _slika_h_
#include "piksel.h"

#include <iostream>
using namespace std;

class Slika {
	int sirina = 0;
	int visina = 0;
	Piksel** p = {};

public:
	Slika (int s, int v){
		sirina = s;
		visina = v;
		Piksel** p = new Piksel * [visina];
		for (int i = 0; i < visina; i++) {
			for (int j = 0; j<sirina; j++){
			p[i][j] = new Piksel(0, 0);
			cout << p[i][j] << " ";
			}
		cout << endl;
		}
	}
	int get_sirina() const { return sirina; }
	int get_visina() const { return visina; }



};
#endif // !_slika_h_