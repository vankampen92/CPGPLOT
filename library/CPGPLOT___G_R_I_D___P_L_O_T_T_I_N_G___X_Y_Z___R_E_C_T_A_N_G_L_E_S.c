#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"

void C_P_G___P_L_O_T_T_I_N_G___X_Y_Z___R_E_C_T_A_N_G_L_E_S( Parameter_CPGPLOT * CPG, 
							    double * x_Data, 
							    int No_of_POINTS_1, 
							    double * y_Data, 
							    int No_of_POINTS_2,
							    double * W_GRID )
{
  /* BEGIN : 2D GRID cpgplot representation */
  CPG->ORIGIN_X    = x_Data[0];
  CPG->X_Dimension = (x_Data[No_of_POINTS_1-1] - x_Data[0]);    

  CPG->ORIGIN_Y = y_Data[0];
  CPG->Y_Dimension = (y_Data[No_of_POINTS_2-1] - y_Data[0]);
  
  CPG->x_GRID  = No_of_POINTS_1; 
  CPG->y_GRID  = No_of_POINTS_2;
 
  int FIRST_PLOT = 0;
  double i_PLOT  = 0.0;
  
  int no_of_COLORS = 5;
  double * COLOR_STATES = (double *)calloc( no_of_COLORS, sizeof(double) );
  COLOR_STATES[0] = 1.0; 
  COLOR_STATES[1] = 3.0; COLOR_STATES[2] = 2.0; COLOR_STATES[3] = 8.0; COLOR_STATES[4] = 5.0;
  
  C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___R_E_C_T_A_N_G_L_E_S( CPG,
								W_GRID, 
								FIRST_PLOT,
								no_of_COLORS, 
								COLOR_STATES,
								i_PLOT );

  free (COLOR_STATES);
  /*   END : ----------------------------------------------------------------------*/
}


