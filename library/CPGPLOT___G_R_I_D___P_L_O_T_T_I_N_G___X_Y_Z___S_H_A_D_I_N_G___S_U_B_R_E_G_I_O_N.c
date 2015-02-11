#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"

void C_P_G___P_L_O_T_T_I_N_G___X_Y_Z___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N( Parameter_CPGPLOT * CPG, 
									  double * x_Data, 
									  double x0, double x1,
									  double x_Step,
									  double * y_Data, 
									  double y0, double y1,
									  double y_Step,
									  double * z_Data,
									  int No_of_POINTS,
									  int No_of_LEVELS, 
									  double THICKNESS,
									  int FIRST_PLOT,
									  int A, 
									  double Z_Artificial_MAX )
{
  /* This function is only a driver for:
     C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N 9...)
  */
  int i;
  /* Input: 
     . (x0, x1, y0, y1) define the region where plotting will be possible, this is, the
     X and Y plotting ranges.
     . x_Step and y_Step are the dimensions of an elemental square. 
     . x_Data[] and y_Data[] define the central possicion of the elemental square where 
     a function z = f(x, y), takes a value: Z[k] = f(X[k], Y[k]), for k=0, ...
     . No_of_POINTS is the length of the X, Y and Z vectors. 
     . No_of_LEVELS, number of discrete levels in which the function Z will be discretized.
     . THICKNESS, maximum intensity corresponding to the highst level.
     . FIRST_PLOT, if FIRST_PLOT=0, then no axes nor labels are plotted. If FIRST_PLOT = 1, 
     axes and labels are drawn to annotate current graph. 
     . A, lid for function Z = f(X,Y). If Z[k] > A, then Z[k] takes the value 
     Z_Artificial_MAX.
     
     Otput:
     . A plot where there is a shaded region with different intensities according to the 
     discretivation level is shown.
  */

  /* BEGIN : 2D GRID cpgplot representation */
  CPG->ORIGIN_X    = x0;
  CPG->X_Dimension = x1 - x0; 
  
  CPG->ORIGIN_Y = y0;
  CPG->Y_Dimension = y1 - y0;
  
  double Z_MAX = 0.0;
  for(i=0; i<No_of_POINTS; i++){
    Z_MAX = MAX ( z_Data[i], Z_MAX );
  }
  
  if ( A == 1 ) {
    for(i=0; i<No_of_POINTS; i++){
      if(z_Data[i] > Z_Artificial_MAX ) z_Data[i] = Z_Artificial_MAX;
    }  
  }
  
  printf(" Shading a region of a function z = f(x,y) in color intensities...\n");
  printf(" z_max value: %g\t Artificial z_max value: %g\n", Z_MAX, Z_Artificial_MAX);
  /* 
     Multiplying character size with respect 1/40 of vertical viewport 
     by a factor, f, with cpgsch(f) 
  */
  cpgsch(1.5);
  
  C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N( CPG,
									      FIRST_PLOT,
									      x_Data, 
									      y_Data, 
									      z_Data,
									      No_of_POINTS,
									      x_Step, y_Step, 
									      No_of_LEVELS,
									      THICKNESS);
  /*   END : ----------------------------------------------------------------------*/
}


