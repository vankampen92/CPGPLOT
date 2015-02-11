#include "cpgplot_headers.h"

void cpg_XY_same_scattered_pt_per_pt( int n, float *xs, float *ys, 
				      int * color_Index, int * type_of_Symbol )
{  
  int i;
  float x,y;

  for (i=0; i<n; i++) {
    
    cpgsci(color_Index[i]);
    x = xs[i]; 
    y = ys[i];

    cpgpt(1, &x, &y, type_of_Symbol[i]);
  }
  
  cpgsci(1);
  return;
}



