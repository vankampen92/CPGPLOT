#include "../CPGPLOT_HEADER.h"

void C_P_G___P_L_O_T_T_I_N_G___E_X_T_R_A___L_I_N_E (double x_1, double y_1,
                                                    double x_2, double y_2,
                                                    int color_Index,
                                                    int type_of_Line,
                                                    int type_of_Width,
                                                    int type_of_Symbol)
{
  float * X = (float *)calloc( 2, sizeof(float) );
  float * Y = (float *)calloc( 2, sizeof(float) );

  X[0] = (float)x_1;  X[1] = (float)x_2;
  Y[0] = (float)y_1;  Y[1] = (float)y_2;

  cpg_XY_same_plot(2, X, Y,
                   color_Index, type_of_Line, type_of_Width, type_of_Symbol );

  free(X); free(Y);
}

