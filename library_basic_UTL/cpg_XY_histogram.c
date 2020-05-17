#include "cpgplot_headers.h"

void cpg_XY_histogram (int n, float * data, int n_BINS,
		       float * Range_x, float * Range_y, 
		       int color_Index, int type_of_Line, int type_of_Width,
		       char * X_Label, char * Y_Label, char * Title )
{
  /* Draw a histogram of N values of a variable in array              */
  /* data(1...N) in the range DATMIN to DATMAX using NBIN bins. The   */
  /* range ind defined in input argument Range_x[]. Note that array   */
  /* elements which fall exactly on the boundary between two bins     */
  /* will be counted in the higher bin rather than the lower one      */
  /* Array elements whose value is less than DATMIN (Range_x[0])      */
  /* or ater than or equal to DATMAX (Range_x[1]) will not be counted */
  /* at all.                                                          */

  int PGFLAG  = 1; 
  /* if PGFLAG = 1, the histogram is plotted in the                   */
  /*                current window and viewport; if PGFLAG = 0,       */
  /*                PGENV is called automatically by PGHIST to start  */
  /*                a new plot (the x-limits of the window will be    */
  /*                DATMIN and DATMAX; the y-limits will be chosen    */
  /*                automatically.                                    */
  /* if PGFLAG = 2,3 the histogram will be in the same                */
  /*                window and viewport but with a filled area style. */
  /*                If pgflag=4,5 as for pgflag = 0,1, but simple     */
  /*                line drawn as for PGBIN                           */
  
  cpgsci(color_Index); cpgslw(type_of_Width); cpgsls(type_of_Line);
  
  cpghist(n, data, Range_x[0], Range_x[1], n_BINS, PGFLAG);

  cpgsci(1);           cpgslw(1);             cpgsls(1); 
}


