#!/bin/bash

make re
echo "" > enumeration.txt
for fic in instances/vec*
do
    # echo $fic >> test_vecteur.txt
    # ./Tomo $fic 2>> test_vecteur.txt

    echo $fic
    ./Tomo $fic
done


