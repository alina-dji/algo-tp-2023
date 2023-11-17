/* Lina Djihane AZIZA 10/2023 */

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

// fonction qui alloue l'espace mémoire pour une cellule, remplit les champs de la cellule et retourne un pointeur sur cette cellule 
Cellule* NouvCel(Point p) {
	Cellule *cel = (Cellule*)malloc(sizeof(Cellule));
	// gestion de l'échec de l'allocation mémoire
	if(cel != NULL) {
		cel->pt.x = p.x;
		cel->pt.y = p.y;
		cel->suiv = NULL;
		cel->prec = NULL;
	}
	else {
		printf("error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	return cel;
}

// La position pl passée en paramètre est une position valide, i.e. 0 <= pl <= indice de la dernière cellule.
// On considère que la première cellule de la liste est à la position 1.

// fonction qui insère la cellule cel après la position pl dans la liste 
void InsererCellule(int pl, Cellule *cel, Cellule *liste) {
	Cellule *T = liste;
	Cellule *S = NULL;
	int i = 1; 
	while(pl != i) {
		T = T->suiv;
		i++;
	}
	cel->suiv = T->suiv;
	cel->prec = T;
	S = T->suiv;
	T->suiv = cel;
	if(S != NULL) S->prec = cel;
	if(cel->suiv == NULL) {
		cel->suiv = liste;
		liste->prec = cel;
	}
}

// fonction qui supprime la cellule à la position pl dans la liste 
void SupprimeCellule(int pl, Cellule **liste) {
	Cellule *T, *S, *L;
	L = *liste;
	if (pl == 1) {
		T = (*liste);
		*liste = (*liste)->suiv;
		(*liste)->prec = T->prec;
		S = T->prec;
		S->suiv = *liste;
		free(T);
		return;
	}
	int i = 1;
	while(pl != i) {
		L = L->suiv;
		i++;
	}
//	Cellule *celPrec, *celSuiv;
	T = L->prec;
	T->suiv = L->suiv;
	S = L->suiv;
	S->prec = L->prec;
	free(L);
}

// fonction qui affiche la liste
void Afficher(Cellule *liste) {
	Cellule *T = liste;
	int i = 1;
	do {
		printf("P%d = (%d, %d)\n", i, T->pt.x, T->pt.y);
		T = T->suiv;
		i++;
	} while(T != liste);
}