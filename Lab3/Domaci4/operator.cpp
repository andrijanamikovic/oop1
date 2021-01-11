#include "operator.h"

bool operator>(const Operator& op1, const Operator& op2)
{
    return op1.getPrioritet() > op2.getPrioritet();
}
