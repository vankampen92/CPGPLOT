#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"

/* File name of this file should be:  
   CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___X_Y_Z___S_H_A_D_E_S.c
   
   This function calls:

   C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S(...)
   
   from CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___S_H_A_D_E_S.c 
*/
   

void C_P_G___P_L_O_T_T_I_N_G___X_Y_Z___S_H_A_D_E_S( Parameter_CPGPLOT * CPG, 
						    double * x_Data, int No_of_POINTS_1, 
						    double * y_Data, int No_of_POINTS_2,
						    double * W_GRID, 
						    int A, 
						    double W_Artificial_MAX )
{
  int i;

  /* BEGIN : 2D GRID cpgplot representation */
  CPG->ORIGIN_X    = x_Data[0];
  CPG->X_Dimension = (x_Data[No_of_POINTS_1-1] - x_Data[0]);    
  
  CPG->ORIGIN_Y = y_Data[0];
  CPG->Y_Dimension = (y_Data[No_of_POINTS_2-1] - y_Data[0]);
  
  CPG->x_GRID  = No_of_POINTS_1; 
  CPG->y_GRID  = No_of_POINTS_2;
  
  int FIRST_PLOT = 0;
  double i_PLOT  = 0.0;
  
  double W_GRID_MAX = 0.0;
  for(i=0; i<(No_of_POINTS_1 * No_of_POINTS_2); i++){
    W_GRID_MAX = MAX ( W_GRID[i], W_GRID_MAX );
  }
  
  if ( A == 1 ) {
    for(i=0; i<(No_of_POINTS_1 * No_of_POINTS_2); i++){
      if(W_GRID[i] > W_Artificial_MAX ) W_GRID[i] = W_Artificial_MAX;
    }  
  }
  
  printf(" Plotting function z = f(x,y) in color shades...\n");
  printf(" z_max value: %g\t Artificial z_max value: %g\n", W_GRID_MAX, W_Artificial_MAX);
  /* 
     Multiplying character size with respect 1/40 of vertical viewport 
     by a factor, f, with cpgsch(f) 
  */
  cpgsch(1.5);
  
  C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S( CPG,
							W_GRID, 
							FIRST_PLOT,
							CPG->CPG_SCALE_W, 
							CPG->CPG_RANGE_W_0,
							CPG->CPG_RANGE_W_1,
							i_PLOT );
  /*   END : ----------------------------------------------------------------------*/
}


