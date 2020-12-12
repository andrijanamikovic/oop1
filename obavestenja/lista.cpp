#include "lista.h"

void Lista::brisi()
{
	while (prvi) {
		Elem* pom = prvi;
		prvi = prvi->sled;
		delete pom;
	}
}

Lista::~Lista()
{
	brisi();
}

Lista& Lista::operator+=(Obavestenje* o)
{
	prvi = new Elem(o, prvi);
	return *this;
}

void Lista::operator()() const
{
	for (Elem* pom = prvi; pom; pom = pom->sled) {
		if (pom->o->is_read() == false)
			cout << *(pom->o);
	}
}

int Lista::operator+() const
{
	int n = 0;
	for (Elem* pom = prvi; pom; pom = pom->sled) {
		if (pom->o->is_read() == false)
			n++;
	}
	return n;
}

void Lista::operator!()
{
	for (Elem* pom = prvi; pom; pom = pom->sled)
		if (pom->o->is_read() == false)
			pom->o->set_read();

}

Obavestenje* Lista::operator[](int id)
{
	for (Elem* pom = prvi; pom; pom = pom->sled)
		if (pom->o->is_read() == false && pom->o->get_id() == id)
			return pom->o;
	return nullptr;
}

ostream& operator<<(ostream& os, const Lista& l)
{
	for (Lista::Elem* pom = l.prvi; pom; pom = pom->sled)
		os << *(pom->o) << endl;
	return os;
}
