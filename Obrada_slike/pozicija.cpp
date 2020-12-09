#include "pozicija.h"
#include <math.h>


int operator-( const Pozicija p1, const Pozicija p2) 
{
    return abs(p1.get_kolona() - p2.get_kolona()) + abs(p2.get_vrsta() - p1.get_vrsta());
}
