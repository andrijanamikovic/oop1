#include <iostream>
#include "lista.h"
#include "desna_zagrada.h"
#include "izraz.h"
#include "leva_zagrada.h"
#include "operand.h"
#include "operator.h"
#include "sabiranje.h"
#include "generator.h"


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
		Operand c("C");
		Izraz i;
		i += a.kopija();
		Sabiranje s;
		i += s.kopija();
		Leva l;
		Desna d;
		i += l.kopija();
		i += b.kopija();
		i += s.kopija();
		i += c.kopija();
		i += d.kopija();
		i += s.kopija();
		Operand da("D");
		i += da.kopija();
		Operand r("R");
		i += s.kopija();
		i += l.kopija();
		i += r.kopija();
		Operand e("E");
		i += s.kopija();
		i += e.kopija();
		i += d.kopija();
		//cout << i <<endl;
	
		cout << "Infiks : " << i<<endl;
		
		Generator::get()(i);
		cout <<"Postfiks: "<<i;



	}
	catch (exception& e) {
		cout << e.what();
	}
}