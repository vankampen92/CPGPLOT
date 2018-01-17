/* $Id: x18c.c 6639 2006-05-27 20:59:50Z hbabcock $

	3-d line and point plot demo.  Adapted from x08c.c.
*/
#include "plcdemos.h"

void plplot3D_xyz_bifu_curves(double *** ,
			      double *** ,
			      double *** ,
			      int **, int);

void X_Y_Z___R_E_A_D___3C ( char * Name, 
			    double * x_Data, 
			    double * y_Data,
			    double * z_Data, 
			    int * No_of_POINTS);
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

    double *** X = (double ***) calloc(No_of_POINTS, sizeof(double **));
    double *** Y = (double ***) calloc(No_of_POINTS, sizeof(double **));
    double *** Z = (double ***) calloc(No_of_POINTS, sizeof(double **));
    for(j=0; j<No_of_POINTS; j++) { 
    /* Definition of the curves to 3D-plot              */
      X[j] = (double **)calloc(3, sizeof(double *));
      Y[j] = (double **)calloc(3, sizeof(double *));
      Z[j] = (double **)calloc(3, sizeof(double *));
      for (i = 0; i < 3; i++) { 
	X[j][i] = (double *)calloc(NPTS, sizeof(double));
	Y[j][i] = (double *)calloc(NPTS, sizeof(double));
	Z[j][i] = (double *)calloc(NPTS, sizeof(double));
      }
    }
    int ** N = (int **)calloc( No_of_POINTS, sizeof(int *) );
    for(n=0; n<No_of_POINTS, n++) { 
      N[n] = (int *)calloc(3, sizeof(int) );
    }
    
    for(n=0; n<No_of_POINTS; n++) {
      X_Y_Z___R_E_A_D___3C ( "Lower.dat", X[n][0], Y[n][0], Z[n][0], 
			     &N[n][0] );
      X_Y_Z___R_E_A_D___3C ( "Inter.dat", X[n][1], Y[n][1], Z[n][1], 
			     &N[n][1] );
      X_Y_Z___R_E_A_D___3C ( "Lower.dat", X[n][2], Y[n][2], Z[n][2], 
			     &N[n][2] );
    }
        
    plplot3D_xyz_bifu_curves(X,Y,Z, N, No_of_POINTS);    

    for(j=0; j<No_of_POINTS; j++) { 
    /* Definition of the curves to 3D-plot              */
      for (i = 0; i < 3; i++) { 
	free (X[j][i]); 
	free (Y[j][i]); 
	free (Z[j][i]); 
      }
      free (X[j]);
      free (Y[j]);
      free (Z[j]);
      free (N[j]); 
    }
    free(X); free(Y); free(Z); free(N); 
    
    exit(0);
}

void X_Y_Z___R_E_A_D___3C ( char * Name, 
			    double * x_Data, 
			    double * y_Data,
			    double * z_Data, 
			    int * No_of_POINTS)
{
  /* This function reads the xyz file (Name) 
     Important note: The number of columns of this file should be 
     always 3. Otherwise, another reading function is required	
  
     This a version of the last function which counts the number of elements 
     of the three column vectors, x_Data, y_Data, z_Data, an returns it as 
     pointer to No_of_POINTS. 
  */
  FILE * fp;
  double x,y,z;
  int n;   

  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * */
    if( (fp = fopen(Name,"r") ) == NULL) {
      printf("File %s on-existent in current directory!!!\n --- Cannot open file.\n", Name);
      exit(1);
    }
    
    n=0;                                         
    while (fscanf(fp, "%lf\t%lf%lf\n", &x, &y, &z) != EOF ){  
      x_Data[n] = x; y_Data[n] = y; z_Data[n] = z; 
      n++;
    }
    fclose(fp);

    (*No_of_POINTS) = n;
  /*   END : -----------------------------------------------------------*/
}  
