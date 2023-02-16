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
t_tile p_lab[16]; //tableau de tuiles
int playerX,playerY; //coordonnées du joueur (nous/notre bot)
int Next; // numéro du prochain trésor du joueur
} t_lab;

//Fonctions de verification d'un passage

//Passage Droit Si la fonction renvoie 1 le passage droit existe sinon 0
int PassageDroit(int i , t_tile p_lab[16]){
	if( p_lab[i].tileE == 0 && p_lab[i+1].tileW == 0){
	return 1;
	}
	return 0;

}

//Passage Gauche Si la fonction renvoie 1 le passage gauche existe sinon 0
int PassageGauche(int i , t_tile p_lab[16]){
	if( p_lab[i].tileW == 0 && p_lab[i-1].tileE == 0){
	return 1;
	}
	return 0;

}

//Passage Haut Si la fonction renvoie 1 le passage Haut existe sinon 0
int PassageHaut(int i , t_tile p_lab[16]){
	if( p_lab[i].tileN == 0 && p_lab[i-4].tileS == 0){
	return 1;
	}
	return 0;

}

//Passage Bas Si la fonction renvoie 1 le passage Bas existe sinon 0
int PassageBas(int i , t_tile p_lab[16]){
	if( p_lab[i].tileS == 0 && p_lab[i+4].tileN == 0){
	return 1;
	}
	return 0;

}

//Fonction d'expansion qui retourne 1 si un chemin es trouvée et 0 sinon		
int Expansion(t_tile p_lab[16],int X,int Y,int Nbtresor){

//On réorganise d'abord le labyrinthe

//Position du joueur
p_lab[Y*4+X].tileItem = 1;

//tresor
for(int i = 0; i<16;i++){
	if(p_lab[i].tileItem == Nbtresor){ p_lab[i].tileItem = -1 ; }
	printf("%d ",p_lab[i].tileItem);	
}
}		
	

int main(){

	//Creation et initialisation du labyrinthe ( ce peut être une copie du labyrinthe pour ne pas le perdre lors de l'expansion)
	t_lab Labyrinthe;
	//coordonnées joueur
	Labyrinthe.playerX = 0;
	Labyrinthe.playerY = 0;
	// Numéro trésor
	Labyrinthe.Next = 3;
	// initialisation des tiles D'abord tout à zéro puis placement trésor etc
		for(int i = 0; i<16 ; i++){
			Labyrinthe.p_lab[i].tileItem = 0;
			Labyrinthe.p_lab[i].tileN = 0;
			Labyrinthe.p_lab[i].tileS = 0;
			Labyrinthe.p_lab[i].tileW = 0;
			Labyrinthe.p_lab[i].tileE = 0;
		}
		Labyrinthe.p_lab[11].tileItem = 3;
		
		//initialisation des bords du plateaux
		for(int i = 0; i<4 ; i++){
			Labyrinthe.p_lab[i].tileN = 1; //Haut
		}
		for(int i = 12; i<16 ; i++){
			Labyrinthe.p_lab[i].tileS = 1; //Bas
		}
		for(int i = 3; i<16 ; i++){
			Labyrinthe.p_lab[i].tileE = 1; //Droit
			i = i+3;
		}
		for(int i = 0; i<14 ; i++){
			Labyrinthe.p_lab[i].tileW = 1; //Gauche
			i = i+3;
		}
		
		//initialisation du reste
		//Bas
		Labyrinthe.p_lab[0].tileS = 1;
		Labyrinthe.p_lab[1].tileS = 1;
		Labyrinthe.p_lab[4].tileS = 1;
		Labyrinthe.p_lab[7].tileS = 1;
		Labyrinthe.p_lab[9].tileS = 1;
		Labyrinthe.p_lab[10].tileS = 1;
		//Haut
		Labyrinthe.p_lab[4].tileN = 1;
		Labyrinthe.p_lab[8].tileN = 1;
		Labyrinthe.p_lab[9].tileN = 1;
		Labyrinthe.p_lab[11].tileN = 1;
		Labyrinthe.p_lab[12].tileN = 1;
		Labyrinthe.p_lab[15].tileN = 1;
		//Droite
		Labyrinthe.p_lab[2].tileE = 1;
		Labyrinthe.p_lab[5].tileE = 1;
		Labyrinthe.p_lab[6].tileE = 1;
		Labyrinthe.p_lab[9].tileE = 1;
		//Gauche
		Labyrinthe.p_lab[3].tileW = 1;
		Labyrinthe.p_lab[5].tileW = 1;
		Labyrinthe.p_lab[6].tileW = 1;
		Labyrinthe.p_lab[9].tileW = 1;
		Labyrinthe.p_lab[13].tileW = 1;
	
//APPEL DE LA FONCTION EXPANSION 

		

	int a =Expansion(Labyrinthe.p_lab,Labyrinthe.playerX,Labyrinthe.playerY,Labyrinthe.Next);

	//Fin
	printf("ok \n");
	return 1;
}
