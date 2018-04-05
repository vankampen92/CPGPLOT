# Wellcome to CPGPLOT Graphix Library #

This project runs on linux machines out of the box. To run in other platforms makefiles should be modified accordingly.

## CPGPLOT Graphix Library.
This is a set of functions written in C relying on cpgplot primitives from pgplot, and plplot. The follwing dependencies are required:

### [pgplot](/http://www.astro.caltech.edu/~tjp/pgplot/)
### [plplot](http://plplot.sourceforge.net/)

### What is this repository for? ###

* This repository includes code to produce high quality 2D plots based on pgplot. In addition, it implements some extra examples from PLPLOT to produce 3D plots. Most library functions are simple wrappers for pgplot native functions and call the respective C bindings functions (cpgplot). The library is based on two basic data structures: 'Parameter_CPGPLOT' and 'Parameter_FILE'.  Both data structures are defined in the header files Parameter_CPGPLOT.h and Parameter_FILE.h, respectively. The structure 'Parameter_CPGPLOT' has 'Parameter_FILE' as one of its members. The first struct packs fine-tunning plotting parameters. The second one encapsulates information about the files containing the data to plot. Both structures handle a bunch of input parameters such as, for instance, the files to read, the characteristics of the plot, etc. All these arguments can be given as input arguments as invoking the main program to produce the plots. A variable usually named CPG of type 'Parameter_CPGPLOT' is passed on as a pointer to each library function when they are called from parent code. 
  
* Version
0.0.99

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

First you should install the libraries to meet the dependencies mentioned above. Look for pgplot and libplplot12 in your usual package handler. Notice that the linking command in makefiles of code you may develop should contain, at least, the following libraries:

* -lX11 -lpng -lplplotd -lpgplot -lcpgplot
* -lda_cpgplot_XY_GRID_FILE -lda_cpgplot_BASIC

* Summary of set up:
  
  + #### 1. Install plplot library
  + #### 2. Install pgplot library
  + #### 3. git clone CPGPLOT Graphix library. This will create the directory ~/CPGPLOT/
  + #### 4. Install the CPGPLOT Graphix library. Simply do: 
      + ~$ cd ~/CPGPLOT/library/ 
      + ~$ make 
      + ~$ cd ~/CPGPLOT/library_basic_UTL/
      + ~$ make
      
      This should create the corresponding files libda_cpgplot_XY_GRID_FILE.a and libda_cpgplot_BASIC.a
  
  + #### 5. Tests:
  In order to test if pgplot, plplot and CPGPLOT are correctly installed in your machine, you go to the directory ~/CPGPLOT_EXAMPLES. In that directory, there is a simple example of how to use the CPGPLOT library. You build it by typing:

     + ~/CPGPLOT_EXAMPLES/make

     and you will get the exectutable file PLOT. You may run the example with some command arguments (see main.c). For instance, 

     + ~/CPGPLOT_EXAMPLES/PLOT -G0 2 -G1 2 -G2 1 -G3 0 -G4 6.0 -G5 1 -G6 0.0 -G7 1.0

     You should get a graph with four different subplots. You may also type:

     + ~/PROJECT_CPGPLOT_EXAMPLES/PLOT -h

     and see other available command line arguments. You may also type:

     + ~/PROJECT_CPGPLOT_EXAMPLES/PLOT -G29 ?

     and see the different available graphic formats in which plots can be saved. The value for these input arguments can be overriden by the internal program code. You may have a good reason to do it, for instance, the necessity to produce several plots with different parameters as program executions proceeds. If you are in the mood, make moodfications at your own risk. Be creative.			       	   

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin: David Alonso (<dalonso@ceab.csic.es>)
