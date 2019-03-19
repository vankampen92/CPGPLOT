#include <MODEL.h>

/* The prototypes of the following functions are  
   defined in CPGPLOT___X_Y___Parameter_Table.h
*/
/* This file depends on previous definition of 
   Parameter_Table Structure, which is model specific, and
   it is done in a model specific header file (MODEL.h).  
*/ 
#define NO_TITLES
// #define STATIONARY_POINT_REPRESENTATION
// Alternatively, this variable definition controling compilation
// can also be defined in the corresponding make file.   

#if defined CPGPLOT_REPRESENTATION
void C_P_G___S_U_B___P_L_O_T_T_I_N_G___C_U_S_T_O_M_I_Z_E_D___T_I_T_L_E ( Parameter_Table * P,  
									 int NO, double * x_Time,
									 double ** y_Time, 
									 int Input_Parameter )
{
  /* CPG Representation: Time evolution of the array stored at y_Time[] */
  int i, j, k;
  char * p_Title;
  char * Number   = (char *)malloc( sizeof(char) * 50 );
  char * X_label  = (char *)malloc( sizeof(char) * 500 ); 
  char ** Y_label = (char **)malloc( sizeof(char *) * P->SUB_OUTPUT_VARIABLES );
  char * Title    = (char *)malloc( sizeof(char) * 500 );
  double X_RANGE[2];
  double ** Y_RANGE = (double **)calloc( P->SUB_OUTPUT_VARIABLES, sizeof(double *));
  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    Y_RANGE[i] = (double *)calloc(2, sizeof(double));
  }
  int SCALE_Y = P->CPG->CPG_SCALE_Y; 
  int SCALE_X = P->CPG->CPG_SCALE_X;
  C_P_G___S_C_A_L_E___F_I_X ( P, X_RANGE, Y_RANGE);
  
  label_Name(X_label, "Time");
  /*********************************************************************/
  for(i=0; i < P->SUB_OUTPUT_VARIABLES; i++){
    k = P->IO_VARIABLE_LIST[i]; 
    Y_label[i]  = P->Variable_Name[k]; 
  }

  double ** y_Stationarity = (double **)calloc( P->SUB_OUTPUT_VARIABLES, sizeof(double *) );
  for (i=0; i<P->SUB_OUTPUT_VARIABLES; i++){
    y_Stationarity[i] = (double *)calloc( NO, sizeof(double) );
  }

  for (i = 0; i < P->SUB_OUTPUT_VARIABLES; i++) {
    
    Title[0] = '\0';
#ifndef NO_TITLES    
    p_Title = strcat( Title, Y_label[i] );    
    p_Title = strcat( Title, ". Time Evolution" );
    p_Title = strcat( Title, P->Name_Parameters[Input_Parameter]);
    p_Title = strcat( Title, "  =  ");    
    double Value = AssignStructValue_to_VectorEntry( Input_Parameter, P );
    doubletochar( Value, Number );
    p_Title = strcat( Title, Number);
#else
    if( MODEL_PARAMETERS_MAXIMUM < 10 )
      sprintf(Title, "%s = %5.2f   %s = %5.2f   %s = %5.2f",
	      P->Symbol_Parameters[3],  P->Default_Vector_Parameters[3], 
	      P->Symbol_Parameters[7],  P->Default_Vector_Parameters[7], 
	      P->Symbol_Parameters[8],  P->Default_Vector_Parameters[8]); 
#endif
    
    
#if defined VERBOSE  
    printf("Title: %s\nX axes: %s\nY axes: %s\n\n", Title, X_label, Y_label[i]);
#endif
    
    P->CPG->type_of_Symbol = 1; P->CPG->color_Index = 4;  P->CPG->type_of_Line = 1; //P->CPG->type_of_Symbol = 9;
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_C_A_L_E ( P->CPG,
						  NO, x_Time, y_Time[i],    
						  X_label, Y_label[i], Title,
						  SCALE_X, SCALE_Y );
#if defined STATIONARY_POINT_REPRESENTATION   
    /* B E G I N :   Plotting the stationary assymptotic behavior      */    
    k =  P->IO_VARIABLE_LIST[i];
    /* L O W E R   S O L U T I O N : */
    y_Stationarity[i][0] = definition_OutPut_Variables(k, 
						       P->Vector_Model_Variables_MultiStability[0], 
						       0.0, P);
    for ( j = 1; j < NO; j++ ) y_Stationarity[i][j] = y_Stationarity[i][0]; 
 
    P->CPG->type_of_Symbol = 1; P->CPG->color_Index = 8; P->CPG->type_of_Line = 3;
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( P->CPG, 1,
						  NO, x_Time, y_Stationarity[i],    
						  X_label, Y_label[i], Title,
						  SCALE_X, SCALE_Y );
    /* U P P E R   S O L U T I O N : */
    y_Stationarity[i][0] = definition_OutPut_Variables(k, 
						       P->Vector_Model_Variables_MultiStability[2], 
						       0.0, P);
    for ( j = 1; j < NO; j++ ) y_Stationarity[i][j] = y_Stationarity[i][0]; 
 
    P->CPG->type_of_Symbol = 1; P->CPG->color_Index = 8; P->CPG->type_of_Line = 3;
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( P->CPG, 1,
						  NO, x_Time, y_Stationarity[i],    
						  X_label, Y_label[i], Title,
						  SCALE_X, SCALE_Y );
    /*     E N D : ----------------------------------------------------*/
#endif
  }
  /*********************************************************************/
  free (Title); free (Y_label); 
  
  for (i=0; i<P->SUB_OUTPUT_VARIABLES; i++){
    free (y_Stationarity[i]);
  }
  free( y_Stationarity );

  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    free (Y_RANGE[i]);
  }
  free( Y_RANGE );
} 

