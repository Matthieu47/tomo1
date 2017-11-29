#include "my.h"
#include <stdio.h>


/* int TestSiAucunLigne (tGrille *grille, int ligne, int j1, int j1, int couleur){ */
/*   int i; */
/*   for(i=j1; i<=j2; i++){ */
/*     if(grille->matrice[ligne][i] == couleur){ */
/*       return FALSE; */
/*     } */
/*   } */
/*   return TRUE; */
/* } */

/* int TestSiAucunColonne (tGrille *grille, int colone, int j1, int j1, int couleur){ */
/*   int i; */
/*   for(i=j1; i<=j2; i++){ */
/*     if(grille->matrice[i][colonne] == couleur){ */
/*       return FALSE; */
/*     } */
/*   } */
/*   return TRUE; */

/* int TestVecteurLigne_Rec (tGrille *grille, int ligne, int j, int lSeq, int **TT){ */
/*   int c1, c2; */
/*   if(l == 0) */
/*     return TestSiAucun(); */
/*   if(l==1 && j==grille->seqLig[ligne][l] - 1){ */
/*     return TestSiAucunLigne(grille, ligne, 0, j, BLANC); */
/*   } */
/*   if(j<=seqLig[ligne][l]-1){ */
/*     return FALSE; */
/*   } */

/*   //Ajouter aux enums NON_VISITE */
/*   if(TT[j][l] != NON_VISITE){ */
/*     return TT[j][l]; */
/*   } */

/*   if(grille->matrice[ligne][j] == NOIR){ */
/*     c1 = FALSE; */
/*   } */
/*   else{ */
/*     c1 = TestVecteurLigne_Rec(grille, ligne, j-1, l, TT); */
/*   } */

/*   if(!TestSiAucun(grille, ligne, j - grille->seqLig[ligne][l] - 1, j, BLANC)){ */
/*     c2 = FALSE; */
/*   } */
/*   else{ */
/*     if(grille->matrice[ligne][j-grille->seqLig[ligne][l]] == NOIR){ */
/*       c2 = FALSE; */
/*     } */
/*     else{ */
/*       c2 = TestVecteurLigne_Rec(grille, ligne, j - grille->seqLig[ligne][l]-1, l-1, TT); */
/*     } */
/*   } */

/*   TT[j][l] = c1|c2; */
/*   return TT[j][l]; */
  
/* } */

/* int TestVecteurColonne_Rec(){ */
/* } */
