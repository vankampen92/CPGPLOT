#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */    

#if defined CPGPLOT_REPRESENTATION
void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___R_E_C_T_A_N_G_L_E_S( Parameter_CPGPLOT * CPG,
								   double * W, 
								   int FIRST_PLOT,
								   int no_of_COLORS, 
								   double * COLOR_STATES,
								   double i_PLOT )
{
  /*  Input parameters:
      . no_of_COLORS: number of different color states (i.e., 4)
      . COLOR_STATES[0] = 1.0; COLOR_STATES[1] = 2.0; COLOR_STATES[2] = 3.0; COLOR_STATES[3] = 4.0;
      which means that when W[i] takes the value 1.0, then the corresponding rectangle will be drawn and 
      filled with the first color in index. This involves that the array W[] should only contain values 
      1.0, 2.0, 3.0 and 4.0, in this example. 
      . CPG plotting data structure:  
      . W: GRID (values to plot) as a pointer to  double array.  
      . i_PLOT: the 2D plot is drawn for each value of i_PLOT. For instance i_PLOT could be a given time or a parameter value.
      
      Output:
      Color grid where a W value is plotted at each lattice node as a snabshot at a 
      given value of i_PLOT:
  */ 
  int i;
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

  /* BEGIN: Title and axes labels to annote the plot */
  char * Number = (char *)calloc( 20, sizeof(char) );                                
  /*   END: Title and axes labels */

  int n_SITES = L__X * L__Y;
  float * g = (float *)calloc( n_SITES, sizeof(float) );
  for(i=0; i<n_SITES; i++){			
      g[i]= (float)W[i];
  }
  
  float * colors = (float * )calloc( no_of_COLORS,  sizeof(float) );
  for(i=0; i<no_of_COLORS; i++){			
      colors[i]= (float)COLOR_STATES[i];
  }

  int Status = C_P_G___P_L_O_T_T_I_N_G___2d___C_O_L_O_R___R_E_C_T_A_N_G_L_E_S___D_R_I_V_E_R ( FIRST_PLOT,  g, 										 
										 no_of_COLORS, colors,
										 ORIGIN,
										 L__X, L__Y, X_d, Y_d,
										 CPG->X_label, 
										 CPG->Y_label, 
										 CPG->W_label, 
										 CPG->Title );
  
  free( Number );
  free( g );
  free( colors );
}
         
int C_P_G___P_L_O_T_T_I_N_G___2d___C_O_L_O_R___R_E_C_T_A_N_G_L_E_S___D_R_I_V_E_R ( int FIRST_PLOT, float * g,  
										   int no_of_COLORS, float * colors, 
										   double * ORIGIN, 
										   int L__X, int L__Y,
										   double X_d, double Y_d,
										   char * X_label, 
										   char * Y_label, 
										   char * W_label,
										   char * Title )
{
  /* Input parameters:
     . W_SCALE: Variable controling self-ajustment of the vertical 
     third dimension scale (W_SCALE = 1 for self-ajustment)
     . W_RANGE[0], W_RANGE[1], max and min values for the vertical 
     third dimension axis, when W_SCALE = 0, i.e., no self-ajustment. 
     . G: multi-species grid structure;
     . n: species label;
     . L__X, L__Y: grid dimensions;
     Notice that L__X is the number of subdivision in horizontal axis
     (no of columns of array g[]), and L_Y is the number of
     subsdivisions of the vertical axis (the number of rows of matrix g[]). 
     . X_d, Y_d: corresponding physical dimensions of the grid
     . X_label, Y_label, W_label, and Title of the output PGPLOT
  */
  int i,j,k;
  float x1, y1;
  float x2, y2;
  int n_SITES;
  float step_X, step_Y;
  float x_rect_1, x_rect_2, y_rect_1, y_rect_2;
  int color_Index;

  n_SITES = L__X * L__Y;

  printf(" Plot title: %s\n", Title);
  printf(" X axes label: %s\n", X_label);
  printf(" Y axes label: %s\n", Y_label);
  printf(" Z axes label: %s\n", W_label);
  
    /* x1 = (float)ORIGIN[0]; */
    /* y1 = (float)ORIGIN[1]; */

    x1 = (float)ORIGIN[0] + 0.5 * (float)X_d/(float)L__X;
    y1 = (float)ORIGIN[1] + 0.5 * (float)Y_d/(float)L__Y;
  
    x2  = x1 + (float)X_d;
    y2  = y1 + (float)Y_d;

    if (FIRST_PLOT == 0){  
      cpgpage();
      // cpgvstd();
      cpgsvp(0.2, 0.975, 0.2, 0.8);
    }

    cpgswin( x1, x2, y1, y2 );

    step_X =  (x2 - x1)/(float)L__X;
    step_Y =  (y2 - y1)/(float)L__Y;
  
  /* BEGIN : Drawing the rectangles */
    for(j=0; j<L__Y; j++) {
      
      y_rect_1 = (float)j     * step_Y + y1;
      y_rect_2 = (float)(j+1) * step_Y + y2;

      for(i=0; i<L__X; i++) {
	
	x_rect_1 = (float)i     * step_X + x1;
	x_rect_2 = (float)(i+1) * step_X + x1;
	
	k = j* L__X + i; assert (k < n_SITES);
 	color_Index = which_COLOR ( g[k], colors, no_of_COLORS );  

	cpgsci(color_Index);
	cpgrect(x_rect_1, x_rect_2, y_rect_1, y_rect_2);
      
    }
  }     
  /* Bact to default styles */
  cpgsls(1);             cpgslw(1);            cpgsci(1);
  /*  END : Drawing the rectangles */

  if (FIRST_PLOT == 0){
      cpgslw(3);
      cpgsci(1);                          /* Back to default color  */
      
      cpgsch(1.5);                        /* Character size control */
      cpgmtxt("t",1.0,0.0,0.0, Title);    

      //cpgsch(0.7);                        /* Character size control */
      cpgsch(1.0);                        /* Character size control */
      cpgbox( "bcntsi",0.0,0,       "bcntsiv",0.0,0 );

      cpgsch(1.5);                        /* Character size control */
      //cpgmtxt("b", 3.0, 1.0,1.0, X_label); 
      cpgmtxt("b", 2.20, 0.5,0.5, X_label); 

      cpgsch(1.5);                        /* Character size control */
      //cpgmtxt("l", 3.0, 1.0,1.0, Y_label); 
      cpgmtxt("l", 3.0, 0.5,0.5, Y_label); 
      
      cpgsch(1.0);                     /* Character size control */
      cpgslw(1);
      /* Axis labels and Title */ 
  }
  return(0);
}

int which_COLOR (float g, float * colors, int n )
{
  int k;
  int Color_Index; 
 
  k           =  (int)g;
  
  assert( k < n );
 
  Color_Index = (int)colors[k];
  
  return(Color_Index);
}  
#endif
