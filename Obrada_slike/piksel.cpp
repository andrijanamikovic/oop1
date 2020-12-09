#include "piksel.h"


Piksel& Piksel::operator+(const Piksel p1) const
{
    Piksel p;
    p.blue = (blue + p1.blue) / 2;
    p.red = (red + p1.red) / 2;
    p.green = (green + p1.green) / 2;
    return p;
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
