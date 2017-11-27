#include "my.h"

/* A TESTER INTEGRALEMENT -> segfault */

// A TESTER
// Verifie si coloriage verifie la sequence de la ligne
int compare_seq_ligne(tGrille *grille, int ligne){
    int i, current_seq, decal;

    //si pas de sequence -> coloriage libre -> toujours bon
    if (grille->seqLig[ligne][0] == -1)
	return TRUE;    
    current_seq = 0;
    i = 0;
    //pour chaque case de la ligne
    while (i< grille->nb_Col){
	if (grille->matrice[ligne][i] == NOIR){
	    decal=0;
            //parcours toute le bon nombre de cases pour la sequence
	    while (i < grille->nb_Col && decal< grille->seqLig[ligne][current_seq]){
		//si une case est mal coloree
		if (grille->matrice[ligne][i] != NOIR)
		    return FALSE;
		i++;
		decal++;
	    }
	    //si la case apres sequence est noire -> pas bon
	    if (grille->matrice[ligne][i] == NOIR)
		return FALSE;
	    current_seq++;
	} else
	    i++;
    }
    //a la fin du parcours, toutes les sequences ont été respectées
    if (grille->seqLig[ligne][current_seq] == -1)
	return TRUE;
    return FALSE;
}

// A TESTER
// Verifie si coloriage verifie la sequence de la ligne
int compare_seq_col(tGrille *grille, int col){
    int i, current_seq, decal;

    //si pas de sequence -> coloriage libre -> toujours bon
    if (grille->seqCol[col][0] == -1)
	return TRUE;    
    current_seq = 0;
    i = 0;
    //pour chaque case de la colonne
    while (i< grille->nb_Lig){
	if (grille->matrice[i][col] == NOIR){
	    decal=0;
            //parcours toute le bon nombre de cases pour la sequence
	    while (i < grille->nb_Lig && decal< grille->seqCol[col][current_seq]){
		//si une case est mal coloree
		if (grille->matrice[i][col] != NOIR)
		    return FALSE;
		i++;
		decal++;
	    }
	    //si la case apres sequence est noire -> pas bon
	    if (grille->matrice[i][col] == NOIR)
		return FALSE;
	    current_seq++;
	} else
	    i++;
    }
    //a la fin du parcours, toutes les sequences ont été respectées
    if (grille->seqCol[col][current_seq] == -1)
	return TRUE;
    return FALSE;
}

// code vu a la BU
int enumeration(tGrille *grille, int k_case, int c_color){
    int ok, raz, i, j;

    i=k_case/grille->nb_Col;
    j=k_case%grille->nb_Col;
    if (grille->matrice[i][j] == LIBRE){
	grille->matrice[i][j] = c_color;
	raz = TRUE;
    } else
	if (grille->matrice[i][j] != c_color)
	    return FALSE;
	else
	    raz = FALSE;
    ok = TRUE;
    if (i == grille->nb_Lig-1)
	ok=compare_seq_col(grille,j);
    if (ok == TRUE && j == grille->nb_Col-1)
	ok=compare_seq_ligne(grille,i);
    if (ok == TRUE){
	if (i == grille->nb_Lig-1 && j == grille->nb_Col-1)
	    return TRUE;
	// code douteux
	ok = enumeration(grille, k_case+1, BLANC) | enumeration(grille, k_case+1, NOIR);
    }
    if (ok == FALSE && raz ==TRUE)
	grille->matrice[i][j] = LIBRE;
    return ok; 
}
