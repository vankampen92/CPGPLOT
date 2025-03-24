/* This main function defines a squared grid of N_X times N_Y sites
 * Then a fraction of sites is occupied with individual resource items. 
 * A site can only fit and hold one single resource item. 
 * A resource item is defined as a data type with a particular data structure. 
 * The members of this structure are such as the size and the shape of the  
 * resource item and its position on the grid (pointer to Lattice Site)
 * Resource item position are chosen at random within the squared grid. 
 * Then, a (low) number of consumers are introduced in the system. They 
 * attack resources at a rate Alpha. Since attacks are at random, some 
 * fail. The effective 'per capita' resource depletion rate, this is, 
 * the number of resource items really captured per unit time by a searching 
 * and active consumer depends on the density of resource items in the system.  
 * In fact: 
 * 
 *                                       n_R
 *                      Theta  = Alpha  -----
 *                                        N
 * 
 * where N is a measure of the size (or volume) or the system. In our 
 * case N = N_X x N_Y, and n_R is No_of_RESOURCE items. 
 *  
 * Compilation:
   
   ~$: make 

   Execution:

   ~$ ./program -G0 1 -G1 1 -G2 1 -G3 0 -G4 1.0 -G5 1 -G6 0.0 -G7 0.5   
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
/* 
 * The header file CPGPLOT_HEADER.h is a superheader file 
 * containing elaborated (hand-made), primitive cpgplot function
 * prototypes for plotting procedures and the defintion of new 
 * type 'Parameter_CPGPLOT', which a plotting structure passed down
 * to any plotting procedure. 
 * This header file is obligated when compiling with the libraries:
 * -lda_cpgplot_XY_GRID_FILE -lda_cpgplot_BASIC -lcpgplot -lpgplot
 * 
 */
#ifndef GSL_HEADER_FILES
#define GSL_HEADER_FILES
#include <gsl/gsl_rng.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fit.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_sort.h>
#include <gsl/gsl_sort_vector.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_odeiv.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_roots.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_multimin.h>
#include <gsl/gsl_linalg.h>
#endif 

#include <CPGPLOT_HEADER.h>
#include "GSL_stat.h"
#include "global.h"

/* Model Fixed Parameters */

#define D_X 10  // Lattice physical dimension in the X direction
#define D_Y 10  // Lattice physical dimension in the Y direction

#define N_X 20 // No of SITES in the X direction 
#define N_Y 20 // No of SITES in the Y direction

#define RESOURCE_DENSITY 0.3 
#define No_of_CONSUMERS 10

#define Alpha  0.5  // Attack rate 

#define CONTRACTION_FACTOR 0.95 // How much Site surface one resource item spans 
#define THICK_HEIGHT 0.1        // How thick or tall resource items are

typedef struct {
    int n;                 // Site index 
    int n_x;               // Site index on the X axis        
    int n_y;               // Site index on the Y axis
    double c_x;            // Position of the center (X axis)
    double c_y;            // Position of the center (Y axis)
    int A;                 // Boolean variable (1/0)
} Site;

typedef struct {
    int n;                 // Resource index (fromn 0 to No of RESOURCES minus 1)
    double c;              // Contraction factor (if c = 1, the resource spans the whole Site)
    double w;              // Third dimension (how thick/tall is it?) 
    Site * Location;       // Location pointing to the Site where the resource item is found.
} Resource;

gsl_rng * r; /* Global generator defined and initialized in main.c */

/* Functions used directly and only by main.c: */ 
void ArgumentControl(int argc, char **argv);

