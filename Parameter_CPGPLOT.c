#include "CPGPLOT_HEADER.h"

#include "include.CPG.extern.h"

#if defined CPGPLOT_REPRESENTATION 
void  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___A_L_L_O_C (Parameter_CPGPLOT * C, 
						     int NO, int Time)
{
  int i;

  C->CPG_File = (Parameter_FILE *)malloc( 1 * sizeof(Parameter_FILE) );
  P_A_R_A_M_E_T_E_R___F_I_L_E___A_L_L_O_C( C->CPG_File );  

  C->y_Time   = (double **)calloc( NO, sizeof(double *) );
  for (i=0; i < NO; i++){
    C->y_Time[i] = (double *)calloc( Time, sizeof(double) );
  }
  C->x_Time   = (double *)calloc( Time, sizeof(double) );
}

void  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___U_P_L_O_A_D (Parameter_CPGPLOT * C)
{

  P_A_R_A_M_E_T_E_R___F_I_L_E___U_P_L_O_A_D ( C->CPG_File );

  C->CPG__PANEL__X = CPG__PANEL__X;
  C->CPG__PANEL__Y = CPG__PANEL__Y;

  C->CPG_SCALE_X         = CPG_SCALE_X; 
  C->CPG_RANGE_X_0       = CPG_RANGE_X_0;
  C->CPG_RANGE_X_1       = CPG_RANGE_X_1;

  C->CPG_SCALE_Y         = CPG_SCALE_Y;
  C->CPG_RANGE_Y_0       = CPG_RANGE_Y_0;
  C->CPG_RANGE_Y_1       = CPG_RANGE_Y_1;
 
  C->CPG_LINE_TYPES      = CPG_LINE_TYPES; 
  C->color_Index         = color_Index;
  C->type_of_Line        = type_of_Line; 
  C->type_of_Width       = type_of_Width; 
  C->type_of_Symbol      = type_of_Symbol;

  C->X_axis_Control      = X_axis_Control;
  C->Y_axis_Control      = Y_axis_Control;
  
  C->CPG_LABEL_TYPES     = CPG_LABEL_TYPES; 
  C->Title               = Title;
  C->X_label             = X_label; 
  C->Y_label             = Y_label; 
  
  C->W_label             = W_label;
  C->CPG_SCALE_W         = CPG_SCALE_W;
  C->CPG_RANGE_W_0       = CPG_RANGE_W_0;
  C->CPG_RANGE_W_1       = CPG_RANGE_W_1;

  C->y_GRID              = y_GRID; 
  C->x_GRID              = x_GRID; /* number of COLs (L__Y) and ROWs (L__X), respectively, in the final matrix represent  */
  C->X_Dimension         = X_Dimension;
  C->Y_Dimension         = Y_Dimension;
  C->ORIGIN_X            = ORIGIN_X; 
  C->ORIGIN_Y            = ORIGIN_Y;

  C->NC                  = NC;
  C->AUTOMATIC_CONTOUR   = AUTOMATIC_CONTOUR;

  C->CPG_DRIVER_NAME     = CPG_DRIVER_NAME;
  
  C->SIDE                  = SIDE;
  C->Type_of_COLOR_SHADING = Type_of_COLOR_SHADING;
  C->Type_of_BRIGHT        = Type_of_BRIGHT;
  C->Type_of_CONTRA        = Type_of_CONTRA;

	
}

void P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( Parameter_CPGPLOT * C, int NO)
{
  int i;

  P_A_R_A_M_E_T_E_R___F_I_L_E___F_R_E_E ( C->CPG_File );
  free(C->CPG_File);
  
  for (i=0; i<NO; i++){
    free (C->y_Time[i]);
  }
  free( C->y_Time );
  free( C->x_Time );
  free ( C );
}

Parameter_CPGPLOT * A_C_T_I_V_A_T_E___C_P_G_P_L_O_T (int No_of_OUTPUT_VARIABLES, 
						     int N, 
						     int cpgask_argument, 
						     char * cpgopen_argument )
{
   
  printf(" Maximum Number of Panels = %d\t Number of Subpanels = %d\n", 
	 No_of_OUTPUT_VARIABLES, CPG__PANEL__X * CPG__PANEL__Y);
  
  if( No_of_OUTPUT_VARIABLES > CPG__PANEL__X * CPG__PANEL__Y ){
    printf(" Warning!!!\n Not enough subpanels to draw this quantity of variables\n");
    printf(" in separate subplots\n");
    //Press_Key();
    /*   printf(" The program will exit\n"); */
    /*   exit(0); */
  }
  
  int DEVICE_NUMBER;
  DEVICE_NUMBER = cpgopen( cpgopen_argument );

  if (DEVICE_NUMBER <= 0 ) {
    printf(" Graphic device cannot be opened\n");
    exit(1);
  }
  
  printf(" Device Number: %d\n", DEVICE_NUMBER); 
  // getchar();

  cpgsubp(CPG__PANEL__X, CPG__PANEL__Y); /* Subdivision of the window in panels.
					    Automatic writing on consecutive panels
					    in CPG__PANEL__X  x  CPG__PANEL__Y grid 
					 */
  cpgask( cpgask_argument );

  printf(" Parameter_CPGPLOT structure will be allocated: \n");
  printf(" %d output variables of length %d points will allocated\n", No_of_OUTPUT_VARIABLES, N);
  Parameter_CPGPLOT * C = (Parameter_CPGPLOT *)malloc( 1 * sizeof(Parameter_CPGPLOT) );
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___A_L_L_O_C ( C, No_of_OUTPUT_VARIABLES, N );
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___U_P_L_O_A_D (C);

  C->DEVICE_NUMBER = DEVICE_NUMBER;
  
  return( C );
}
#endif
