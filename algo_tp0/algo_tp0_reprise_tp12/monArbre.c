/* Lina Djihane AZIZA 10/2023 */

#include <stdio.h>
#include "arbre.h"

int main() {
	int choix, pos;
	char carac, fils;
	Noeud *arbre;
	do {
		printf("Que voulez vous faire ?\n");
		printf("1. Creer et inserer un noeud\n");
		printf("2. Afficher l'arbre en parcours prefixe\n");
		printf("0. Quitter\n");
		scanf("%d", &choix);
		switch(choix) {
			case 1:
				printf("donnez le caractere a inserer dans le noeud\n");
				scanf(" %c", &carac);
				printf("donnez le numero du noeud sous lequel vous voulez effectuer l'insertion (-1 s'il s'agit du noeud racine)\n");
				scanf("%d", &pos);
				printf("voulez vous l'inserer en tant que fils gauche (G) ou fils droit (D) (R s'il s'agit du noeud racine)\n");
				scanf(" %c", &fils);
				if (pos == -1) {
					arbre = nouvNoeud(carac);
					break;
				} 
				Noeud *nouveau = nouvNoeud(carac);
				if(fils == 'G') insererFG(nouveau, arbre, pos);
				if(fils == 'D') insererFD(nouveau, arbre, pos);
				break;
			case 2:
				parcoursPrefixe(arbre);
		}
	} while(choix != 0);
	return 0;
}