int main (int argc, char **argv)
{
  int i, j, k; 
  double S_X;      // Lattice Step in the X direction 
  double S_Y;      // Lattice Step in the Y direction
  int No_of_SITES;     // Total No of SITES 
  int No_of_RESOURCES; // Total No of RESOURCE Items 
  double x_R;          // True Resource Density 
  double Theta;    // Effective (average) Per Capita Resource Depletion Rate
  double O_X;      // Origin of the lattice (x)
  double O_Y;      // Origin of the lattice (y)
	 

  #include "default.c"  // Only CPGPLOT default values

  S_X = D_X/(double)N_X;
  S_Y = D_Y/(double)N_Y;

  O_X = S_X/2.0; 
  O_Y = S_Y/2.0;   

  No_of_SITES = N_X * N_Y; 

  No_of_RESOURCES = (int)(RESOURCE_DENSITY * No_of_SITES);
  x_R             = (double)No_of_RESOURCES / (double)No_of_SITES;
  Theta           = Alpha * x_R; 

  /* Allocation of the lattice structure (as an array of pointers to Sites) */
  Site ** Lattice = (Site **)calloc(No_of_SITES, sizeof(Site *));
  for(i=0; i<No_of_SITES; i++)
    Lattice[i] = (Site *)calloc(1, sizeof(Site));

  /* Allocation of the set of resource items */
  Resource ** Resources = (Resource **)calloc(No_of_RESOURCES, sizeof(Resource *));
  for(i=0; i<No_of_RESOURCES; i++)
    Resources[i] = (Resource *)calloc(1, sizeof(Resource));

  /* Initiation and the Lattice Grid */
  for(i=0; i<No_of_SITES; i++) {
    Lattice[i]->n   = i; 
    Lattice[i]->n_x = i%N_X;
    Lattice[i]->n_y = i/N_X;
    Lattice[i]->c_x = O_X + (1.0/2.0 + (double)Lattice[i]->n_x) * S_X; 
    Lattice[i]->c_y = O_Y + (1.0/2.0 + (double)Lattice[i]->n_y) * S_Y;
  }
  /* Resource will be placed on the lattice at random, but we need */
  /* to set up our random generator functions: */
  /* B E G I N: Random Number Generator Setup * * * * * * * * * * */
  /* GNU Scientific Library:                                      */
  /*                                                              */
  /* 	     const gsl_rng_type * gsl_rng_env_setup (void);         */
  /*                                                              */
  /* 	     This function reads the environment variables          */
  /* 	     GSL_RNG_TYPE and GSL_RNG_SEED and uses their values    */ 
  /* 	     to set the corresponding library variables             */ 
  /* 	     gsl_rng_default and gsl_rng_default_seed.              */ 
  /* 	     These global variables are defined as follows,         */
  /*                                                               */
  /*  (extern const gsl_rng_type *gsl_rng_default                 */
  /*   extern unsigned long int gsl_rng_default_see               */	  
  /*	 in the corresponding header file)                          */
  const gsl_rng_type * T;
  const gsl_rng_type **t, **t0;
  gsl_rng_env_setup();
  T = gsl_rng_taus2; //T = gsl_rng_default; T = gsl_rng_ranlux389; 
  r = gsl_rng_alloc(T);
  t0 = gsl_rng_types_setup ();
#if defined VERBOSE
  printf("Random number information... Available generators:\n");
  for(t=t0; *t != 0; t++){
    printf("%s, ", (*t)->name);
  }
#endif
  printf("\n In this example, the random generator at work... is the '%s' generator\n\n",
         gsl_rng_name(r));
  GSL_Init_Random_Seed(r);  
  /* See full definition of the function at GSL_Random library    */
	/* or before the main()                                         */
#if defined VERBOSE
  /* Checking if the chosen random generator works fine           */
  for(i=0; i<10; i++){
    printf( "f(%d)=%g, ", i, gsl_rng_uniform(r) );
    printf( "f_GAUS(%d)=%g\n", i, gsl_ran_gaussian(r, 1.0) );
  }
  printf("\n"); Press_Key();
#endif
  /*   E N D: Random Number Generator Setup * * * * * * * * * * * */

  for(i=0; i<No_of_RESOURCES; i++) {
    Resources[i]->n = i; 
    Resources[i]->c = CONTRACTION_FACTOR; 
    Resources[i]->w = THICK_HEIGHT;
    /* Assignation of the resources at random locations within the Lattice */
    j = (int)((double)No_of_SITES * gsl_rng_uniform(r)); /* Random choice of a site */
    Resources[i]->Location = Lattice[j];                 /* in the Lattice          */
    Lattice[j]->A = 1; 
  }

  /* Command line arguments: only plotting arguments can enter through command line */
  if(argc>1) ArgumentControl(argc,argv);

  int No_of_PANELS = CPG__PANEL__X * CPG__PANEL__Y;
  int No_of_POINTS = 2;
  Parameter_CPGPLOT * CPG = A_C_T_I_V_A_T_E___C_P_G_P_L_O_T ( No_of_PANELS, No_of_POINTS, 0,
                                                              CPG_DRIVER_NAME );

  // printf("Plot Title:\t %s\n", CPG->Title);
  // printf("Plot X axis Label:\t %s\n", CPG->X_label);
  // printf("Plot Y axis Label:\t %s\n", CPG->Y_label);
		  
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
  CPG->CPG_RANGE_X_0 = 0.0;   CPG->CPG_RANGE_X_1 = O_X + D_X + S_X/2.0;
  CPG->CPG_RANGE_Y_0 = 0.0;   CPG->CPG_RANGE_Y_1 = O_Y + D_Y + S_Y/2.0;

  CPG->color_Index   = 0; /* Effectively, no axes, no labels, no title, 
                             if color_Index is 0 */
  CPG->type_of_Width = 3;
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___A_X_E_S ( CPG, 
							                                CPG->X_label, 
							                                CPG->Y_label, 
							                                CPG->Title );

  CPG->color_Index    = 2;
  CPG->type_of_Line   = 2; 
  CPG->type_of_Width  = 1;
  CPG->type_of_Symbol = 1;                                          
  CPGPLOT___X_Y___S_Q_U_A_R_E_D___L_A_T_T_I_C_E ( CPG, 
                                                  O_X, O_Y, 
                                                  D_X, D_Y, 
                                                  N_X, N_Y );  

  /* Drawing the resources on the lattice */
  float x1, y1, x2, y2; 
  int color_Index     = 3; 
  int type_of_Filling = 1;

  for(i=0; i<No_of_RESOURCES; i++) {
    x1 = (float)(Resources[i]->Location->c_x - 0.5 * Resources[i]->c * S_X);
    y1 = (float)(Resources[i]->Location->c_y - 0.5 * Resources[i]->c * S_Y);

    x2 = (float)(Resources[i]->Location->c_x + 0.5 * Resources[i]->c * S_X);
    y2 = (float)(Resources[i]->Location->c_y + 0.5 * Resources[i]->c * S_Y);    
    
    cpg_XY_same_rectangle( x1, y1, x2, y2, color_Index, type_of_Filling );   
  }

  /* Feeding Experiments (one go for every animal):
     Calculation of the number of successful attacks per unit time 
     (on a per capita base, this is, for each animal).
     Final representation of the empirical averages and comparison 
     with the expectation: 
                                        n_R
                       Theta  = Alpha  -----
                                         N
  */
  float radius;
  double * Theta_T = (double *)calloc(No_of_CONSUMERS, sizeof(double));
  double * Theta_X = (double *)calloc(No_of_CONSUMERS, sizeof(double));
  double * Alpha_T = (double *)calloc(No_of_CONSUMERS, sizeof(double));
  double * Alpha_X = (double *)calloc(No_of_CONSUMERS, sizeof(double));
  double * Animal  = (double *)calloc(No_of_CONSUMERS, sizeof(double));  
  double Time_0  = 0.0; 
  double Time_1  = 100.0; 
  double Time    = Time_0; 
  int n_S, n_0; 
  
  /* Go and draw on first panel */
  CPG->color_Index = 13;     /* Animal Color */                                                                                                                                                                                         
  for(k=0; k<No_of_CONSUMERS; k++) {
    n_0 = 0;        /* Counter for the total number of attacks      */
    n_S = 0;        /* Counter for the number of successful attacks */
    Time = Time_0;  /* Accumulationg time for each experiment       */
    while(Time < Time_1) {
      Time += (- 1.0/Alpha * log(gsl_rng_uniform(r)));

      /* Choice of a random cell within the Lattice */
      j = (int)((double)No_of_SITES * gsl_rng_uniform(r)); /* Random choice of a site */

      if (Lattice[j]->A == 1) n_S++;
      
      n_0++;

      /* Represent the attack... (a circle appears on the lattice site) */
      radius = (float)(0.4 * CONTRACTION_FACTOR * MIN(S_X, S_Y));
      type_of_Filling  = 1;
      cpg_XY_same_circle(Lattice[j]->c_x, Lattice[j]->c_y, radius, 
		                     CPG->color_Index, type_of_Filling);

      /* Wait some 0.5 seconds time */
      // Wait for 500000 microseconds (0.5 seconds)
      usleep(500000); 
      // sleep() does not understand fractions of seconds!!!
      // sleep(1.0);

      /* Erase the animal and regrow the resource if necessary */
      radius = (float)(0.4 * CONTRACTION_FACTOR * MIN(S_X, S_Y));
      cpg_XY_same_circle(Lattice[j]->c_x, Lattice[j]->c_y, radius, 
		                     0, type_of_Filling);
      if (Lattice[j]->A == 1) {
        color_Index      = 3; /* Resource Color          */
        type_of_Filling  = 1; /* Resouce type of Filling */
        x1 = (float)(Lattice[j]->c_x - 0.5 * CONTRACTION_FACTOR * S_X);
        y1 = (float)(Lattice[j]->c_y - 0.5 * CONTRACTION_FACTOR * S_Y);

        x2 = (float)(Lattice[j]->c_x + 0.5 * CONTRACTION_FACTOR * S_X);
        y2 = (float)(Lattice[j]->c_y + 0.5 * CONTRACTION_FACTOR * S_Y);    
    
        cpg_XY_same_rectangle( x1, y1, x2, y2, color_Index, type_of_Filling );
      }                         
    }

    Theta_X[k] = (double)n_S/(Time_1 - Time_0);
    Alpha_X[k] = (double)n_0/(Time_1 - Time_0);

    printf("Theta (empirical)[%d] = %g\t Theta (theory)[%d] = %g\n", k, Theta_X[k], k, Theta);
  }

  /* Summarize results by drawing on the 2nd panel */
  CPG->CPG_RANGE_X_0 = 0.0;   CPG->CPG_RANGE_X_1 = (double)No_of_CONSUMERS + 1.0; 
  CPG->CPG_RANGE_Y_0 = 0.0;   CPG->CPG_RANGE_Y_1 = 1.5 * Alpha; 

  CPG->color_Index   = 1; /* Effectively, no axes, no labels, no title, 
                             if color_Index is 0 */
  CPG->type_of_Width = 3;
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___A_X_E_S ( CPG, 
							                                CPG->X_label, 
							                                CPG->Y_label, 
							                                CPG->Title );
  CPG->color_Index   = 6; 
  CPG->type_of_Width = 5;
  CPG->type_of_Line  = 2; 
  for(k=0; k<No_of_CONSUMERS; k++) {
    Animal[k]  = (double)k + 1.0;
    Alpha_T[k] = Alpha; 
  }
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, 1, 
							                                          No_of_CONSUMERS, Animal, Alpha_T,
							                                          CPG->X_label, CPG->Y_label, CPG->Title,
							                                          1, 1); 
  CPG->color_Index   = 7; 
  CPG->type_of_Width = 5;
  CPG->type_of_Line  = 2;
  for(k=0; k<No_of_CONSUMERS; k++) {
    Animal[k]  = (double)k + 1.0;
    Theta_T[k] = Theta; 
  }
  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, 1, 
							                                          No_of_CONSUMERS, Animal, Theta_T,
							                                          CPG->X_label, CPG->Y_label, CPG->Title,
							                                          1, 1);  
  CPG->color_Index   = 7; 
  CPG->type_of_Width = 3;
  CPG->type_of_Line  = 1;
  CPG->type_of_Symbol = 7; 
  CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E___P_L_O_T( CPG, 1,
						                                             No_of_CONSUMERS, Animal, Alpha_X,  
						                                             CPG->X_label, CPG->Y_label, CPG->Title,
							                                           1, 1);
  CPG->color_Index   = 9; 
  CPG->type_of_Width = 3;
  CPG->type_of_Line  = 1;
  CPG->type_of_Symbol = 5; 
  CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E___P_L_O_T( CPG, 1,
						                                             No_of_CONSUMERS, Animal, Theta_X,  
						                                             CPG->X_label, CPG->Y_label, CPG->Title,
							                                           1, 1);    						     
  /* De-Allocation of the lattice structure */   
  for(i=0; i<No_of_SITES; i++) free(Lattice[i]); 
  free(Lattice);  
  /* De-Allocation of the set of resource items */
  for(i=0; i<No_of_RESOURCES; i++) free(Resources[i]);
  free(Resources);

  free(Theta_T); free(Theta_X); 
  free(Alpha_T); free(Alpha_X);
  free(Animal);

  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( CPG, No_of_PANELS );
  cpgclos();

  printf("\nEnd of progam\n");
  return(0);
}
