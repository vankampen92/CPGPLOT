#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */
     
void CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___F_R_A_C_T_I_O_N_S (Parameter_CPGPLOT * CPG, 
							    int SAME_PLOT,
							    int NO_of_POINTS, 
							    double * X, 
							    double * Y, 
							    char * X_label, 
							    char * Y_label, 
							    char * Title,
							    int SCALE_X, 
							    int SCALE_Y, 
							    int * color_Index, 
							    int * type_of_Line, 
							    int * type_of_Width, 
							    char ** Bar_Titles )
{
  /* This function produces a simple bar plots in a (x, y) two-dimensional plot 
     The input arrat Y[][] should be structured as follows: 
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

   X_RANGE[0] = CPG->CPG_RANGE_X_0;   X_RANGE[1] = CPG->CPG_RANGE_X_1;
   Y_RANGE[0] = CPG->CPG_RANGE_Y_0;   Y_RANGE[1] = CPG->CPG_RANGE_Y_1;

  if( SAME_PLOT == 0 ) {
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
  
  printf(" CPGPLOT\n");
  for(i=0; i<NO_of_POINTS; i++) { 
    printf("%s: ", Bar_Titles[i]);
    printf("%g papers ", Y[i]);
    printf("( color[%d], line[%d], width[%d]\n", 
	   color_Index[i], type_of_Line[i], type_of_Width[i] );
  }

  cpg_bar_plot_Fractions( SAME_PLOT, 
			  NO_of_POINTS, xs, ys,
			  Range_x, Range_y, 
			  color_Index, 
			  type_of_Line, 
			  type_of_Width, 
			  X_label, Y_label, Title, 
			  Bar_Titles );
  
  free(xs); free(ys);
}

