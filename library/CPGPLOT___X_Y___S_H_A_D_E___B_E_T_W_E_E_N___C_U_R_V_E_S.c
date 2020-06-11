#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */

void CPGPLOT___X_Y___S_H_A_D_E___B_E_T_W_E_E_N___C_U_R_V_E_S ( Parameter_CPGPLOT * CPG,       
							       int NO_of_POINTS, 
							       double * x, 
							       double * y_1, double * y_2 )
{
  /* This function produces a shade between the curves defined by (x, y_1) and (x, y_2). */
  /* This function should be always called after having drawn the two curves on a graph, so
     that the shade appears on the same graph.                                           */
  int i;

  /* BEGIN:   Defining symbols, lines, ranges, etc                              */
  int color_Index;    
  int type_of_Line;   
  int type_of_Width;  

  color_Index    = CPG->color_Index;
  type_of_Line   = CPG->type_of_Line;
  type_of_Width  = CPG->type_of_Width;
  /*   END:   Initialization of colors, lines, and symbols                      */

  float * xs   = (float *)malloc( sizeof(float) * NO_of_POINTS );
  float * ys_1 = (float *)malloc( sizeof(float) * NO_of_POINTS );
  float * ys_2 = (float *)malloc( sizeof(float) * NO_of_POINTS );

  for(i=0; i<NO_of_POINTS; i++){ 
    xs[i] = (float)x[i]; 
    ys_1[i] = (float)y_1[i]; 
    ys_2[i] = (float)y_2[i]; 
  }
  
  cpg_XY_shade_between_curves(NO_of_POINTS, 
			      xs, ys_1, ys_2,
			      CPG->color_Index, 
			      CPG->type_of_Line, 
			      CPG->type_of_Width );
  
  free(ys_1); free(ys_2); free(xs);
}

