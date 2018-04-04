#include <CPGPLOT_HEADER.h>

/* Global Shared parameters main Program <---> ArgumentControl() */
#include "extern.h"

void ArgumentControl(int argc, char **argv)
{
  int argcount, skip;
  int n_Dummy;
  
  for(argcount=1; argcount<argc; argcount+=skip)
    {
      if(argv[argcount][0] == '-')
	{
	  skip = 1;
	  switch(argv[argcount][1])
	    {

#include <include.CPG.argumentControl.c>
#include <include.FILES_to_READ.argumentControl.c>

  	    default:
	      printf("**invalid command line argument >%c< \n",
		     argv[argcount][1]);
	    case 'h':

              C           = (Parameter_CPGPLOT*)malloc (1 * sizeof(Parameter_CPGPLOT ) );
	      C->CPG_File = (Parameter_FILE *)malloc( 1 * sizeof(Parameter_FILE) );
              P_A_R_A_M_E_T_E_R___F_I_L_E___A_L_L_O_C( C->CPG_File );
	      P_A_R_A_M_E_T_E_R___F_I_L_E___U_P_L_O_A_D (C->CPG_File);
              paramCommand_Line(stdout, C);

              P_A_R_A_M_E_T_E_R___F_I_L_E___F_R_E_E( C->CPG_File );
	      printf(" As an example,\n"); 
	      printf("        >> [PROGRAM_NAME] -n2 -v0 1 -v1 2 -B0 2\n\n");

	      exit(0);   
	    }
	}
      else
	{
	  printf("**invalid command line flag >%c<\n",argv[argcount][0]);
	  printf("try -h for help.\n");
	  exit(0);
	}
    }
}	