void C_P_G___S_U_B___P_L_O_T_T_I_N_G ( Parameter_Table * P,  
				       int NO, double * x_Time, double ** y_Time )
{
  /* CPG Representation: Time evolution of the array stored at y_Time[] */
  int i, k;
  char * p_Title;
  char * X_label  = (char *)malloc( sizeof(char) * 500 ); 
  char ** Y_label = (char **)malloc( sizeof(char *) * P->SUB_OUTPUT_VARIABLES );
  char * Title    = (char *)malloc( sizeof(char) * 500 );
  double X_RANGE[2];
  double ** Y_RANGE = (double **)calloc( P->SUB_OUTPUT_VARIABLES, sizeof(double *));
  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    Y_RANGE[i] = (double *)calloc(2, sizeof(double));
  }
  int SCALE_Y = P->CPG->CPG_SCALE_Y; 
  int SCALE_X = P->CPG->CPG_SCALE_X;
  C_P_G___S_C_A_L_E___F_I_X ( P, X_RANGE, Y_RANGE);
  
  label_Name(X_label, "Time");
  /*********************************************************************/
  for(i=0; i < P->SUB_OUTPUT_VARIABLES; i++){
    k = P->IO_VARIABLE_LIST[i]; 
    Y_label[i]  = P->Variable_Name[k]; 
  }
  for (i = 0; i < P->SUB_OUTPUT_VARIABLES; i++) {
    
    Title[0] = '\0';
    // p_Title = strcat( Title, Y_label[i] );    
    // p_Title = strcat( Title, ".    T i m e   E v o l u t i o n" );
#if defined VERBOSE  
    printf("Title: %s\nX axes: %s\nY axes: %s\n\n", Title, X_label, Y_label[i]);
#endif

    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_C_A_L_E ( P->CPG,
						  NO, x_Time, y_Time[i],    
						  X_label, Y_label[i], Title,
						  SCALE_X, SCALE_Y );

  }
  /*********************************************************************/
  free (Title); free (Y_label); 

  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    free (Y_RANGE[i]);
  }
  free( Y_RANGE );
} 

void C_P_G___P_H_A_S_E____D_I_A_G_R_A_M ( Parameter_Table * P,       
					  int k_0, int k_1,
					  int NO, double ** y_Time )
{
  /* Phase diagram output variable k_0 against output variable k_1  */
  /* Notice that:                */
  /* i_0 = P->IO_VARIABLE_LIST[k_0] */
  /* i_1 = P->IO_VARIABLE_LIST[k_1] */
  int no_OUTPUT_VARIABLES = P->SUB_OUTPUT_VARIABLES;
  int i, k;
  char * p_Title;
  char ** Y_label = (char **)malloc( sizeof(char *) * P->SUB_OUTPUT_VARIABLES );
  char * Title    = (char *)malloc( sizeof(char) * 500 );

  int i_0 = P->IO_VARIABLE_LIST[k_0];
  int i_1 = P->IO_VARIABLE_LIST[k_1];

  Y_label[0]  = P->Variable_Name[i_0]; 
  Y_label[1]  = P->Variable_Name[i_1];
 
  Title[0] = '\0';
  p_Title = strcat( Title, " P h a s e   D i a g r a m " );
  
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_C_A_L_E ( P->CPG,
						NO, y_Time[k_0], y_Time[k_1], 
						Y_label[0], Y_label[1], Title,
						P->CPG->CPG_SCALE_Y, P->CPG->CPG_SCALE_Y );
  free (Title); free (Y_label); 
}

