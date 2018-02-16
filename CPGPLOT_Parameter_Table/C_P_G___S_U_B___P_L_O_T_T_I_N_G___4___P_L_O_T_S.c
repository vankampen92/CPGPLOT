#include <MODEL.h>

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___4___P_L_O_T_S( int SAME_PLOT, int No_of_POINTS, 
						      Parameter_Table * Table )
{
  /* Important Notice: 
     For this function call to work fine, proper X-axis and Y-axix scales should be 
     been defined for all plots */
  int k, kk;
  
  Parameter_Model * P = Table->P;
  
  for (k = 0; k<Table->SUB_OUTPUT_VARIABLES; k++) {
      cpgpanl(1, 1);
      cpgpanl(2, 1);
      
      kk = Table->IO_VARIABLE_LIST[k];  
      CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( P->CPG, SAME_PLOT, 
							    No_of_POINTS, 
							    P->CPG->x_Time, 
							    P->CPG->y_Time[0],
							    "Time",
							    Table->Variable_Name[kk], 
							    "",
							    1, 1 );
  }
}
