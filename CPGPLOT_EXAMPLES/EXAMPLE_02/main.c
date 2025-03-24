/* This main function plots Gaussian distributions 
   for different species with a characteristic mean 
   and variance. The curves represent environmental 
   preferences across a set of sites.  

   Compilation:
   ~$: make 
      
   ~$ ./PLOT -G0 1 -G1 2 -G2 1 -G3 0 -G4 1001.0 -G5 1 -G6 0.0 -G7 0.1

   It is very important to establish the axis ranks through the corresponding command line arguments as in the example above. Your ranks will be active as long as you also introduce -G2 1 (x axis) and G5 1 (y axis) --- as oposed to -G2 0 and -G5 0, which will shut down your axis rank choice. In the latter case, the program calculates axis ranks automatically. 
*/
#include "main.h"

#include "global.h"

gsl_rng * r; /* Global generator defined and initialized in main.c */

/* Model Parameters */
#define No_of_SITES_MAX 1000
#define No_of_SPECIES 3

void GSL_Init_Random_Seed(const gsl_rng * r)
{
  /* This function seed the GSL Random Generator r
     with a seed which is different for each initialization
     according to current computer time 
  */
        unsigned long int     seed;
        time_t  nowtime;
        struct  tm *preztime;

        time(&nowtime);
        preztime = localtime(&nowtime);
        seed = (int)((preztime->tm_sec+1)*(preztime->tm_min+1)*
                (preztime->tm_hour+1)*(preztime->tm_year)*(preztime->tm_year));
        if(seed%2==0) seed++;

	printf(" Random Number Seed: %lu\n", seed);
	
        gsl_rng_set(r, seed);
}

