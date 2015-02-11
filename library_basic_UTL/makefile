# =======================
# CPGPLOT BASIC LIBRARY make 
# =======================

# Gnu C make libda_cpgplot_BASIC.a 
CPGPLOT            = ${HOME}/CPGPLOT/
EXTRA_INCLUDE_PATH = -I${CPGPLOT} -I/usr/local/pgplot

CFLAGS=-g -Wall -DHAVE_INLINE ${EXTRA_INCLUDE_PATH} -DCPGPLOT_REPRESENTATION 
###CFLAGS= -Wall -O21

COMPILER=gcc

OBJECTS_BASIC=A_X_E_S___R_A_N_G_E_S.o cpg_XY_plot.o cpg_XY_plot_logaxis.o cpg_XY_histogram.o cpg_XY_arrow.o cpg_XY_plot_error_bar.o cpg_XY_scattered.o cpg_XY_same_plot.o cpg_XY_same_arrow.o cpg_XY_same_scattered.o cpg_XY_same_scattered_pt_per_pt.o cpg_XYn_plot.o  cpg_XY_same_circle.o cpg_XY_same_rectangle.o  cpg_XY_shade_between_curves.o cpg_random_number.o cpg_plot_random_points.o

OBJECTS_BASIC_TO_LINK=A_X_E_S___R_A_N_G_E_S.o cpg_XY_plot.o cpg_XY_plot_logaxis.o cpg_XY_histogram.o  cpg_XY_arrow.o cpg_XY_plot_error_bar.o cpg_XY_scattered.o cpg_XY_same_plot.o cpg_XY_same_arrow.o cpg_XY_same_scattered.o cpg_XY_same_scattered_pt_per_pt.o cpg_XYn_plot.o cpg_XY_same_circle.o cpg_XY_same_rectangle.o cpg_XY_shade_between_curves.o cpg_random_number.o cpg_plot_random_points.o
.SUFIXES:       .o .c

.c.o: 
	${COMPILER} $(CFLAGS) -c $<

cpgplot_BASIC:${OBJECTS_BASIC} ${CPGPLOT}CPGPLOT_HEADER.h
	ar -q libda_cpgplot_BASIC.a ${OBJECTS_BASIC_TO_LINK}

clean:  
	rm -f *.o  *~


