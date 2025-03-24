#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */

void CPGPLOT___X_Y___P_L_O_T_T_I_N_G___A_X_E_S ( Parameter_CPGPLOT * CPG, 
							                            char * X_label, 
							                            char * Y_label, 
							                            char * Title)
{
  /* This function produces a simple two-dimensional (empty, only XY axes) plot */
  /* This function acts as a wrapper of cpg_XY_plot_axes(...)                   */

  /* The ranges, plot features (color, line, width, type) are
     first specified, and float converstion performed 

     This function calls one function from cpgplot_UTL.c:
	. cpg_XY_plot_axes(...) 
  */
  float Range_x[2], Range_y[2];
  double X_RANGE[2], Y_RANGE[2];

  /* BEGIN : Preparing cpgplot representation: Ranges and float conversion */ 
  /* Ranges */
  X_RANGE[0] = CPG->CPG_RANGE_X_0;   X_RANGE[1] = CPG->CPG_RANGE_X_1;
  Y_RANGE[0] = CPG->CPG_RANGE_Y_0;   Y_RANGE[1] = CPG->CPG_RANGE_Y_1;

  Range_x[0] = (float)X_RANGE[0];    Range_x[1] = (float)X_RANGE[1];  
  Range_y[0] = (float)Y_RANGE[0];    Range_y[1] = (float)Y_RANGE[1]; 
  /*   END : Float conversion completed */
     
  cpg_XY_plot_axes(Range_x, Range_y, 
		             CPG->color_Index, 
		             CPG->type_of_Line, 
		             CPG->type_of_Width, 
		             CPG->type_of_Symbol, 
		             X_label, Y_label, Title);  
}

