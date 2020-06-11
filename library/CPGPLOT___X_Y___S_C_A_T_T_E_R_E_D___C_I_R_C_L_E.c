#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */
     
void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___C_I_R_C_L_E ( Parameter_CPGPLOT * CPG,
						       double x_Center, 
						       double y_Center,
						       double Radius, 
						       int type_of_Filling )
{
    /* This function acts as a wrapper of cpg_XY_same_circle (...) */
  /* Important Note: 
     This function only works properly if previously a call to box, 
     labels and plot axes have been already drawn */
 
  float xs     = (float)x_Center; 
  float ys     = (float)y_Center;
  float radius = (float)Radius;
  
  cpg_XY_same_circle(xs, ys, radius, 
		     CPG->color_Index, type_of_Filling );
}

/* void cpgsfs(int fs);  Setting type of filling                        */
/* Argument: fs(input)  : the fill-area style to be used for subsequent */
/* 			  plotting:                                     */
/* 			  fs = 1 => solid (default)                     */
/*                        fs = 2 => outline                             */
/*                        fs = 3 => hatched                             */
/*                        fs = 4 => cross-hatched                       */