void C_P_G___P_H_A_S_E____D_I_A_G_R_A_M___S_A_M_E ( Parameter_Table * P,
						    int SAME_PLOT,
						    int k_0, int k_1,
						    int NO, double ** y_Time )
{
  /* Phase diagram output variable k_0 against output variable k_1  */
  /* Notice that:                */
  /* i_0 = P->IO_VARIABLE_LIST[k_0] */
  /* i_1 = P->IO_VARIABLE_LIST[k_1] */
  int no_OUTPUT_VARIABLES = P->SUB_OUTPUT_VARIABLES;
  int i, k;
  char * p_Title;
  char ** Y_label = (char **)malloc( sizeof(char *) * P->SUB_OUTPUT_VARIABLES );
  char * Title    = (char *)malloc( sizeof(char) * 500 );

  int i_0 = P->IO_VARIABLE_LIST[k_0];
  int i_1 = P->IO_VARIABLE_LIST[k_1];

  Y_label[0]  = P->Variable_Name[i_0]; 
  Y_label[1]  = P->Variable_Name[i_1];
 
  Title[0] = '\0';
  p_Title = strcat( Title, " P h a s e   D i a g r a m " );
  
  cpgsch(0.5);                        /* Character size control */
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T( P->CPG, 
						       SAME_PLOT,
						       NO, y_Time[k_0], y_Time[k_1], 
						       Y_label[0], Y_label[1], Title,
						       P->CPG->CPG_SCALE_Y, 
						       P->CPG->CPG_SCALE_Y );

  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___A_R_R_O_W( P->CPG,
 							SAME_PLOT,
 							NO, y_Time[k_0], y_Time[k_1],
 							Y_label[0], Y_label[1], Title,
 							P->CPG->CPG_SCALE_Y,
 							P->CPG->CPG_SCALE_Y );
  cpgsch(1.0);                        /* Character size control */
  
  free (Title); free (Y_label); 
}


