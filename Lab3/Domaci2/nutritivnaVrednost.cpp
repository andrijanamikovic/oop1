#include "nutritivnaVrednost.h"

NutritivnaVrednost operator+(const NutritivnaVrednost& n1, const NutritivnaVrednost& n2)
{
	return NutritivnaVrednost(n1.ugljeniHidrati + n2.ugljeniHidrati, n1.mast + n2.mast, n1.proteini + n2.proteini);
}

double NutritivnaVrednost::kalorije()
{
	return mast * 9 + proteini * 4 + ugljeniHidrati * 4;
}
