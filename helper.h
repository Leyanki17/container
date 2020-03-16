#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#include <string>
 struct Cel{
        int val;
        Cel* suivant;
       Cel* previous;
    };
     struct Cellule{
        int val;
        Cellule* suivant;
    };
/**
* operation va permettre de fait le choix des op�rations sur la structure tableau
* op�ration ne prend rien en param
* operation ne renvoie rien en retour
*/
void operation();

/**
* swapElt va permettre de permuter de nombre
* @param tab est le tableau contenant les �l�ment a permuter
* @param i,j sont les indices des valeurs � permuter
* swapElt ne renvoie rien
*/
void swapElt(int *tab,int i,int j);

/**
* searchMin permet de rechercher le minimum d'un tableau
* @param tab est le tableau dont on veu un min
* @param taille est taille du tableau
* @param ind est la position a� partie de la quelle on commence a cherche
* searchMin renvoie l'indice du min
*/
int searchMin(int *tab,int taille,int ind);
/**
* searchMax permet de rechercher le maximum d'un tableau
* @param tab est le tableau dont on veu un man
* @param taille est taille du tableau
* @param ind est la position a� partie de la quelle on commence a cherche
* searchMin renvoie l'indice du min
*/
int searchMax(int tab[],int taille,int ind);
void insertTab(int tab[],int taille);
void displayTab(int tab[],int taille);
/**
* selectionSort permet de trier un tableau par selection du minimum
* @param tab qui est le tableau � trier
* @param taille est la taille du tableau � trier
* selectionSort ne renvoie rien en retour
*/
void selectionSort(int tab[],int taille);
/**
* BulbeSort permet de triee un tableau par bulle
* @param tab qui est le tableau � trier
* @param taille est la taille du tableau � trier
* bulbeSort ne renvoie rien
*/
void bulbeSort(int tab[],int taille);

/**
* insertion permet de trier un tableau en ins�rant les elts
* @param tab tableau � trier
* @param taille taille du tableau � trier
*insertionSort ne renvoie rien
*/
void insertionSort(int tab[],int taille);

/**
* searchVal permet de faire la recherche d'un elt dans un tableau
* @param tab est le tableau o� on doit rechercher l'elt
* @param taille est la taille du tableau
* searchVal ne renvoie rien ;
*/
void searchVal(int tab[],int taille);
/**
* isSorted permet de savoir si un tableau est trier ou pas;
* @param tab tableau � trier
* @param taille taille du tableau en question
* isSorted renvoie un bool qui dit si oui ou non le tableau est tri�e
*/
bool isSorted(int tab[],int taille);

void dichotomicSearchVal(int tab[],int taille);

#endif // HELPER_H_INCLUDED
