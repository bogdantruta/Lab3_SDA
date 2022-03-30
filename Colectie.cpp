#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
	if (e1 <= e2) return true;
	return false;
}

Colectie::Colectie() {
	this->nod = 0;
	this->size = 0;
}

void Colectie::adauga(TElem e) {
	Nod* i = this->nod;
	if (this->size == 0) {
		Nod* nodNou = new Nod;
		nodNou->elem = e;
		nodNou->next = 0;
		this->nod = nodNou;
		this->size++;
		return;
	}
	if (rel(e, i->elem)) {
		Nod* nodNou = new Nod;
		nodNou->elem = e;
		nodNou->next = this->nod;
		this->nod = nodNou;
		this->size++;
		return;
	}
	while (i->next != 0) {
		if (rel(e, i->next->elem)) {
			Nod* nodNou = new Nod;
			nodNou->elem = e;
			nodNou->next = i->next;
			i->next = nodNou;
			this->size++;
			return;
		}
		else i = i->next;
	}
	i->next = new Nod;
	i->next->elem = e;
	i->next->next = 0;
	this->size++;

}


bool Colectie::sterge(TElem e) {
	Nod* i = this->nod;
	Nod* aux;
	if (this->size == 0) return false;
	if (i->elem == e) {
		this->nod = i->next;
		this->size--;
		delete i;
		return true;
	}
	while (i->next != 0) {
		if (i->next->elem == e) {
			aux = i->next;
			i->next = i->next->next;
			delete aux;
			this->size--;
			return true;
		}
		else i = i->next;
	}
	return false;
}


bool Colectie::cauta(TElem elem) const {
	Nod* i = this->nod;
	while (i != 0) {
		if (i->elem == elem)
			return true;
		i = i->next;
	}
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	int nr = 0;
	Nod* i = this->nod;
	while (i != 0) {
		if (i->elem == elem)
			nr++;
		i = i->next;
	}
	return nr;
}



int Colectie::dim() const {
	return this->size;
}


bool Colectie::vida() const {
	if (this->size != 0) return false;
	return true;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	Nod* i = this->nod;
	Nod* aux;
	while (i != 0) {
		aux = i->next;
		delete i;
		i = aux;
	}
}
