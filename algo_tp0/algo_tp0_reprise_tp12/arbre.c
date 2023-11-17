/* Lina Djihane AZIZA 10/2023 */

#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

// fonction qui permet d’allouer de l’espace mémoire pour un noeud et d’initialiser les champs du noeud
Noeud* nouvNoeud(char carac) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
	// gestion de l'échec de l'allocation mémoire
    if (nouveau == NULL) {
        printf("error allocating memory\n");
        exit(EXIT_FAILURE);
    } 
    nouveau->data = carac;
    nouveau->filsG = NULL;
    nouveau->filsD = NULL; 
    static int numeroCreation = 0;
    numeroCreation++;
    nouveau->num = numeroCreation;
    return nouveau;
}

// fonction récursive qui cherche un noeud dans un arbre dont le champs num est égale au numéro passé en paramètre
Noeud* rechercheNoeud(Noeud *n, int numNoeud) {
	Noeud *tmpNoeud;
	if(n == NULL) return(NULL);
	if(n->num == numNoeud) return(n);
	tmpNoeud = rechercheNoeud(n->filsG, numNoeud);
	if(tmpNoeud != NULL) return(tmpNoeud);
	return(rechercheNoeud(n->filsD, numNoeud));
}

// fonction pour insérer un fils gauche
void insererFG(Noeud* noeudAInserer, Noeud* arbre, int numNoeudParent) {
	// recherche du noeud parent
    Noeud* noeudParent = rechercheNoeud(arbre, numNoeudParent);
    // si le noeud parent n'est pas trouvé, ou si le noeud à insérer est NULL, on ne fait rien
    if(noeudParent == NULL || noeudAInserer == NULL) return;
    // si le noeud parent a déjà un fils gauche, alors son fils gauche devient le fils gauche du noeud à insérer
    if(noeudParent->filsG != NULL) noeudAInserer->filsG = noeudParent->filsG;
    // on insère le noeud à insérer en tant que fils gauche du noeud parent
    noeudParent->filsG = noeudAInserer;
}


// fonction pour insérer un fils droit
void insererFD(Noeud* noeudAInserer, Noeud* arbre, int numNoeudParent) {
    // recherche du noeud parent
    Noeud* noeudParent = rechercheNoeud(arbre, numNoeudParent);
    // si le noeud parent n'est pas trouvé, ou si le noeud à insérer est NULL, on ne fait rien
    if (noeudParent == NULL || noeudAInserer == NULL) return;
    // si le noeud parent a déjà un fils droit, alors son fils droit devient le fils droit du noeud à insérer
    if(noeudParent->filsD != NULL) noeudAInserer->filsD = noeudParent->filsD;
    // on insère le noeud à insérer en tant que fils droit du noeud parent
    noeudParent->filsD = noeudAInserer;
}

// fonction récursive qui fait le parcours préfixe d’un arbre
void parcoursPrefixe(Noeud* arbre) {
    if (arbre == NULL) return;
	printf("%c\n", arbre->data);
    parcoursPrefixe(arbre->filsG);
    parcoursPrefixe(arbre->filsD);
}