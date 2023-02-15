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
	void InitialisationLab(t_tile * PremiereTuile){
	
		PremiereTuile = malloc(16*sizeof(t_tile));
		
		// initialisation des tiles items D'abord tout à zéro puis placement trésor
		for(int i = 0; i<16 ; i++){
			PremiereTuile[i].tileItem = 0;
		}
		PremiereTuile[11].tileItem = 3;
		
		//initialisation des bords du plateaux
		for(int i = 0; i<4 ; i++){
			PremiereTuile[i].tileN = 1; //Haut
		}
		//initialisation des bords du plateaux
		for(int i = 13; i<16 ; i++){
			PremiereTuile[i].tileS = 1; //Bas
		}
		for(int i = 3; i<16 ; i+4){
			PremiereTuile[i].tileW = 1; //Droit
		}
		for(int i = 0; i<14 ; i+4){
			PremiereTuile[i].tileE = 1; //Gauche
		}
	}
	
	
//Main 

int main(){
	printf("ok \n");
	return 1;
}
