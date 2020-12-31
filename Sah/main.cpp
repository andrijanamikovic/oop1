#include <string>
#include <exception>
#include <iostream>
#include "polje.h"
#include "figura.h"
#include "top.h"
#include "lovc.h"
#include "skakac.h"
#include "sah.h"

using namespace std;

int main() {
	try {
		Polje a4('A', 4);
		Polje b3('B', 3);
		Polje d4('D', 4);

		Top t1(Figura::BELA, a4);
		Lovac l1(Figura::CRNA, b3);
		Skakac s1(Figura::BELA, d4);

		Sah sah;
		//cout << t1 << endl;
		//cout << l1 << endl;
		//cout <<( l1 > t1);
		sah+=t1;
		sah += l1;
		sah += s1;
	
		cout << sah;

		while (true) {
			try {
				char kolona;
				int red;

				cout << "Unesite kolonu i red polja sa koga pomerate figuru: " << endl;;
				cin >> kolona >> red;
				Polje sa(kolona, red);

				cout << "Unesite kolonu i red polja na koje pomerate figuru: ";
				cin >> kolona >> red;
				Polje na(kolona, red);

				sah.pomeri(sa, na);

				cout << "\x1B[2J\x1B[H"; //cisti konzolu
				cout << sah;
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
		}
	}
	catch(exception e){
		cout << e.what() << endl;
	}

	cout << endl << "Kraj programa..." << endl;
}
	