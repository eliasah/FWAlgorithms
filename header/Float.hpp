#ifndef FLOAT_H
#define FLOAT_H

#include "Stat.hpp"
#include "Object.hpp"

/**
 * @class Float
 * La classe Float répresente un 
 * modele de classe de type float et une réference 
 * vers une instance de statistique.
 * La classe Float hérite de la spécification de Object<float,stat>
 */
template<Stat *stat> class Float : public Object<float,stat> {
public:
	/**
	 * Constructeur.
	 * Donne une valeur par défaut à un flotant.
	 * @tparam stat réference vers la statistiques en cours d'utilisation.
	 **/
	Float<stat>() : Object<float,stat>() {}
	/**
	 * Constructeur.
	 * Donne une réference vers un element de type O à cet objet.
	 * @tparam stat réference vers la statistiques en cours d'utilisation.
	 * @param i réference vers un flotant.
	 **/
	Float<stat>(const float &i) : Object<float,stat>(i) {}
	/**
	 * Destructeur
	 * Detruit l'objet de type Float
	 **/
	virtual ~Float() {}

	/**
	 * Surcharge de l'operateur + 
	 * @param i un flotant.
	 */
	Float operator+(const float &i) {
		stat->incrNbOpAr();
		return this->elt + i;
	}
	/**
	 * Surcharge de l'operateur + 
	 * @param e un objet Float.
	 */
	Float operator+(const Float &e) { 
		stat->incrNbOpAr();
		return *this + e.elt; 
	}
	/**
	 * Surcharge de l'operateur - 
	 * @param i un flotant.
	 */
	Float operator-(const float &i) {
		stat->incrNbOpAr();
		return this->elt - i;
	}
	/**
	 * Surcharge de l'operateur - 
	 * @param e un objet Float.
	 */
	Float operator-(const Float &e) {
		stat->incrNbOpAr();
		return *this - e.elt;
	}
	/**
	 * Surcharge de l'operateur * 
	 * @param i un flotant.
	 */
	Float operator*(const float &i) {
		stat->incrNbOpAr();
		return this->elt * i;
	}
	/**
	 * Surcharge de l'operateur * 
	 * @param e un objet Float.
	 */
	Float operator*(const Float &e) {
		stat->incrNbOpAr();
		return *this * e.elt;
	}
	/**
	 * Surcharge de l'operateur / 
	 * @param i un flotant.
	 */
	Float operator/(const float &i) {
		stat->incrNbOpAr();
		return this->elt / i;
	}
	/**
	 * Surcharge de l'operateur / 
	 * @param e un objet Float.
	 */
	Float operator/(const Float &e) {
		stat->incrNbOpAr();
		return *this / e.elt;
	}
	/**
	 * Surcharge de l'operateur % 
	 * @param i un flotant.
	 */
	Float operator%(const float &i) {
		stat->incrNbOpAr();
		return this->elt % i;
	}
	/**
	 * Surcharge de l'operateur % 
	 * @param e un objet Float.
	 */
	Float operator%(const Float &e) {
		stat->incrNbOpAr();
		return *this % e.elt;
	}

	/**
	 * Surcharge de l'operateur d'incrementation prefixe ++ 
	 */
	Float &operator++() {
		stat->incrNbOpAr();
		(this->elt)++;
		return *this;
	}

	/**
	 * Surcharge de l'operateur de decrementation prefixe -- 
	 */
	Float &operator--() {
		stat->incrNbOpAr();
		(this->elt)--;
		return *this;
	}

	/**
	 * Surcharge de l'operateur de réaffecation avec incrementation
	 * @param i un flotant.
	 */
	Float &operator+=(const float &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		this->elt += i;
		return *this;
	}
	/**
	 * Surcharge de l'operateur de réaffecation avec incrementation 
	 * @param e un objet Float.
	 */
	Float &operator+=(const Float &e) {
		return *this += e.elt;
	}
	/**
	 * Surcharge de l'operateur de réaffecation avec decrementation
	 * @param i un flotant.
	 */
	Float &operator-=(const float &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return this->elt -= i;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec decrementation
	 * @param e un objet Float.
	 */
	Float &operator-=(const Float &e) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return *this -= e.elt;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec multiplication
	 * @param i un flotant.
	 */
	Float &operator*=(const float &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return this->elt *= i;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec multiplication
	 * @param e un objet Float.
	 */
	Float &operator*=(const Float &e) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return *this *= e.elt;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec division
	 * @param i un flotant.
	 */
	Float &operator/=(const float &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return this->elt /= i;
	}
	/**
	 * Surcharge de l'operateur de réaffecation avec division
	 * @param e un objet Float.
	 */
	Float &operator/=(const Float &e) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return *this /= e.elt;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec le modulo 
	 * @param i un flotant.
	 */
	Float &operator%=(const float &i) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return this->elt /= i;
	}
	/**
	 * Surcharge de l'operateur de réaffectation avec le modulo 
	 * @param e un objet Float.
	 */
	Float &operator%=(const Float &e) {
		stat->incrNbOpAr();
		stat->incrNbAff();
		return *this /= e.elt;
	}
};

#endif /* FLOAT_H */
