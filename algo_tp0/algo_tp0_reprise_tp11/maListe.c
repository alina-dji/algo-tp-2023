/* Lina Djihane AZIZA 10/2023 */

#include <stdio.h>
#include "liste.h"

int main () {
	int sommets = 0;
	do {
		printf("donnez le nombre de sommets de votre polygone\n");
		scanf("%d", &sommets);
	} while(sommets < 3);
	int i;
	Point p;
	Cellule *newCel;
	Cellule *liste; // la tete de liste 	
	printf("donnez les points de votre polygone\n");
	for(i = 1; i <= sommets; i++) {
		printf("Coordonees du point P%d : \n", i);
		printf("x = ");
		scanf("%d", &p.x);
		printf("y = ");
		scanf("%d", &p.y);
		if(i == 1) {
			liste = NouvCel(p);
		} else {
			newCel = NouvCel(p);
			InsererCellule(i-1, newCel, liste);
		}
	}
	printf("voici les points de votre polygone :\n");
	Afficher(liste);
	int choix = 0;
	int pos = 0;
	do {
		printf("Que voulez vous faire maintenant ?\n");
		printf("1. Ajouter un point au polygone\n");
		printf("2. Supprimer un point du polygone\n");
		printf("3. Afficher les points du polygone\n");
		printf("0. Quitter\n");
		scanf("%d", &choix);
		
		switch(choix) {
			case 1:
				printf("Donnez les coordonees du point P a ajouter :\n");
				printf("x = ");
				scanf("%d", &p.x);
				printf("y = ");
				scanf("%d", &p.y);
				do {
					printf("Donnez la position a laquelle vous voulez inserer le point\n");
					scanf("%d", &pos);
				} while(pos <= 0 || pos > sommets);
				newCel = NouvCel(p);
				InsererCellule(pos, newCel, liste);
				sommets++;
				break;
			case 2:
				int pos = 0;
				do {
					printf("Donnez la position a laquelle vous voulez supprimer le point\n");
					scanf("%d", &pos);
				} while(pos <= 0 || pos > sommets);
				SupprimeCellule(pos, &liste);
				sommets--;
				break;
			case 3:
				Afficher(liste);			
		}	
	} while(choix != 0);
	
	return 0;
}