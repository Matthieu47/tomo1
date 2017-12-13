#!/bin/bash

make re

echo "Demonstration MATTHIEU EYRAUD, BRUNO LAURANNE"
for fic in $(ls -Sr instances/mat/*)
do
    clear
    echo $fic
    ./Tomo $fic

done

# gen file for graphique
# echo "" > Output/in.txt
# for fic in $(ls  instances/mat/*)
# 	   # for fic in $(ls -Sr instances/vec*)
# do
#     # echo $fic
#     # echo $fic >> Output/in.txt
#     ./Tomo $fic >> Output/in.txt
# done


# fichiers vecteur-> enumeration, testVecteurLigne/Col -> temps d'exec
# echo "" > Output/vecteur_enum.txt
# for fic in $(ls -Sr instances/vec*)
# do
#     echo $fic >> Output/vecteur_enum.txt
#     ./Tomo $fic 2>> Output/vecteur_enum.txt
# done


# fichiers matrice -> propagation -> temps exec + pourcentage coloration
# echo "" > Output/propagation.txt
# for fic in $(ls -Sr instances)
# do
#     echo $fic >> Output/propagation.txt
#     ./Tomo instances/$fic 2>> Output/propagation.txt
# done

# fichier matrice -> propagation puis enumeration -> temps d'exec + commentaire
# echo "" > Output/full_test.txt
# for fic in $(ls -Sr instances)
# do
#     echo $fic >> Output/full_test.txt
#     ./Tomo instances/$fic 2>> Output/full_test.txt
# done
