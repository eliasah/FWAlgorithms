#include <iostream>
#include "../header/Entier.hpp"
#include "../header/Float.hpp"
#include <unistd.h>
#include <ctime>
#include <cstdlib>

template<Stat *s> void sommeNaive(Entier<s> debut, Entier<s> fin) {
	Entier<s> somme = 0;
	for (Entier<s> i=debut; i<=fin; i++) {
		somme += i;
		// std::cout << somme << std::endl;
	}
	std::cout << "Somme des éléments allant de " 
	<< debut << " à " << fin << ": " << somme << std::endl;;
}


template<Stat *s> void sommeGauss(Entier<s> debut, Entier<s> fin) {
	Entier<s> somme;
	somme = (fin * (fin + debut)) / 2;
	std::cout << "Somme des éléments allant de " 
	<< debut << " à " << fin << ": " << somme << std::endl;;
}


template<Stat *s,class T> void triBulles(T *tab, int taille) {
	bool echange = false;
	while (!echange) {
		echange = true;
		for (int i=0; i<taille-1; i++) {
			if (tab[i] > tab[(i+1)]) {
				T tmp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = tmp;
				echange = false;
			}
		}
		taille--;
	}
}

template<Stat *s,class T> void triSelection(T *tab, int taille) {
	int i, j, minIndex;
	T tmp;    
	for (i = 0; i < taille - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < taille; j++)
			if (tab[j] < tab[minIndex])
				minIndex = j;
		if (minIndex != i) {
			tmp = tab[i];
			tab[i] = tab[minIndex];
			tab[minIndex] = tmp;
		}
	}
}

template<Stat *machin,class T> void quicksort(T *a, int leftarg, int rightarg) {
	// std::cout << "quicksort(" << a << "," << leftarg << "," << rightarg <<")"<< endl;
	// sleep(1);
	if (leftarg < rightarg) {
		T pivotvalue = a[leftarg];
		int left = leftarg - 1;
		int right = rightarg + 1;

		for(;;) {

			while (a[--right] > pivotvalue);
			while (a[++left] < pivotvalue);

			if (left >= right) break;

			T temp = a[right];
			a[right] = a[left];
			a[left] = temp;
		}

		int pivot = right;
		quicksort<machin>(a,
				leftarg, pivot);
		quicksort<machin>(a,
				pivot + 1, rightarg);
	}
}

Stat s, naive, gauss,sort,st,programme;

int test1() {
	//st.time_reset();
	naive.time_reset();
	std::cout << "SOMME NAIVE" << std::endl;
	sommeNaive<&naive>(1,32000);
	naive.show_stats();
	std::cout << std::endl;

	//gauss.time_reset();
	std::cout << "SOMME DE GAUSS" << std::endl;
	sommeGauss<&gauss>(1,320);
	gauss.show_stats();
	std::cout << std::endl;

	//std::cout << "TRI BULLES" << std::endl;

	std::cout << "TRI SELECTION" << std::endl;
	int taille = 10;
	Float<&s> tab1[10] = {12.1,48.3,5.4,9,1.7,20.5,1.3,24.5,3,7};
	// triBulles<&s>(tab,taille);

	// s.time_reset();
	triSelection<&s>(tab1,taille);
	std::cout << "[";
	for (int i=0; i<taille; i++) {
		std::cout << tab1[i];
		if (i < taille-1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	s.show_stats();

	// sort.time_reset();
	std::cout << "QUICKSORT" << std::endl;
	Float<&sort> tab2[20];
	int i;
	for(i=0;i<20;i++) {
		tab2[i]=20-i;
	}

	quicksort<&sort>(tab2,0,19);	
	std::cout << "[";
	for (int i=0; i<20; i++) {
		std::cout << tab2[i];
		if (i < 19)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	sort.show_stats();

	return 0;
}

int test3() {
	srand(time(NULL));
	std::cout << "QUICKSORT" << std::endl;
	Float<&sort> tab2[20];
	int i,taille = 500;
	std::cout << "creation du tableau" << std::endl;
	for(i=0;i<taille;i++) {
		tab2[i] = 1 + (int)(((double)rand())/((double)RAND_MAX+1)*(double)1000);
	}
	sort.time_reset();
	std::cout << "triage du tableau" << std::endl;
	quicksort<&sort>(tab2,0,taille);	
	std::cout << "[";
	for (int i=0; i<taille; i++) {
		std::cout << tab2[i];
		if (i < taille - 1)
			std::cout << ", ";
		if (i%20==1)
			std::cout << std::endl;
	}
	std::cout << "]" << std::endl;
	sort.show_stats();

	return 0;

}

int main() {
	programme.time_reset();
	test3();
	programme.print_time();

}
