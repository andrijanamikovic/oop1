#include "smestaj.h"

ostream& operator<<(ostream& os, const Smestaj& s)
{
    os << s.getTip() << " " << s.getNaziv();
    for (int i = 0; i < s.broj_zvezdica; i ++) {
        os << "*";
    }
    return os;
}
