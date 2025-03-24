################################################# 
PROJECT_DIR=${HOME}/CPGPLOT_EXAMPLES/
LIBRARY_DIR=${PROJECT_DIR}Library/
INCLUDE_DIR=${PROJECT_DIR}Include/
WKD=${PROJECT_DIR}
CPGPLOT = ${HOME}/CPGPLOT/
EXTRA_LIBRARY_PATH=-L/usr/local/pgplot
EXTRA_LIBRARY_PATH+=-L${CPGPLOT}library_basic_UTL
EXTRA_LIBRARY_PATH+=-L${CPGPLOT}library
EXTRA_LIBRARY_PATH+=-L/usr/lib
EXTRA_LIBRARY_PATH+=-L/usr/local/lib
EXTRA_LIBRARY_PATH+=-L${LIBRARY_DIR}
EXTRA_INCLUDE_PATH=-I/usr/local/pgplot/
EXTRA_INCLUDE_PATH+=-I/usr/include/plplot/
EXTRA_INCLUDE_PATH+=-I${INCLUDE_DIR}
EXTRA_INCLUDE_PATH+=-I${PROJECT_DIR}
EXTRA_INCLUDE_PATH+=-I${LIBRARY_DIR}
EXTRA_INCLUDE_PATH+=-I${WKD}
EXTRA_INCLUDE_PATH+=-I${CPGPLOT}library/
EXTRA_INCLUDE_PATH+=-I${CPGPLOT}library_basic_UTL/
EXTRA_INCLUDE_PATH+=-I${CPGPLOT} 
#################################################
CPG=CPGPLOT_REPRESENTATION############## Possibilities: Note: No other options possible! 
#################################################
LDFLAGS+=${EXTRA_LIBRARY_PATH}  -lm -lgsl -lgslcblas -lda_cpgplot_XY_GRID_FILE -lda_cpgplot_BASIC
CXXFLAGS+=${EXTRA_INCLUDE_PATH} -g -D${CPG} #-Wall 
######## either -g or some optimization opiton, for instance, -O3 
###################################################################
# PLPLOT_LIB=-L/usr/lib -lplplot -lcpgplot -lpgplot -lX11 -lpng 
PLPLOT_LIB=-L/usr/lib -lcpgplot -lpgplot -lX11 -lpng 
###################################################################
TYPE_of_MAIN=
## D E F I N I T I O N   N A M E   E X E C U T B L E   C O D E ####
EXE=PLOT${TYPE_of_MAIN}###################
###################################################################
OBJECTS = main${TYPE_of_MAIN}.o  argumentControl.o 

CC=gcc -fPIC -DSHARED_OBJECT##

.SUFIXES:	.o .c

.c.o: 
	${CC} $(CXXFLAGS) -c $<

${EXE}:  	$(OBJECTS)   
		gfortran $(CXXFLAGS) -o ${EXE} $(OBJECTS) $(LDFLAGS) $(PLPLOT_LIB) 

###################################################################
clean:  
	rm -f *.o *~ core
