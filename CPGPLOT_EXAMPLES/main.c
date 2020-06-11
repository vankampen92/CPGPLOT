/* This main function plots two scatter plots and their 
   corresponding smoothing lines on a single plot.
  
   Data are given as 4 input files.    

   Compilation:
   ~$: make 
     
   Execution (if data files are read from directory, which is NOT the case in thi main code below unless you modify the program accordingly):

   ~$ ./PLOT -Fn 4 -F0 Name_of_File0.dat -F1 -F0 Name_of_File1.dat -F2 Name_of_File2.dat  -F3 Name_of_File3.dat -G0 1 -G1 1 -G2 1 -G3 1914 -G4 2009 -G5 1 -G6 0.0 -G7 1.0E-06

   Execution (if data are generated within the code, as in this main code below)
   
   ~$ ./PLOT -G0 2 -G1 2 -G2 1 -G3 0 -G4 6.0 -G5 1 -G6 0.0 -G7 1.0

   It is very important to establish the axis ranks through the corresponding command line arguments as in the example. Your ranks will be active as long as you also introduce -G2 1 (x axis) and G5 1 (y axis) --- as oposed to -G2 0 and -G5 0, which will shut down your axis rank choice. In the latter case, the program calculates rank axis automatically. 
*/
#include "main.h"

#include "global.h"

#define No_of_POINTS_MAX 10000
/* Model Parameters */
#define BETA_1    2.0 
#define BETA_2    4.0
#define BETA_MAX  6.0

#define GAMMA_1    2.0
#define GAMMA_2    3.0
#define GAMMA_MAX  6.0

int main (int argc, char **argv)
{
  int i, n, N;
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
  
  /* B E G I N : Generating 1st Curve Values */
  for(n=0; n<No_of_POINTS_MAX; n++) {
    x_Data[0][n] = (double)n * BETA_MAX  / (double)No_of_POINTS_MAX;
    if( x_Data[0][n] > GAMMA_1 )     y_Data[0][n] = 1 - GAMMA_1/x_Data[0][n];
    if( x_Data[0][n] > GAMMA_2 )     y_Data[1][n] = 1 - GAMMA_2/x_Data[0][n];
  }
  /*     E N D :                         */

  CPG->Title[0] = '\0'; // Effectively deleting previsously defined title
  char * p = strcat(CPG->Title, "Bifurcation Diagram");
  /* char * Num = (char *)calloc( 10, sizeof(char) ); */
  /* sprintf(Num, "%7d", 5195769); */
  /* p = strcat(CPG->Title, Num); */
  /* free(Num); */

  /* Just checking data are correctly read...         */
  /* printf("First Data Set\n");                      */
  /* for(n=0; n<No_of_POINTS_Data_0; n++)             */
  /*   printf( "Year: %4.3g\t Frequency: %4.3g\n",    */
  /* 	        x_Data[0][n], y_Data[0][n]);          */              
  /* printf("\n");                                    */
  
  int SAME_PLOT = 0;   
  CPG->color_Index    = 2;
  CPG->type_of_Line = 1;
  CPG->type_of_Width = 8;  
  CPG->type_of_Symbol = 1;  
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME_PLOT,
							No_of_POINTS_MAX,
							x_Data[0], y_Data[0],
							"Contact Rate (\\gb)", "Infected Population Fraction",
							CPG->Title,
							CPG->CPG_SCALE_X,
							CPG->CPG_SCALE_Y );
  //getchar(); 
  SAME_PLOT = 0; 
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME_PLOT,
							No_of_POINTS_MAX,
							x_Data[0], y_Data[1],
							"Contact Rate (\\gb)", "Infected Population Fraction",
							CPG->Title,
							CPG->CPG_SCALE_X,
							CPG->CPG_SCALE_Y );
  //getchar();
  /* B E G I N : Generating 2nd Curve Values */
  for(n=0; n<No_of_POINTS_MAX; n++) {
    x_Data[0][n] = (double)n * GAMMA_MAX  / (double)No_of_POINTS_MAX;
    if (BETA_1 > x_Data[0][n]) y_Data[0][n] = 1.0 - x_Data[0][n]/BETA_1;
    else y_Data[0][n] = 0;
    if (BETA_2 > x_Data[0][n]) y_Data[1][n] = 1.0 - x_Data[0][n]/BETA_2;
    else y_Data[1][n] = 0; 
  }
  /*     E N D :                         */

  SAME_PLOT = 0;
  CPG->color_Index  = 6;
  CPG->type_of_Line = 1;
  CPG->type_of_Width = 8;  
  CPG->type_of_Symbol = 1; 
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME_PLOT,
							No_of_POINTS_MAX,
							x_Data[0], y_Data[0], 
							"Recovery Rate (\\gg)", "Infected Population Fraction",
							CPG->Title,
							CPG->CPG_SCALE_X,
							CPG->CPG_SCALE_Y );
  //getchar();
  SAME_PLOT = 0; 
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME_PLOT,
							No_of_POINTS_MAX,
							x_Data[0], y_Data[1], 
							"Recovery Rate (\\gg)", "Infected Population Fraction",
							CPG->Title,
							CPG->CPG_SCALE_X,
							CPG->CPG_SCALE_Y );
  
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
