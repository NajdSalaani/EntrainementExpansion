/*	
	Ce fichier a pour but la compréhension et l'entrainement à l'expansion (labyrinthe) dans un environnement de développement propre. Les fonctions , types et structures sont relatives à ce fichier et permettent de reprendre les éléments et conditions du project labyrinthe.
	
	Pour compiler rapidement on pourra utiliser:
	alias lab='gcc Entrainement.c -o Bot.out'
	alias play='./Bot.out'
	alias LP=' lab &&  play '
*/


//Librairies et .h 
#include <stdio.h>
#include <stdlib.h>

//Creation des types et structures

//Pour une tuile

typedef struct {
int tileN, tileE, tileS, tileW; //1 si mur et 0 si rien
int tileItem; // numero item ou 0 si aucun 

} t_tile;

//Pour le labyrinthe 

typedef struct {
t_tile* p_lab; //Pointeur vers la première tuile du labyrinthe
int playerX,playerY; //coordonnées du joueur (nous/notre bot)
int Next; // numéro du prochain trésor du joueur
} t_lab;


/* Fonction de création du Labyrinthe 
	Cette fonction créer et initialise un labyrinthe 4*4 
	Elle renvoie l'adresse de la première tuile du labyrinthe 
*/
	void RemplissageLab(t_tile * PremiereTuile){
	
		PremiereTuile = malloc(16*sizeof(t_tile));
	
	}
	
	
//Main 

int main(){
	return 1;
}
