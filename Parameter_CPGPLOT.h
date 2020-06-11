typedef struct Parameter_CPGPLOTinfo
{
  #include "include.CPG.global.h"

  float character_Size; /* Extra member to be passed between 
			   function using this structure */
  
  Parameter_FILE * CPG_File;

  
  
  double ** y_Time;
  double  * x_Time;
}Parameter_CPGPLOT;

void  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___A_L_L_O_C (Parameter_CPGPLOT * C, 
						     int NO, int Time);

void  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___U_P_L_O_A_D (Parameter_CPGPLOT * C);

void P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( Parameter_CPGPLOT * C, int NO );

Parameter_CPGPLOT * A_C_T_I_V_A_T_E___C_P_G_P_L_O_T (int No_of_OUTPUT_VARIABLES, 
						     int N, 
						     int cpgask_argument, 
						     char * cpgopen_argument );

void paramCommand_Line(FILE *fp, Parameter_CPGPLOT * CPG);

void modelReport(char *File, Parameter_CPGPLOT * CPG);

