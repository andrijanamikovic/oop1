#include <iostream>
#include "igrac.h"
#include "team.h"
#include "greske.h"
#include "privilegovani.h"
#include "mec.h"

using namespace std;

int main() {
	try {
		Igrac i1("Zika", 60);
		Igrac i2("Zika", 40);

		//i1.promeniVrednost(false, 20);
		//cout << i1 << endl;
		//cout << (i1 == i2);
		Tim t(2, "Idemo");
		t.dodajIgraca(2, i1);
		//cout << t.brojIgracauTimu() << endl;
		t.dodajIgraca(1, i2);
		//cout << t[1] << endl;
		//cout << t;
		Tim t2(2, "Idemo2");
		t2.dodajIgraca(1, i1);
		//cout << t2;
		Igrac i3("Janko", 20);
		t2.dodajIgraca(2, i3);
		//cout << endl << (t == t2);
		Mec m(&t,&t2);
		//cout << t2.brojIgracauTimu();
		m.odigrati();
		cout << m.getPoeni() << endl;
		cout << m;

	}
	catch (exception e) {
		cout << e.what();
	}
}