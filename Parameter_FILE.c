#include "CPGPLOT_HEADER.h"

#include "include.FILES_to_READ.extern.h"

void P_A_R_A_M_E_T_E_R___F_I_L_E___A_L_L_O_C( Parameter_FILE * T )
{
  int i;

  /* Input Model Parameter Control */
  T->Code_Parameters = (char **)malloc( MAX_No_of_FILES * sizeof(char *) );
  for (i=0; i<MAX_No_of_FILES; i++){
    T->Code_Parameters[i] = (char *)malloc( 100 * sizeof(char) );
  }

  T->Name_Parameters = (char **)malloc( MAX_No_of_FILES * sizeof(char *) );
  for (i=0; i<MAX_No_of_FILES; i++){
    T->Name_Parameters[i] = (char *)malloc( 500 * sizeof(char) );
  }
}

void P_A_R_A_M_E_T_E_R___F_I_L_E___U_P_L_O_A_D( Parameter_FILE * T )
{
  int i;

  T->No_of_FILES  = No_of_FILES;
  T->Name_of_FILE = Name_of_FILE;
  T->F_x_GRID     = F_x_GRID;
  T->F_y_GRID     = F_y_GRID;
  
  /* BEGIN: Names and codes for model parameters */
  for(i = 0; i<MAX_No_of_FILES; i++){
    AssignLabel_to_Parameter_FILE(i, T->Name_Parameters[i], T);
    AssignCodes_to_Parameter_FILE(i, T->Code_Parameters[i], T);
  }
  /*   END: Names and codes for model parameter  */
}

void P_A_R_A_M_E_T_E_R___F_I_L_E___F_R_E_E( Parameter_FILE * T )
{
  int i;

  for (i=0; i < MAX_No_of_FILES; i++){
    free( T->Code_Parameters[i] );
  }
  free(T->Code_Parameters);
  
  for (i=0; i < MAX_No_of_FILES; i++){
    free( T->Name_Parameters[i] );
  }
  free(T->Name_Parameters);
}

void AssignLabel_to_Parameter_FILE(int j, char * Label, Parameter_FILE *P)
{
  char * p;
  char num[12];
  
  if (j < MAX_No_of_FILES ) {
    Label[0] = '\0';
    p = strcat(Label, "File_Number: ");
    sprintf(num, "%d", j);
    p = strcat(Label, num);
    p = strcat(Label, "; Name: ");
    p = strcat( Label, P->Name_of_FILE[j]);  
  
  }
  else {

    printf(".... INVALID PARAMETER KEY [key = %d]\n", j);
    printf(" The maximum number of parameters is %d\n", MAX_No_of_FILES);
    printf("\n");
    exit(0);

  }
}	

void AssignCodes_to_Parameter_FILE(int j, char * Label, Parameter_FILE *P)
{
  char * p;
  char num[12];

  if (j < MAX_No_of_FILES ) {
    
    sprintf(num, "%d", j);

    Label[0] = '\0';    
    p = strcat(Label, "-F");           p = strcat(Label, num); 
    p = strcat(Label, " [File Name] ");
    p = strcat(Label, "-X");           p = strcat(Label, num);            
    p = strcat(Label, " [X dimension] ");
    p = strcat(Label, "-Y");           p = strcat(Label, num);
    p = strcat(Label, " [Y dimension]");
  }
  else {

    printf(".... INVALID PARAMETER KEY [key = %d]\n", j);
    printf(" The maximum number of parameters is %d\n", MAX_No_of_FILES);
    printf("\n");
    exit(0);
  }
}	

void fprintf_Input_Parameter_FILE(FILE * fp, Parameter_FILE * P)
{
  int i;

  fprintf(fp, "------------------------------------------------\n");

  for(i=0; i < P->No_of_FILES; i++){
    fprintf(fp, "FILES: %d: %s:\t %s\n",
            i, P->Name_Parameters[i], P->Code_Parameters[i] );
  }

  int No_of_FILES_maximum = MAX_No_of_FILES;

  fprintf(fp, "No of FILES (maximum): %d\t", No_of_FILES_maximum);
  fprintf(fp, "-N [No of FILES: %d]\n", P->No_of_FILES);

  fprintf(fp, "------------------------------------------------\n");
}

