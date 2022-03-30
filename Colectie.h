#pragma once;
#include "IteratorColectie.h"
typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//typedef struct Nod{
//	Nod *next;
//	TElem elem;
//};

class Nod {
	
	friend class IteratorColectie;
	friend class Colectie;

private:

	TElem elem;
	Nod* next;

};

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;


class Colectie {

	friend class IteratorColectie;

private:
	int size;
	Nod* nod;

public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();


};

