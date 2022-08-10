#include "../CPGPLOT_HEADER.h"

void F_I_L_E___X___R_E_A_D ( Parameter_FILE * Table, 
			       int i, 
			       double * x_Data, 
			       int * No_of_POINTS )
{
  /* This function reads the i-th file (from the argument list) 
     The number of columns should be always 1. 
     Otherwise, another reading function is required	*/
   FILE * fp;
   double x;
   int n;

   assert( i < Table->No_of_FILES );
   if( (fp = fopen(Table->Name_of_FILE[i],"r") ) == NULL) {
     printf("File %s non-existent in current directory!!!\n --- Cannot open file.\n", 
	    Table->Name_of_FILE[i] );
      exit(1);
   }

   n=0;;                                         
   while (fscanf(fp, "%lf\n", &x) != EOF ){                                            
      x_Data[n++] = x;
   }                                                  
   fclose(fp);
   
   (*No_of_POINTS ) = n;
  /*   END : -----------------------------------------------------------*/
}  

void X___R_E_A_D ( char * Name, 
		   double * x_Data,
		   int * No_of_POINTS ) 
{
  /* This function reads a one-column double array x_Data from a 
     file named [Name]. In addition, it counts the number of vector
     entries [No_of_POINTS].
     Important note: The number of columns of this file should be 
     always 1. Otherwise, another reading function is required	*/
  FILE * fp;
  double x;
  int n;   
  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * */
    if( (fp = fopen(Name,"r") ) == NULL) {
      printf("File %s non-existent in current directory!!!\n --- Cannot open file.\n", 
	     Name );
      exit(1);
    }
    n=0;;
    while (fscanf(fp, "%lf\n", &x) != EOF ){
      x_Data[n++] = x;
    }
    fclose(fp);

    (*No_of_POINTS ) = n;
  /*   END : -----------------------------------------------------------*/
}  


