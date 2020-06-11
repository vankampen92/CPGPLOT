#include "cpgplot_headers.h"

void cpg_XYn_scattered (int n, int n_XY, float *xs, float **ys, float *Range_x, float *Range_y, 
			int * color_Index, 
			int * type_of_Line, int * type_of_Width, 
			int * type_of_Symbol, 
			char * X_label, char * Y_label, char * Title)
{
  int j;

  
  /* 
   * (x, y1), (x, y2), ..., (x, yn) are plotted in the same graph with different line, color, sympbol, and with
   * attributes:
   */
  /*
   * Call cpgenv to specify the range of the axes and to draw a box, and
   * cpglab to label it. The x-axis runs from 0 to 10, and y from 0 to 20.
   */
  cpgenv(Range_x[0], Range_x[1], Range_y[0], Range_y[1], 0, 1);

  //cpglab("(x)", "(y)", "PGPLOT Example (adding noise to both x and y): y = x\\u2\\d");

  cpglab(X_label, Y_label, Title);

  for(j=0; j < n_XY; j++){
  /* 
   * BEGIN : Plotting the j series (xs, ys[j]) 
   */
    cpgsci(color_Index[j]);
    cpgslw(type_of_Width[j]);
    cpgsls(type_of_Line[j]); /* For instance, type_of_Line[j] = 2: Dashed line */
    /*
     * Mark 'n' points (coordinates in arrays xs and ys[j]), using symbol
     * number type_of_Symbol_1.
     */
    cpgpt(n, xs, ys[j], type_of_Symbol[j]);
  /* 
   *   END : Plotting the j series (xs, ys[j])
   */
  }
 
  cpgsls(1);            /*  
			 * Back to full line... 
			 * type_of Line = 1: Full line 
			 */
  cpgslw(1);            /*  
			 * Back to default line width...
			 * type_of Line = 1: thinest line 
			 */
  /* 
   * Back to default color 
   */
  cpgsci(1);

  return;
}


