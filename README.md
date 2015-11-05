# README: CPGPLOT/FILE library #

This README explains the basics of this project and the steps necessary to get my CPGPLOT library up and running.

### What is this repository for? ###

* This repository includes code to produce high quality 2D plots. It is based on pgplot. In fact, most library functions are simple wrappers for pgplot native functions (C bindings: cpgplot). The library is based on two basic data structures: Parameter_CPGPLOT and Parameter_FILE.  Both data structures are defined as pointers. The first one packs fine-tunning plotting parameters. The second one is used to pack information about the files containing data to plot, which can be given as input arguments for the main program to read. As you will see, both data structures are passed on to each plotting library function as pointers from the calling parent code. 
  
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