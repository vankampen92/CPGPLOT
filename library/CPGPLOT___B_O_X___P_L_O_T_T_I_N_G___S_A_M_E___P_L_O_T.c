#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */
     
void CPGPLOT___B_O_X___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
							     int SAME_PLOT,
							     int NO_of_POINTS, 
							     double * X, 
							     double ** Y, int NP, 
							     char * X_label, 
							     char * Y_label, 
							     char * Title,
							     int SCALE_X, int SCALE_Y )
{
  /* This function produces a simple box plots in a (x, y) two-dimensional plot 
     The input arrat Y[][] should be structured as follows: 

   *  . Y[][] contains the percentile values in the following structure:
   *
   *                             X     p(0.05)   p(0.25)   p(0.5)   p(0.75)   p(0.95)
   *                             ...   ...       ...       ...      ...       ...
   *                             X[j]  Y[0][j]   Y[1][j]   Y[2][j]  Y[3][j]   Y[4][j]

   *  The actual percentile values (p(0.05)   p(0.25)   p(0.5)   p(0.75)   p(0.95)) 
   *  are fixed in the code calling this procedure and may change. This is only an
   *  example. 
   * . NP is 5 in the example above, because there are five percentile values. 
  */
  
  /* The ranges, plot features (color, line, width, type) are
     first specified, and float converstion performed */

  /* Ranges are either fixed to (X_RANGE[0], X_RANGE[1]) and
     (Y_RANGE[0], Y_RANGE[1]) from command line or dynamically adjusted,
     depending on boolean value of SCALE_X, SCALE_Y  
     (see also: void A_X_E_S___R_A_N_G_E_S( int n, double * x, 
	                                    double * X_RANGE, int SCALE, 
				            float * Range_x) )
     
     This function uses two functions from cpgplot_UTL.c:
	. cpg_XY_box_plot(...)
        . void A_X_E_S___R_A_N_G_E_S( int n, double * x, 
	                              double * X_RANGE, int SCALE, 
				      float * Range_x) 
  */
  float Range_x[2], Range_y[2];
  double X_RANGE[2], Y_RANGE[2];
  int i,n,m;

  /* BEGIN : Preparing cpgplot representation: Ranges and float conversion */ 
  /* x and y Ranges */
  /* SCALE_X = 0: x-axis automatic scale
     SCALE_Y = 0: y-axis automatic scale                                   */
  double * YY = (double *)calloc( NP * NO_of_POINTS, sizeof(double) );

  if( SAME_PLOT == 0 ) {
    m = 0; 
    for(i=0; i<NO_of_POINTS; i++) for(n=0; n<NP; n++) YY[m++] = Y[n][i]; 

    X_RANGE[0] = CPG->CPG_RANGE_X_0;   X_RANGE[1] = CPG->CPG_RANGE_X_1;
    Y_RANGE[0] = CPG->CPG_RANGE_Y_0;   Y_RANGE[1] = CPG->CPG_RANGE_Y_1;
    
    A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, X, X_RANGE, SCALE_X, Range_x );
    A_X_E_S___R_A_N_G_E_S( NP*NO_of_POINTS, YY, Y_RANGE, SCALE_Y, Range_y );
  }
  
  float * xs = (float *)malloc( sizeof(float) * NO_of_POINTS );
  float ** ys = (float **)malloc( sizeof(float *) * NP );
  for(n=0; n<NP; n++) ys[n] = (float *)malloc( sizeof(float) * NO_of_POINTS );

  for(i=0; i<NO_of_POINTS; i++){ 
    xs[i] = (float)X[i]; 
    for(n=0; n<NP; n++) ys[n][i] = (float)Y[n][i]; 
  }
  /*   END : Float conversion completed */

  cpg_box_plot( SAME_PLOT, 
		NO_of_POINTS, xs, ys, NP,
		Range_x, Range_y, 
		CPG->color_Index, 
		CPG->type_of_Line, 
		CPG->type_of_Width, 
		CPG->type_of_Symbol, 
		X_label, Y_label, Title );
  
  for(n=0; n<NP; n++) free(ys[n]); 
  free(xs); free(ys);

  free(YY);
}

