#! /bin/bash

# rm -f "Outputpourcentage.png"
gnuplot <<EOF
set term png
set output "pourcentage.png"
unset key
set title "pourcentage"
set xlabel "taille instance" 
set ylabel "pourcentage"
plot "$1" using 1:2
EOF


gnuplot <<EOF
set term png
set output "temps_exec.png"
unset key
set title "temps exec"
set xlabel "taille instance" 
set ylabel "temps exec"
plot "$1" using 1:3
EOF
