/* This main function plots the electricity 
 * consumption of the house at St Pere 22 in Mieres
 * (Girona) for the four family units: Baixos (B), 
 * 1st apartment 1-1 (1), 2nd apartment 1-2 (2), and 
 * restaurant (R). The program reads the file of electricity 
 * consumption over time ('electricity.dat' in kWh).
 * It is a file with this structure: 
    
  time:    B    1    2   R
  ----  
  t_1:
  t_2:
  ...
  t_n:

  * The entries are separated by tabs and represent accumulated
  * electricity consumption in kWh. The time is in year units, but
  * there are 12 entries per year (one per month). The program reads
  * the file and stores the data in a matrix of dimensions (rows, columns)
  * The program also reads the file of the cost of electricity over time 
  * ('cost.dat' in EUR), with identical structure to the file of 
  * electricity consumption (columns are not labeled. First rows are
  * labeled by the the times in years). 

  * The program reads the cost of electricity from the last month
  * (in EURO), the accumulated consumption of the last month for the B, 
  * 1, and 2 family units, the total consummption for the last month in
  * three separated quantities (Punta, Vall, Pla, in kWh), and calculates 
  * the consumption of electricity for the restaurant. Then, the code 
  * adds an additional row to the file 'electricity.dat'. 
  * 
  * The program also calculates the bill for the last month for each 
  * family unit and the restaurant in proportion to the electricity
  * consumption of the last month. The programs adds a new row to the
  * file 'cost.dat' with the cost of electricity for the last month.

  * The program plots the electricity consumption over time 
  * of the four family units in the same panel, and also the
  * cost of electricity over time in a second panel. The program
  * uses the CPGPLOT library for plotting.
  * 
  * Specific Input arguments:
  * 
  * -Fn 2 -F0 electricity.dat -X0 20000 -Y0 4 -F1 cost.dat -X1 20000 -Y1 4
  * 
  * where X0 and X1 are the maximum number of rows in the files, 
  * and Y0 and Y1 are the number of columns in the files.
  * 
  * -AB [Accumulated Consumption in kWh for the B unit] 
  * -A1 [Accumulated Consumption in kWh for the 1 unit]
  * -A2 [Accumulated Consumption in kWh for the 2 unit]
  * 
  * -C0 [Cost of electricity in EURO for the last month]
  * 
  * -P0 [Punta consumption in kWh for the last month]
  * -V0 [Vall consumption in kWh for the last month]
  * -L0 [Pla consumption in kWh for the last month]
      
  * Compilation:
   ~$: make 

  * Execution:
     
   ~$ ./program -Fn 2 -F0 electricity.dat -X0 10000 -Y0 4 -F1 cost.dat -X1 10000 -Y1 4 \
                -AB 15173.6 -A1 7524.9 -A2 8157.9 -C0 173.47 -P0 135 -V0 132 -L0 400 \
                -G0 4 -G1 2 \ [Panel Control]
                -G2 1 -G3 0 -G4 1.0   -G5 1 -G6 0.0 -G7 0.5 \ [Axis Control] 
                -G10 1 \ [type of Line]
                -G11 2 \ [type of Width]
                -G12 0 \ [type of Symbol]
                -G13 1 \ [Labels is active]
                -G14 Title
                -G15 X axis Label
                -G16 Y axis Label
   It is very important to establish the axis ranks through the corresponding command line arguments 
   as in the example above. Your ranks will be active as long as you also introduce -G2 1 (x axis) 
   and G5 1 (y axis) --- as oposed to -G2 0 and -G5 0, which will shut down your axis rank choice. 
   In the latter case, the program calculates axis ranks automatically. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
/* 
 * The header file CPGPLOT_HEADER.h is a superheader file 
 * containing elaborated (hand-made), primitive cpgplot function
 * prototypes for plotting procedures and the defintion of new 
 * type 'Parameter_CPGPLOT', which a plotting structure passed down
 * to any plotting procedure. 
 * This header file is obligated when compiling with the libraries:
 * -lda_cpgplot_XY_GRID_FILE -lda_cpgplot_BASIC -lcpgplot -lpgplot
 */

/* Including CPGPLOT_HEADER.h for plotting utilities and custom plotting structures */
#include <CPGPLOT_HEADER.h>

#include "global.h"

double AB, A1, A2, C0, P0, V0, L0;

/* Functions used directly and only by main.c: */ 
void ArgumentControl(int , char ** );

// void X_Y_n___R_E_A_D___R_O_W_S ( char * , int * , int , double * , double ** );

