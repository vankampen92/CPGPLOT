# Wellcome to CPGPLOT Graphix Library #

This project runs on linux machines out of the box. To run in other platforms makefiles should be modified accordingly.

## CPGPLOT Graphix Library.
This is a set of functions written in C relying on cpgplot primitives from pgplot, and plplot. The follwing dependencies are required:

### [pgplot](/http://www.astro.caltech.edu/~tjp/pgplot/)
### [plplot](http://plplot.sourceforge.net/)

### What is this repository for? ###

* This repository includes code to produce high quality 2D plots based on pgplot and implement some examples from extra PLPLOT to produce 3D plots. Most library functions are simple wrappers for pgplot native functions and call the respective C bindings (cpgplot). The library is based on two basic data structures: 'Parameter_CPGPLOT' and 'Parameter_FILE'.  Both data structures are defined in header files Parameter_CPGPLOT.h and Parameter_FILE.h, respectively. The struct 'Parameter_CPGPLOT' has 'Parameter_FILE' as one of its members. The first one packs fine-tunning plotting parameters. The second one encapsulates information about the files containing the data to plot. Both structures handle a bunch of input parameters such as, for instance, the files to read, the characteristics of the plot, etc. All these arguments are given as input arguments of the main program to produce the plots. A variable usually named CPG is of type 'Parameter_CPGPLOT' is passed on as a pointer to each library function when functions are called from parent code. 
  
* Version
0.0.99

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

First you should install the libraries to meet the dependencies mentioned above. Look for pgplot and libplplot12 in your usual package handler.
Notice that the linking command from most makefiles contains, at least, the following libraries:

* -lX11 -lpng -lplplotd -lpgplot -lcpgplot
* -lda_cpgplot_XY_GRID_FILE -lda_cpgplot_BASIC

* Summary of set up:
  
  + #### 1. Install plplot library
  + #### 2. Install pgplot library
  + #### 3. git clone CPGPLOT Graphix library
  + #### 4. Tests:
  In order to test if pgplot, plplot and CPGPLOT are correctly installed in your machine, you can expand the tar file PROJECT_CPGPLOT_EXAMPLES.tar, which is in the project root directory on your home directory. Then you will get the directory ~/PROJECT_CPGPLOT_EXAMPLES. In that directory, there is a simple example of how to use the CPGPLOT library. You build it by typing:

     + ~/PROJECT_CPGPLOT_EXAMPLES/make

     and you will get the exectutable file PLOT. You may run the example with some command arguments (see main.c). You should get a graph with four different subplots. You may also type:

     + ~/PROJECT_CPGPLOT_EXAMPLES/PLOT -h

     and see other available command line arguments. You may also type:

     + ~/PROJECT_CPGPLOT_EXAMPLES/PLOT -G29 ?

     and see the different avaiable graphic formats in which plots can be saved. Notice that sometimes the value for these input arguments is overriden by the internal program code. When this happens, it is for a good reason. Please check the code to understand why. If you are in mood, make moodfications at your own risk. Be creative.			       	   

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin: David Alonso (<dalonso@ceab.csic.es>)