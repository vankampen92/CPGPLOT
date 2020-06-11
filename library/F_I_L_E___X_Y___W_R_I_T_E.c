#include "../CPGPLOT_HEADER.h"

void F_I_L_E___X_Y___W_R_I_T_E ( FILE * fp_OUT,
				 char * File_Name, 
				 int    NUMBER, 
				 double * x_Data, double * y_Data, int No_of_POINTS )
{
  /* Input arguments:
     . fp_OUT:    User pointer pointing to user predefined file
     . File_Name: File name (without extension) 
     . x_Data[]:  No_of_POINTS long double array
     . y_Data[]:  No_of_POINTS long double array
     . NUMBER:    Identifying [NUMBER] for the file to save 
     
     Output:
     . A file named: [File_Name]_[NUMBER].dat containing  two columns columns:    
                       x_Data   y_Data
		       ------   ------
		       10.0     2.1   
		       ...      ...
  */

  /* This function reads the i-th (x, y, z)-file (from the argument list) */
  FILE * fp;
  double x;
  int k;
  char * p_FILE;
  char * FILE_NAME = (char *)calloc (100, sizeof(char)); 
  char * Number    = (char *)calloc (10, sizeof(char));

  printf("%s", "Saving File... ");
  int Number_of_Characters_File_Name = printf("%s", File_Name);
  printf("_%d.dat\n", NUMBER);

  if( Number_of_Characters_File_Name > 80 ){
    printf("%s\n", "Problems saving file: File name too long!");
    printf("%s\n", "The program will abort\n");
    exit(0);
  }

  if( fp_OUT == NULL) {
    FILE_NAME[0]='\0';
    p_FILE = strcat(FILE_NAME, File_Name);
    sprintf(Number, "%d", NUMBER);
    p_FILE = strcat(FILE_NAME, "_");
    p_FILE = strcat(FILE_NAME, Number);
    p_FILE = strcat(FILE_NAME, ".dat");
    fp = fopen(FILE_NAME, "w");
  }
  else {
    fp = fp_OUT;
  }
  /* BEGIN : Writing File * * * * * * * * * * * * * * * * * * * * * * * */
  for( k = 0; k < No_of_POINTS; k++ ){   
    fprintf(fp, "%g\t%g\n", x_Data[k], y_Data[k]); 
  }  
  if( fp_OUT == NULL) fclose(fp);

  free( Number ); 
  free( FILE_NAME );
  /*   END : -----------------------------------------------------------*/
}  

