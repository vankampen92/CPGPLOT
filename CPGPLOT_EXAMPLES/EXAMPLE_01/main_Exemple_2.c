/* This main function plots a family of functions, as 
 * defined in the code. It is an example of the use of
 * the library function: 
 *
 * CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T(...).
 *
 * and how to use the input arguments that control it, 
 * including axes ranks, subplots, etc. 
 */
 /*
   Data may be given as 4 input files.    

   Compilation:
   ~$: make 
     
   Execution (if data files are read from directory, which is NOT the case in thi main code below unless you modify the program accordingly):

   ~$ ./PLOT -Fn 4 -F0 Name_of_File0.dat -F1 -F0 Name_of_File1.dat -F2 Name_of_File2.dat  -F3 Name_of_File3.dat -G0 1 -G1 1 -G2 1 -G3 1914 -G4 2009 -G5 1 -G6 0.0 -G7 1.0E-06

   Execution (if data are generated within the code, as this is the case for the main code below)
   
   ~$ ./PLOT -G0 1 -G1 1 -G2 1 -G3 0 -G4 20.0 -G5 1 -G6 0.0 -G7 100.0 -G10 [type_of_Line] -G11 [type_of_Width] -G12 [type_of_Symbol]
   ~$ ./PLOT -G0 1 -G1 1 -G2 1 -G3 0 -G4 20.0 -G5 1 -G6 0.0 -G7 100.0 -G10 1 -G11 2 -G12 5

   Notice that the values of -G10 [type_of_Line] -G11 [type_of_Width] -G12 [type_of_Symbol] may be overwritten by the main code!!! 

   It is very important to establish the axis ranks through the corresponding command line arguments as in the example. 
   Your ranks will be active as long as you also introduce -G2 1 (x axis) and G5 1 (y axis) --- as oposed to -G2 0 and -G5 0, 
   which will shut down your axis rank choice. In the latter case, the program calculates rank axes automatically. 
 */
#include "main.h"

#include "global.h"

#define No_of_POINTS_MAX 10000
/* Model Parameters */
#define ETA_MAX          8.0
#define ETA_MIN          0.5

#define DELTA            1.0
#define DELTA_A          0.5
#define Z_0              0.8
#define No_of_STRATEGIES 100

