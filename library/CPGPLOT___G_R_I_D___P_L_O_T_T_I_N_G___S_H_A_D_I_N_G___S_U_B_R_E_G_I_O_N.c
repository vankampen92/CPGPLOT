#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"
/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */    

#if defined CPGPLOT_REPRESENTATION
int C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N (Parameter_CPGPLOT * CPG,
										int FIRST_PLOT,
										double * X, 
										double * Y, 
										double * Z,
										int Total_POINTS, 
										double x_Step,
										double y_Step, 	
										int No_of_LEVELS, 
										double THICKNESS)
{
  /*  This function is called by:
      C_P_G___P_L_O_T_T_I_N_G___X_Y_Z___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N(...) */
  /*  Input parameters:
     . (X,Y): a number of Total_POINTS defines the subregion of the parameter space 
     that will be highlighted. Highlighting intensity is defined by vector Z for each pair
     (X,Y) values. Highlighting level is defined by the Z value.  
     . THICKNESS is a pararameter representing how thick should be the shade to plot. For
     instance, if this parameter takes the value 2.0, the subregion representing the highest 
     level would be represented by 2.0 random drawing points per defining square. 
           
     Output:
     . Subregion highlighted  on a grid   
  */ 
  int i,k;
  double ORIGIN[2];
  double X_d;
  double Y_d;

  int * Zn = (int *)calloc( Total_POINTS, sizeof(int) );
  /* B E G I N : Level discretization */
  double MAX_Z, min_Z;
  double z0, z1; 
  MAX_Z = Z[0]; min_Z = Z[0];
  for (k = 0; k<Total_POINTS; k++){
    MAX_Z = MAX(MAX_Z, Z[k]); 
    min_Z = MIN(min_Z, Z[k]);
  }
  double rang_Z = MAX_Z - min_Z;
  double step_Z = rang_Z/(double)(No_of_LEVELS);

  int No_of_XYZ_POINTS = 0; 
  for (i = 0; i<No_of_LEVELS; i++) {
    z0 = min_Z + (double)(i)*step_Z;
    z1 = z0 + step_Z;
    for (k = 0; k<Total_POINTS; k++) {
      if (i > 0) {
	if( Z[k] > z0 && Z[k] <= z1 ){
	  Zn[k] = i;
	  No_of_XYZ_POINTS++;
	}
      }
      else {
	if( Z[k] > z0 && Z[k] <= z1 ){
	  Zn[k] = i;
	  No_of_XYZ_POINTS++;
	}
	else{
	  if(Z[k] == min_Z) {
	    Zn[k] = 0;
	    No_of_XYZ_POINTS++;
	  }
	}
      }
    }
  }
  assert(No_of_XYZ_POINTS == Total_POINTS);
  /*     E N D :                      */
  /*
     . X_d, Y_d: corresponding physical dimensions of the grid
     . X_label, Y_label, W_label, and Title of the output PGPLOT
  */
  X_d = CPG->X_Dimension;
  Y_d = CPG->Y_Dimension;
  ORIGIN[0]  = CPG->ORIGIN_X; 
  ORIGIN[1]  = CPG->ORIGIN_Y;
  
  float x1, y1;
  float x2, y2;
  float x_rect_1, x_rect_2, y_rect_1, y_rect_2;
  int color_Index;
  
  x1 = (float)ORIGIN[0];
  y1 = (float)ORIGIN[1];

  /* x1 = (float)ORIGIN[0] + 0.5 * x_Step */
  /* y1 = (float)ORIGIN[1] + 0.5 * y_Step */
  
  x2  = x1 + (float)X_d;
  y2  = y1 + (float)Y_d;

  if (FIRST_PLOT == 0){  
      cpgpage();
      cpgvstd();
      //cpgsvp(0.0, 1.0, 0.0, 1.0);
  }
  cpgswin( x1, x2, y1, y2 );
  
  /* Intrinsic steps, x_Step and y_Step, are those for which the (X,Y,Z) where 
     initially obtained. */ 
    
  /* BEGIN : Drawing subregion */
  cpgsch(0.5);
  for(k=0; k<Total_POINTS ;k++) {
      
    y_rect_1 = (float)Y[k] - (float)y_Step/2.0;
    y_rect_2 = (float)Y[k] + (float)y_Step/2.0;

    x_rect_1 = (float)X[k] - (float)x_Step/2.0;
    x_rect_2 = (float)X[k] + (float)x_Step/2.0;
	
    color_Index = CPG->color_Index; 
    cpgsci(color_Index);
    
    // cpgrect(x_rect_1, x_rect_2, y_rect_1, y_rect_2);
    
   
    srand(time(NULL));
    cpg_plot_random_points( x_rect_1, y_rect_1, x_rect_2, y_rect_2,
    			    Zn[k], No_of_LEVELS, THICKNESS,
    			    CPG->type_of_Symbol );
  }
  cpgsch(1.0);

  free(Zn);
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
