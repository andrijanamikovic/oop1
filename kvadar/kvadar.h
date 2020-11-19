#ifndef _kvadar_h_
#include < iostream>
using namespace std;
class Kvadar {
	double a, b, c;
	static double	volume, maxvolume;
	Kvadar(double a1, double b1, double c1);
public:
	
	~Kvadar();
	static Kvadar* make(double a1, double b1, double c1);

	static bool setVmax(double max) {
		if (max < volume) { return false; }
		maxvolume = max;
		return true;
	}
	static double getVmax() { return maxvolume; }
	static double getV() { return volume; }

	double dohvA() const { return a; }
	double dohvB() const { return b; }
	double dohvC() const { return c; }

	double V() const { return a * b * c; }
	void pisi() const;

	static Kvadar* read() {
		double a, b, c;
		cin >> a >> b >> c;
		return make(a, b, c);
	}



};
#endif // !_kvadar_h_

