#include <stdio.h>

#include "my.h"

static int my_err(char *msg){
    printf("%s\n", msg);
    return 1;
}

int main(int ac, char **av){
    tGrille *grille;
    int ligne, col;
    
    if (ac<2)
	return my_err("Usage : ./Tomo file");
    grille = init_grille(av[1]);
    if (grille == NULL)
	return my_err("Grille init failed");

    grille->matrice[0][1] = 2;
    grille->matrice[0][2] = 1;
    grille->matrice[2][2] = 2;
    grille->matrice[3][0] = 2;    
    //    printf("%d\n", TestVecteurLigne(grille, 0));
    //    printf("%d\n", TestVecteurCol(grille, 0));    
    
    //test avant remplissage
    
    
    for (ligne = 0 ; ligne < grille->nb_Lig ; ligne++){
	if (TestVecteurLigne(grille, ligne) == TRUE)
	    printf("Possible ligne %d\n", ligne);
	else
	    printf("Impossible\n");
    }

    
    for (col = 0 ; col < grille->nb_Col ; col++){
	if (TestVecteurCol(grille, col) == TRUE)
	    printf("Possible col %d\n", col);
	else
	    printf("Impossible\n");
    }
    
    // int ret =  enumeration(grille, 0, BLANC);
    //int ret2 = enumeration(grille, 0, NOIR);
  
    showGrille(grille);

    /* if(ret == FALSE && ret2 == FALSE) */
    /*   return my_err("Pas pu colorier =("); */
    return 0;
}

