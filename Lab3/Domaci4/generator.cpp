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

void Generator::operator()(Izraz& i)
{
	Izraz postfix;
	Lista<Element> stack;

	while (i.getBr() != 0 ) {

		Element* a = i.operator*();
	
		if (a->getOZnaka() == 'D') {
			postfix += a->kopija();
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
			if (stack.getBr() == 0) {
				stack += a;
			}
			else {
				Element* b = -stack;
				if (prioritet(a) > prioritet(b)) {
					stack += b;
					stack += a;
				}
				else if (prioritet(a) == prioritet(b)) {
					throw GPostfiks();
					//stack += b;
					//stack += a;
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
				}
			}

		}
	}
	if (stack.getBr() != 0) {
		while (stack.getBr() != 0) {
			Element* b = -stack;
			postfix += b->kopija();
		}
	}
	i = postfix;
}
