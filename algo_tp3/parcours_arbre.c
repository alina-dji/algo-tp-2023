#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int data;
    struct Noeud *filsD, *filsG;
} Noeud;

Noeud* creerNoeud(int val) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    nouveau->data = val;
    nouveau->filsG = NULL;
    nouveau->filsD = NULL;
    return nouveau;
}

// fonction récursive pour construire un arbre binaire 
Noeud* construireArbre(int val, int hauteur) {
    if (hauteur == 0) {
        return NULL; 
    }
    Noeud* racine = creerNoeud(val);
    // construction récursive des sous-arbres gauche et droit
    racine->filsG = construireArbre(2 * val, hauteur - 1);
    racine->filsD = construireArbre(2 * val + 1, hauteur - 1);
    return racine;
}

// parcours préfixe (ordre : racine - gauche - droit)
void parcoursPrefixe(Noeud* racine) {
    if (racine != NULL) {
        printf("%d ", racine->data);
        parcoursPrefixe(racine->filsG);
        parcoursPrefixe(racine->filsD);
    }
}

// parcours infixé (ordre : gauche - racine - droit)
void parcoursInfixe(Noeud* racine) {
    if (racine != NULL) {
        parcoursInfixe(racine->filsG);
        printf("%d ", racine->data);
        parcoursInfixe(racine->filsD);
    }
}

// parcours postfixe (ordre : gauche - droit - racine)
void parcoursPostfixe(Noeud* racine) {
    if (racine != NULL) {
        parcoursPostfixe(racine->filsG);
        parcoursPostfixe(racine->filsD);
        printf("%d ", racine->data);
    }
}

int main() {
    Noeud* arbre = construireArbre(1, 3);

    printf("Parcours prefixe : ");
    parcoursPrefixe(arbre);
    printf("\n");

    printf("Parcours infixe : ");
    parcoursInfixe(arbre);
    printf("\n");

    printf("Parcours postfixe : ");
    parcoursPostfixe(arbre);
    printf("\n");

    return 0;
}
