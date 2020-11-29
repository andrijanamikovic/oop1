#include "datum.h"

Datum::Datum(int d, int m, int g) {
    if (g > 0) godina = g;
    if (m > 0 && m < 13) mesec = m;
    switch (m)
    {
    case 1: case 3: case 5: case 7: case 9: case 10: case 12:
        if (d > 0 && d < 32) dan = d;
    case 2:
        if (d > 0 && d < 28) dan = d;
    case 4: case 6: case 8: case 11:
        if (d > 0 && d < 31) dan = d;
    }
}
int Datum::operator[](string s) const
{
    if (s == "dan") return dan;
    else
        if (s == "mesec") return mesec;
        else
            if (s == "godina") return godina;
            else
                return -1;
}

ostream& operator<<(ostream& os, Datum d) 
{
    return os << d.dan << "." << d.mesec << "." << d.godina << ".";
}

bool operator<(const Datum d1, const Datum d2)
{
    if (d1.godina < d2.godina) return true;
    else if (d1.godina > d2.godina) return false;
    else if (d1.mesec < d2.mesec) return true;
    else if (d1.mesec > d2.mesec) return false;
    else if (d1.dan < d2.dan) return true;
    else return false;
}
