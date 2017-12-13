#! /bin/bash

# rm -f "Outputpourcentage.png"
gnuplot <<EOF
set term png
set output "pourcentage.png"
unset key
set title "Pourcentage de remplissage en fonction de la taille de l'instance"
set xlabel "taille instance" 
set ylabel "pourcentage"
plot "$1" using 1:2 with points pointsize 2 linecolor rgb "blue"
EOF


gnuplot <<EOF
set term png
set output "temps_exec.png"
unset key
set title "Temps d'execution de propagation en fonction de la taille de l'instance"
set xlabel "taille instance" 
set ylabel "temps exec"
plot "$1" using 1:3 with linespoints linewidth 2 linecolor rgb "blue"
EOF
