#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 5


typedef struct {
	int elements[TAILLE_MAX];  // Taille maximale de notre pile
	int sommet;
	
}Pile;

//initialisation de la pile
void initialiserPile(Pile *p) {
	p->sommet = -1;
}


//verifier si la pile est vide
int estVide(Pile *p) {
	return (p->sommet == -1);
}


//verifier si la pile est pleine
int estPleine(Pile *p) {
		return (p->sommet == TAILLE_MAX - 1 );
}



//empiler les elements de la pile
void empiler(Pile *p, int valeur) {
	if (estPleine(p)) {
		printf("la pile est pleine! Impossible d'ajouter %d\n", valeur);
	}else{
		p->sommet++;
		p->elements[p->sommet] = valeur;
		printf("%d a ete empile. \n", valeur);
	}
}


//depiler les elements de la pile
int depiler(Pile *p) {
	int valeur;
	if (estVide(p)) {
		printf("la pile est vide, rien a depiler \n");
		return -1;
	}else{
		valeur = p->elements[p->sommet];
		p->sommet--;
		printf("%d a ete depilé. \n", valeur);
		return valeur;
	}
}

//afficher les elements de la pile
void afficherPile(Pile *p) {
	if (estVide(p)){
		printf("La pile est vide. \n");
	}else{
		printf("Le contenu de la pile: ");
		for (int i = 0; i <= p->sommet; i++ ) {
			printf("%d ", p->elements[i]);
		}
		printf(" \n");
	}
}

// la fonction principale
int main() {
	Pile p;
	initialiserPile(&p);
	
	
	int choix, valeur;
	do{
		printf("\n====== MENU PILE ======\n");
		printf("1 -Empiler\n");
		printf("2 -Depiler\n");
		printf("3 -Afficher\n");
		printf("0 -Quitter\n");
		printf("Faites votre choix\n");
		scanf("%d", &choix);
		
		switch (choix) {
			case 1:
				printf("entrez une valeur a empiller :");
				scanf("%d", &valeur);
				empiler(&p, valeur); 
				system("cls");
				break;
				
			case 2:
				depiler(&p);
				break;
				
			case 3:
				afficherPile(&p);
				break;
				
			case 0:
				printf("Fin du programme.\n");
				break;
			default:
				printf("choix invalide !\n");
		}
	} while (choix != 0);
	
	return 0;
}
