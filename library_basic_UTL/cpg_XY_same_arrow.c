#include "cpgplot_headers.h"

void cpg_XY_same_arrow( int n, float *xs, float *ys, 
			int color_Index, int type_of_Line, int type_of_Width )
{ 
  int i;
  float x1,y1, x2,y2;
  
  cpgsci(color_Index);
  cpgslw(type_of_Width);
  cpgsls(type_of_Line); 
  
  cpgsah(1, 40.0, 0.6);
  
  // i = 50;
  assert(n == 2); 

  x1 = xs[0]; 
  y1 = ys[0];
  x2 = xs[1]; 
  y2 = ys[1];
  
  cpgarro(x1, y1,  x2, y2);

  /* k = (int)( (double)n/2.0 );   */
  /* for (i=1; i<n; i++) {         */
  /*   if ( i%k == 0 ) {           */
  /*     x1 = xs[i-1];             */
  /*     y1 = ys[i-1];             */
  /*     x2 = xs[i];               */
  /*     y2 = ys[i];               */
  /*     cpgarro(x1, y1,  x2, y2); */
  /*   }                           */
  /* }                             */
 
  /* Back to default defintions of line, width and symbol */
  cpgsls(1);            
  cpgslw(1);            
  cpgsci(1);

  return;
}
  
/* void cpgsah(int fs, float angle, float barb);                        */

/*       SUBROUTINE PGSAH (FS, ANGLE, BARB)                             */
/*       INTEGER  FS                                                    */
/*       REAL ANGLE, BARB                                               */

/* Set the style to be used for arrowheads drawn with routine PGARRO.   */

/* Argument:                                                            */
/*  FS     (input)  : FS = 1 => filled; FS = 2 => outline.              */
/*                    Other values are treated as 2. Default 1.         */
/*  ANGLE  (input)  : the acute angle of the arrow point, in degrees;   */
/*                    angles in the range 20.0 to 90.0 give reasonable  */
/*                    results. Default 45.0.                            */
/*  BARB   (input)  : the fraction of the triangular arrow-head that    */
/*                    is cut away from the back. 0.0 gives a triangular */
/*                    wedge arrow-head; 1.0 gives an open >. Values 0.3 */
/*                    to 0.7 give reasonable results. Default 0.3.      */
