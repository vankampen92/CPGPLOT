#include "cpgplot_headers.h"

void cpg_XY_same_rectangle( float x1, float y1,  
			    float x2, float y2,  
			    int color_Index, int type_of_Filling )
{  
  /* Coordinates of the bottom left corner: (x1, y1) */
  /* Coordinates of the upper right corner: (x2, y2) */

  cpgsci(color_Index);
  
  cpgsfs(type_of_Filling);

  cpgrect(x1, x2,  y1, y2);

  cpgsci(1);
  cpgsfs(1);

  return;
}


/* void cpgsfs(int fs);                                                 */
/* Argument: fs(input)  : the fill-area style to be used for subsequent */
/* 			  plotting:                                     */
/* 			  fs = 1 => solid (default)                     */
/*                        fs = 2 => outline                             */
/*                        fs = 3 => hatched                             */
/*                        fs = 4 => cross-hatched                       */
