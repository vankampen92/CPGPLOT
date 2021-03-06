#include "cpgplot_headers.h"

void cpg_XY_plot_logaxis( int n, float *xs, float *ys, float *Range_x, float *Range_y, 
		 int color_Index, int type_of_Line, int type_of_Width, int type_of_Symbol, 
		 char *X_label, char *Y_label, char *Title, int TYPE_of_AXIS, int LINES )
{  
  /* color_Index... (0,1, ..., 15) 0: Background (black), 1: White, ..., 15 (15 different colors predefined) */
  /* type_of_Line... (1, ..., 5)     (only five all possible)                                                */
  /* type_of_Width... (1, ..., 201)  Default, 1 = 1/200 Inches (approx 0.003 Inches)                         */
  /* type_of_Symbol...  (0, ..., 31) Standard maker sympols (more markers are available. See manual)         */
  /*                                                                                                         */
  /* ( See http://www.astro.caltech.edu/~tjp/pgplot/subroutines.html, for further details )                  */

  /*
   * Call cpgenv to specify the range of the axes and to draw a box, and
   * cpglab to label it. The x-axis runs from 0 to 10, and y from 0 to 20.
   */
  /*  
     TYPE_of_AXIS = 10 //: draw box and label X-axis logarithmically;
     TYPE_of_AXIS = 20 //: draw box and label Y-axis logarithmically;
     TYPE_of_AXIS = 30 //: draw box and label both axes logarithmically.
  */
  /* 
     LINES = 1 //: Draw lines between points 
     LINES = 0 //: No lines between points 
  */	
  cpgslw(2.0);
  float ch;
  cpgqch( &ch );
  cpgsch(1.5 * ch);  // cpgsch(1.2);  
  //cpgsch(2.5 * ch);  // cpgsch(1.2);  
  cpgenv(Range_x[0], Range_x[1], Range_y[0], Range_y[1], 0, TYPE_of_AXIS);
  
  cpgbbuf();
  cpgmtxt("T", 2.0, 0.5, 0.5, Title);    
  cpgmtxt("B", 3.2, 0.5, 0.5, X_label);	
  cpgmtxt("L", 2.2, 0.5, 0.5, Y_label);
  cpgebuf();

  // This is equivalent to a full call to cpglab(X_label, Y_label, Title);
  cpgsch(1.0); // cpgsch(0.83);
    
  cpgsci(color_Index);
  
  /*
   * Mark 'n' points (coordinates in arrays XS and YS), using symbol
   */
  cpgpt(n, xs, ys, type_of_Symbol);
  if (LINES == 1)  {	
  /* 
   * Draw a strainght line to merge the points, using color_Index ... 
   */
    cpgslw(type_of_Width);
    cpgsls(type_of_Line); /* For instance, type_of_Line = 2: Dashed line */
    cpgline(n, xs, ys);
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

