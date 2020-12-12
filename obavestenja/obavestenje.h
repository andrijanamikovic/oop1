#ifndef _obavestenje_h_
#define _obavestenje_h_
#include "Windows.h"
#include <iostream>


using namespace std;

class Korisnik;

class Obavestenje {
	Korisnik* koris = nullptr;
	static int current_id;
	int id;
	int h, m, s;
	bool read = false;
public:
	explicit Obavestenje(Korisnik* k) :id(current_id++) {
		koris = k;
		SYSTEMTIME time;
		GetLocalTime(&time);
		h = time.wHour;
		m = time.wMinute;
		s = time.wSecond;
	};
	int get_id() const { return id; }
	Korisnik* get_Kor() const { return koris; }
	bool is_read() const { return read; }
	void set_read() { read = true; }
	Obavestenje& readObs() { read = true; return *this; }
protected:
	virtual void pisi(ostream& os) const = 0;
	friend ostream& operator << (ostream& os, const  Obavestenje& o);
	
};
#endif // !_obavestenje_h_