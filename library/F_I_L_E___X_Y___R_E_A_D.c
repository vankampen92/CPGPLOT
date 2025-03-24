#include "../CPGPLOT_HEADER.h"

void F_I_L_E___X_Y___R_E_A_D ( Parameter_FILE * Table, 
			       int i, 
			       double * x_Data, 
			       double * y_Data )
{
  /* This function reads the i-th file (from the argument list) 
     Important note: The number of columns of this file should be 
     always 2. Otherwise, another reading function is required	*/
  FILE * fp;
  double x,y;
  int j;
  int No_of_POINTS_1, No_of_POINTS_2;

  assert( i < Table->No_of_FILES );
  No_of_POINTS_2 = Table->F_y_GRID[i]; No_of_POINTS_1 = Table->F_x_GRID[i];
  assert( No_of_POINTS_2 == 2);
  
  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * */
    if( (fp = fopen(Table->Name_of_FILE[i],"r") ) == NULL) {
      printf("File non-existent in current directory!!!\n --- Cannot open file.\n");
      exit(1);
    }
    for( j = 0; j < No_of_POINTS_1; j++ ){
	    fscanf(fp, "%lf\t%lf\n", &x, &y);
	    x_Data[j] = x; y_Data[j] = y; 
    }
    fclose(fp);
  /*   END : -----------------------------------------------------------*/
}  

void X_Y___R_E_A_D ( char * Name, 
		     double * x_Data, 
		     double * y_Data, 
		     int * No_of_POINTS)
{
  /* This function reads the x,y file (Name) 
     Important note: The number of columns of this file should be 
     always 2. Otherwise, another reading function is required	*/
  FILE * fp;
  double x,y;
  int n;   

  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * */
    if( (fp = fopen(Name,"r") ) == NULL) {
      printf("File non-existent in current directory!!!\n --- Cannot open file.\n");
      exit(1);
    }
    
    n=0;                                         
    while (fscanf(fp, "%lf\t%lf\n", &x, &y) != EOF ){  
	    x_Data[n] = x; y_Data[n] = y; 
      n++;
    }
    fclose(fp);

    (*No_of_POINTS) = n;
  /*   END : -----------------------------------------------------------*/
}  


