#include "../CPGPLOT_HEADER.h"

void CPGPLOT___X_Y___H_I_S_T_O_G_R_A_M___N_O_R_M_A_L_I_Z_E_D ( int SAME, 
                                                               Parameter_CPGPLOT * CPG, 
							                                                 int NO_of_POINTS, 
                                                               double * x_DATA, int n_BINS,
							                                                 char * X_Label, 
                                                               char * Y_Label,  
                                                               char * Title, 
							                                                 int SCALE_X, int SCALE_Y,
                                                               int BAR )
{
  int i, n_Sum; 
  double x_i, x_s; 
  double * X  = (double *)calloc(n_BINS+1, sizeof(double));
  double * Pn = (double *)calloc(n_BINS+1, sizeof(double));
  
  double * x_RANGE = (double *)calloc(2, sizeof(double));
  float * x_Range  = (float *)calloc(2, sizeof(float));
                                      /* By default, if SCALE_X is 1 */ 
                                      /* 1 means: "Respect CPG predefined ranges" */
  x_RANGE[0] = CPG->CPG_RANGE_X_0;    /* By default, (x_i, x_s) are defined */
  x_RANGE[1] = CPG->CPG_RANGE_X_1;    /* through the corresponding range in 
                                         the CPG structure of Parameter_CPG 
                                         type 
                                      */
  A_X_E_S___R_A_N_G_E_S( NO_of_POINTS, x_DATA, x_RANGE, SCALE_X, 
                         x_Range );

  x_i = (double)x_Range[0]; 
  x_s = (double)x_Range[1];

  float step = (x_s - x_i)/(float)n_BINS;  

  x_i = x_i - step/(float)n_BINS;  /* Not excactly the natural x_i, x_s limits */
  x_s = x_s + step/(float)n_BINS;  /* but some extended limits by a little fraction   
                                      of step
                                   */
  cpg_histogram_x_axes(X, n_BINS, x_i, x_s);
  cpg_histogram_Pn_val(x_DATA, NO_of_POINTS, Pn, n_BINS, x_i, x_s);

  n_Sum = 0;
  for(i=0; i<n_BINS; i++)
    n_Sum += Pn[i];

  printf(" A No of Points (%d) has been distributed between\n", NO_of_POINTS);
  printf(" a minimum (%g) and a maximum (%g) value\n", x_i, x_s); 
  printf(" There are values (n = %d) lying outside this range\n", NO_of_POINTS-n_Sum);
  
  for(i=0; i<n_BINS; i++)
    Pn[i] /= (double)n_Sum;
  
  if (BAR == 0)
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME,
							                                            n_BINS, X, Pn, 
							                                            X_Label, Y_Label, Title,
							                                            SCALE_X, SCALE_Y );
  else 
    CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME,
							                                              n_BINS, X, Pn,  
							                                              X_Label, Y_Label, Title,
							                                              SCALE_X, SCALE_Y );                                                      

  free(x_RANGE);
  free(x_Range);
  free(X);
  free(Pn); 
}  
  

