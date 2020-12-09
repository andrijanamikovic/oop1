#ifndef _piksel_h_
#define _piksel_h_
#include <iostream>
using namespace std;

class Piksel {
	int red = 0;
	int green = 0;
	int blue = 0;
public:
	Piksel() {}
	Piksel(int r, int g, int b) {
		if (r >= 0 && r <= 255) { red = r; }
		if (b >= 0 && b <= 255) { blue = b; }
		if (g >= 0 && g <= 255) { green = g; }
	}
	int get_red() const { return red; }
	int get_blue() const { return blue; }
	int get_green() const { return green; }

	Piksel &operator +(const Piksel p1)const;
	friend bool operator==(const Piksel& p1, const Piksel& p2);
	friend ostream& operator<<(ostream& os, Piksel p1);
	

 };
#endif // !_piksel_h_