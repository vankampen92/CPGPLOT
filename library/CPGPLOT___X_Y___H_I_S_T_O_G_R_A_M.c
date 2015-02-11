#include "../CPGPLOT_HEADER.h"

void CPGPLOT___X_Y___H_I_S_T_O_G_R_A_M (Parameter_CPGPLOT * CPG,
		       int NO_of_POINTS, double * x_DATA, int n_BINS,
		       char * X_Label, char * Y_Label, char * Title, 
		       int SCALE_X, int SCALE_Y )
{
  float Range_x[2], Range_y[2];
  double X_RANGE[2], Y_RANGE[2];
  int i;
  
  X_RANGE[0] = CPG->CPG_RANGE_X_0;   X_RANGE[1] = CPG->CPG_RANGE_X_1;
  Y_RANGE[0] = CPG->CPG_RANGE_Y_0;   Y_RANGE[1] = CPG->CPG_RANGE_Y_1;

  A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, x_DATA, X_RANGE, SCALE_X, Range_x );
  Range_y[0] = (float)Y_RANGE[0];   Range_y[1] = (float)Y_RANGE[1];

  float * data = (float *)malloc( sizeof(float) * NO_of_POINTS );
  for(i=0; i<NO_of_POINTS; i++){ data[i] = (float)x_DATA[i]; }
  
  float ch;
  cpgqch( &ch );
  cpgsch(1.5 * ch);
  
  cpgenv(Range_x[0], Range_x[1], Range_y[0], Range_y[1], 0, 1);
  cpglab(X_Label, Y_Label, Title);
   
  cpgsch(1.0);

  cpg_XY_histogram( NO_of_POINTS, data, n_BINS, 
		    Range_x, Range_y,
		    CPG->color_Index, CPG->type_of_Line, CPG->type_of_Width,
		    X_Label, Y_Label, Title );
  free(data);
}


