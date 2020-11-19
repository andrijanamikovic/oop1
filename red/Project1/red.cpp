#include "red.h"
#include <iostream>
#include <cstdlib>

using namespace std;
Red::Red(int k)
{
	arr = new int[k];
	cap = k;
	first = last = 0;
}

Red::Red(const Red& rd) {
	arr = new int[rd.cap];
	for (int i = 0; i < rd.cap; i++) {
		arr[i] = rd.arr[i];
	}
	cap = rd.cap;
	last = rd.last;
	l = rd.l;
	first = rd.first;
}

Red::Red(Red&& rd) {
	arr = rd.arr;
	cap = rd.cap;
	last = rd.last;
	l = rd.l;
	first = rd.first;
	rd.arr = nullptr;
}

Red::~Red() {
	delete []arr;
}

void Red::put(int k) {
	if (l == cap) exit(1);
	arr[last++] = k;
	if (last == cap) last = 0;
	l++;
}

int Red::get()
{
	if (l == 0) exit(2);
	int b = arr[first++];
	if (first == cap) first = 0;
	l--;
	return b;
}

void Red::print()const 
{
	if (l == 0) cout <<"Red je prazan";
	for (int i = 0; i < l; i++) {
		cout << arr[first + i] << " ";
	}
}

