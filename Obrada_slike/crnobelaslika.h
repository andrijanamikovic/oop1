#ifndef _crnobelaslika_h_
#define _crnobelaslika_h_
#include "slika.h"

class CrnoBelaSlika : public Slika {
public:
	CrnoBelaSlika(int v, int s);

	CrnoBelaSlika(const CrnoBelaSlika& cbs);
	CrnoBelaSlika(CrnoBelaSlika&& cbs);
	~CrnoBelaSlika();


	void set_piksel(Piksel p, Pozicija poz);
};
#endif // !_crnobelaslika_h_
