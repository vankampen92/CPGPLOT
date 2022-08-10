# Script to transform a pgplot.ps of serveral pages into a pdf with the same number of pages
# procress_pgplotps2pdf.sh [INPUT FILE NAME]  [OUTPUT FILE NAME]
gs -q -dSAFER -dNOPAUSE -dBATCH -sOutputFile=$2.pdf -sDEVICE=pdfwrite -c .setpdfwrite "-c <</Orientation 3>> setpagedevice" -f $1.ps
