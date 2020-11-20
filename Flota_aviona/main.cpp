#include <iostream>
#include "arhiva.h"
#include "avion.h"
#include "flota.h"
#include "let.h"
#include "pilot.h"

using namespace std;

int main() {
	Flota* f = new Flota("idemo");

	Pilot* p1 = new Pilot("Mika", 200, false);
	Pilot* p2 = new Pilot("Zika", 20, false);
	Pilot* p3 = new Pilot("Pera", 100, false);
	Pilot* p4 = new Pilot("Zoki", 40, false);

	Avion* a1 = new Avion("Mig1", 200);
	Avion* a2 = new Avion("Mig2", 500);

	Arhiva* a = new Arhiva();

	a1->setKapetan(p1);
	a2->setKapetan(p3);
	a1->SetKopilot(p2);
	a2->SetKopilot(p4);

	//Let* l1 = new Let("Bg", "Ms", a1);
	
	f->dodaj(a1);
	f->dodaj(a2);
	a1->ispis();
	a2->ispis();
	f->ispis();
	//a->dodaj(l1);
	//Let* l2 = a->dohvLetove()->let;
	//l2->ispis();

}