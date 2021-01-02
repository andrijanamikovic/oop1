#include "skola.h"

const Djak* Skola::najbolji() const
{
    Djak* naj = nullptr;
    double max = 0;
    for (djaci.naPrvi(); djaci.imaTek(); djaci.naSled()) {
        Djak* tek = djaci.dohvTek();
        double srednja = tek->srOcena();
        if (srednja > max) {
            max = srednja;
            naj = tek;
        }
    }
    return naj;
}
