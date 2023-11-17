/* Lina Djihane AZIZA 10/2023 */

#ifndef LISTE_H
#define LISTE_H

typedef struct point {
	int x, y;
} Point;

typedef struct cellule {
	Point pt;
	struct cellule *suiv, *prec;
} Cellule;

Cellule* NouvCel(Point p);
void InsererCellule(int pl, Cellule *cel, Cellule *liste);
void SupprimeCellule(int pl, Cellule **liste);
void Afficher(Cellule *liste);

#endif /* LISTE_H */


