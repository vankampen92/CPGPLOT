#include "../CPGPLOT_HEADER.h"

void F_I_L_E___X_Y_Z___R_E_A_D ( Parameter_FILE * Table, 
				 int i, 
				 double * x_Data, 
				 double * y_Data, 
				 double * W_GRID )
{
  /* This function reads the i-th (x, y, z)-file (from the argument list) */
  /* 
     Notice that this function can only handle 3 column files of a GRID type. This 
     is those containing a map for No_of_POINTS_1 times No_of_POINTS_2 grid. 
  */
  FILE * fp;
  int No_of_POINTS_1, No_of_POINTS_2;
  double x,y,z;
  int j,k, n;

  assert( i < Table->No_of_FILES );

  No_of_POINTS_2 = Table->F_y_GRID[i]; No_of_POINTS_1 = Table->F_x_GRID[i];
  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    n = 0;
    if( (fp = fopen(Table->Name_of_FILE[i],"r") ) == NULL) {
      printf("File %s non-existent in current directory!!!\n --- Cannot open file.\n", Table->Name_of_FILE[i]);
      exit(1);
    }
    for( k = 0; k < No_of_POINTS_2; k++ ) {
      for( j = 0; j < No_of_POINTS_1; j++ ){
	fscanf(fp, "%lf\t%lf\t%lf\n", &x, &y, &z);
	x_Data[j] = x; y_Data[k] = y; W_GRID[n++] = z;
      }
    }
    fclose(fp);
  /*   END : ----------------------------------------------------------------------*/
}  

void X_Y_Z___R_E_A_D ( char * Name,
		       int No_of_POINTS_1, int No_of_POINTS_2, 
		       double * x_Data, 
		       double * y_Data, 
		       double * W_GRID )
{
  /* This function reads an (x, y, z)-file (Name) */
  /* 
     Notice that this function can only handle 3 column files of a GRID type. This 
     is those containing a map for No_of_POINTS_1 times No_of_POINTS_2 grid. 
  */
  FILE * fp;
  double x,y,z;
  int j,k, n;

  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    n = 0;
    if( (fp = fopen(Name,"r") ) == NULL) {
      printf("File %s on-existent in current directory!!!\n --- Cannot open file.\n", Name);
      exit(1);
    }
    for( k = 0; k < No_of_POINTS_2; k++ ) {
      for( j = 0; j < No_of_POINTS_1; j++ ){
	fscanf(fp, "%lf\t%lf\t%lf\n", &x, &y, &z);
	x_Data[j] = x; y_Data[k] = y; W_GRID[n++] = z;
      }
    }
    fclose(fp);
  /*   END : ----------------------------------------------------------------------*/
}  

void P_A_R_A_M_E_T_E_R___F_I_L_E___X_Y_Z___R_E_A_D ( Parameter_FILE * Table, 
						     int i, 
						     double * x_Data, 
						     double * y_Data, 
						     double * W_GRID )
{
  /* This function reads the i-th (x, y, z)-file (from the argument list) */
  /* This is the same function as F_I_L_E___X_Y_Z___R_E_A_D(...), but with a different 
     name for back compatibility 
  */
  /* 
     Both functions can only handle 3 column files of a GRID type. This 
     is those containing a map for No_of_POINTS_1 times No_of_POINTS_2 grid. 
  */

  FILE * fp;
  int No_of_POINTS_1, No_of_POINTS_2;
  double x,y,z;
  int j,k, n;

  assert( i < Table->No_of_FILES );
  No_of_POINTS_2 = Table->F_y_GRID[i]; No_of_POINTS_1 = Table->F_x_GRID[i];
  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    n = 0;
    if( (fp = fopen(Table->Name_of_FILE[i],"r") ) == NULL) {
      printf("File %s on-existent in current directory!!!\n --- Cannot open file.\n", Table->Name_of_FILE[i]);
      exit(1);
    }
    for( k = 0; k < No_of_POINTS_2; k++ ) {
      for( j = 0; j < No_of_POINTS_1; j++ ){
	fscanf(fp, "%lf\t%lf\t%lf\n", &x, &y, &z);
	x_Data[j] = x; y_Data[k] = y; W_GRID[n++] = z;
      }
    }
    fclose(fp);
  /*   END : ----------------------------------------------------------------------*/
}  

void F_I_L_E___X_Y_Z___R_E_A_D___3_C ( Parameter_FILE * Table, 
				       int i, 
				       double * x_Data, 
				       double * y_Data, 
				       double * z_Data )
{
  /* This function reads the i-th (x, y, z)-file (from the argument list) */
  
  FILE * fp;
  double x,y,z;
  int k;
  int No_of_POINTS_1, No_of_POINTS_2;

  assert( i < Table->No_of_FILES );
  No_of_POINTS_2 = Table->F_y_GRID[i]; No_of_POINTS_1 = Table->F_x_GRID[i];
  
  assert( No_of_POINTS_2 == 3);
  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * * * * * * */;
    if( (fp = fopen(Table->Name_of_FILE[i],"r") ) == NULL) {
      printf("File %s on-existent in current directory!!!\n --- Cannot open file.\n", Table->Name_of_FILE[i]);
      exit(1);
    }
    for( k = 0; k < No_of_POINTS_1; k++ ) {
      
	fscanf(fp, "%lf\t%lf\t%lf\n", &x, &y, &z);
	x_Data[k] = x; y_Data[k] = y; z_Data[k] = z;
      
    }
    fclose(fp);
  /*   END : ----------------------------------------------------------------------*/
}  

void X_Y_Z___R_E_A_D___3C ( char * Name, 
			    double * x_Data, 
			    double * y_Data,
			    double * z_Data, 
			    int * No_of_POINTS)
{
  /* This function reads the xyz file (Name) 
     Important note: The number of columns of this file should be 
     always 3. Otherwise, another reading function is required	
  
     This a version of the last function which counts the number of elements 
     of the three column vectors, x_Data, y_Data, z_Data, an returns it as 
     pointer to No_of_POINTS. 
  */
  FILE * fp;
  double x,y,z;
  int n;   

  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * */
    if( (fp = fopen(Name,"r") ) == NULL) {
      printf("File %s on-existent in current directory!!!\n --- Cannot open file.\n", Name);
      exit(1);
    }
    
    n=0;                                         
    while (fscanf(fp, "%lf\t%lf%lf\n", &x, &y, &z) != EOF ){  
      x_Data[n] = x; y_Data[n] = y; z_Data[n] = z; 
      n++;
    }
    fclose(fp);

    (*No_of_POINTS) = n;
  /*   END : -----------------------------------------------------------*/
}  




