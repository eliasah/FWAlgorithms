#ifndef STAT_H
#define STAT_H

#include <iostream>
#include <ctime>
/**
 * @class Stat
 * La classe Stat répresente un objet
 * de statistique qui va mesurer des 
 * operations effectuées par un certain algorithmes.
 */
class Stat {
protected:
	int nbTests; /*!< Nombre d'operations de comparaisons */
	int nbAff; /*!< Nombre d'operations d'affectations*/
	int nbOpAr; /*!< Nombre d'operations arithmétiques */
	clock_t chrono; /*!< Temps d'execution (version Beta)*/
public:

	/**
	 * Constructeur.
	 * Initialise une instance de la class Stat.
	 **/
	Stat() : nbTests(0), nbAff(0), nbOpAr(0){
		chrono = std::clock();
	}

	/**
	 * Desctructeur.
	 * Detruit l'instance de la class Stat.
	 **/
	virtual ~Stat() {}

	/**
	 * Incremente le nombre d'operation de comparaisons
	 **/
	void incrNbTests() { nbTests++; }

	/**
	 * Incremente le nombre d'operation d'affectations
	 **/
	void incrNbAff() { nbAff++; }

	/**
	 * Incremente le nombre d'operation arithmétiques
	 **/
	void incrNbOpAr() { nbOpAr++; }

	/**
	 * Reinitialise le chrono de stat
	 **/
	void time_reset() {
		chrono = std::clock();
	}

	/**
	 * Affiche tous les stats
	 */
	void show_stats() {
		print_tests();
		print_assignments();
		print_opar();
		print_time();
	}

	/**
	 * Affiche le temps d'execution d'un algorithme associé à une statistiques
	 * Son utilisation s'attend à la réinitialisation du chrono
	 */
	void print_time() {
		double duration;
		duration = ( std::clock() - chrono ) / (double) CLOCKS_PER_SEC;
		std::cout<<"# Temps d'execution: " << duration << " sec. "<< std::endl;
	}

	/**
	 * Affiche le nombre de comparaisons d'un algorithme
	 */
	void print_tests() {
		std::cout << "# Tests: " << nbTests << std::endl;
	}

	/**
	 * Affiche le nombre d'affectations d'un algorithme
	 */
	void print_assignments(){
		std::cout << "# Affectations: " << nbAff << std::endl;
	}

	/**
	 * Affiche le nombre d'operations arithmétiques d'un algorithme
	 */

	void print_opar(){
		std::cout << "# Opérations arithmétiques: " << nbOpAr << std::endl;
	}
};

#endif /* STAT_H */
