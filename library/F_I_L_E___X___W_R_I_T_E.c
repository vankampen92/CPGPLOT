#include "../CPGPLOT_HEADER.h"

void F_I_L_E___X___W_R_I_T_E ( Parameter_FILE * Table, 
			       int i, 
			       double * x_Data, 
			       int No_of_POINTS )
{
  /* This function writes the i-th file (from the argument list) 
     The number of columns should be always 1. 
     Otherwise, another reading function is required	*/
   FILE * fp;
  
   int n;

   assert( i < Table->No_of_FILES );
   fp = fopen(Table->Name_of_FILE[i],"w");
     
   n=0;;                                         
   while ( n < No_of_POINTS ) {
     fprintf(fp, "%g\n", x_Data[n]);                                           
     n++;
   }
   fclose(fp);
  /*   END : -----------------------------------------------------------*/
}  

void X___W_R_I_T_E ( char * Name, 
		     double * x_Data,
		     int No_of_POINTS ) 
{
  /* This function writes a double array x_Data as one columns on a file 
     with name 'Name'. 
     Important note: The number of columns of this file should be 
     always 1. Otherwise, another reading function is required	*/
  FILE * fp;
 
  int n;   

  fp = fopen(Name,"w");
  
  n=0;;                                         
  while ( n < No_of_POINTS ) {
    fprintf(fp, "%g\n", x_Data[n]);                                           
    n++;
  }
  fclose(fp);
  /*   END : -----------------------------------------------------------*/
}  