void C_P_G___S_U_B___P_L_O_T_T_I_N_G___D_U_A_L ( Parameter_Table * P,  
						 int NO, double * x_Time, double ** y_Time )
{
  /* CPG Representation: Time evolution of the array stored at y_Time[] */
  /* This function differs from the simpler C_P_G___S_U_B___P_L_O_T_T_I_N_G () just 
     in the fact that each variable is followed by a companion variable that appears
     represented in the same plot for comparisons purposes
  */
  int i, k;
  char * p_Title;
  char * X_label  = (char *)malloc( sizeof(char) * 500 ); 
  char ** Y_label = (char **)malloc( sizeof(char *) * P->SUB_OUTPUT_VARIABLES );
  char * Title    = (char *)malloc( sizeof(char) * 500 );
  double X_RANGE[2];
  double ** Y_RANGE = (double **)calloc( P->SUB_OUTPUT_VARIABLES, sizeof(double *));
  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    Y_RANGE[i] = (double *)calloc(2, sizeof(double));
  }
  int SCALE_Y = P->CPG->CPG_SCALE_Y; 
  int SCALE_X = P->CPG->CPG_SCALE_X;
  C_P_G___S_C_A_L_E___F_I_X ( P, X_RANGE, Y_RANGE);
  
  label_Name(X_label, "Time");
  /*********************************************************************/
  for(i=0; i < P->SUB_OUTPUT_VARIABLES; i++){
    k = P->IO_VARIABLE_LIST[i]; 
    Y_label[i]  = P->Variable_Name[k]; 
  }
  for (i = 0; i < P->SUB_OUTPUT_VARIABLES; i++) {
    
    Title[0] = '\0';
    p_Title = strcat( Title, Y_label[i] );    
    p_Title = strcat( Title, ".    T i m e   E v o l u t i o n" );
    
    printf("Title: %s\nX axes: %s\nY axes: %s\n\n", Title, X_label, Y_label[i]);
    
    if( i%2 == 0 ) {
      CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_C_A_L_E ( P->CPG,
						    NO, x_Time, y_Time[i], 
						    X_label, Y_label[i], Title,
						    SCALE_X, SCALE_Y );
    }
    else{
      CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( P->CPG,
							    1,
							    NO, x_Time, y_Time[i],
							    X_label, Y_label[i], Title,
                                                            SCALE_X, SCALE_Y ) ;
    } 
  }
  /*********************************************************************/
  free (Title); free (Y_label); 

  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    free (Y_RANGE[i]);
  }
  free( Y_RANGE );
} 

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( int REPLICATE, 
							   Parameter_Table * P,  
							   int NO, double * x_Time, double ** y_Time )
{
  /* CPG Representation: Time evolution of the array stored at y_Time[] */
  int no_OUTPUT_VARIABLES = P->SUB_OUTPUT_VARIABLES;
  int i, k;
  char * p_Title;
  char * X_label  = (char *)malloc( sizeof(char) * 500 ); 
  char ** Y_label = (char **)malloc( sizeof(char *) * P->SUB_OUTPUT_VARIABLES );
  char * Title    = (char *)malloc( sizeof(char) * 500 );
  double X_RANGE[2];
  double ** Y_RANGE = (double **)calloc( P->SUB_OUTPUT_VARIABLES, sizeof(double *));
  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    Y_RANGE[i] = (double *)calloc(2, sizeof(double));
  }

  /* BEGIN: Scale defintions  */
  /* SCALE_* = 0 (fixed scale)  / SCALE_* = 1 (dynamic scale) */
  int SCALE_Y = P->CPG->CPG_SCALE_Y; 
  int SCALE_X = P->CPG->CPG_SCALE_X;
  C_P_G___S_C_A_L_E___F_I_X ( P, X_RANGE, Y_RANGE );
                       //  SCALE__ = 1 (fixed scale)  / SCALE__ = 0 (dynamic scale)
                       //  Note: If Ranges are dynamic no default ranges
                       //        need to be defined here
                       //  Otherwise, this part need to be adapted for
                       //  every purpose.
  /*   END: Scale definitions */

  label_Name(X_label, "Time");
  /*********************************************************************/
  for(i=0; i < P->SUB_OUTPUT_VARIABLES; i++){
    k = P->IO_VARIABLE_LIST[i]; 
    Y_label[i]  = P->Variable_Name[k]; 
  }
  for (i = 0; i < P->SUB_OUTPUT_VARIABLES; i++) {
	
    Title[0] = '\0';
    p_Title = strcat( Title, Y_label[i] );    
    p_Title = strcat( Title, ".    T i m e   E v o l u t i o n" );
    
    printf("Title: %s\nX axes: %s\nY axes: %s\n\n", Title, X_label, Y_label[i]);

    //Y_RANGE[i][0] =0.0; Y_RANGE[i][1] =1.0;  
    
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( P->CPG,
                                                          REPLICATE,
                                                          NO, x_Time, y_Time[i],
							  X_label, Y_label[i], Title,
							  SCALE_X, SCALE_Y );
  }
  /*********************************************************************/
  free (Title); free (Y_label); 

  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    free (Y_RANGE[i]);
  }
  free( Y_RANGE );
} 

