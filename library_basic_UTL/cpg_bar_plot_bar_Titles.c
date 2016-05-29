#include "cpgplot_headers.h"

#define SHRINKING_FACTOR_BOX 0.8

void cpg_bar_plot_bar_Titles (int SAME_PLOT, 
			      int n, float *xs, float *ys,
			      float *Range_x, float *Range_y,   
			      int color_Index, 
			      int type_of_Line, 
			      int type_of_Width, 
			      int type_of_Symbol, 
			      char *X_label, char *Y_label, char *Title, 
			      char ** Bar_Titles )
{  
  /* color_Index... (0,1, ..., 15) 0: 
     Background (black), 1: White, ..., 15 (15 different colors predefined) */
  /* type_of_Line... (1, ..., 5)     
     (only five all possible)                                               */
  /* type_of_Width... (1, ..., 201)  D
     efault, 1 = 1/200 Inches (approx 0.003 Inches)                         */
  /* type_of_Symbol...  (0, ..., 31) 
     Standard maker sympols (more markers are available. See manual)        */
  /*                                                                        */
  /* ( See http://www.astro.caltech.edu/~tjp/pgplot/subroutines.html, 
     for further details )                                                  */

  /*
   * Call cpgenv to specify the range of the axes and to draw a box, and
   * cpglab to label it. The x-axis runs from 0 to 10, and y from 0 to 20.
   */
  
  int i; 
  float x1, y1, x2, y2; 
  int type_of_Filling;

  cpgslw(4.0);
  float ch;
  cpgqch( &ch );
  cpgsch(1.5 * ch);  // cpgsch(1.2); cpgsch(2.5 * ch);  cpgsch(1.2);  

  if( SAME_PLOT == 0 ) {
    cpgpage();
    cpgvstd();
    cpgswin(Range_x[0], Range_x[1], Range_y[0], Range_y[1]); 
    cpgbox ("BC", 0.0, 0, "BCINTS", 0.0, 0);
    cpgbbuf();

    cpgmtxt("T", 2.0, 0.5, 0.5, Title);
    cpgmtxt("B", 3.2, 0.5, 0.5, X_label);	
    cpgmtxt("L", 2.2, 0.5, 0.5, Y_label);
    cpgebuf();
  // This is equivalent to a full call to cpglab(X_label, Y_label, Title);
  }
  
  cpgslw(2.0);  
  float v = - 0.05 * (Range_y[1] - Range_y[0]);
  for(i=0; i<n; i++)
    cpgptxt(xs[i], v, 30.0, 1.0, Bar_Titles[i]);

  cpgsch(1.0); // cpgsch(0.83);    
  cpgsci(color_Index);
  /* The fill-area style to be used:                                      */ 
  /* 			  type_of_Filling = 1 => solid (default)          */
  /*                      type_of_Filling = 2 => outline                  */
  /*                      type_of_Filling = 3 => hatched                  */
  /*                      type_of_Filling = 4 => cross-hatched            */
  type_of_Filling = 3; 

  float XD = (xs[n-1] - xs[0] ) / (float)(n-1); 

  for(i=0; i<n; i++) {
    x1 = xs[i] - 0.5* SHRINKING_FACTOR_BOX * XD; 
    y1 = 0.0; 
    x2 = xs[i] + 0.5* SHRINKING_FACTOR_BOX * XD; 
    y2 = ys[i];
  
    type_of_Width = 8; cpgslw(type_of_Width);
    color_Index = 2;   cpgsci(color_Index);
    cpg_XY_same_rectangle(x1, y1,  x2, y2,  
			  color_Index, type_of_Filling );
  }  
  cpgsls(1);            /*  Back to full line... 
			    type_of Line = 1: Full line 
			 */
  cpgslw(1);            /*  Back to default line width...  
			    type_of Line = 1: thinest line 
			 */
                        /* Back to default color 
                         */
  cpgsci(1);

  return;
}

