#include "plcdemos.h"

#define No_of_POINTS_MAX 20000

void plplot3D_xyz_bifu_curves(double *** X,
			      double *** Y,
			      double *** Z,
			      int ** npts, int N,
			      double * Range_x,
			      double * Range_y,
			      double * Range_z,
			      char * x_Label,
			      char * y_Label,
			      char * z_Label)
{
  int i, k, n;
  PLFLT * x = (PLFLT *) malloc(No_of_POINTS_MAX * sizeof(PLFLT));
  PLFLT * y = (PLFLT *) malloc(No_of_POINTS_MAX * sizeof(PLFLT));
  PLFLT * z = (PLFLT *) malloc(No_of_POINTS_MAX * sizeof(PLFLT));
  char title[80];
  static int OPT[] = { 1, 0 };
  static PLFLT ALT[] = {20.0, 35.0, 50.0, 65.0};
  static PLFLT AZ[]  = {30.0, 40.0, 50.0, 60.0};
  PLFLT color[]      = {3, 7, 1}; 
  
  int naz = 1;            /* Altitud/Azimut Options */  
  int nop = 1;            /* lines vs point Option  */
  /* OPT[0]=1 : lines between points                */
  /* OPT[1]=0 : single points represented by symbol */

  plscolbg(255,255,255);  /* Background color: White */
  
  plinit();
  pladv(0);
  plvpor(0.0, 1.0, 0.0, 0.9);
  plwind(-1.0, 1.0, -0.9, 1.1);
  plcol0(8); /* Brown foreground color */
  
  plw3d(1.0, 1.0, 1.0,
	(PLFLT)Range_x[0], (PLFLT)Range_x[1],
	(PLFLT)Range_y[0], (PLFLT)Range_y[1],
	(PLFLT)Range_z[0], (PLFLT)Range_z[1],
	ALT[naz], AZ[naz]);

  plbox3("bnstu", x_Label, 0.0, 0,
	 "bnstu", y_Label, 0.0, 0,
	 "bcdmnstuv", z_Label, 0.0, 0);

  for(k = 0; k<3; k++) { 

    for(n = 0; n < N; n++) {   
	  
      for (i = 0; i < npts[n][k]; i++) {
	x[i] = (PLFLT)X[n][k][i];
	y[i] = (PLFLT)Y[n][k][i];
	z[i] = (PLFLT)Z[n][k][i];
      }
    
      // plcol0(2+k);
      
      plcol0(color[k]);
      
      // if (OPT[nop])
	plline3( npts[n][k], x, y, z );
      // else
	plpoin3( npts[n][k], x, y, z, 1 );
    }
  }
    
  plcol0(4);
  sprintf(title, "#frPLplot Bifurcation Curves - Alt=%.0f, Az=%.0f",
	  ALT[naz], AZ[naz]);
  /* No Title ===> */ title[0] = '\0'; 
  plmtex("t", 1.0, 0.5, 0.5, title);
  
  /* Clean up */
  free((void *) x);
  free((void *) y);
  free((void *) z);
  
  plend();
}
