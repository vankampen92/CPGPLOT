#include "../CPGPLOT_HEADER.h"

int CPGPLOT___X_Y_n___S_C_A_T_T_E_R_E_D ( Parameter_CPGPLOT * CPG, 
					  int NO_of_POINTS, int n_XY, 
					  double * x_Data, double ** y_Data, 
					  char * X_label, char * Y_label, char * Title,
					  int SCALE_X, int SCALE_Y )
{
  /* This function produces a simple (x, y) two-dimensional plot */
  /* This function acts as a wrapper of cpg_XYn_plot(...).        */
  /* The ranges, plot features (color, line, width, type) are
     first specified, and float converstion performed */

  /* Axes ranges is either fixed to:
     ( X_RANGE[0], X_RANGE[1]) and ( Y_RANGE[0], Y_RANGE[1])
     or dynamically determined, depending on boolean value of SCALE_X  
     (see also:
     void A_X_E_S___R_A_N_G_E_S( int n, double * x, double * X_RANGE, 
                                 int SCALE, float * Range_x) 
      This function calls two functions from basic library:
        . cpg_XYn_plot(...)
        . void A_X_E_S___R_A_N_G_E_S( int n, double * x, double * X_RANGE, 
	                              int SCALE, float * Range_x) 
  */
  /* Data (x, y1), (x, y2), ..., (x, yn) will be plotted:
   *
   *                                      x     y1    y2    y3    y4    y5
   *                                     ...   ...   ...   ...   ...   ... 
   * 
   * This procedure is equivalent to:
   *
   * int C_P_G___P_L_O_T_T_I_N_G___n_x_y___F_I_L_E(...), 
   *
   * but the data to plot are passed here as arguments x_Data and y_Data instead of
   * read from a file.
   */
  float Range_x[2], Range_y[2];
  double X_RANGE[2], Y_RANGE[2];
  int i,j;
  double y_min, y_MAX;
  /* BEGIN : Preparing cpgplot representation 
   *         Defining symbols, lines, ranges, etc  
   *         Allocating and calculating non-variable float vectors for cpgplot */
  /* x and y Ranges                                                            */

  /* SCALE_X = 0: x-axis automatic scale
     SCALE_Y = 0: y-axis automatic scale 
  */
  /* BEGIN : Defining the vector of color, type of line, type of width
     and type of symbol                                                        */

  /* color_Index... (0,1, ..., 15) 
     0: Background (black), 1: White, ..., 15 (15 different colors predefined) */
  /* type_of_Line... (1, ..., 5)     (only five all possible)                                                */
  /* type_of_Width... (1, ..., 201)  
     Default, 1 = 1/200 Inches (approx 0.003 Inches)                           */
  /* type_of_Symbol...  (0, ..., 31) Standard maker sympols 
     (more markers are available. See manual)                                  */
  /*                                                                           */
  /* ( See http://www.astro.caltech.edu/~tjp/pgplot/subroutines.html, for further details )                  */
  int * color_Index = (int *)malloc( sizeof(int) * n_XY );
  int * type_of_Line = (int *)malloc( sizeof(int) * n_XY );
  int * type_of_Width = (int *)malloc( sizeof(int) * n_XY );
  int * type_of_Symbol = (int *)malloc( sizeof(int) * n_XY );
  
  for ( j = 0; j < n_XY; j++ ){
    color_Index[j] = 2+j;
    type_of_Line[j] = 2;
    type_of_Width[j] = 4;
    type_of_Symbol[j] = 17;
  }
  /*   END : Defining color, lines and so on * * * * * * * * * * * * */ 

  /* BEGIN : Finding suitable ranges * * * * * * * * * * * * * * * * * * * * * * */
  X_RANGE[0] = CPG->CPG_RANGE_X_0;   X_RANGE[1] = CPG->CPG_RANGE_X_1;
  A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, x_Data, X_RANGE, SCALE_X, Range_x );
  
  Y_RANGE[0] = CPG->CPG_RANGE_Y_0;   Y_RANGE[1] = CPG->CPG_RANGE_Y_1;
  if(SCALE_Y == 0){
    y_min = y_Data[0][0]; y_MAX = y_Data[0][0];
    for(i=0; i < NO_of_POINTS; i++){
      for(j=0; j < n_XY; j++) {
	y_min = MIN(y_min, y_Data[j][i]);
	y_MAX = MAX(y_MAX, y_Data[j][i]);
      }
    }
    Range_y[0] = (float)y_min; Range_y[1] = (float)y_MAX;
  }
  else {
    Range_y[0] = (float)Y_RANGE[0]; Range_y[1] = (float)Y_RANGE[1];
  }
  /*   END : Finding suitable ranges * * * * * * * * * * * * * * * * * * * * * * */
  
  /* BEGIN : Allocating and calculating non-variable float vectors for cpgplot */
  float ** y_cpg_Data = (float **)malloc( sizeof(float *) * n_XY );
  for ( i=0; i < n_XY; i++ ) y_cpg_Data[i] = (float *)malloc( sizeof(float) * NO_of_POINTS);
  float * x_cpg_Data = (float *)malloc( sizeof(float) * NO_of_POINTS);
  /*   END :  End allocation * * * * * * * * * * * * * * * * * * * * * * * * * */
  
  for(i=0;  i < NO_of_POINTS;  i++){
    x_cpg_Data[i] = (float)x_Data[i];
    for(j=0;  j < n_XY;  j++) y_cpg_Data[j][i] = (float)y_Data[j][i];
  }
  
  cpg_XYn_scattered(NO_of_POINTS, n_XY, x_cpg_Data, y_cpg_Data, Range_x, Range_y, 
		    color_Index, type_of_Line, type_of_Width, type_of_Symbol, 
		    X_label, Y_label, Title);
  
  for ( i=0; i < n_XY; i++ ) free(y_cpg_Data[i]);
  free(y_cpg_Data); 
  free(x_cpg_Data);

  free(color_Index); free(type_of_Line); free(type_of_Width), free(type_of_Symbol);
  return(0);
}
