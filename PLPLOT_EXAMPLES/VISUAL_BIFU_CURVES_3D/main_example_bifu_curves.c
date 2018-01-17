/* $Id: x18c.c 6639 2006-05-27 20:59:50Z hbabcock $

	3-d line and point plot demo.  Adapted from x08c.c.
*/
#include "plcdemos.h"

/* This code generates a 3D plot of bifucation curves defined by their 3 branches 
   Lower(stable), Inter(unstable), and Upper(stable). The visual integration of 
   the curves creates a proper represation of a surface. 
   
   The codes reads these files and call:
   
   plplot3D_xyz_bifu_curves(X,Y,Z, N, No_of_POINTS);    

   to do the 3D plot representation.

   Compilation: 

   . ~$ make EXAMPLE=_bifu_curves 
   
   Exectution
   
   . ~$ ./PLOT_bifu_curves 

   . ~$ ./PLOT_bifu_curves -bg FFFFFF -dev psc -o bifuCurves.ps
*/

void plplot3D_xyz_bifu_curves(double *** ,
			      double *** ,
			      double *** ,
			      int **, int,
			      double *,
			      double *,
			      double *,
			      char * ,
			      char * ,
			      char * );

void X_Y_Z___R_E_A_D___3C ( char * Name, 
			    double * x_Data, 
			    double * y_Data,
			    double * z_Data, 
			    int * N);

void File_Name_Ordered(char * Prefix, int File_Number, char * Sufix, char * File); 

void Generate_File_Name (char * file, char * a, int b, char * c);

void axis_Range( int n, double * x, double * Range_x); 

#define NPTS 1000

#define No_of_POINTS 20

int main(int argc, const char *argv[])
{
  int i, j, k, n;
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
    for(n=0; n<No_of_POINTS; n++) { 
      N[n] = (int *)calloc(3, sizeof(int) );
    }

    char ** Lower_File = (char **)calloc( No_of_POINTS, sizeof(char *) );
    char ** Inter_File = (char **)calloc( No_of_POINTS, sizeof(char *) );
    char ** Upper_File = (char **)calloc( No_of_POINTS, sizeof(char *) );
    for(n=0; n<No_of_POINTS; n++) {
      Lower_File[n] = (char *)calloc( 50, sizeof(char) );
      Inter_File[n] = (char *)calloc( 50, sizeof(char) );
      Upper_File[n] = (char *)calloc( 50, sizeof(char) );
    }			      

    for(n=0; n<No_of_POINTS; n++) {
      File_Name_Ordered("bifuCURVES_Lower_", n, ".dat", Lower_File[n]);
      File_Name_Ordered("bifuCURVES_Inter_", n, ".dat", Inter_File[n]);
      File_Name_Ordered("bifuCURVES_Upper_", n, ".dat", Upper_File[n]); 
    }

    double * Total_Range_x = (double *)calloc(2, sizeof(double) );
    double * Total_Range_y = (double *)calloc(2, sizeof(double) );
    double * Total_Range_z = (double *)calloc(2, sizeof(double) );

    double * Range_x = (double *)calloc(2, sizeof(double) );
    double * Range_y = (double *)calloc(2, sizeof(double) );
    double * Range_z = (double *)calloc(2, sizeof(double) );

    for(n=0; n<No_of_POINTS; n++) {
      X_Y_Z___R_E_A_D___3C ( Lower_File[n], X[n][0], Y[n][0], Z[n][0], 
			     &N[n][0] );

      axis_Range( N[n][0], X[n][0], Range_x ); 
      axis_Range( N[n][0], Y[n][0], Range_y );
      axis_Range( N[n][0], Z[n][0], Range_z );

      Total_Range_x[0] = MIN( Total_Range_x[0], Range_x[0]);
      Total_Range_y[0] = MIN( Total_Range_y[0], Range_y[0]);
      Total_Range_z[0] = MIN( Total_Range_z[0], Range_z[0]);
      Total_Range_x[1] = MAX( Total_Range_x[1], Range_x[1]);
      Total_Range_y[1] = MAX( Total_Range_y[1], Range_y[1]);
      Total_Range_z[1] = MAX( Total_Range_z[1], Range_z[1]);
      
      X_Y_Z___R_E_A_D___3C ( Inter_File[n], X[n][1], Y[n][1], Z[n][1], 
			     &N[n][1] );

      axis_Range( N[n][1], X[n][1], Range_x ); 
      axis_Range( N[n][1], Y[n][1], Range_y );
      axis_Range( N[n][1], Z[n][1], Range_z );

      Total_Range_x[0] = MIN( Total_Range_x[0], Range_x[0]);
      Total_Range_y[0] = MIN( Total_Range_y[0], Range_y[0]);
      Total_Range_z[0] = MIN( Total_Range_z[0], Range_z[0]);
      Total_Range_x[1] = MAX( Total_Range_x[1], Range_x[1]);
      Total_Range_y[1] = MAX( Total_Range_y[1], Range_y[1]);
      Total_Range_z[1] = MAX( Total_Range_z[1], Range_z[1]);
      
      X_Y_Z___R_E_A_D___3C ( Upper_File[n], X[n][2], Y[n][2], Z[n][2], 
			     &N[n][2] );

      axis_Range( N[n][2], X[n][2], Range_x ); 
      axis_Range( N[n][2], Y[n][2], Range_y );
      axis_Range( N[n][2], Z[n][2], Range_z );
      
      Total_Range_x[0] = MIN( Total_Range_x[0], Range_x[0]);
      Total_Range_y[0] = MIN( Total_Range_y[0], Range_y[0]);
      Total_Range_z[0] = MIN( Total_Range_z[0], Range_z[0]);
      Total_Range_x[1] = MAX( Total_Range_x[1], Range_x[1]);
      Total_Range_y[1] = MAX( Total_Range_y[1], Range_y[1]);
      Total_Range_z[1] = MAX( Total_Range_z[1], Range_z[1]);
     
    }

    char * x_Label = (char *)calloc(30, sizeof(char) );
    char * y_Label = (char *)calloc(30, sizeof(char) );
    char * z_Label = (char *)calloc(30, sizeof(char) );
    sprintf(x_Label, "%s", "Biting Rate (a)");
    sprintf(y_Label, "%s", "Carrying Capacity (K)");
    sprintf(z_Label, "%s", "Infectious Humans (y)"); 
    
    plplot3D_xyz_bifu_curves(X, Y, Z, N, No_of_POINTS,
			     Total_Range_x, Total_Range_y, Total_Range_z,
			     x_Label, y_Label, z_Label );    

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

    for(n=0; n<No_of_POINTS; n++) {
      free (Lower_File[n]);
      free (Inter_File[n]); 
      free (Upper_File[n]); 
    }
    free (Lower_File); 
    free (Inter_File);
    free (Upper_File); 

    free( Total_Range_x ); free (Total_Range_y); free(Total_Range_z);
    free( Range_x );       free (Range_y);       free(Range_z);
    free( x_Label );       free (y_Label);       free(z_Label);
    
    exit(0);
}

