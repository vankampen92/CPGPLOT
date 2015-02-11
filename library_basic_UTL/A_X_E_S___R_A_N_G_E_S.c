#include "cpgplot_headers.h"

void A_X_E_S___R_A_N_G_E_S( int n, double * x, double * X_RANGE, int SCALE, float * Range_x)
{
  int i;
  double x_min, x_MAX;
  
  if(SCALE == 0){
    x_min = x[0]; x_MAX = x[0];
    for(i=0; i < n; i++){
	x_min = MIN( x_min, x[i]);
	x_MAX = MAX( x_MAX, x[i]);    
    }
  }
  else{
    x_min = X_RANGE[0]; x_MAX = X_RANGE[1];
  }
    
  Range_x[0] = (float)x_min; Range_x[1] = (float)x_MAX;
}

