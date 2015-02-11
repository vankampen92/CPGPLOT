#include "cpgplot_headers.h"

void cpg_plot_random_points( float x__1, float y__1, float x__2, float y__2, 
			     int Zn, int No_of_LEVELS, double shade, 
			     int type_of_Symbol )
{
      int i;
      float xpt, ypt; 
      float step_X, step_Y;

      float x = (double)(Zn+1) * shade/(double)No_of_LEVELS;
      int i_x    = (int)x;
      float p_x = x - i_x;
      
      step_X = x__2 - x__1;
      step_Y = y__2 - y__1;
      
      for(i=0; i<i_x; i++) {
	
	xpt = x__1 + step_X * cpg_random_number();
	ypt = y__1 + step_Y * cpg_random_number();
	
	cpgpt1(xpt, ypt, type_of_Symbol);
      }
      
      if( cpg_random_number() < p_x ) {
	xpt = x__1 + step_X * cpg_random_number();
	ypt = y__1 + step_Y * cpg_random_number();
	
	cpgpt1(xpt, ypt, type_of_Symbol);
      }
}