int main (int argc, char **argv)
{
  int i, n, m, N;
  Parameter_CPGPLOT * CPG;
  int colors[3] = {2,12,8};
  float x_SP[2], y_SP[2];
  float x, y, d;
  
#include "default.c"

 /* Command line arguments */
  if(argc>1) ArgumentControl(argc,argv);
  int No_of_PANELS = 1;
  int No_of_POINTS = 2;
  CPG = A_C_T_I_V_A_T_E___C_P_G_P_L_O_T ( No_of_PANELS, No_of_POINTS, 0,
                                          CPG_DRIVER_NAME );
  printf(" Parameter_CPGPLOT data structure has been allocated and initiated\n");

  double ** x_Data = (double **)calloc( 2, sizeof(double *) );
  double ** y_Data = (double **)calloc( 2, sizeof(double *) );
  for(i=0; i<2; i++) {
    x_Data[i] = (double *)calloc( No_of_POINTS_MAX, sizeof(double) );
    y_Data[i] = (double *)calloc( No_of_POINTS_MAX, sizeof(double) );
  }

  /* int No_of_POINTS_Data_0, No_of_POINTS_Data_1; */
  /* int No_of_POINTS_Fit_0, No_of_POINTS_Fit_1; */
  
  /* X_Y___R_E_A_D ( CPG->CPG_File->Name_of_FILE[0],   */
  /* 		  x_Data[0],  */
  /* 		  y_Data[0],  */
  /* 		  &No_of_POINTS_Data_0); */

  /* X_Y___R_E_A_D ( CPG->CPG_File->Name_of_FILE[2],   */
  /* 		  x_Data[1],  */
  /* 		  y_Data[1],  */
  /* 		  &No_of_POINTS_Data_1); */

  /* X_Y___R_E_A_D ( CPG->CPG_File->Name_of_FILE[1],   */
  /* 		  x_Fit[0],  */
  /* 		  y_Fit[0],  */
  /* 		  &No_of_POINTS_Fit_0); */

  /* X_Y___R_E_A_D ( CPG->CPG_File->Name_of_FILE[3],   */
  /* 		  x_Fit[1],  */
  /* 		  y_Fit[1],  */
  /* 		  &No_of_POINTS_Fit_1); */

  /* Just checking data are correctly read...         */
  /* printf("First Data Set\n");                      */
  /* for(n=0; n<No_of_POINTS_Data_0; n++)             */
  /*   printf( "Year: %4.3g\t Frequency: %4.3g\n",    */
  /* 	        x_Data[0][n], y_Data[0][n]);          */              
  /* printf("\n");                                    */
  
  double Eta_Threshold_Min, Eta_Threshold_Max;
  double C, Beta, Eta, Delta, Delta_A, z_0, Offset;
  int S;
  S       = No_of_STRATEGIES; 
  z_0     = Z_0;     /* Free space at equilibrium */
  Delta   = DELTA;
  Delta_A = DELTA_A;
  Offset  = 0.001; 
  
  Eta_Threshold_Min = CPG->CPG_RANGE_X_0 + Offset;  
  Eta_Threshold_Max = CPG->CPG_RANGE_X_1;
  assert(Eta_Threshold_Max > Eta_Threshold_Min); 

  /* B E G I N : Generating 1st Curve Values */
  for(n=0; n<No_of_POINTS_MAX; n++) {
    x_Data[0][n] = Eta_Threshold_Min + (double)n / (double)No_of_POINTS_MAX * (Eta_Threshold_Max - Eta_Threshold_Min);
    y_Data[0][n] = ( 1.0 + DELTA / (z_0*x_Data[0][n]) ) * DELTA_A; 

    Eta  = x_Data[0][n];
    Beta = y_Data[0][n];
    
    C = (Delta * Delta_A) / (Beta - Delta_A) / Eta;

    printf(" z_0 = %.2g\t z_0 = %.2g\n", z_0, C);
    
    assert(C < 1.0); 
  }
  /*     E N D :                         */
  
  CPG->Title[0] = '\0'; // Effectively deleting previsously defined title
  char * p = strcat(CPG->Title, "Propagule Production vs Propagule Establishment Tradeoff");
  CPG->Title[0] = '\0'; // Effectively deleting previsously defined title

  int SAME_PLOT = 0;   
  CPG->color_Index    = 2;
  CPG->type_of_Line = 1;
  CPG->type_of_Width = 8;  
  CPG->type_of_Symbol = 1;  
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME_PLOT,
							No_of_POINTS_MAX,
							x_Data[0], y_Data[0],
							"Establishment Rate (\\gy)",
							"Production Rate (\\gb)",
							CPG->Title,
							CPG->CPG_SCALE_X,
							CPG->CPG_SCALE_Y );
  getchar(); 

  /* Representing the No_of_STRATEGIES strategies on the tradeoff curve */
  for(n=0; n<S; n++) {
    x_Data[1][n] = ETA_MIN + (double)n/(double)(S-1) * (ETA_MAX - ETA_MIN);
    y_Data[1][n] = ( DELTA + z_0 * x_Data[1][n] ) / ( z_0 * x_Data[1][n] ) * DELTA_A; 

    Eta  = x_Data[1][n];
    Beta = y_Data[1][n];
    
    C = (Delta * Delta_A) / (Beta - Delta_A) / Eta;

    assert(C < 1.0);
   
    printf("Delta = %.2g\tDelta_A = %.2g\tz_0 = %.2g\tBeta = %.2g\tEta = %.2g\t C = %.2g < 1.0\n",
	   Delta, Delta_A, z_0, Beta, Eta, C);  
  }
	  
  x_Data[0][0] = x_Data[1][0];
  y_Data[0][0] = y_Data[1][0];  
    
  x_Data[0][1] = x_Data[1][1];
  y_Data[0][1] = y_Data[1][1];  
  
  x_Data[0][2] = x_Data[1][2];
  y_Data[0][2] = y_Data[1][2];  
  
  x_Data[0][3] = x_Data[1][10];
  y_Data[0][3] = y_Data[1][10];  
    
  x_Data[0][4] = x_Data[1][20];
  y_Data[0][4] = y_Data[1][20];  
    
  x_Data[0][5] = x_Data[1][30];
  y_Data[0][5] = y_Data[1][30];  
    
  x_Data[0][6] = x_Data[1][40];
  y_Data[0][6] = y_Data[1][40];

  x_Data[0][7] = x_Data[1][50];
  y_Data[0][7] = y_Data[1][50];  
    
  x_Data[0][8] = x_Data[1][60];
  y_Data[0][8] = y_Data[1][60];  
    
  x_Data[0][9] = x_Data[1][70];
  y_Data[0][9] = y_Data[1][70];  
  
  x_Data[0][10] = x_Data[1][80];
  y_Data[0][10] = y_Data[1][80];  
    
  x_Data[0][11] = x_Data[1][90];
  y_Data[0][11] = y_Data[1][90];  
    
  x_Data[0][12] = x_Data[1][S-1];
  y_Data[0][12] = y_Data[1][S-1];
  /*
  SAME_PLOT = 1;
  CPG->color_Index  = 7;
  CPG->type_of_Line = 1;
  CPG->type_of_Width = 8;  
  CPG->type_of_Symbol = 5;  
  CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E___P_L_O_T ( CPG,
							  SAME_PLOT,
							  S, x_Data[1], y_Data[1],
							  "Establishment Rate (\\gc)",
							  "Production Rate (\\gb)",
							  CPG->Title,
							  CPG->CPG_SCALE_X,
							  CPG->CPG_SCALE_Y );
  */

  SAME_PLOT = 1;
  CPG->color_Index  = 7;
  CPG->type_of_Line = 1;
  CPG->type_of_Width = 8;  
  CPG->type_of_Symbol = 5;
  m = 13;   
  CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E___P_L_O_T ( CPG,
							  SAME_PLOT,
							  m, x_Data[0], y_Data[0],
							  "Establishment Rate (\\gc)",
							  "Production Rate (\\gb)",
							  CPG->Title,
							  CPG->CPG_SCALE_X,
							  CPG->CPG_SCALE_Y );
  SAME_PLOT = 1;
  CPG->color_Index  = 1;
  CPG->type_of_Line = 1;
  CPG->type_of_Width = 8;  
  CPG->type_of_Symbol = 25;
  m = 13;   
  CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E___P_L_O_T ( CPG,
							  SAME_PLOT,
							  m, x_Data[0], y_Data[0],
							  "Establishment Rate (\\gc)",
							  "Production Rate (\\gb)",
							  CPG->Title,
							  CPG->CPG_SCALE_X,
							  CPG->CPG_SCALE_Y );

  /* Drawing the horizontal assymptotes (broken lines) */
  double x_1, y_1, x_2, y_2; 
  /* Horizontal */
  x_1 = 0.0;                       y_1 = DELTA_A;
  x_2 = CPG->CPG_RANGE_X_1;        y_2 = DELTA_A;
  SAME_PLOT = 1;
  CPG->color_Index  = 1;
  CPG->type_of_Line = 3;
  CPG->type_of_Width = 4;  
  CPG->type_of_Symbol = 1;
  C_P_G___P_L_O_T_T_I_N_G___E_X_T_R_A___L_I_N_E (x_1, y_1,
                                                 x_2, y_2,
                                                 CPG->color_Index,
                                                 CPG->type_of_Line,
                                                 CPG->type_of_Width,
                                                 CPG->type_of_Symbol);
  
  for(i=0; i<2; i++) {
    free(x_Data[i]);
    free(y_Data[i]);

  }
  free(x_Data); free(y_Data); 
  
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( CPG, No_of_PANELS );
  cpgclos();

  printf("\nEnd of progam\n");
  return(0);
}