void X_Y_Z___R_E_A_D___3C ( char * Name, 
			    double * x_Data, 
			    double * y_Data,
			    double * z_Data, 
			    int * N )
{
  /* This function reads the xyz file (Name) 
     Important note: The number of columns of this file should be 
     always 3. Otherwise, another reading function is required	
  
     This a version of the last function which counts the number of elements 
     of the three column vectors, x_Data, y_Data, z_Data, an returns it as 
     pointer to N. 
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

    (*N) = n;
  /*   END : -----------------------------------------------------------*/
}  

void File_Name_Ordered(char * Prefix, int File_Number, char * Sufix, char * File)
{
  /* This function returns the name of a file a as pointer to 'File' 
     where 'char * Prefix' is the prefix, 'int File_Number' is an ordering number and 
     'char * Sufix' is a sufix. For instance, noSp_ +  5 + .dat = noSp_5.dat.
  */
  int i; 
  
  File[0]='\0';    
  Generate_File_Name(File, Prefix, File_Number, Sufix);
  printf("Generated File name: %s\n",File);
}

void Generate_File_Name (char * file, char * a, int b, char * c)
{
  /* This function returns the name of a file where 'char a[]' is the prefix, 
     'int b' is an ordering number i 'char c[]' is a sufix.
     For instance, noSp_ +  5 + .dat = noSp_5.dat.
  */
  char *pFile;
  char num[12];
  
  pFile = strcat(file,a);
  sprintf(num, "%d", b); 
  pFile = strcat(file,num);
  pFile = strcat(file,c);
}

void axis_Range( int n, double * x, double * Range_x)
{
  int i;
  double x_min, x_MAX;
  
    x_min = x[0]; x_MAX = x[0];
    for(i=0; i < n; i++){
	x_min = MIN( x_min, x[i]);
	x_MAX = MAX( x_MAX, x[i]);    
    }
    
  Range_x[0] = x_min; Range_x[1] = x_MAX;
}
