#include <iostream>
#include "lista.h"
#include "desna_zagrada.h"
#include "izraz.h"
#include "leva_zagrada.h"
#include "operand.h"
#include "operator.h"
#include "sabiranje.h"


using namespace std;

int main() {
	try {
		/*Lista<int> l;
		l +=new int (1);
		l += new int(2);
		l += new int(3);
		l += new int(4);
		int* a;
		int* b;
		cout << l;
		a = -l;
		b = *l;
		cout <<endl<<  *a<< " "<<*b;
		cout << endl << l;*/
		Operand a("A");
		Operand b("B");
		Izraz i;
		i += a.kopija();
		Sabiranje s;
		i += s.kopija();
		cout << " " << i;


	}
	catch (exception& e) {
		cout << e.what();
	}
}