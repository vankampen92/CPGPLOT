/* $Id: x18c.c 6639 2006-05-27 20:59:50Z hbabcock $

	3-d line and point plot demo.  Adapted from x08c.c.
*/

#include "plcdemos.h"

void plplot3D_xyz_curves(double ** ,
			double ** ,
			double ** ,
			int , int);

/*------------------------------------------------------------*\
 * main
 *
 * Does a series of 3-d plots for a given data set, 
 * with different viewing options in each plot.
\*------------------------------------------------------------*/
#define NPTS 1000

int main(int argc, const char *argv[])
{
  int i, k, n;
  PLFLT r;
  
/* Parse and process command line arguments */
    (void) plparseopts(&argc, argv, PL_PARSE_FULL);

    n = 2; 
    /* Definition of the curves to 3D-plot              */
    double ** X = (double **) malloc(n * sizeof(double *));
    double ** Y = (double **) malloc(n * sizeof(double *));
    double ** Z = (double **) malloc(n * sizeof(double *));
    for (i = 0; i<n; i++) { 
      X[i] = (double *) malloc(NPTS * sizeof(double));
      Y[i] = (double *) malloc(NPTS * sizeof(double));
      Z[i] = (double *) malloc(NPTS * sizeof(double));
    }
    /* From the mind of a sick and twisted physicist... */
    for (i = 0; i < NPTS; i++) {
      Z[0][i] = -1. + 2. * i / NPTS;
      r    = 1. - ( (PLFLT) i / (PLFLT) NPTS );
      X[0][i] = r * cos( 2. * M_PI * 6. * i / NPTS );
      Y[0][i] = r * sin( 2. * M_PI * 6. * i / NPTS );

      Z[1][i] = -1. + 2. * i / NPTS;
      r    = Z[0][i];
      X[1][i] = r * cos( 2. * M_PI * 6. * i / NPTS );
      Y[1][i] = r * sin( 2. * M_PI * 6. * i / NPTS );
    }
    /* ------------------------------------------------ */
        
    plplot3D_xyz_curves(X,Y,Z, NPTS, n);    

    for (i = 0; i<n; i++) { 
      free(X[i]); 
      free(Y[i]);
      free(Z[i]);
    }
    free(X);
    free(Y);
    free(Z); 
    
    exit(0);
}


