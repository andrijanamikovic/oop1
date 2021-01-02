#include "djak.h"

double Djak::srOcena() const
{
    double sum = 0;
    int n = 0;
    for (ispiti.naPrvi(); ispiti.imaTek(); ispiti.naSled()) {
        int ocena = ispiti.dohvTek()->getOcena();
        if (ocena > 5) {
            sum += ocena;
            n++;
        }
    }
    if (n > 0) {
        return (sum / n);
    }
    else
        return n;
}

Djak::~Djak()
{
    for (ispiti.naPrvi(); ispiti.imaTek(); ispiti.naSled()) {
        delete ispiti.dohvTek();
    }

}
