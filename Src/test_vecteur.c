#include <stdio.h>
#include <stdlib.h>
#include "my.h"


/* verifie si aucune case remplie par couleur entre j1 et j2 */
int TestSiAucunLigne (tGrille *grille, int ligne, int j1, int j2, int couleur){
  int i;
  for(i=j1; i<=j2; i++)
    if(grille->matrice[ligne][i] == couleur)
      return FALSE;
  return TRUE;
}

int TestSiAucunColonne (tGrille *grille, int colonne, int j1, int j2, int couleur){
  int i;

  for(i=j1; i<=j2; i++)
    if(grille->matrice[i][colonne] == couleur)
      return FALSE;
  return TRUE;
}

int TestVecteurLigne(tGrille *grille,int ligne){
  /* init données necessaires */
  int **TT;
  int i, n, nb_seq;

  nb_seq = nb_seqLig(ligne,grille);
  TT = malloc(sizeof(int*) * nb_seq);
  for (i=0; i<nb_seq ; i++){
    TT[i] = malloc(sizeof(int) * grille->nb_Col);
    for (n=0; n<grille->nb_Col ; n++)
      TT[i][n] = NON_VISITE;
  }
  return (TestVecteurLigne_Rec(grille, ligne, grille->nb_Col, nb_seq, TT));
}

//vecteur V = ligne de la matrice
// taille : nb_col
//1er appel : l=nb sequences pour ligne, TT init a NON_VISITE de taille [nb_col][l], 
int TestVecteurLigne_Rec (tGrille *grille, int ligne, int j, int l, int ** TT){
  int c1, c2;

  if(l == 0)
    return TestSiAucunLigne(grille, ligne,0,j,NOIR);
  if(l==1 && j==grille->seqLig[ligne][l] - 1)
    return TestSiAucunLigne(grille, ligne, 0, j, BLANC);
  if(j <= grille->seqLig[ligne][l]-1)
    return FALSE;
  if(TT[j][l] != NON_VISITE)
    return TT[j][l];

  if(grille->matrice[ligne][j] == NOIR)
    c1 = FALSE;
  else
    c1 = TestVecteurLigne_Rec(grille, ligne, j-1, l, TT);

  if(!TestSiAucunLigne(grille, ligne, j - grille->seqLig[ligne][l] - 1, j, BLANC))
    c2 = FALSE;
  else{
    if(grille->matrice[ligne][j-grille->seqLig[ligne][l]] == NOIR)
      c2 = FALSE;
    else
      c2 = TestVecteurLigne_Rec(grille, ligne, j - grille->seqLig[ligne][l]-1, l-1, TT); 
  }

  TT[j][l] = c1|c2;
  return TT[j][l];
  
}

/* int TestVecteurColonne_Rec(){ */
/* } */
