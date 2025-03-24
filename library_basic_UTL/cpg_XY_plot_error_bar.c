#include "cpgplot_headers.h"

void cpg_XY_plot_error_bar( int n, double * X, double * Y, double * E )
{
  /* This function plot only error bars, E, on the vertical direction 
     on the same plot or subplot at use at the moment the function is called, 
     without redefining axes or scales */
  /* The definition of line and point features is given below */ 

  int i;
  float * xs = (float *)malloc( n * sizeof(float) );
  float * ys = (float *)malloc( n * sizeof(float) );
  float * er = (float *)malloc( n * sizeof(float) );

  for(i = 0; i < n; i++){
    xs[i] = (float)X[i];
    ys[i] = (float)Y[i];
    er[i] = (float)E[i];
  }
  
  /* Defining color index, type of line, type of width and type of Symbol: */
  int color_Index = 2;
  int type_of_Line = 1;
  int type_of_Width = 4;

  cpgsci(color_Index);  
  cpgslw(type_of_Width);
  cpgsls(type_of_Line); 

  /* When the last parameter at the cpgerrb call is 0.0
     no tips of the bars are drawn */
  cpgerrb(6, n, xs, ys, er, 1.0); 

  /* Back to default defintions of line, width and symbol */
  cpgsls(1);            
  cpgslw(1);            
  cpgsci(1);
  
  free(xs); free(ys); free(er);
}
