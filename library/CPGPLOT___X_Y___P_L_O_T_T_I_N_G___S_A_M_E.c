#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */

void CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
							   int SAME_PLOT,
							   int NO_of_POINTS, 
							   double * x_Data, 
							   double * y_Data,
							   char * X_label, 
							   char * Y_label, 
							   char * Title,
							   int SCALE_X, int SCALE_Y )
{
  /* This function produces a simple (x, y) two-dimensional plot */
  /* This function acts as a wrapper of cpg_XY_plot(...) and
     cpg_XY_same_plot (...) depending on booleand parameter 
     SAME_PLOT */

  /* The ranges, plot features (color, line, width, type) are
     first specified, and float converstion performed */

  /* Ranges are either fixed to (X_RANGE[0], X_RANGE[1]) and
     (Y_RANGE[0], Y_RANGE[1]) or dynamically,
     depending on boolean value of SCALE_X, SCALE_Y  
     (see also:
        void A_X_E_S___R_A_N_G_E_S( int n, double * x, double * X_RANGE, int SCALE, float * Range_x) 
        void C_P_G___2d___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T (...) in cpgplot_UTL.c
     which is version of this very same function where Parameter_CPGPLOT * CPG
     is not used )
     
     This function calls three functions from cpgplot_UTL.c:
	. cpg_XY_plot(...)
	. cpg_XY_same_plot(...)
        . void A_X_E_S___R_A_N_G_E_S( int n, double * x, double * X_RANGE, int SCALE, float * Range_x) 
  */
  float Range_x[2], Range_y[2];
  double X_RANGE[2], Y_RANGE[2];
  int i;

  /* BEGIN : Preparing cpgplot representation: Ranges and float conversion */ 
  /* x and y Ranges */
  /* SCALE_X = 0: x-axis automatic scale
     SCALE_Y = 0: y-axis automatic scale                                   */
  
  X_RANGE[0] = CPG->CPG_RANGE_X_0;   X_RANGE[1] = CPG->CPG_RANGE_X_1;
  Y_RANGE[0] = CPG->CPG_RANGE_Y_0;   Y_RANGE[1] = CPG->CPG_RANGE_Y_1;

  float * xs = (float *)malloc( sizeof(float) * NO_of_POINTS );
  float * ys = (float *)malloc( sizeof(float) * NO_of_POINTS );

  for(i=0; i<NO_of_POINTS; i++){ xs[i] = (float)x_Data[i]; ys[i] = (float)y_Data[i]; }
  /*   END : Float conversion completed */

  if (SAME_PLOT == 0 ){
    A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, x_Data, X_RANGE, SCALE_X, Range_x );
    A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, y_Data, Y_RANGE, SCALE_Y, Range_y );
    
    cpg_XY_plot(NO_of_POINTS, xs, ys, Range_x, Range_y, 
		CPG->color_Index, 
		CPG->type_of_Line, 
		CPG->type_of_Width, 
		CPG->type_of_Symbol, 
		X_label, Y_label, Title);
  }
  else{
    
    cpg_XY_same_plot(NO_of_POINTS, xs, ys,
		     CPG->color_Index, 
		     CPG->type_of_Line, 
		     CPG->type_of_Width, 
		     CPG->type_of_Symbol);
  }
  
  free(ys); free(xs);
}

