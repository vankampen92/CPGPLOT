#include "cpgplot_headers.h"

void cpg_XY_same_plot( int n, float *xs, float *ys, 
		       int color_Index, int type_of_Line, int type_of_Width, int type_of_Symbol )
{  
  cpgsci(color_Index);
    
  cpgpt(n, xs, ys, type_of_Symbol);

  cpgslw(type_of_Width);
  cpgsls(type_of_Line); 
  
  cpgline(n, xs, ys);

  /* Back to default defintions of line, width and symbol */
  cpgsls(1);            
  cpgslw(1);            
  cpgsci(1);

  return;
}

