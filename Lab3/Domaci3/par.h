#ifndef _par_h_
#define _par_h_
#include <iostream>

template <typename T>
class Par {
	T* domaci;
	T* gost;
public:
	Par(T* d = nullptr, T* g = nullptr):domaci(d),gost(g){}
	void setPrvi(T* t) {
		domaci = t;
	}
	void setDrugi(T* t) {
		gost = t;
	}
	T* getDomaci() const { return domaci; }
	T* getGost() const { return gost; }
	/*Par(const Par& p) {
		domaci = new T(p.domaci);
		gost = new T(p.gost);
	}
	Par(Par&& p) {
		domaci = p.domaci;
		gost = p.gost;
	}
	~Par() {
		delete domaci;
		delete gost;
	}*/
	friend bool operator==(const Par p1, const Par p2) {
		if (*p1.getDomaci() == *p2.getDomaci() && *p1.getGost() == *p2.getGost) return true;
		return false;
	}

	friend std::ostream& operator<<(std::ostream& os, const Par& p) {
		return os << "[" << (*p.getDomaci()) << "-" << (*p.getGost()) << "]";
	}
};
#endif // !_par_h_
