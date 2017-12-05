#include <stdio.h>
#include <time.h> 
#include "my.h"

long int demarrer_chrono() {
  return clock();
}

void stop_chrono(long int top_chrono) {
  long int arret_chrono = clock();
  fprintf(stderr, "Le calcul a pris %f secondes.\n",
	  (float)(arret_chrono - top_chrono) / CLOCKS_PER_SEC);
}
 
static int my_err(char *msg){
    printf("%s\n", msg);
    return 1;
}

int main(int ac, char **av){
    tGrille *grille;
    int ligne, col;
    long int top_chrono;
    
    if (ac<2)
	return my_err("Usage : ./Tomo file");
    grille = init_grille(av[1]);
    if (grille == NULL)
	return my_err("Grille init failed");

    /* grille->matrice[0][1] = 2; */
    /* grille->matrice[0][2] = 1; */
    /* grille->matrice[2][2] = 2; */
    /* grille->matrice[3][0] = 2;     */
    //    printf("%d\n", TestVecteurLigne(grille, 0));
    //    printf("%d\n", TestVecteurCol(grille, 0));    
    
    //test avant remplissage   

    /* top_chrono = demarrer_chrono(); */
    /* for (ligne = 0 ; ligne < grille->nb_Lig ; ligne++){ */
    /* 	if (!TestVecteurLigne(grille, ligne) == TRUE) */
    /* 	  return my_err("Coloriage impossible ligne\n"); */
    /* } */
    /* for (col = 0 ; col < grille->nb_Col ; col++){ */
    /* 	if (!TestVecteurCol(grille, col) == TRUE) */
    /* 	  return my_err("Coloriage impossible colonne\n"); */
    /* } */
    /* stop_chrono(top_chrono); */
    
    /* printf("\n\n\t\tAVANT PROPAGATION\n"); */
    /* showGrille(grille); */
    /* propagation(grille); */
    /* printf("\n\n\t\tAPRES PROPAGATION\n"); */
    /* showGrille(grille); */
    
    top_chrono = demarrer_chrono();
    int ret =  enumeration(grille, 0, BLANC);
    int ret2 = enumeration(grille, 0, NOIR);
    stop_chrono(top_chrono);
    
    /* printf("\n\n\t\tAPRES ENUMERATION\n"); */
    /* showGrille(grille); */

    /* if(ret == FALSE && ret2 == FALSE) */
    /*   return my_err("Pas pu colorier =("); */
    return 0;
}

