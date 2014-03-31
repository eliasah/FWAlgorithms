/** @mainpage Algorithms FrameWork
 *
 * Il s'agit d'un ensemble de classes, modèles de classes, fonctions, modèles de fonctions, etc. permettant
 * d’écrire des algorithmes et d’effectuer des mesures sur leurs exécutions. L’utilisateur de ce canevas pourra 
 * par exemple être simplement conduit à indiquer qu’il souhaite mesurer
 * un algorithme sur des Entiers (exemple quicksort sur les tableaux d’ints).
 *
 * @author Richard Isabelle, Abou Haydar Elias, Ourfahli Anthony
 **/


#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include "Stat.hpp"

using namespace std;

/**
 * @class Object
 * La classe Object répresente un 
 * modele de classe de type O et une réference 
 * vers une instance de statistique.
 */
template<class O, Stat *stat> class Object {
protected:
	O elt; /*!< élement de type O. */
public:

	/**
	 * Constructeur.
	 * Donne une valeur par défaut et un type O de cet objet.
	 * @tparam O type de l'objet à construire.
	 * @tparam stat réference vers la statistiques en cours d'utilisation.
	 **/
	Object<O,stat>() {}

	/**
	 * Constructeur.
	 * Donne une réference vers un element de type O à cet objet.
	 * @tparam O type de l'objet à construire.
	 * @tparam stat réference vers la statistiques en cours d'utilisation.
	 * @param elt réference vers un element.
	 **/
	Object<O,stat>(const O &elt) : elt(elt) {}
	/**
	 * Destructeur.
	 * Detruit une object Object
	 */
	virtual ~Object() {}

	/**
	 * Operateur de redirection du flux de sortie standard cout
	 * @param os flux de sortie standard
	 * @param o un objet
	 */ friend ostream &operator<<(ostream &os, const Object &o) {
		 os << o.elt;
		 return os;
	 }

	 /**
	  * Surcharge de l'operateur d'affectation = 
	  * @param elt un element de type O.
	  */
	 void operator=(O &elt) {
		 stat->incrNbAff();
		 this->elt = elt;
	 }

	 /**
	  * Surcharge de l'operateur d'affectation = 
	  * @param o un objet (Object).
	  */
	 void operator=(const Object &o) {
	     stat->incrNbAff();
		 this->elt = o.elt;
	 }

	 /**
	  * Surcharge de l'operateur de comparaison >
	  * @param o un element de type O. 
	  */
	 bool operator>(const O &o) {
		 stat->incrNbTests();
		 return this->elt > o;
	 }

	 /**
	  * Surcharge de l'operateur de comparaison >
	  * @param o un objet (Object).
	  */
	 bool operator>(const Object &o) { 
		 // stat->incrNbTests();
		 return *this > o.elt; 
	 }

	 /**
	  * Surcharge de l'operateur de comparaison <
	  * @param o un element de type O. 
	  */
	 bool operator<(const O &o) {
		 stat->incrNbTests();
		 return this->elt < o;
	 }
	 /**
	  * Surcharge de l'operateur de comparaison <
	  * @param o un objet (Object).
	  */
	 bool operator<(const Object &o) { 
	     stat->incrNbTests();
	     return this->elt < o.elt; 
	 }
	 /**
	  * Surcharge de l'operateur de comparaison <=
	  * @param o un element de type O. 
	  */
	 bool operator<=(const O &o) {
		 stat->incrNbTests();
		 return !(this->elt > o);
	 }
	 /**
	  * Surcharge de l'operateur de comparaison <=
	  * @param o un objet (Object).
	  */
	 bool operator<=(const Object &o) { 
		 // stat->incrNbTests();
		 return *this <= o.elt; 
	 }
	 /**
	  * Surcharge de l'operateur de comparaison >=
	  * @param o un element de type O. 
	  */
	 bool operator>=(const O &o) {
		 stat->incrNbTests();
		 return !(this->elt < o);
	 }
	 /**
	  * Surcharge de l'operateur de comparaison >=
	  * @param o un objet (Object).
	  */
	 bool operator>=(const Object &o) { 
		 // stat->incrNbTests();
		 return *this >= o.elt; 
	 }
	 /**
	  * Surcharge de l'operateur de comparaison ==
	  * @param o un element de type O. 
	  */
	 bool operator==(const O &o) {
		 stat->incrNbTests();
		 return this->elt == o;
	 }
	 /**
	  * Surcharge de l'operateur de comparaison ==
	  * @param o un objet (Object).
	  */
	 bool operator==(const Object &o) { 
		 //stat->incrNbTests();
		 return *this == o.elt; 
	 }
	 /**
	  * Surcharge de l'operateur de comparaison !=
	  * @param o un element de type O. 
	  */
	 bool operator!=(const O &o) {
		 stat->incrNbTests();
		 return this->elt != o;
	 }
	 /**
	  * Surcharge de l'operateur de comparaison !=
	  * @param o un objet (Object).
	  */
	 bool operator!=(const Object &o) { 
		 //stat->incrNbTests();
		 return *this != o.elt; 
	 }

	 // ---------------------------------------------------------------------------------------------

	 /**
	  * Surcharge de l'operateur bit a bit ^
	  * @param o un element de type O. 
	  */
	 Object &operator^(const O &o) {
		 stat->incrNbTests();
		 return this->elt ^ o;
	 }
	 /**
	  * Surcharge de l'operateur bit a bit ^
	  * @param o un objet (Object).
	  */
	 Object &operator^(const Object &o) {
		// stat->incrNbTests();
		 return *this ^ o.elt;
	 }
	 /**
	  * Surcharge de l'operateur bit a bit &
	  * @param o un element de type O. 
	  */
	 Object &operator&(const O &o) {
		 stat->incrNbTests();
		 return this->elt & o;
	 }
	 /**
	  * Surcharge de l'operateur bit a bit &
	  * @param o un objet (Object).
	  */
	 Object &operator&(const Object &o) {
		// stat->incrNbTests();
		 return *this & o.elt;
	 }
	 /**
	  * Surcharge de l'operateur bit a bit |
	  * @param o un element de type O. 
	  */
	 Object &operator|(const O &o) {
		 stat->incrNbTests();
		 return this->elt | o;
	 }
	 /**
	  * Surcharge de l'operateur bit a bit ~
	  */
	 Object &operator~() {
		 stat->incrNbTests();
		 return ~this->elt;
	 }

};

#endif /* OBJET_H */
