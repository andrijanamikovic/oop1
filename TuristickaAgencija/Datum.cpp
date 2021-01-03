#include "Datum.h"

bool operator<(const Datum d1, const Datum d2)
{
    if (d1.godina < d2.godina) return true;
    else
        if (d1.godina > d2.godina) return false;
        else
            if (d1.mesec < d2.mesec) return true;
            else
                if (d1.mesec > d2.mesec) return false;
                else
                    if (d1.dan < d2.dan) return true;
                    else
                        return false;
}
