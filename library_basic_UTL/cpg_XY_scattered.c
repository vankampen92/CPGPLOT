#include "cpgplot_headers.h"

void cpg_XY_scattered(int n, float *xs, float *ys, float *Range_x, float *Range_y, 
		      int color_Index, int type_of_Symbol, 
		      char *X_label, char *Y_label, char *Title)
{  
  /* color_Index... (0,1, ..., 15) 0: Background (black), 1: White, ..., 15 
     (15 different colors predefined) 
  */
  /* type_of_Line... (1, ..., 5)     
     (only five all possible)
  */
  /* type_of_Width... (1, ..., 201)  
     Default, 1 = 1/200 Inches (approx 0.003 Inches)                         
  */
  /* type_of_Symbol...  (0, ..., 31) Standard maker sympols 
     (more markers are available. See manual)         
  */
  /* ( See http://www.astro.caltech.edu/~tjp/pgplot/subroutines.html, 
     for further details )                  
  */
  /*
   * Call cpgenv to specify the range of the axes and to draw a box, and
   * cpglab to label it. The x-axis runs from 0 to 10, and y from 0 to 20.
   */
  
  cpgslw(3.0);
  cpgsch(1.6);  
  
  cpgenv(Range_x[0], Range_x[1], Range_y[0], Range_y[1], 0, 1);
  
  cpglab(X_label, Y_label, Title);

  cpgsch(1.0); // cpgsch(0.83);
    
  cpgsci(color_Index);
  /*
   * Mark 'n' points (coordinates in arrays XS and YS), using 
   * number 'type_of_Symbol' as symbol tag.
   */
  // cpgsch(1.5);  // cpgsch(1.2);  
  cpgpt(n, xs, ys, type_of_Symbol);
  
  /* 
   * Back to default color and size 
   */
  cpgsch(1);
  cpgsci(1);

  return;
}

