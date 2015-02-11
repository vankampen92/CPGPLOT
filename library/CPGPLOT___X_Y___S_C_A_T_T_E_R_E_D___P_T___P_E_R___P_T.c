#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */
     
void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___P_T___P_E_R___P_T ( Parameter_CPGPLOT * CPG,
							     int NO_of_POINTS, 
							     double * x_Data, double * y_Data,
							     int * color_Index, 
							     int * type_of_Symbol )
{
  int i;
  /* This function produces a simple (x, y) two-dimensional plot    */
  /* This function acts as a wrapper of cpg_XY_same_scattered (...) */
  /* Important Note: 
     This function only works properly if previously calls to box, labels and
     plot axes have been already done. 
  */
 
  float * xs = (float *)malloc( sizeof(float) * NO_of_POINTS );
  float * ys = (float *)malloc( sizeof(float) * NO_of_POINTS );

  /* BEGIN : Float converstion          */
  for(i=0; i<NO_of_POINTS; i++){ xs[i] = (float)x_Data[i]; ys[i] = (float)y_Data[i]; }
  /*   END : Float conversion completed */

  cpg_XY_same_scattered_pt_per_pt(NO_of_POINTS, xs, ys,
				  color_Index, type_of_Symbol);
  
  free(ys); free(xs);
}

