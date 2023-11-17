/* Lina Djihane AZIZA 10/2023 */

#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeud {
	char data;
	int num;
	struct noeud *filsD, *filsG;
} Noeud;

Noeud* nouvNoeud(char carac);
Noeud* rechercheNoeud(Noeud *n, int numNoeud);
void insererFG(Noeud* noeudAInserer, Noeud* arbre, int numNoeudParent);
void insererFD(Noeud* noeudAInserer, Noeud* arbre, int numNoeudParent);
void parcoursPrefixe(Noeud* arbre);

#endif /* ARBRE_H */
