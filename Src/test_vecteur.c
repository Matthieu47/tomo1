#include <stdio.h>
#include <stdlib.h>
#include "my.h"


/* verifie si aucune case remplie par couleur entre j1 et j2 */
int TestSiAucunLigne (tGrille *grille, int ligne, int j1, int j2, int couleur){
  int i;
  for(i=j1; i<=j2; i++){
    if(grille->matrice[ligne][i] == couleur)
      return FALSE;
  }
  return TRUE;
}

int TestSiAucunColonne (tGrille *grille, int colonne, int j1, int j2, int couleur){
  int i;
  //  printf("j1 : %d, j2: %d\n", j1, j2);
  for(i=j1; i<=j2; i++)
    //printf("i = %d\n", i);
    if(grille->matrice[i][colonne] == couleur)
      return FALSE;
  return TRUE;
}



//vecteur V = ligne de la matrice
// taille : nb_col
//1er appel : l=nb sequences pour ligne, TT init a NON_VISITE de taille [nb_col][l], 
int TestVecteurLigne_Rec(tGrille *grille, int ligne, int j, int l, int ** TT){
  int c1, c2;

  //   printf("call ligne %d : j %d l %d\n", ligne, j, l); 
  if (l == 0)
    return TestSiAucunLigne(grille, ligne,0,j,NOIR);
  /* printf("la\n"); */
  if(l==1 && j==grille->seqLig[ligne][l-1] - 1){
    /* printf("oups\n");  */
    return TestSiAucunLigne(grille, ligne, 0, j, BLANC);

  }
  if(j <= grille->seqLig[ligne][l-1]-1)
    return FALSE;
  /* printf("wow %d %d\n", j, l); */
  if(TT[j][l-1] != NON_VISITE)
    return TT[j][l-1];
  /* printf("ici\n"); */

  if(grille->matrice[ligne][j] == NOIR)
    c1 = FALSE;
  else{
    c1 = TestVecteurLigne_Rec(grille, ligne, j-1, l, TT);
  }
  if(!TestSiAucunLigne(grille, ligne, j - grille->seqLig[ligne][l-1] + 1, j, BLANC))
    c2 = FALSE;
  else{
    if(grille->matrice[ligne][j-grille->seqLig[ligne][l-1]] == NOIR)
      c2 = FALSE;
    else
      c2 = TestVecteurLigne_Rec(grille, ligne, j - grille->seqLig[ligne][l-1]-1, l-1, TT); 
  }

  TT[j][l-1] = c1|c2;
  
  return TT[j][l-1];
  
}

int TestVecteurLigne(tGrille *grille, int ligne){
    /* init données necessaires */
    int **TT;
    int i, n, nb_seq,res;

    nb_seq = nb_seqLig(ligne,grille);
    if (nb_seq == 0)
	return TRUE;
    /* TT = malloc(sizeof(int*) * nb_seq); */
    /* printf("TT : %d %d  \n", nb_seq, grille->nb_Col); */
    /* for (i=0; i<nb_seq ; i++){ */
    /* 	TT[i] = malloc(sizeof(int) * grille->nb_Col); */
    /* 	for (n=0; n<grille->nb_Col ; n++){ */
    /* 	    TT[i][n] = NON_VISITE; */
    /* 	} */
    /* } */
    TT = malloc(sizeof(int*) * grille->nb_Col);
    /* printf("TT : %d %d  \n", nb_seq, grille->nb_Col); */
    for (i=0; i<grille->nb_Col ; i++){
	TT[i] = malloc(sizeof(int) * nb_seq);
	for (n=0; n<nb_seq ; n++){
	    TT[i][n] = NON_VISITE;
	}
    }
    //nb_seq au lieu de nb_seq-1 et il faut donc decaler tous les indices dans TestVecteurLigne_Rec 
    res = TestVecteurLigne_Rec(grille, ligne, grille->nb_Col -1, nb_seq, TT);
    
    return res;
}


//vecteur V = ligne de la matrice
// taille : nb_col
//1er appel : l=nb sequences pour ligne, TT init a NON_VISITE de taille [nb_col][l], 
int TestVecteurCol_Rec(tGrille *grille, int col, int j, int l, int ** TT){
  int c1, c2;

  //printf("call colonne %d : j %d l %d\n", col, j, l); 
  if(l == 0){
    //    printf("la\n");
    return TestSiAucunColonne(grille, col,0,j,NOIR);
  }
  if(l==1 && j==grille->seqCol[col][l-1] - 1){
    //    printf("oups\n"); 
    return TestSiAucunColonne(grille, col, 0, j, BLANC);
  }
  if(j <= grille->seqCol[col][l-1]-1){
    //    printf("wow %d %d\n", j, l); 
    return FALSE;
  }
  if(TT[j][l-1] != NON_VISITE){
    //    printf("ici\n"); 
    return TT[j][l-1];
  }

  //  printf("aa\n");
  if(grille->matrice[j][col] == NOIR)
    c1 = FALSE;
  else{
    c1 = TestVecteurCol_Rec(grille, col, j-1, l, TT);
  }
  if(!TestSiAucunColonne(grille, col, j - grille->seqCol[col][l-1] + 1, j, BLANC))
    c2 = FALSE;
  else{
    if(grille->matrice[j-grille->seqCol[col][l-1]][col] == NOIR)
      c2 = FALSE;
    else
      c2 = TestVecteurCol_Rec(grille, col, j - grille->seqCol[col][l-1]-1, l-1, TT); 
  }

  TT[j][l-1] = c1|c2;
  
  return TT[j][l-1];
  
}

int TestVecteurCol(tGrille *grille, int col){
    /* init données necessaires */
    int **TT;
    int i, n, nb_seq,res;

    nb_seq = nb_seqCol(col,grille);
    if (nb_seq == 0)
	return TRUE;
    /* TT = malloc(sizeof(int*) * nb_seq); */
    /* printf("TT : %d %d  \n", nb_seq, grille->nb_Col); */
    /* for (i=0; i<nb_seq ; i++){ */
    /* 	TT[i] = malloc(sizeof(int) * grille->nb_Col); */
    /* 	for (n=0; n<grille->nb_Col ; n++){ */
    /* 	    TT[i][n] = NON_VISITE; */
    /* 	} */
    /* } */
    TT = malloc(sizeof(int*) * grille->nb_Lig);
    /* printf("TT : %d %d  \n", nb_seq, grille->nb_Col); */
    for (i=0; i<grille->nb_Lig ; i++){
	TT[i] = malloc(sizeof(int) * nb_seq);
	for (n=0; n<nb_seq ; n++){
	    TT[i][n] = NON_VISITE;
	}
    }
    //nb_seq au lieu de nb_seq-1 et il faut donc decaler tous les indices dans TestVecteurCol_Rec 
    res = TestVecteurCol_Rec(grille, col, grille->nb_Lig -1, nb_seq, TT);
    
    return res;
}
