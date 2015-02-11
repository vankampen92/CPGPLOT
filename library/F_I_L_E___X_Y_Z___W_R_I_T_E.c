#include "../CPGPLOT_HEADER.h"

void F_I_L_E___X_Y_Z___W_R_I_T_E ( Parameter_FILE * Table, 
	                           int i, 
	                           char * OUTPUT_FILE_NAME,
				   double * x_Data, 
				   double * y_Data, 
				   double * W_GRID )
{
  /* This function reads the i-th (x, y, z)-file (from the argument list) */
  
  FILE * fp;
  int No_of_POINTS_1, No_of_POINTS_2;
  double x,y,z;
  int j,k, n;

  No_of_POINTS_2 = Table->F_y_GRID[i]; No_of_POINTS_1 = Table->F_x_GRID[i];
  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    n = 0;
    fp = fopen(OUTPUT_FILE_NAME,"w");
     
    for( k = 0; k < No_of_POINTS_2; k++ ) {
      for( j = 0; j < No_of_POINTS_1; j++ ){
	fprintf(fp, "%lf\t%lf\t%lf\n", x_Data[j], y_Data[k], W_GRID[n++]);
      }
    }
    fclose(fp);
  /*   END : ----------------------------------------------------------------------*/
}  


void X_Y_Z___W_R_I_T_E ( char * Name,
		       int No_of_POINTS_1, int No_of_POINTS_2, 
		       double * x_Data, 
		       double * y_Data, 
		       double * W_GRID )
{
  /* This function reads an (x, y, z)-file (Name) */
  FILE * fp;
  double x,y,z;
  int j,k, n;

  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    n = 0;
    fp = fopen(Name,"w");
    for( k = 0; k < No_of_POINTS_2; k++ ) {
      for( j = 0; j < No_of_POINTS_1; j++ ){
	fprintf(fp, "%lf\t%lf\t%lf\n", x_Data[j], y_Data[k], W_GRID[n++]);
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
      printf("File non-existent in current directory!!!\n --- Cannot open file.\n");
      exit(1);
    }
    for( k = 0; k < No_of_POINTS_1; k++ ) {
      
	fscanf(fp, "%lf\t%lf\t%lf\n", &x, &y, &z);
	x_Data[k] = x; y_Data[k] = y; z_Data[k] = z;
      
    }
    fclose(fp);
  /*   END : ----------------------------------------------------------------------*/
}  

