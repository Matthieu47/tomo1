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
  grille = init_grille(av[1]);
  if (grille == NULL)
    return my_err("Grille init failed");

  int ret =  enumeration(grille, 0, BLANC);
  int ret2 = enumeration(grille, 0, NOIR);
  
  showGrille(grille);
    
  /* if(ret == FALSE && ret2 == FALSE) */
  /*   return my_err("Pas pu colorier =("); */
  return 0;
}

