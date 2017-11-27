#include <stdio.h>

#include "my.h"

static int my_err(char *msg){
    printf("%s\n", msg);
    return 1;
}

int main(int ac, char **av){
    tGrille *grille;

    if (ac<2)
	return my_err("Usage : ./Tomo file");
    if ((grille = init_grille(av[1])) == NULL)
	return my_err("Grille init failed");
    /* call de enumeration a refaire (?) */
    /* if (enumeration(grille, grille->nb_Col*grille->nb_Lig, BLANC) == FALSE) */
    /* 	return my_err("Pas pu colorier =("); */
    return 0;
}

