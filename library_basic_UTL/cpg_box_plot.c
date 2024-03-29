#include "cpgplot_headers.h"

#define SHRINKING_FACTOR_BOX 0.7

void cpg_box_plot(int SAME_PLOT, 
		  int n, float *xs, float **ys, int np, 
		  float *Range_x, float *Range_y,   
		  int Initial_color_Index, 
		  int type_of_Line, 
		  int type_of_Width, 
		  int type_of_Symbol, 
		  char *X_label, char *Y_label, char *Title)
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
  int color_Index;
  float XD; 
  float * x_line = (float *)calloc(2, sizeof(float) );
  float * y_line = (float *)calloc(2, sizeof(float) );
  
  if( SAME_PLOT == 0 ) {
    cpgslw(3.0);
    float ch;
    // cpgqch( &ch );
    cpgsch(3.0);  // cpgsch(1.2); cpgsch(2.0 * ch);  cpgsch(1.2 * ch);  
                         
    // cpgenv(Range_x[0], Range_x[1], Range_y[0], Range_y[1], 0, 1);
    /* Notice that cpgenv(...) is equivalent to this: */ 
    cpgpage();
    cpgvstd();
    cpgswin(Range_x[0], Range_x[1], Range_y[0], Range_y[1]);

    cpgsch(1.0);  
    cpgbox ("BCST", 0.0, 0, "BCNSTV", 0.0, 0); 

    // cpglab(X_label, Y_label, Title);
    /* Notice that cpglab(...) is equivanent to this: */
    cpgbbuf();
    // cpgmtxt("T", 2.0, 0.5, 0.5, Title);   // No Title if commented out
    // cpgmtxt("B", 3.2, 0.5, 0.5, X_label); // No axis title if commented out	
    // cpgmtxt("B", 3.2, 0.5, 0.5, X_label); // Please, activate this line of code
                                             // for normal box plots.  	
    cpgsch(2.0);
    cpgmtxt("L", 2.2, 0.5, 0.5, Y_label);
    cpgebuf();
 
  }

  cpgsch(1.0); // cpgsch(0.83);    
  color_Index = Initial_color_Index; cpgsci(color_Index);
  /* The fill-area style to be used:                                      */ 
  /* 			  type_of_Filling = 1 => solid (default)          */
  /*                      type_of_Filling = 2 => outline                  */
  /*                      type_of_Filling = 3 => hatched                  */
  /*                      type_of_Filling = 4 => cross-hatched            */
  if( Initial_color_Index == 2) type_of_Filling = 1;
  else                          type_of_Filling = 2;

  if( n > 1 ) XD = (xs[n-1] - xs[0] ) / (float)(n-1);
  else        XD = 1; 

  for(i=0; i<n; i++) {
    x1 = xs[i] - 0.5* SHRINKING_FACTOR_BOX * XD; 
    y1 = ys[1][i]; 
    x2 = xs[i] + 0.5*SHRINKING_FACTOR_BOX * XD; 
    y2 = ys[3][i];
  
    type_of_Width = 10;                    cpgslw(type_of_Width);
    color_Index = Initial_color_Index;    cpgsci(color_Index);
    cpg_XY_same_rectangle(x1, y1,  x2, y2,  
			  Initial_color_Index, type_of_Filling );
    
    /* Superior Vertical Line */
    /* ------------- */
    x_line[0] = xs[i];    x_line[1] = xs[i]; 
    y_line[0] = ys[3][i]; y_line[1] = ys[4][i]; 
    /* Mark '2' points (coordinates in arrays x_line and y_line  using symbol
     */
    // cpgpt(2, x_line, y_line, type_of_Symbol);
    /* Draw a strainght line to merge the points, using color_Index ... 
     */
    color_Index = 2; cpgsci(color_Index);
    type_of_Width = 1; cpgslw(type_of_Width);
    type_of_Line = 2; cpgsls(type_of_Line); 
    /* For instance, type_of_Line = 2: Dashed line */
    cpgline(2, x_line, y_line);

    /* Inferior Vertical Line */
    /* ............. */
    x_line[0] = xs[i];    x_line[1] = xs[i]; 
    y_line[0] = ys[0][i]; y_line[1] = ys[1][i]; 
    /* Mark '2' points (coordinates in arrays x_line and y_line  using symbol
     */
    // cpgpt(2, x_line, y_line, type_of_Symbol);
    /* Draw a strainght line to merge the points, using color_Index ... 
     */
    color_Index = 2; cpgsci(color_Index);
    type_of_Width = 1; cpgslw(type_of_Width);
    type_of_Line = 2; cpgsls(type_of_Line); 
    /* For instance, type_of_Line = 2: Dashed line */
    cpgline(2, x_line, y_line);

    /* Horizontal Median Line */
    x_line[0] = xs[i] - 0.5* SHRINKING_FACTOR_BOX * XD; 
    x_line[1] = xs[i] + 0.5* SHRINKING_FACTOR_BOX * XD;  
    y_line[0] = ys[2][i]; y_line[1] = ys[2][i];
    color_Index = 1; cpgsci(color_Index);
    type_of_Width = 4; cpgslw(type_of_Width);
    type_of_Line = 1; cpgsls(type_of_Line); 
    /* For instance, type_of_Line = 2: Dashed line */
    cpgline(2, x_line, y_line);

    /* Upper Horizontal Line */
    x_line[0] = xs[i] - 0.25* SHRINKING_FACTOR_BOX * XD; 
    x_line[1] = xs[i] + 0.25* SHRINKING_FACTOR_BOX * XD;  
    y_line[0] = ys[4][i]; y_line[1] = ys[4][i];
    color_Index = 1; cpgsci(color_Index);
    type_of_Width = 1; cpgslw(type_of_Width);
    type_of_Line = 1; cpgsls(type_of_Line); 
    cpgline(2, x_line, y_line);

    /* Lower Horizontal Line */
    x_line[0] = xs[i] - 0.25* SHRINKING_FACTOR_BOX * XD; 
    x_line[1] = xs[i] + 0.25* SHRINKING_FACTOR_BOX * XD;  
    y_line[0] = ys[0][i]; y_line[1] = ys[0][i]; 
    color_Index = 1; cpgsci(color_Index);
    type_of_Width = 1; cpgslw(type_of_Width);
    type_of_Line = 1; cpgsls(type_of_Line); 
    cpgline(2, x_line, y_line);
  }

  free(x_line); free(y_line); 
  
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

