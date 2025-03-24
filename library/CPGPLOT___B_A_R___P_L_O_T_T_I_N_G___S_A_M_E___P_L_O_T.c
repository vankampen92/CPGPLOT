#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */
     
void CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
							     int SAME_PLOT,
							     int NO_of_POINTS, 
							     double * X, 
							     double * Y, 
							     char * X_label, 
							     char * Y_label, 
							     char * Title,
							     int SCALE_X, int SCALE_Y )
{
  /* This function produces a simple bar plots in a (x, y) two-dimensional plot 
     X[i] Index of the i-th bar
     Y[i] Height of the i-th bar
     from i = 0 to NO_of_POINTS - 1 
  */
  
  /* The ranges, plot features (color, line, width, type) are
     first specified, and float converstion performed */

  /* Ranges are either fixed to (X_RANGE[0], X_RANGE[1]) and
     (Y_RANGE[0], Y_RANGE[1]) from either command line (or anywhere in 
     advance in the code calling this function), or dynamically adjusted,
     depending on boolean values of SCALE_X, SCALE_Y  
     (see also: void A_X_E_S___R_A_N_G_E_S( int n, double * x, 
	                                    double * X_RANGE, int SCALE, 
				            float * Range_x) )
     
     This function uses two functions from cpgplot_UTL.c:
	. cpg_XY_bar_plot(...)
        . void A_X_E_S___R_A_N_G_E_S( int n, double * x, 
	                              double * X_RANGE, int SCALE, 
				      float * Range_x) 
  */
  float Range_x[2], Range_y[2];
  double X_RANGE[2], Y_RANGE[2];
  int i;

  /* BEGIN : Preparing cpgplot representation: Ranges and float conversion */ 
  /* x and y Ranges */
  /* SCALE_X = 0: x-axis automatic scale
     SCALE_Y = 0: y-axis automatic scale                                   */

  if( SAME_PLOT == 0 ) {
    
    X_RANGE[0] = CPG->CPG_RANGE_X_0;   X_RANGE[1] = CPG->CPG_RANGE_X_1;
    Y_RANGE[0] = CPG->CPG_RANGE_Y_0;   Y_RANGE[1] = CPG->CPG_RANGE_Y_1;
    
    A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, X, X_RANGE, SCALE_X, Range_x );
    A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, Y, Y_RANGE, SCALE_Y, Range_y );
  }
  
  float * xs = (float *)malloc( sizeof(float) * NO_of_POINTS );
  float * ys = (float *)malloc( sizeof(float) * NO_of_POINTS );
 
  for(i=0; i<NO_of_POINTS; i++){ 
    xs[i] = (float)X[i]; 
    ys[i] = (float)Y[i]; 
  }
  /*   END : Float conversion completed */

  cpg_bar_plot( SAME_PLOT, 
		NO_of_POINTS, xs, ys,
		Range_x, Range_y, 
		CPG->color_Index, 
		CPG->type_of_Line, 
		CPG->type_of_Width, 
		CPG->type_of_Symbol, 
		X_label, Y_label, Title );
 
  free(xs); free(ys);
}

