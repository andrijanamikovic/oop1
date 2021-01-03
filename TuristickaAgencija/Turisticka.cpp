#include "Turisticka.h"
#include "Greske.h"

Lista<string>* Turisticka::nadjiOdDo(const Datum& d1, const Datum& d2, char tip)
{
    Lista<string>* l = new Lista<string>();

    for (naPrvi(); daLiTek(); naSled()) {
        Aranzman* a = getPod();
        if (a->getOznaku() != tip) continue;
        if (a->getPoc() < d1 && a->getKraj() < d2) {
            l->dodajNaKraj(a->getNaziv());
        }
    }
    if (l->brojElem() == 0) throw GNemaArazman();
    return l;
}

string Turisticka::nadjiMin()
{
    naPrvi();
    double min = getPod()->izrCenu();
    string naz = getPod()->getNaziv();
    naSled();
    for (; daLiTek(); naSled()) {
        if (getPod()->izrCenu() < min) {
            min = getPod()->izrCenu();
            naz = getPod()->getNaziv();
        }
    }
    return naz;
}

ostream& operator<<(ostream& os, const Turisticka& t)
{
    os << t.ime << endl;
    for (t.naPrvi();  t.daLiTek(); t.naSled()) {
        os << *t.getPod() << endl;
    }
    return os;
}
