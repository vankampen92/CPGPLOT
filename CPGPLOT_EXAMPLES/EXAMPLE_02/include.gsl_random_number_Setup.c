  /* GNU Scientific Library:  Random numbers set up */

  /* 
	     const gsl_rng_type * gsl_rng_env_setup (void);

	     This function reads the environment variables 
	     GSL_RNG_TYPE and GSL_RNG_SEED and uses their values 
	     to set the corresponding library variables 
	     gsl_rng_default and gsl_rng_default_seed. 
	     These global variables are defined as follows,

              extern const gsl_rng_type *gsl_rng_default
              extern unsigned long int gsl_rng_default_seed
	  
	     in the corresponding header file
  */
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

#if defined CURRENT_TIME_RDN_SEED
  GSL_Init_Random_Seed(r);
#else
  GSL_Init_Random_Seed_from_File(r);
#endif

  /* End of Random number setting */
