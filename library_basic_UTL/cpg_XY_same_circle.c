#include "cpgplot_headers.h"

void cpg_XY_same_circle( float xcent, float ycent, float radius,  
			 int color_Index, int type_of_Filling )
{  
  cpgsci(color_Index);
  
  cpgsfs(type_of_Filling);

  cpgcirc(xcent, ycent, radius);

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