int main (int argc, char **argv)
{
  int i, n, N;
  Parameter_CPGPLOT * CPG;
  int colors[3] = {2,12,8};
  float x_SP[2], y_SP[2];
  float x, y, d;
  double Environmental_AVERAGE, Environmental_VARIANCE;
  
  if(No_of_SPECIES > 3) {
    printf("No of SPECIES is greater than 3!!!\n");
    printf("The program will exit\n"); 
    exit(0); 
  }

#include "default.c"

 /* Command line arguments */
  if(argc>1) ArgumentControl(argc,argv);

  int No_of_PANELS = 1;
  int No_of_SITES = 2;
  CPG = A_C_T_I_V_A_T_E___C_P_G_P_L_O_T ( No_of_PANELS, No_of_SITES, 0,
                                          CPG_DRIVER_NAME );
  printf(" Parameter_CPGPLOT data structure has been allocated and initiated\n");

  double ** x_Data = (double **)calloc( No_of_SPECIES, sizeof(double *) );
  double ** y_Data = (double **)calloc( No_of_SPECIES, sizeof(double *) );
  for(i=0; i<No_of_SPECIES; i++) {
    x_Data[i] = (double *)calloc( No_of_SITES_MAX, sizeof(double) );
    y_Data[i] = (double *)calloc( No_of_SITES_MAX, sizeof(double) );
  }

  /* B E G I N: Random Number Generator Setup * * * * * * * * * * */
  /* GNU Scientific Library:                                      */
  /*                                                              */
  /* 	     const gsl_rng_type * gsl_rng_env_setup (void);       */

  /* 	     This function reads the environment variables        */
  /* 	     GSL_RNG_TYPE and GSL_RNG_SEED and uses their values  */ 
  /* 	     to set the corresponding library variables           */ 
  /* 	     gsl_rng_default and gsl_rng_default_seed.            */ 
  /* 	     These global variables are defined as follows,       */

  /*  extern const gsl_rng_type *gsl_rng_default                  */
  /*  extern unsigned long int gsl_rng_default_seed               */
	  
  /*	     in the corresponding header file                     */

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

  GSL_Init_Random_Seed(r);  /* See full definition of the function at GSL_Random library
			       or before the main()                                    */
#if defined VERBOSE
  /* Checking if the chosen random generator works fine */
  for(i=0; i<10; i++){
    printf( "f(%d)=%g, ", i, gsl_rng_uniform(r) );
    printf( "f_GAUS(%d)=%g\n", i, gsl_ran_gaussian(r, 1.0) );
  }
  printf("\n"); Press_Key();
#endif
  /*   E N D: Random Number Generator Setup */
  
  /* B E G I N : Generating 1st Curve Values */
  printf("Generating 1st Curve Values for the species...\n");
  for(i=0; i<No_of_SPECIES; i++) {
    Environmental_AVERAGE  = No_of_SITES_MAX * gsl_rng_uniform(r);
    Environmental_VARIANCE = 0.1 * No_of_SITES_MAX * gsl_rng_uniform(r);

    printf("Species %d:\n ", i); 
    printf("Environmental average: %g\t", Environmental_AVERAGE);
    printf("Environmental stdev (sigma): %g\n\n", Environmental_VARIANCE);    
    
    for(n=0; n<No_of_SITES_MAX; n++) {
      x_Data[i][n] = 1.0 + (double)n;
      x            = x_Data[i][n] - Environmental_AVERAGE;  
      y_Data[i][n] = gsl_ran_gaussian_pdf(x, Environmental_VARIANCE);
    }
  }
  /*     E N D : Generating 2nd Curve Values */

  CPG->Title[0] = '\0'; // Effectively deleting previsously defined title
  // char * p = strcat(CPG->Title, "Bifurcation Diagram");
  /* char * Num = (char *)calloc( 10, sizeof(char) ); */
  /* sprintf(Num, "%7d", 5195769); */
  /* p = strcat(CPG->Title, Num); */
  /* free(Num); */

  int SAME_PLOT = 0;   
  // CPG->color_Index    = 2;
  CPG->type_of_Line = 1;
  CPG->type_of_Width = 8;  
  CPG->type_of_Symbol = 1;

  for(i=0; i<No_of_SPECIES; i++) {
    CPG->color_Index    = colors[i];

    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME_PLOT,
							  No_of_SITES_MAX,
							  x_Data[i], y_Data[i],
							  "Spatial Dimension (x)", "Environmental Preference",
							  CPG->Title,
							  CPG->CPG_SCALE_X,
							  CPG->CPG_SCALE_Y );
    //getchar(); 
    SAME_PLOT = 1; 
  }
  //getchar();
  
  /* B E G I N : Generating 2nd Curve Values for the species */
  Environmental_VARIANCE = 0.1 * No_of_SITES_MAX * gsl_rng_uniform(r);
  
  printf("\n\n\n");
  printf("Generating 2nd Curve Values for the species...\n");
  for(i=0; i<No_of_SPECIES; i++) {
    Environmental_AVERAGE  = No_of_SITES_MAX * gsl_rng_uniform(r);
    
    printf("Species %d:\n ", i);
    printf("Environmental average: %g\t", Environmental_AVERAGE);
    printf("Environmental stdev (sigma): %g\n\n", Environmental_VARIANCE);

    for(n=0; n<No_of_SITES_MAX; n++) {
      x_Data[i][n] = 1.0 + (double)n;
      x            = x_Data[i][n] - Environmental_AVERAGE;  
      y_Data[i][n] = gsl_ran_gaussian_pdf(x, Environmental_VARIANCE);
    }
  }
  /*     E N D : Generating 2nd Curve Values for the two species */

  SAME_PLOT = 0;
  // CPG->color_Index  = 6;
  CPG->type_of_Line = 1;
  CPG->type_of_Width = 8;  
  CPG->type_of_Symbol = 1; 

  for(i=0; i<No_of_SPECIES; i++) {
    CPG->color_Index    = colors[i];
    
    CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( CPG, SAME_PLOT,
							  No_of_SITES_MAX,
							  x_Data[i], y_Data[i], 
							  "Spatial Dimension (x)", "Environmental Preference",
							  CPG->Title,
							  CPG->CPG_SCALE_X,
							  CPG->CPG_SCALE_Y );
    //getchar();
    SAME_PLOT = 1;
  }
  
  gsl_rng_free(r);

  for(i=0; i<No_of_SPECIES; i++) {
    free(x_Data[i]);
    free(y_Data[i]);
  }
  free(x_Data); free(y_Data); 
  
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( CPG, No_of_PANELS );
  cpgclos();

  printf("\nEnd of progam\n");
  return(0);
}
