#include "cpgplot_headers.h"

void cpg_XYn_plot(int n, int n_XY, float *xs, float **ys, float *Range_x, float *Range_y, 
		  int * color_Index, int * type_of_Line, int * type_of_Width, int * type_of_Symbol, 
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
  cpgslw(2.0);
  float ch;
  cpgqch( &ch );
  //cpgsch(1.5 * ch);
  cpgsch(2.7 * ch);
  
  cpgenv(Range_x[0], Range_x[1], Range_y[0], Range_y[1], 0, 1);
  // cpglab(X_label, Y_label, Title);
  
  cpgsch(3.0 * ch);
  cpgbbuf();
  cpgmtxt("T", 2.0, 0.5, 0.5, Title);    
  cpgmtxt("B", 3.2, 0.5, 0.5, X_label);	
  cpgmtxt("L", 2.2, 0.5, 0.5, Y_label);
  cpgebuf();

  cpgsch(1.0);
  cpgslw(1.0);

  for(j=0; j < n_XY; j++){
  /* 
   * BEGIN : Plotting the j series (xs, ys[j]) 
   */
    cpgsci(color_Index[j]);
  
    /*
     * Mark 'n' points (coordinates in arrays xs and ys[j]), using symbol
     * number type_of_Symbol_1.
     */
    cpgpt(n, xs, ys[j], type_of_Symbol[j]);

  /* 
   * Draw a strainght line to merge the points, using color_Index ... 
   */
    cpgslw(type_of_Width[j]);
    cpgsls(type_of_Line[j]); /* For instance, type_of_Line[j] = 2: Dashed line */
    cpgline(n, xs, ys[j]);
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


