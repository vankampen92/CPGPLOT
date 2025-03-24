EXTRA_LIBRARY_PATH=-L/usr/lib/###########
# EXTRA_LIBRARY_PATH+=-L/usr/lib/plplot/
# EXTRA_LIBRARY_PATH+=-L/usr/lib/i386-linux-gnu/######
EXTRA_INCLUDE_PATH=-I/usr/include/plplot/########### 
# EXTRA_INCLUDE_PATH+=-I/usr/include/X11/########### 
######################################## Possibilities: GA (locally executed) / GA_EXTERN (non-locally executed)
LDFLAGS+=-lm ${EXTRA_LIBRARY_PATH}
CXXFLAGS+=${EXTRA_INCLUDE_PATH} -g #-Wall 
##############################################################################################################
# either -g or some optimization opiton, for instance, -O3 
# This makefile uses full power of conditional compilation. There is a bunch of variables that control this and
# are passed as flags -D[NAME_of_the_VARIABLE] to the compiler during compilation 
##############################################################################################################
PLPLOT_LIB=-L/usr/lib -lplplot -L/usr/lib -lX11 -L/usr/lib -lpng
##############################################################################################################
TYPE_of_MAIN=################# 
EXAMPLE=###########################
## D E F I N I T I O N   N A M E   E X E C U T B L E   C O D E ###############################################
EXE=PLOT${EXAMPLE}###############################
##############################################################################################################
OBJECTS = main${TYPE_of_MAIN}${EXAMPLE}.o plplot3D_xyz_bifu_curves.o
CC=gcc##

all: ${EXE}

${EXE}:  	$(OBJECTS)   
		$(CC) -o $@ $(OBJECTS) $(LDFLAGS) $(CXXFLAGS) $(PLPLOT_LIB) 

clean:  
	rm -f *.o *~ core
