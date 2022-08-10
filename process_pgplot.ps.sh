ps2ps pgplot.ps $1.ps
ps2eps $1.ps
epstopdf $1.eps
evince $1.pdf
