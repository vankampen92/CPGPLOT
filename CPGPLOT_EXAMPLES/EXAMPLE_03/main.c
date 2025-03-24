/* This main function plots normalized histrograms 
 * in several examples (random numbers and 
 * random distributions) or from files given as input
 * arguments of the main programs histogram.
 

   Compilation:
   ~$: make 

   Execution:
   If there is no file to read:  
   ~$ ./program -G0 1 -G1 1 -G2 1 -G3 0 -G4 1.0 -G5 1 -G6 0.0 -G7 0.5

   If there is a pre-existing file to read:  
   ~$ ./program -G0 1 -G1 1 \
                -G2 1 -G3 0 -G4 1.0 -G5 1 -G6 0.0 -G7 0.5 \
                -Fn 1 -F0 MLE_0_HII.dat -X0 20000 -Y1 2 \
                -G10 1 \ [type of Line]
                -G11 2 \ [type of Width]
                -G12 0 \ [type of Symbol]
                -G13 1 \ [Labels is active]
                -G14 Title
                -G15 X axis Label
                -G16 Y axis Label

   ~$ ./program -G0 1 -G1 1 \
                -G2 1 -G3 0.1 -G4 1.95 -G5 1 -G6 0.0 -G7 0.11 \
                -Fn 1 -F0 MLE_0_HII.dat \
                -G9 7   \\ color_Line
                -G10 1  \\ type_of_Line
                -G11 4  \\ type_of_Width
                -G14 Title -G15 "\\gn\\u(C)\\d" -G16 Frequency

   It is very important to establish the axis ranks through the corresponding command line arguments as in the example above. Your ranks will be active as long as you also introduce -G2 1 (x axis) and G5 1 (y axis) --- as oposed to -G2 0 and -G5 0, which will shut down your axis rank choice. In the latter case, the program calculates axis ranks automatically. 
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
#include <CPGPLOT_HEADER.h>

#include "Discrete_Sampling.h"
#include "global.h"

/* Functions used directly and only by main.c: */ 
void ArgumentControl(int argc, char **argv);

int main (int argc, char **argv)
{
  int i, n; 
  int M; 
  int Event; 

  #include "default.c"

    /* Command line arguments */
  if(argc>1) ArgumentControl(argc,argv);

  int No_of_PANELS = 1;
  int No_of_POINTS = 2;
  Parameter_CPGPLOT * CPG = A_C_T_I_V_A_T_E___C_P_G_P_L_O_T ( No_of_PANELS, No_of_POINTS, 0,
                                                              CPG_DRIVER_NAME );

  // printf("Plot Title:\t %s\n", CPG->Title);
  // printf("Plot X axis Label:\t %s\n", CPG->X_label);
  // printf("Plot Y axis Label:\t %s\n", CPG->Y_label);
  
  printf(" Parameter_CPGPLOT data structure has been allocated and initiated\n");
  M  = 100000; /* M plays the role of the number of events. */

  // printf("Enter and integer-valued number, M, please... ");
  // printf("It will be used to allocate the array of values in memory.\n");
  // scanf("%d", &M); 

  double * x           = (double *)calloc(M, sizeof(double));
  double * Rates       = (double *)calloc(M, sizeof(double));
  double * Rates_Final = (double *)calloc(M, sizeof(double));
         
  for (i=0; i<M; i++) {
        Rates[i] = drand48();
        // printf( "Rate[%d] = %g\n", i, Rates[i] );
  }
  /* 
  F_I_L_E___X_Y___R_E_A_D ( CPG->CPG_File->Name_of_FILE,
                            CPG->CPG_File->No_of_FILES, x, Rates );
  */
  X_Y___R_E_A_D ( CPG->CPG_File->Name_of_FILE[0], 
		              x, 
		              Rates, 
		              &M ); 

  n = 0; 
  for (i=0; i<M; i++)
	  if(Rates[i] > 0.001) 
		  Rates_Final[n++] = Rates[i];
		  
  CPG->Title[0] = '\0'; // Effectively deleting previsously defined title
	//
  // char * p = strcat(CPG->Title, "Bifurcation Diagram");
  /* char * Num = (char *)calloc( 10, sizeof(char) ); */
  /* sprintf(Num, "%7d", 5195769); */
  /* p = strcat(CPG->Title, Num); */
  /* free(Num); */

  /* Default values: ACTIVATE!!! 
      CPG->color_Index    = 2;
      CPG->type_of_Line = 1;
      CPG->type_of_Width = 8;  
      CPG->type_of_Symbol = 1;
  */
  int SAME = 0; int BAR = 1; 
  CPGPLOT___X_Y___H_I_S_T_O_G_R_A_M___N_O_R_M_A_L_I_Z_E_D( SAME, 
                                                           CPG, 
                                                           n, Rates_Final, 50, 
                                                           CPG->X_label, 
                                                           CPG->Y_label,
                                                           CPG->Title, 
                                                           CPG->CPG_SCALE_X,
                                                           CPG->CPG_SCALE_Y,
							                                             BAR ); 
  Discrete_Sampling(Rates, &M, &Event);

  printf(" The winner event is... the %d-th!!!\n", Event);
  printf(" (from 1 to %d)\n", M);

  free(Rates); free(Rates_Final);

  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( CPG, No_of_PANELS );
  cpgclos();

  printf("\nEnd of progam\n");
  return(0);
}
