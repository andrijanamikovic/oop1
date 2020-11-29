#include "piksel.h"


Piksel& Piksel::operator+=(Piksel p1)
{
    red += p1.get_red();
    red = red / 2;

    blue += p1.get_blue();
    blue = blue / 2;

    green += p1.get_green();
    green = green / 2;
    
    return *this;
}

bool operator==(const Piksel& p1, const Piksel& p2)
{
    if (p2.get_red() == p1.get_red() && p2.get_blue() == p1.get_blue() && p2.get_blue() == p1.get_green()) {
        return true;
    }

    return false;
}

ostream& operator<<(ostream& os, Piksel p1)
{
    return os << "(" << p1.get_red() << "," << p1.get_green() << "," << p1.get_blue() << ")" << endl;
}
