#include "team.h"

void Tim::kopiraj(const Tim& t)
{
    duzina = t.duzina;
    for (int i = 0; i < duzina; i++) {
        niz[i] = new Igrac(*t.niz[i]);
    }
}

void Tim::premesti(Tim& t)
{
    duzina = t.duzina;
    niz = t.niz;
    t.niz = nullptr;
}

void Tim::brisi()
{
   /* for (int i = 0; i < duzina; i++) {
        delete niz[i];
    }
    */
    delete[] niz;
    niz = nullptr;
}

Igrac* Tim::operator[](int i)
{
    return niz[i-1];
}

const Igrac* Tim::operator[](int i) const
{
    return niz[i-1];
}

double Tim::vrednostTima() const
{
    double vrednost = 0;
    int br = 0;
    for (int i = 0; i < duzina; i++) {
        if (niz[i] != nullptr) {
            vrednost += niz[i]->getVrednost();
            br++;
        }
    }
    if( br != 0) vrednost = vrednost / br;
    return vrednost;
}

bool operator==(const Tim& t1, const Tim& t2)
{
    if (t1.duzina != t2.duzina)
        return false;
    if (t1.naziv != t2.naziv)
        return false;
    for (int i = 0; i < t1.duzina; i++) {
        if (t1.niz[i] != nullptr && t2.niz[i] != nullptr)
        {
            if (!(*t1.niz[i] == *t2.niz[i])) return false;
        }
        else if (t1.niz[i] == nullptr && t2.niz[i] == nullptr) continue;
        else
            return false;
    }
    return true;
}

ostream& operator<<(ostream& os, const Tim& t)
{
    if (&t)
        os << t.naziv << "[";
        t.pisi(os);
    return os;
}
