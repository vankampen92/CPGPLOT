#include "plcdemos.h"


void plplot3D_xyz_curves(double ** X,
			double ** Y,
			double ** Z,
			int npts, int n)
{
  int i, k; 
  PLFLT * x = (PLFLT *) malloc(npts * sizeof(PLFLT));
  PLFLT * y = (PLFLT *) malloc(npts * sizeof(PLFLT));
  PLFLT * z = (PLFLT *) malloc(npts * sizeof(PLFLT));
  char title[80];
  static int OPT[] = { 1, 0 };
  static PLFLT ALT[] = {20.0, 35.0, 50.0, 65.0};
  static PLFLT AZ[]  = {30.0, 40.0, 50.0, 60.0};

  int naz = 2;            /* Altitud/Azimut Options */  
  int nop = 0;            /* lines vs point Option  */
  /* OPT[0]=1 : lines between points                */
  /* OPT[1]=0 : single points represented by symbol */

  plinit();
  pladv(0);
  plvpor(0.0, 1.0, 0.0, 0.9);
  plwind(-1.0, 1.0, -0.9, 1.1);
  plcol0(1);
  plw3d(1.0, 1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0,
	ALT[naz], AZ[naz]);
  plbox3("bnstu", "x axis", 0.0, 0,
	 "bnstu", "y axis", 0.0, 0,
	 "bcdmnstuv", "z axis", 0.0, 0);

  for(k = 0; k<n; k++) { 
	  
    for (i = 0; i < npts; i++) {
      x[i] = (PLFLT)X[k][i];
      y[i] = (PLFLT)Y[k][i];
      z[i] = (PLFLT)Z[k][i];
    }
    
    plcol0(2+k);
    
    if (OPT[nop])
      plline3( npts, x, y, z );
    else
      plpoin3( npts, x, y, z, 1 );
  }

  plcol0(4);
  sprintf(title, "#frPLplot Bifurcation Curves - Alt=%.0f, Az=%.0f",
	  ALT[naz], AZ[naz]);
  plmtex("t", 1.0, 0.5, 0.5, title);
  
  /* Clean up */
  free((void *) x);
  free((void *) y);
  free((void *) z);
  
  plend();
}
