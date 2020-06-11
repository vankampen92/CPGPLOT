#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"
/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */    

#if defined CPGPLOT_REPRESENTATION
int C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_U_B_R_E_G_I_O_N ( Parameter_CPGPLOT * CPG,
								  int FIRST_PLOT, 
								  double * X, double * Y, 
								  int Total_POINTS )
{
  /*  Input parameters:
     . (X,Y): a number of Total_POINTS defines the subregion of the parameter space 
     that will be highlighted. 
           
     Output:
     . Region plotted on a grid   
  */ 
  int k;
  double ORIGIN[2];
  int L__X; /* No of divisions in the horizontal (x_GRID) and vertical (y_GRID) axes are equal to the */
  int L__Y; /* number of COLs (L__Y) and ROWs (L__X), respectively, in the final matrix represent  */
  double X_d;
  double Y_d;

  L__X = CPG->y_GRID; /* No of divisions in the horizontal (x_GRID) and vertical (y_GRID) axes are equal to the */
  L__Y = CPG->x_GRID; /* number of COLs (L__Y) and ROWs (L__X), respectively, in the final matrix represent  */
  X_d = CPG->X_Dimension;
  Y_d = CPG->Y_Dimension;
  ORIGIN[0]  = CPG->ORIGIN_X; 
  ORIGIN[1]  = CPG->ORIGIN_Y;
  /*
     . L__X, L__Y: grid dimensions;
     Notice that L__X is the number of subdivision in horizontal axis
     (no of columns of array g[]), and L_Y is the number of
     subsdivisions of the vertical axis (the number of rows of matrix g[]). 
     . X_d, Y_d: corresponding physical dimensions of the grid
     . X_label, Y_label, W_label, and Title of the output PGPLOT
  */
  int n_SITES;
  float x1, y1;
  float x2, y2;
  float step_X, step_Y;
  float x_rect_1, x_rect_2, y_rect_1, y_rect_2;
  float xpt, ypt;
  int color_Index;

  n_SITES = L__X * L__Y;
  
  /* x1 = (float)ORIGIN[0]; */
  /* y1 = (float)ORIGIN[1]; */

  x1 = (float)ORIGIN[0] + 0.5 * (float)X_d/(float)L__X;
  y1 = (float)ORIGIN[1] + 0.5 * (float)Y_d/(float)L__Y;
  
  x2  = x1 + (float)X_d;
  y2  = y1 + (float)Y_d;

  if (FIRST_PLOT == 0){  
      cpgpage();
      cpgvstd();
      //cpgsvp(0.0, 1.0, 0.0, 1.0);
  }
  cpgswin( x1, x2, y1, y2 );

  step_X =  (x2 - x1)/(float)L__X;
  step_Y =  (y2 - y1)/(float)L__Y;
  
  /* BEGIN : Drawing subregion */
  for(k=0; k<Total_POINTS ;k++) {
      
    y_rect_1 = (float)Y[k];
    y_rect_2 = (float)Y[k] + step_Y;

    x_rect_1 = (float)X[k];
    x_rect_2 = (float)X[k] + step_X;
	
    color_Index = CPG->color_Index; /* 14: Dark gray */
    cpgsci(color_Index);
    // cpgrect(x_rect_1, x_rect_2, y_rect_1, y_rect_2);

    //if( k%2 == 0 ) {
      xpt = (x_rect_1 + x_rect_2)/2.0;
      ypt = (y_rect_1 + y_rect_2)/2.0;
    
      cpgpt1(xpt, ypt, CPG->type_of_Symbol);
    //}
  }     
  /*  END : Drawing subregion */
  
  if (FIRST_PLOT == 0){
    /* Axis labels and Title */ 
    cpgslw(2);
    cpgsci(1);                        /* Back to default color */
    
    cpgsch(1.0);                      /* Character size control */
    cpgmtxt("t",1.0,0.0,0.0, CPG->Title);  

    cpgsch(0.8);                      /* Character size control */  
    cpgbox( "bcntsi",0.0,0,       "bcntsiv",0.0,0 );
    cpgsch(1.25);                     /* Character size control */

    cpgsch(1.0);                     /* Character size control */
    //cpgmtxt("b", 3.0, 1.0,1.0, X_label); 
    cpgmtxt("b", 3.0, 0.5,0.5, CPG->X_label); 
    
    cpgsch(1.0);                      /* Character size control */
    //cpgmtxt("l", 3.0, 1.0,1.0, Y_label); 
    cpgmtxt("l", 3.0, 0.5,0.5, CPG->Y_label); 

    cpgsch(1.0);                     /* Character size control */
    cpgslw(1);
  }

  /* Bact to default styles */
  cpgsls(1);             cpgslw(1);            cpgsci(1);

  return(0);
}
#endif
