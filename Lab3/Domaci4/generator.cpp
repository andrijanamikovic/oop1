#include "generator.h"
#include "operator.h"
#include "greske.h"

int p(Operator* o) {
	return o->getPrioritet();
}

int prioritet(Element* e) {
	if (e->getOZnaka() == 'O') {
		return p((Operator*)e);
	}

	return 0;
}
/*bool nextTo(Element* a, char c) {
	if (a->getOZnaka() == 'O' &&  c == '(') return true;
	if (c == 'O' && a->getOZnaka() == '(') return true;
	return false;

	|| nextTo(a, c)
}*/

void Generator::operator()(Izraz& i)
{
	Izraz postfix;
	Lista<Element> stack;
	int rank = 0;
	char c = ' ';

while (i.getBr() != 0 ) {

		Element* a = i.operator*();
		if (a->getOZnaka() == 'D') {
			if (a->getOZnaka() == c ) throw GPostfiks();
			postfix += a->kopija();
			rank++;
		}
		else if (a->getOZnaka() == '(') {
			stack += a;
		}
		else if (a->getOZnaka() == ')') {	
			if (stack.getBr() != 0) {
				Element* b = -stack;
				if (b->getOZnaka() != '(' && stack.getBr() == 0) {
					postfix += b->kopija();
				}
				
				while (stack.getBr() != 0 && b->getOZnaka() != '(') {
					postfix += b->kopija();
					Element* b = -stack;
				}
								/*if (b->getOZnaka() != '(' && stack.getBr() == 0) {
					postfix += b->kopija();
				}*/
			}
		}
		else if (a->getNatpis() == "+") { 
			if (a->getOZnaka() == c) throw GPostfiks();
			if (stack.getBr() == 0) {
				stack += a;
				rank--;
			}
			else {
				Element* b = -stack;
				if (prioritet(a) > prioritet(b)) {
					stack += b;
					stack += a;
					rank--;
				}
				else if (prioritet(a) == prioritet(b)) {
					//throw GPostfiks();
					stack += b;
					postfix += a;
				}
				else {
					postfix += b;
					while (stack.getBr() != 0) {
						Element* b = -stack;
						if (prioritet(a) > prioritet(b)) {
							break;
						}
						postfix += b;
					}
					if (rank!=1) throw GPostfiks();
				}
			}
			

		}
//		if (stack.getBr() == 0 && rank != 1) {
//			throw GPostfiks();
//		}
		if (a->getOZnaka()!=')' && a->getOZnaka()!='(')
			c = a->getOZnaka();
	}
	if (stack.getBr() != 0) {
		while (stack.getBr() != 0) {
			Element* b = -stack;
			postfix += b->kopija();
		}
	}
	i = postfix;
}
