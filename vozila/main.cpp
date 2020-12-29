#include <iostream>
#include <string>

#include "lokomotiva.h"
#include "vagon.h"
#include <exception>
#include "voz.h"
#include "Greska.h"


using namespace std;

int main() {
	try {
		Lokomotiva l(2500, 500);
		Voz l2();
		Vagon v(40, 500);
		Voz v2("Mile");
		v.UlazakPutnika(5);
		v2 += v;
		cout << v2;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	cout << "Kraj programa..." << endl;
}