/* 
 * The header file CPGPLOT_HEADER.h is a superheader file 
 * containing elaborated (hand-made), primitive cpgplot function
 * prototypes for plotting procedures. It is obligated when 
 * compiling with the libraries:
 * -lda_cpgplot_XY_GRID_FILE -lda_cpgplot_BASIC -lcpgplot -lpgplot
 */
#include <CPGPLOT_HEADER.h>

#define No_of_YEARS_MAX 100
#define No_of_PAPERS_MAX 25000

/* Functions used directly from main.c: */ 
void ArgumentControl(int argc, char **argv);

