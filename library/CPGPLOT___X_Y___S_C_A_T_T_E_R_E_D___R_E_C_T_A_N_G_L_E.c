#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */
     
void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___R_E_C_T_A_N_G_L_E ( Parameter_CPGPLOT * CPG,
						       double X1, double Y1, 
	                                               double X2, double Y2, 
						       int type_of_Filling )
{
    /* This function acts as a wrapper of cpg_XY_same_rectangle (...) */
    /* Important Note: 
       This function only works properly if previously a call to box, 
       labels and plot axes have been already drawn */
 
    /* Coordinates of the bottom left corner: (x1, y1) */
    /* Coordinates of the upper right corner: (x2, y2) */

  float x1     = (float)X1; float y1     = (float)Y1;
  float x2     = (float)X2; float y2     = (float)Y2;
  
  cpg_XY_same_rectangle(x1, y1,  x2, y2,  
		    	CPG->color_Index, type_of_Filling );
}

/* void cpgsfs(int fs);  Setting type of filling                        */
/* Argument: fs(input)  : the fill-area style to be used for subsequent */
/* 			  plotting:                                     */
/* 			  fs = 1 => solid (default)                     */
/*                        fs = 2 => outline                             */
/*                        fs = 3 => hatched                             */
/*                        fs = 4 => cross-hatched                       */
