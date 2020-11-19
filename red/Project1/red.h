#ifndef _red_h_
#define _red_h_

class Red
{
	int* arr, first, last;
	int l, cap;
public:
	Red(int k);
	Red(const Red& rd);
	Red(Red&& rd);
	~Red();
	void put(int b);
	int get();

	bool empty() { return l == 0; }
	bool full() { return l == cap; }

	void print()const;

	void emp() { l = first = last = 0; }


};

#endif // !_red_h_