void C_P_G___S_C_A_L_E___F_I_X ( Parameter_Table * P,
				 double * X_RANGE,  double ** Y_RANGE)
{
  int no_OUTPUT_VARIABLES = P->SUB_OUTPUT_VARIABLES;
/* BEGIN: Scale defintions  */
  /* SCALE__ = 0 (fixed scale)  / SCALE__ = 1 (dynamic scale) */
  int i;
  int SCALE_Y = P->CPG->CPG_SCALE_Y; 
  int SCALE_X = P->CPG->CPG_SCALE_X;

  if ( SCALE_Y == 1 ) {
    for( i=0; i<no_OUTPUT_VARIABLES; i++){
       Y_RANGE[i][0] = P->CPG->CPG_RANGE_Y_0; 
       Y_RANGE[i][1] = P->CPG->CPG_RANGE_Y_1; 
    }
  }
  if ( SCALE_X == 1 ) {
    X_RANGE[0] = P->CPG->CPG_RANGE_X_0; 
    X_RANGE[1] = P->CPG->CPG_RANGE_X_1; 
  }
  /* int SCALE_X = 0;     X_RANGE[0]    = P->T->Time_0;  */
  /*                      X_RANGE[1]    = P->T->Time_1; */
  /*   END: Scale definitions */
}

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R ( Parameter_Table * P, int SAME_PLOT, 
							   int NO, double * x_Time,
							   double ** y_Time,
							   double ** y_Error)
{
  /* CPG Representation: Time evolution of the array stored at y_Time[] */
  int Horizontal_Plot_Position;
  int Vertical_Plot_Position;
  int i, k;
  char * p_Title;
  char * X_label  = (char *)malloc( sizeof(char) * 500 ); 
  char ** Y_label = (char **)malloc( sizeof(char *) * P->SUB_OUTPUT_VARIABLES );
  char * Title    = (char *)malloc( sizeof(char) * 500 );
  double X_RANGE[2];
  double ** Y_RANGE = (double **)calloc( P->SUB_OUTPUT_VARIABLES, sizeof(double *));
  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    Y_RANGE[i] = (double *)calloc(2, sizeof(double));
  }
  
  /* BEGIN: Scale defintions  */
  int SCALE_Y = P->CPG->CPG_SCALE_Y; 
  int SCALE_X = P->CPG->CPG_SCALE_X;
  C_P_G___S_C_A_L_E___F_I_X ( P, X_RANGE, Y_RANGE );
                       //  SCALE__ = 0 (fixed scale)  / SCALE__ = 1 (dynamic scale)
                       //  Note: If Ranges are dynamic no default ranges
                       //        need to be defined here
                       //  Otherwise, this part need to be adapted for
                       //  every purpose.
  /*   END: Scale definitions */

  label_Name(X_label, "Time");
  /*********************************************************************/
  for(i=0; i < P->SUB_OUTPUT_VARIABLES; i++){
    k = P->IO_VARIABLE_LIST[i]; 
    Y_label[i]  = P->Variable_Name[k]; 
  }

  P->CPG->type_of_Width       = 4;
  cpgslct(P->CPG->DEVICE_NUMBER);
  Title[0] = '\0';
  for (i = 0; i < P->SUB_OUTPUT_VARIABLES; i++) {
       
    if (SAME_PLOT == 0 ) {
      if( MODEL_PARAMETERS_MAXIMUM < 10 )
      sprintf(Title, "%s = %5.2f   %s = %5.2f   %s = %5.2f",
	      P->Symbol_Parameters[3],  P->Default_Vector_Parameters[3], 
	      P->Symbol_Parameters[7],  P->Default_Vector_Parameters[7], 
	      P->Symbol_Parameters[8],  P->Default_Vector_Parameters[8]);  
    }
    if (SAME_PLOT > 0) {
      if (P->CPG->CPG__PANEL__X > 0 && P->CPG->CPG__PANEL__Y > 0 ){	
	Horizontal_Plot_Position  = i%P->CPG->CPG__PANEL__X + 1;
	Vertical_Plot_Position    = i/P->CPG->CPG__PANEL__X + 1;
      }
      else {	
	Vertical_Plot_Position    = i%abs(P->CPG->CPG__PANEL__Y) + 1;
	Horizontal_Plot_Position  = i/abs(P->CPG->CPG__PANEL__Y) + 1;
      }
      cpgpanl(Horizontal_Plot_Position, Vertical_Plot_Position);
      P->CPG->color_Index         = 5;

      printf("k = %d\t Horizontal Position = %d\t Vertical Position = %d\n",
      	 i, Horizontal_Plot_Position, Vertical_Plot_Position);
      Press_Key(); 
    }
    
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( P->CPG, SAME_PLOT, 
							  NO, x_Time, y_Time[i],
							  X_label, Y_label[i], Title, 
							  SCALE_X, SCALE_Y );
    
    cpg_XY_plot_error_bar( NO, x_Time, y_Time[i], y_Error[i]);
  }
  /*********************************************************************/
  free (Title); free (Y_label);   

  for(i = 0; i<P->SUB_OUTPUT_VARIABLES; i++){
    free (Y_RANGE[i]);
  }
  free( Y_RANGE );
} 

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R___D_R_I_V_E_R ( int DATA_POINTS,
									 Parameter_Table * Table)
{
  
  int DEVICE_NUMBER = cpgopen("/XSERVE");
  if (DEVICE_NUMBER <= 0 ) {
    printf(" Graphic device cannot be opened\n");
    exit(1);
  }
  // printf(" PANEL__X = %d\tPANEL__Y = %d\n",   Table->CPG__PANEL__X, Table->CPG__PANEL__Y);
  cpgsubp(Table->CPG__PANEL__X, Table->CPG__PANEL__Y);
  cpgask(0);
  C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R ( Table, 0, DATA_POINTS,
                                                        Table->T->time_DEF,
                                                        Table->T->AVE,
							Table->T->VAR );
}

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___n___P_L_O_T_S(int No_of_DEVICE, 
						     int SAME_PLOT, int No_of_POINTS, 
						     Parameter_Table * Table )
{
  /* Important Notice: 
     For this function call to work fine, proper X-axis and Y-axix scales should be 
     been defined for all plots */
  int k, kk;
  float x_Time_Position, y_Time_Position, char_Size;
  int Horizontal_Plot_Position;
  int Vertical_Plot_Position;
   Parameter_Model * P     = Table->P;
  Parameter_CPGPLOT * CPG = P->CPG;    /* Please, make sure that 
					  Table->CPG_STO has been initialized and 
					  P->CPG points to this structure */ 
  static double Current_Time = 0.0; 
  double Last_Time;
  
  char * Plot_Title = (char *)calloc( 100, sizeof(char));
  char * Plot_Time  = (char *)calloc( 50, sizeof(char));
  char * Time_Eraser = (char *)calloc(50, sizeof(char));  

  x_Time_Position = 0.90 * (float)CPG->CPG_RANGE_X_1; 
  y_Time_Position = 0.90 * (float)CPG->CPG_RANGE_Y_1;
  
  if( Table->SUB_OUTPUT_VARIABLES > CPG->CPG__PANEL__X * CPG->CPG__PANEL__Y ){
    printf(" Warning!!!\n Not enough subpanels to draw this quantity of variables\n");
    printf(" in separate subplots\n");
    Press_Key();
    printf(" The program will exit\n");
    exit(0);
  }
  Plot_Title[0] ='\0';
  sprintf(Plot_Title, "Realization = %d\tTime = %5.2f", SAME_PLOT, Current_Time);
  
  Last_Time     = Current_Time; 
  Current_Time  = Table->P->CPG->x_Time[No_of_POINTS-1];
  sprintf(Plot_Time, "Time = %5.2f", Current_Time);
  sprintf(Time_Eraser, "Time = %5.2f", Last_Time);  

#if defined VERBOSE  
  printf("Realization = %d\tTime = %5.2f\n", SAME_PLOT, Current_Time);
  Press_Key();
#endif   
  
  CPG->type_of_Width       = 4;   
  cpgslct(No_of_DEVICE);
  Plot_Title[0]  = '\0';
  
  for (k = 0; k<Table->SUB_OUTPUT_VARIABLES; k++) {
    
    if (SAME_PLOT == 0 ) {
      if( MODEL_PARAMETERS_MAXIMUM < 10 )
      sprintf(Plot_Title, "%s = %5.2f   %s = %5.2f   %s = %5.2f",
	      Table->Symbol_Parameters[3],  Table->Default_Vector_Parameters[3], 
	      Table->Symbol_Parameters[7],  Table->Default_Vector_Parameters[7], 
	      Table->Symbol_Parameters[8],  Table->Default_Vector_Parameters[8]); 
    }
    
    if (SAME_PLOT > 0) {
      if (CPG->CPG__PANEL__X > 0 && CPG->CPG__PANEL__Y > 0 ){
	Horizontal_Plot_Position  = k%CPG->CPG__PANEL__X + 1;
	Vertical_Plot_Position    = k/CPG->CPG__PANEL__X + 1;
      }
      else {
	Vertical_Plot_Position    = k%abs(CPG->CPG__PANEL__Y) + 1;
	Horizontal_Plot_Position  = k/abs(CPG->CPG__PANEL__Y) + 1;;
      }
      cpgpanl(Horizontal_Plot_Position, Vertical_Plot_Position);
      CPG->color_Index         = (2 + SAME_PLOT)%10;

      // printf("k = %d\t Horizontal Position = %d\t Vertical Position = %d\n",
      //	 k, Horizontal_Plot_Position, Vertical_Plot_Position);
      // Press_Key(); 
    }
    
    kk = Table->IO_VARIABLE_LIST[k];
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME_PLOT, 
							  No_of_POINTS, 
							  CPG->x_Time, 
							  CPG->y_Time[k],
							  "Time",
							  Table->Variable_Name[kk], 
							  Plot_Title,
							  1, 1 );
    cpgqch(&char_Size);
    cpgsch(2.0);
    cpgsci(0); 
    cpgptxt(x_Time_Position, y_Time_Position, 0.0, 1.0, Time_Eraser);
    cpgsci(1); 
    cpgptxt(x_Time_Position, y_Time_Position, 0.0, 1.0, Plot_Time);
    cpgsch(char_Size); 
  }

  free(Plot_Title); free(Plot_Time); free(Time_Eraser); 
}
#endif 
