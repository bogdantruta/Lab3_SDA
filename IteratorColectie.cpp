#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	this->curent = col.nod;
}

TElem IteratorColectie::element() const{
	if (valid()) return this->curent->elem;
	else throw "Validation Exception";
	return -1;
}

bool IteratorColectie::valid() const {
	if (this->curent != 0) return true;
	return false;
}

void IteratorColectie::urmator() {
	this->curent = this->curent->next;
	valid();
}

void IteratorColectie::prim() {
	this->curent = col.nod;
}
