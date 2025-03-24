#!/bin/bash

# This script transform into a pdf the ps output file (pgplot.ps) from pgplot (-G29 /CPS). 
# For instance, 
# :~$ ./PLOT_Exemple_2 -G0 1 -G1 1 -G2 1 -G3 0 -G4 8.5 -G5 1 -G6 0.0 -G7 5.0 -G10 1 -G11 4 -G12 8 -G29 /CPS

# Usage:
# Example 1:
# :~$ bash ps-to-pdf-pgplot.sh [Name_of_File.pdf] 

rm output.ps
rm output.eps
rm output.pdf
ps2ps pgplot.ps output.ps
ps2eps output.ps
epstopdf output.eps
mv output.pdf $1
