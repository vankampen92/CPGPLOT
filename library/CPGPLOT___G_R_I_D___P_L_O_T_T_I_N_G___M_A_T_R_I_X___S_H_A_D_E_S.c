#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"
/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */    

#if defined CPGPLOT_REPRESENTATION

void C_P_G___P_L_O_T_T_I_N_G___M_A_T_R_I_X___S_H_A_D_E_S( Parameter_CPGPLOT * CPG,
							  double ** GRD,
							  int nx, int ny, 
							  double X_D, double Y_D,
							  double X_0, double Y_0, 
							  int FIRST_PLOT,
							  int W_SCALE, 
							  double W_min, double W_MAX, 
							  double i_PLOT )
{
  /* Input parameters:
     . W_SCALE
     . W_min, W_MAX: max and min values vertical axis.
     . GRD: Lattice values GRD[i][j], i=0,...,nx-1, j=0,...,ny-1
     . T: Parameter_Table
     . W: GRID (values to plot) as a pointer to  double array.  
     . i_PLOT: the 2D plot is drawn for each value of i_PLOT. 
               For instance i_PLOT could be a given time.
      
      Output:
      Color grid where a W value is plotted at each lattice node as a snabshot at a 
      given value of i_PLOT:
  */ 
  int i,j,n;
  double * W = (double *)calloc( nx * ny, sizeof(double) );
  n=0;
  for(j=0; j<ny; j++)
    for(i=0; i<nx; i++)
      W[n++] = GRD[i][j];

  CPG->y_GRID = ny; 
  CPG->x_GRID = nx;    
  CPG->X_Dimension = X_D;
  CPG->Y_Dimension = Y_D;
  CPG->ORIGIN_X    = X_0; 
  CPG->ORIGIN_Y    = Y_0;

  C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S( CPG,
							W, 
						        FIRST_PLOT,
							W_SCALE, W_min, W_MAX, 
							i_PLOT );
  free ( W );
}
#endif
