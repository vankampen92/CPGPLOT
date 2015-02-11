#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */

void CPGPLOT___X_Y___L_O_G___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
								   int SAME_PLOT,
								   int NO_of_POINTS, 
								   double * x_Data, 
								   double * y_Data,
								   char * X_label, 
								   char * Y_label, 
								   char * Title,
								   int SCALE_X, int SCALE_Y, 
								   int TYPE_of_AXIS, 
								   int LINES )
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

  /* BEGIN:   Defining symbols, lines, ranges, etc                              */
  static int color_Index;    
  static int type_of_Line;   
  static int type_of_Width;  
  static int type_of_Symbol; 

  color_Index    = CPG->color_Index;
  type_of_Line   = CPG->type_of_Line;
  type_of_Width  = CPG->type_of_Width;
  type_of_Symbol = CPG->type_of_Symbol; 
  /*   END:   Initialization of colors, lines, and symbols                      */

  /* BEGIN : Preparing cpgplot representation: Ranges and float conversion */ 
  /* x and y Ranges */
  /* SCALE_X = 0: x-axis automatic scale
     SCALE_Y = 0: y-axis automatic scale                                   */
  
  X_RANGE[0] = CPG->CPG_RANGE_X_0;   X_RANGE[1] = CPG->CPG_RANGE_X_1;
  Y_RANGE[0] = CPG->CPG_RANGE_Y_0;   Y_RANGE[1] = CPG->CPG_RANGE_Y_1;

  A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, x_Data, X_RANGE, SCALE_X, Range_x );
  A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, y_Data, Y_RANGE, SCALE_Y, Range_y );
 
  float * xs = (float *)malloc( sizeof(float) * NO_of_POINTS );
  float * ys = (float *)malloc( sizeof(float) * NO_of_POINTS );

  for(i=0; i<NO_of_POINTS; i++){ xs[i] = (float)x_Data[i]; ys[i] = (float)y_Data[i]; }

  float log10 = logf(10.0);
  if ( TYPE_of_AXIS == 10 ) {
    for( i=0; i<NO_of_POINTS; i++ ) xs[i] = logf(xs[i])/log10;
    Range_x[0] = logf(Range_x[0])/log10; Range_x[1] = logf(Range_x[1])/log10;
  }
  else if ( TYPE_of_AXIS == 20 ) {
    for( i=0; i<NO_of_POINTS; i++ ) ys[i] = logf(ys[i])/log10;
    Range_y[0] = logf(Range_y[0])/log10; Range_y[1] = logf(Range_y[1])/log10;
  }
  else if ( TYPE_of_AXIS == 30 ) {
    for( i=0; i<NO_of_POINTS; i++ ) { xs[i] = logf(xs[i])/log10; ys[i] = logf(ys[i])/log10; }
    Range_x[0] = logf(Range_x[0])/log10; Range_x[1] = logf(Range_x[1])/log10;
    Range_y[0] = logf(Range_y[0])/log10; Range_y[1] = logf(Range_y[1])/log10;  
  }
  else {
    printf(" Some error in TYPE_of_AXIS argument (TYPE_of_AXIS = %d \n", TYPE_of_AXIS);
    printf(" but TYPE_of_AXIS should be either 10, 20, or 30\n");
    printf(" Please see CPGPLOT___X_Y___L_O_G___P_L_O_T_T_I_N_G___S_A_M_E.c from\n");
    printf(" CPGPLOT library\n");
  }
  /*   END : Float conversion completed */

  if (SAME_PLOT == 0 ){
    cpg_XY_plot_logaxis(NO_of_POINTS, xs, ys, Range_x, Range_y, 
			CPG->color_Index, CPG->type_of_Line, 
			CPG->type_of_Width, CPG->type_of_Symbol, 
			X_label, Y_label, Title, 
			TYPE_of_AXIS, LINES );
  }
  else{
    /* 
    CPG->color_Index    = (color_Index % 10);
    CPG->type_of_Line   = (type_of_Line % 5);
    CPG->type_of_Width  = (type_of_Width % 3);
    CPG->type_of_Symbol = (type_of_Symbol % 5); 

    assert(CPG->color_Index <= 10);   assert(CPG->type_of_Line <= 5); 
    assert(CPG->type_of_Width <= 3);  assert(CPG->type_of_Symbol <= 5);

    // printf( "color_Index = %d, type_of_Line = %d, type_of_Width = %d, type_of_Symbol = %d\n",
    //	       CPG->color_Index, CPG->type_of_Line, CPG->type_of_Width, CPG->type_of_Symbol ); 
    */
    if( LINES == 1 ) { 
      cpg_XY_same_plot(NO_of_POINTS, xs, ys,
		       CPG->color_Index, 
		       CPG->type_of_Line, 
		       CPG->type_of_Width, 
		       CPG->type_of_Symbol);
    }
    else {
      cpg_XY_same_scattered(NO_of_POINTS, xs, ys, 
			    CPG->color_Index, CPG->type_of_Symbol );
    }
    
    // color_Index++; type_of_Line++; type_of_Width++; type_of_Symbol++; 
  }
  
  free(ys); free(xs);
}

