# README: CPGPLOT-FILE library #

This README explains the basics of this project and the steps necessary to get my CPGPLOT-FILE library up and running.

### What is this repository for? ###

* This repository includes code to produce high quality 2D plots. It is based on pgplot. In fact, most library functions are simple wrappers for pgplot native functions (C bindings: cpgplot). The library is based on two basic data structures: 'Parameter_CPGPLOT' and 'Parameter_FILE'.  Both data structures are defined in the corresponding header files: Parameter_CPGPLOT.h and Parameter_FILE.h. As you will see, the struct 'Parameter_CPGPLOT' has 'Parameter_FILE' as one of its members. The first one packs fine-tunning plotting parameters. The second one encapsulates information about the files containing the data to plot. Both structures handle a bunch of input parameters such as, for instance, the files to read, the characteristics of the plot, etc. All these arguments are given as input arguments which are read by the main program to produce the plots. As you will see, both data structures are passed on to each plotting library function as pointers from the calling parent code. 
  
* Version
1.0.1

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

* Summary of set up
* Configuration
* Dependencies
* Database configuration
* How to run tests
* Deployment instructions

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact