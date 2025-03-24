#include "cpgplot_headers.h"

void cpg_XY_shade_between_curves( int n, 
				  float * x, float * y_1, float * y_2,
				  int color_Index, 
				  int type_of_Line, 
				  int type_of_Width)
{
  /* This function produces a shade between the curves defined by (x, y_1) and (x, y_2). */
  /* This function should be always called after having drawn the two curves on a graph, so
     that the shade appears on the same graph.                                           */
  int i;
  int FS;

  cpgslw(type_of_Width);
  cpgsci(color_Index);
  cpgsls(type_of_Line);

  /* FILL AREA ATRIBUTES...   void cpgsfs(int FS);
        Four different styles are available: 
        solid (fill polygon with solid color of the current color-index), 
        outline (draw outline of polygon only, using current line attributes),
        hatched (shade interior of polygon with parallel lines, using
        current line attributes), or cross-hatched. The orientation and
        spacing of hatch lines can be specified with routine PGSHS (set
        hatch style).
        Argument:
        FS     (input)  : the fill-area style to be used for subsequent
                        plotting:
                        FS = 1 => solid (default)
                        FS = 2 => outline
                        FS = 3 => hatched
                        FS = 4 => cross-hatched
    */
  FS = 1; cpgsfs(FS);

  float * xp   = (float *)malloc( sizeof(float) * 2 * n );
  float * yp   = (float *)malloc( sizeof(float) * 2 * n );

  for( i=0; i<n; i++ ){ 
      xp[i] = x[i];				
      yp[i] = y_1[i];
  }
  for( i=0; i<n; i++ ){ 
      xp[n+i] = x[n-1-i];				
      yp[n+i] = y_2[n-1-i];
  }
  
  cpgpoly(2*n, xp, yp);
  
  cpgsls(1);
  cpgslw(1);
  cpgsci(1);

  free(yp); free(xp);
}

