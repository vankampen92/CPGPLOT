### $PWD
CPGPLOT = ${HOME}/CPGPLOT/##############
PROJECT_DIR=${CPGPLOT}CPGPLOT_EXAMPLES/EXAMPLE_03/# Path to working directory (also $PWD) 

# Adding definitions for the path where include files are searched for  
EXTRA_INCLUDE_PATH+=-I${PROJECT_DIR}####################
EXTRA_INCLUDE_PATH+=-I${CPGPLOT}library/
EXTRA_INCLUDE_PATH+=-I${CPGPLOT}library_basic_UTL/
EXTRA_INCLUDE_PATH+=-I${CPGPLOT} 

# Adding definitions for the path where libraries (lib*.a) are searched for  
EXTRA_LIBRARY_PATH+=-L${PROJECT_DIR}####################
EXTRA_LIBRARY_PATH+=-L${CPGPLOT}library_basic_UTL
EXTRA_LIBRARY_PATH+=-L${CPGPLOT}library

# Adding definitions for the path where the system looks for shared objects at running time
# :~$ echo $LD_LIBRARY_PATH
# :~$ LD_LIBRARY_PATH=${PWD}:${LD_LIBRARY_PATH}
# :~$ export LD_LIBRARY_PATH
# After generating the executable, check with 
# :~$ ldd program
# You can do this in a perennial way by editing the .bashrc file, and adding these two lines
# at the end of it:
# LD_LIBRARY_PATH=${PWD}:${LD_LIBRARY_PATH}
# export LD_LIBRARY_PATH

CPG=CPGPLOT_REPRESENTATION############## Possibilities: Note: No other options possible! 

OBJ = main.o argumentControl.o # Discrete_Sampling.o 
LIBRARY_OBJECTS = Discrete_Sampling.o
              
LDFLAGS+=-lm ${EXTRA_LIBRARY_PATH} -lDA_Discrete_Sampling -lda_cpgplot_XY_GRID_FILE -lda_cpgplot_BASIC
CXXFLAGS+=${EXTRA_INCLUDE_PATH} -D${CPG} -g 
PLPLOT_LIB=-L/usr/lib -lcpgplot -lpgplot -lX11 -lpng

CC  = gcc

CC=gcc -fPIC -DSHARED_OBJECT##

.SUFIXES:	.o .c

.c.o: 
	${CC} $(CXXFLAGS) -c $<

program:	${OBJ} library ##### shared_object
		gfortran $(CXXFLAGS) -o program $(OBJ) $(LDFLAGS) $(PLPLOT_LIB) 

library: ${LIBRARY_OBJECTS} Discrete_Sampling.h
	ar -q libDA_Discrete_Sampling.a ${LIBRARY_OBJECTS}

shared_object: ${LIBRARY_OBJECTS}
	gcc -shared -o libDA_Discrete_Sampling.so ${LIBRARY_OBJECTS}

clean:	
	rm *.o

cleanall: 
	rm *.o program libDA_Discrete_Sampling.a libDA_Discrete_Sampling.so
