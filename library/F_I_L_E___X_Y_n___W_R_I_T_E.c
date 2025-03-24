#include "../CPGPLOT_HEADER.h"


void F_I_L_E___X_Y_n___W_R_I_T_E ( FILE * fp_OUT,
                                   char * File_Name, 
                                   int    NUMBER, 
                                   double * x_Data,  int No_of_POINTS,
                                   double ** y_Data, int No_of_SERIES )
{
  /* Input arguments:
      . fp_OUT:    User pointer pointing to a user pre-defined file 
      . File_Name: File name (without extension) 
      . x_Data[]:  For instance, time in years
      . y_Data[][]: For instance, accumulated consumption in kWh
      . NUMBER:    Identifying [NUMBER] for the file to save 

     Output:
      . If fp_OUT == NULL, then the function saves a file in the current directory   
        named: [File_Name]_[NUMBER].dat containing  No_of_SERIES + 1 different columns:    
              x_Data   y_Data[0], ..., y[No_of_SERIES-1]
              ------   --------        -----------------
              10.0     2.1             3.5
              ...
      
      . If fp_OUT != NULL, then the function saves the data in the file pointed by 
      fp_OUT
*/

/* This function reads the i-th (x, y, z)-file (from the argument list) */
  FILE * fp;
  double x;
  int j,k;
  char * p_FILE;
  char * FILE_NAME = (char *)calloc (100, sizeof(char)); 
  char * Number    = (char *)calloc (10, sizeof(char));
  int Number_of_Characters_File_Name = strlen(File_Name);

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

    printf("%s", "Saving File... ");
    Number_of_Characters_File_Name = printf("%s", File_Name);
    printf("_%d.dat\n", NUMBER);
  }
  else {
    fp = fp_OUT;
  }
  
  /* BEGIN : Writing File * * * * * * * * * * * * * * * * * * * * * * * * */
  for( j = 0; j < No_of_POINTS; j++ ){
    fprintf(fp, "%g\t", x_Data[j] );
    for( k = 0; k < No_of_SERIES; k++ ){
      fprintf(fp, "%g\t", y_Data[k][j]); 
    }
    fprintf(fp, "\n");
  }
  
  if( fp_OUT == NULL) fclose(fp);

  free( Number );
  free( FILE_NAME );
/*   END : -------------------------------------------------------------*/
}  






