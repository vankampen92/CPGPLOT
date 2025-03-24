#include "cpgplot_headers.h"

void cpg_XY_same_scattered( int n, float *xs, float *ys, 
			    int color_Index, int type_of_Symbol )
{  
  cpgsci(color_Index);
 
  cpgpt(n, xs, ys, type_of_Symbol);

  cpgsci(1);

  return;
}



