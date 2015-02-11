#include "../CPGPLOT_HEADER.h"

void CPGPLOT___X_Y___P_L_O_T_T_I_N_G___2DIR___E_R_R_O_R___B_A_R_S ( Parameter_CPGPLOT * CPG,
								    int N,
								    double * x_Data, 
								    double ** xn_Data, 
								    double * y_Data, 
								    double ** yn_Data, 
								    int BAR_TIP_LENGTH )
{ 
  /* This function draws error bars both in the direccion of X and Y axis.
     It requires a previous definition of the plotting window as well as axis labels and 
     graph title. For instance, this should be achieved by previously calling:
     SAME = 0;
     CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E___P_L_O_T ( CPG, SAME,
                                                             N,
                                                             x_Data, y_Data,
							     X_label, Y_label, CPG->Title,
							     CPG_SCALE_X, CPG_SCALE_Y );
     Input arguments;
     . x_Data[i]: X_i data
     . y_Data[i]: Y_i data
     . xn_Data[0][i], xn_Data[1][i]: Inferior (Ex_0) and Superior Error (Ex_1) in the X direction 
     . yn_Data[0][i], yn_Data[1][i]: Inferior (Ey_0) and Superior Error (Ey_1) in the Y direction
    
     So, for intance, horizontal bar of (X, Y) point is a horizontal segment from (X-Ex_0, Y) to 
    (X+Ex_1, Y) :
    
  */
  int i;
    
  float * X = (float *)calloc( N, sizeof(float) );
  float * Y = (float *)calloc( N, sizeof(float) );
  float * E = (float *)calloc( N, sizeof(float) );
  
  for(i=0; i<N; i++) {
    X[i] = (float)x_Data[i];
    Y[i] = (float)y_Data[i];
  }

  int color_Index   = CPG->color_Index;
  int type_of_Line  = CPG->type_of_Line;
  int type_of_Width = CPG->type_of_Width;
  
  cpgsci(color_Index);  
  cpgslw(type_of_Width);
  cpgsls(type_of_Line); 

  for(i=0; i<N; i++) { E[i] = (float)xn_Data[0][i]; };
  cpgerrb(3, N, X, Y, E, BAR_TIP_LENGTH );

  for(i=0; i<N; i++) { E[i] = (float)xn_Data[1][i]; };
  cpgerrb(1, N, X, Y, E, BAR_TIP_LENGTH );

  for(i=0; i<N; i++) { E[i] = (float)yn_Data[0][i]; };
  cpgerrb(4, N, X, Y, E, BAR_TIP_LENGTH );

  for(i=0; i<N; i++) { E[i] = (float)yn_Data[1][i]; };
  cpgerrb(2, N, X, Y, E, BAR_TIP_LENGTH );
  
  cpgsci(1);
  cpgsls(1);            
  cpgslw(1);            
 
  free(X); free(Y); free(E);
}

