#ifndef ENTIER_H
#define ENTIER_H

#include "Stat.hpp"
#include "Object.hpp"

/**
 * @class Entier
 * La classe Entier répresente un 
 * modele de classe de type int et une réference 
 * vers une instance de statistique.
 * La classe Entier hérite de la spécification de Object<int,stat>
 */
template<Stat *stat> class Entier : public Object<int,stat> {
public:
	/**
	 * Constructeur.
	 * Donne une valeur par défaut à un entier.
	 * @tparam stat réference vers la statistiques en cours d'utilisation.
	 **/
	Entier<stat>() : Object<int,stat>() {}
	/**
	 * Constructeur.
	 * Donne une réference vers un element de type O à cet objet.
	 * @tparam stat réference vers la statistiques en cours d'utilisation.
	 * @param i réference vers un entier.
	 **/
	Entier<stat>(const int &i) : Object<int,stat>(i) {}
	/**
	 * Destructeur
	 * Detruit l'objet de type Entier
	 **/
	virtual ~Entier() {}

	/**
	 * Surcharge de l'operateur + 
	 * @param i un entier.
	 */
	Entier operator+(const int &i) {
		stat->incrNbOpAr();
		return this->elt + i;
	}
	/**
	 * Surcharge de l'operateur + 
	 * @param e un objet Entier.
	 */
	Entier operator+(const Entier &e) { 
		//stat->incrNbOpAr();
		return *this + e.elt; 
	}
	/**
	 * Surcharge de l'operateur - 
	 * @param i un entier.
	 */
	Entier operator-(const int &i) {
		stat->incrNbOpAr();
		return this->elt - i;
	}
	/**
	 * Surcharge de l'operateur - 
	 * @param e un objet Entier.
	 */
	Entier operator-(const Entier &e) {
		//stat->incrNbOpAr();
		return *this - e.elt;
	}
	/**
	 * Surcharge de l'operateur * 
	 * @param i un entier.
	 */
	Entier operator*(const int &i) {
		stat->incrNbOpAr();
		return this->elt * i;
	}
	/**
	 * Surcharge de l'operateur * 
	 * @param e un objet Entier.
	 */
	Entier operator*(const Entier &e) {
		//stat->incrNbOpAr();
		return *this * e.elt;
	}
	/**
	 * Surcharge de l'operateur / 
	 * @param i un entier.
	 */
	Entier operator/(const int &i) {
		stat->incrNbOpAr();
		return this->elt / i;
	}
	/**
	 * Surcharge de l'operateur / 
	 * @param e un objet Entier.
	 */
	Entier operator/(const Entier &e) {
		//stat->incrNbOpAr();
		return *this / e.elt;
	}
	/**
	 * Surcharge de l'operateur % 
	 * @param i un entier.
	 */
	Entier operator%(const int &i) {
		stat->incrNbOpAr();
		return this->elt % i;
	}
	/**
	 * Surcharge de l'operateur % 
	 * @param e un objet Entier.
	 */
	Entier operator%(const Entier &e) {
		//stat->incrNbOpAr();
		return *this % e.elt;
	}

	/**
	 * Surcharge de l'operateur d'incrementation prefixe ++ 
	 */
	Entier &operator++() {
		//stat->incrNbOpAr();
		(this->elt)++;
		return *this;
	}

	/**
	 * Surcharge de l'operateur d'incrementation postfixe ++ 
	 * @param i un entier.
	 */
	void operator++(int i) {
		stat->incrNbOpAr();
		++(this->elt);
	}

	/**
	 * Surcharge de l'operateur de decrementation prefixe -- 
	 */
	Entier &operator--() {
		stat->incrNbOpAr();
		(this->elt)--;
		return *this;
	}
	/**
	 * Surcharge de l'operateur de decrementation postfixe -- 
	 * @param i un entier.
	 */
	void operator--(int i) { // postfixe
		stat->incrNbOpAr();
		--(this->elt);
	}
	/**
	 * Surcharge de l'operateur de réaffecation avec incrementation
	 * @param i un entier.
	 */
	Entier &operator+=(const int &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		this->elt += i;
		return *this;
	}
	/**
	 * Surcharge de l'operateur de réaffecation avec incrementation 
	 * @param e un objet Entier.
	 */
	Entier &operator+=(const Entier &e) {
		//stat->incrNbOpAr();
		return *this += e.elt;
	}
	/**
	 * Surcharge de l'operateur de réaffecation avec decrementation
	 * @param i un entier.
	 */
	Entier &operator-=(const int &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return this->elt -= i;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec decrementation
	 * @param e un objet Entier.
	 */
	Entier &operator-=(const Entier &e) {
		//stat->incrNbOpAr();
		//stat->incrNbAff();
		return *this -= e.elt;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec multiplication
	 * @param i un entier.
	 */
	Entier &operator*=(const int &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return this->elt *= i;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec multiplication
	 * @param e un objet Entier.
	 */
	Entier &operator*=(const Entier &e) {
		//stat->incrNbOpAr();
		//stat->incrNbAff();
		return *this *= e.elt;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec division
	 * @param i un entier.
	 */
	Entier &operator/=(const int &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return this->elt /= i;
	}
	/**
	 * Surcharge de l'operateur de réaffecation avec division
	 * @param e un objet Entier.
	 */
	Entier &operator/=(const Entier &e) {
		//stat->incrNbOpAr();
		//stat->incrNbAff();
		return *this /= e.elt;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec le modulo 
	 * @param i un entier.
	 */
	Entier &operator%=(const int &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return this->elt /= i;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec le modulo 
	 * @param e un objet Entier.
	 */
	Entier &operator%=(const Entier &e) {
		//stat->incrNbOpAr();
		//stat->incrNbAff();
		return *this /= e.elt;
	}
};

#endif /* ENTIER_H */