/* 
void X_Y_n___R_E_A_D___R_O_W_S ( char * Name,
                                 int * No_of_POINTS_1, int No_of_POINTS_2,
                                 double * x_Data, 
                                 double ** y_Data )
{
  // This function reads and (x, y1, ..., yn) file (Name) 
  FILE * fp;
  double x;
  int j, n;

  // BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * *
  if( (fp = fopen(Name,"r") ) == NULL) {
    printf("File non-existent in current directory!!!\n --- Cannot open file.\n");
    exit(1);
  }

  n=0;
  while( fscanf(fp, "%lf\t", &x) != EOF ) { 

    x_Data[n] = x;

    for( j = 0; j < No_of_POINTS_2; j++ ){
      fscanf(fp, "%lf\t", &x);
      y_Data[j][n] = x; 
    }

    n++;
  }

  * No_of_POINTS_1 = n;

  fclose(fp);
  //   END : -------------------------------------------------------------*
}  
*/

int main (int argc, char **argv)
{
  FILE * fp; 
  int i; 
  
  #include "default.c"

    /* Command line arguments */
  if(argc>1) ArgumentControl(argc,argv);

  int No_of_PANELS = 2;
  int No_of_POINTS = 2;

  Parameter_CPGPLOT * CPG = A_C_T_I_V_A_T_E___C_P_G_P_L_O_T ( No_of_PANELS, No_of_POINTS, 0,
                                                              CPG_DRIVER_NAME );

  // printf("Plot Title:\t %s\n", CPG->Title);
  // printf("Plot X axis Label:\t %s\n", CPG->X_label);
  // printf("Plot Y axis Label:\t %s\n", CPG->Y_label);  
  printf(" Parameter_CPGPLOT data structure has been allocated and initiated\n");

  // printf("Enter and integer-valued number, M, please... ");
  // printf("It will be used to allocate the array of values in memory.\n");
  // scanf("%d", &M); 

  int M = 1000;   /* Maximum number of rows in the files */
           
  double *  year = (double *)calloc(M, sizeof(double));
  double ** accu = (double **)calloc(4, sizeof(double *));
  double ** cost = (double **)calloc(4, sizeof(double *));
  for (i=0; i<4; i++) {
    accu[i] = (double *)calloc(M, sizeof(double));
    cost[i] = (double *)calloc(M, sizeof(double));
  } 

  X_Y_n___R_E_A_D___R_O_W_S ( CPG->CPG_File->Name_of_FILE[0],
                              &M, 4, 
                              year, accu );         
  int No_of_MONTHS = M;

  assert(No_of_MONTHS == 1);

  F_I_L_E___X_Y_n___W_R_I_T_E ( stdout,
                                CPG->CPG_File->Name_of_FILE[0], 
                                1, 
                                year,  M,
                                accu, 4 );
                  
  X_Y_n___R_E_A_D___R_O_W_S ( CPG->CPG_File->Name_of_FILE[1],
                              &M, 4, 
                              year, cost );

  F_I_L_E___X_Y_n___W_R_I_T_E ( stdout,
                                CPG->CPG_File->Name_of_FILE[1], 
                                1, 
                                year, M,
                                cost, 4 );
	
  getchar();
  assert( No_of_MONTHS == M );

  /* (non-accumulated) monthly consumption and monthly cost */
  double * consum_fracction = (double *)calloc(4, sizeof(double));
  double ** consum = (double **)calloc(4, sizeof(double *));
  double ** mocost = (double **)calloc(4, sizeof(double *));
  for (i=0; i<4; i++) {
    consum[i] = (double *)calloc(No_of_MONTHS+1, sizeof(double));
    mocost[i] = (double *)calloc(No_of_MONTHS+1, sizeof(double));
  } 

  double Consum_Total = P0 + V0 + L0; /* Total Consumption in kWh */

  for (i=0; i<No_of_MONTHS; i++) {

    if(i > 0) {
      consum[0][i-1] = accu[0][i] - accu[0][i-1];
      consum[1][i-1] = accu[1][i] - accu[1][i-1];
      consum[2][i-1] = accu[2][i] - accu[2][i-1];
      consum[3][i-1] = accu[3][i] - accu[3][i-1];
    }
    else {
      consum[0][i] = 352.4;        /* Last Consumption Values (to plot) */
      consum[1][i] = 119.5;
      consum[2][i] = 64.0;
      consum[3][i] = accu[3][i];
    }

    mocost[0][i] = cost[0][i];
    mocost[1][1] = cost[1][i];
    mocost[2][i] = cost[2][i];
    mocost[3][i] = cost[3][i];
  }

  year[No_of_MONTHS] = year[No_of_MONTHS-1] + 1.0/12.0;
  consum[0][No_of_MONTHS] = AB - accu[0][No_of_MONTHS-1]; 
  consum[1][No_of_MONTHS] = A1 - accu[1][No_of_MONTHS-1];
  consum[2][No_of_MONTHS] = A2 - accu[2][No_of_MONTHS-1];
  consum[3][No_of_MONTHS] = Consum_Total - (consum[0][No_of_MONTHS] + consum[1][No_of_MONTHS] + consum[2][No_of_MONTHS]);

  assert(Consum_Total > 0.0);
  printf("Total Consumption in kWh: %g\n", Consum_Total);
  printf("\n");

  /* In use for the titles of the plots */
  char * Unit[4] = {"Baixos", "1-1", "1-2", "Restaurant"};
  
  for(i = 0; i<4; i++) {
    consum_fracction[i] = consum[i][No_of_MONTHS] / Consum_Total;
    mocost[i][No_of_MONTHS] = consum_fracction[i] * C0;

    printf("Consumption of electricity of the last month for %s unit: %g\n", Unit[i], consum[i][No_of_MONTHS]);
    printf("Fraction of electricity of the last month for %s unit: %g\n", Unit[i], consum_fracction[i]);  
    printf("Cost of electricity of the last month for %s unit: %g EUR\n", Unit[i], mocost[i][No_of_MONTHS]);
    printf("\n");
  }
  
  int SAME = 0;
  CPG->CPG_RANGE_X_0 = 2025.0;   CPG->CPG_RANGE_X_1 = 2026.0;
  CPG->CPG_RANGE_Y_0 = 0.0;      CPG->CPG_RANGE_Y_1 = 1000.0;
  CPG->CPG_SCALE_X = 1;          CPG->CPG_SCALE_Y = 1;

  for(i = 0; i<4; i++) {
    CPG->Title[0] = '\0'; // Effectively deleting previsously defined title 
    sprintf(CPG->Title, "Electricity Consumption over Time: %s unit", Unit[i]);

    // CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( ... );
    /* Default values: ACTIVATE!!! */ 
    CPG->color_Index    = 2 + i;
    CPG->type_of_Line = 1;
    CPG->type_of_Width = 8;  
    CPG->type_of_Symbol = 1 + i;
         
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG,
                                                            SAME,
                                                            No_of_MONTHS+1,
                                                            year,                                                                   
                                                            consum[i],
                                                            "Month", 
                                                            "Consumption (kWh)",
                                                            CPG->Title,
                                                            1, 1 );
  }  
  
  SAME = 0;
  CPG->CPG_RANGE_Y_0 = 0.0;      CPG->CPG_RANGE_Y_1 = 500.0;

  for(i = 0; i<4; i++) {
    CPG->Title[0] = '\0'; // Effectively deleting previsously defined title 
    sprintf(CPG->Title, "Electricity Cost over Time: %s unit", Unit[i]);

    // CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( ... );

    CPG->color_Index    = 2 + i;
    CPG->type_of_Line = 1;
    CPG->type_of_Width = 8;  
    CPG->type_of_Symbol = 1 + i;
    
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG,
                                                            SAME,
                                                            No_of_MONTHS+1,
                                                            year,                                                                   
                                                            mocost[i],
                                                            "Month", 
                                                            "Cost (EUR)",
                                                            CPG->Title, 
                                                            1, 1 );
  }   

  /* Saving the data in a file */  
   /* Adding a row to the existing file "cost.dat" */
  fp = fopen(CPG->CPG_File->Name_of_FILE[1], "a");
  fprintf(fp, "%g\t%g\t%g\t%g\t%g\n", year[No_of_MONTHS], 
                                      mocost[0][No_of_MONTHS], 
                                      mocost[1][No_of_MONTHS], 
                                      mocost[2][No_of_MONTHS], 
                                      mocost[3][No_of_MONTHS] );
  fclose(fp);

  /* Adding a row to the existing file "electricity.dat" (accumulated consumption) */
  fp = fopen(CPG->CPG_File->Name_of_FILE[0], "a");
  fprintf(fp, "%g\t%g\t%g\t%g\t%g\n", year[No_of_MONTHS], consum[0][No_of_MONTHS] + accu[0][No_of_MONTHS-1], 
                                                          consum[1][No_of_MONTHS] + accu[1][No_of_MONTHS-1], 
                                                          consum[2][No_of_MONTHS] + accu[2][No_of_MONTHS-1], 
                                                          consum[3][No_of_MONTHS] + accu[3][No_of_MONTHS-1] );
  fclose(fp);
  
  /* Saving Montly Consumption */
  fp = fopen("Monthly_Consumption.dat", "w");
  assert ( fp != NULL );
  F_I_L_E___X_Y_n___W_R_I_T_E ( fp,  "Monthly_Consumption", 1, year,  No_of_MONTHS+1, consum, 4 );
  fclose(fp);

  /* Freeing memory */
  for (i=0; i<4; i++) {
    free(accu[i]);
    free(cost[i]);
  } 
  free(year);
  free(accu);
  free(cost);
  
  for (i=0; i<4; i++) {
    free(consum[i]); 
    free(mocost[i]);
  } 
  free(consum_fracction);
  free(consum);
  free(mocost);

  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( CPG, No_of_PANELS );
  cpgclos();

  printf("\nEnd of progam\n");
  return(0);
}
