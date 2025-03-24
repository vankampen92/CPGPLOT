#include "../CPGPLOT_HEADER.h"

void F_I_L_E___X_Y_n___R_E_A_D ( Parameter_FILE * Table, 
			       int i, 
			       double * x_Data, 
			       double ** y_Data )
{
  /* This function reads the i-th (x, y, z)-file (from the argument list) */
  FILE * fp;
  double x;
  int j,k;
  int No_of_POINTS_1, No_of_POINTS_2;

  assert( i < Table->No_of_FILES );
  No_of_POINTS_2 = Table->F_y_GRID[i]; No_of_POINTS_1 = Table->F_x_GRID[i];
 
  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * */
    if( (fp = fopen(Table->Name_of_FILE[i],"r") ) == NULL) {
      printf("File non-existent in current directory!!!\n --- Cannot open file.\n");
      exit(1);
    }
    for( k = 0; k < No_of_POINTS_1; k++ ){
	fscanf(fp, "%lf\t", &x);
	x_Data[k] = x;
	for( j = 0; j < No_of_POINTS_2; j++ ){
	  fscanf(fp, "%lf\t", &x);
	  y_Data[j][k] = x; 
	}
	fscanf(fp, "\n");
    }
    fclose(fp);
  /*   END : -------------------------------------------------------------*/
}  

void X_Y_n___R_E_A_D ( char * Name,
		       int No_of_POINTS_1, int No_of_POINTS_2,
		       double * x_Data, 
		       double ** y_Data )
{
  /* This function reads and (x, y1, ..., yn) file (Name) */
  FILE * fp;
  double x;
  int j,k;
 
  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * */
  if( (fp = fopen(Name,"r") ) == NULL) {
      printf("File non-existent in current directory!!!\n --- Cannot open file.\n");
      exit(1);
  }
  
  for( k = 0; k < No_of_POINTS_1; k++ ){
	  fscanf(fp, "%lf\t", &x);
	  x_Data[k] = x;
	  for( j = 0; j < No_of_POINTS_2; j++ ){
	    fscanf(fp, "%lf\t", &x);
	    y_Data[j][k] = x; 
	  }
	  fscanf(fp, "\n");
  }
  
  fclose(fp);
  /*   END : -------------------------------------------------------------*/
}  

void X_Y_n___R_E_A_D___R_O_W_S ( char * Name,
                                 int * No_of_POINTS_1, int No_of_POINTS_2,
                                 double * x_Data, 
                                 double ** y_Data )
{
  /* This function reads and (x, y1, ..., yn) file (Name) */
  FILE * fp;
  double x;
  int j, n;

  /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * */
  if( (fp = fopen(Name,"r") ) == NULL) {
    printf("File non-existent in current directory!!!\n --- Cannot open file.\n");
    exit(1);
  }

  n=0;
  while( fscanf(fp, "%lf\t", &x) != EOF ) { 

  x_Data[n] = x;

  for( j = 0; j < No_of_POINTS_2; j++ ){
    fscanf(fp, "%lf\t", &x);
    y_Data[j][n] = x; 
  }

  n++;
  }

  * No_of_POINTS_1 = n;

  fclose(fp);
  /*   END : -------------------------------------------------------------*/
}  
