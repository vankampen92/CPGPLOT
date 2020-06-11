#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"

#if defined CPGPLOT_REPRESENTATION
void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___C_O_N_T_O_U_R(Parameter_CPGPLOT * CPG,
							    double * W, 
							    int FIRST_PLOT,
							    int W_SCALE, double W_min, double W_MAX, 
							    double i_PLOT )
{
  /*  Input parameters:
     . W_SCALE
     . W_min, W_MAX: max and min values vertical axis.
     . no_GRID
     . T: Parameter_Table
     . W: GRID (values to plot) as a pointer to  double array.  
     . i_PLOT: the 2D plot is drawn for each value of i_PLOT. 
               For instance i_PLOT could be a given time.
      
      Output:
      Color grid where a W value is plotted at each lattice node as a snabshot at a 
      given value of i_PLOT:
  */ 
  int i;
  double W_RANGE[2];
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
  double g_min, g_MAX;
  int n_SITES = L__X * L__Y;
  float * g = (float *)malloc( n_SITES * sizeof(float) ); 
  /* BEGIN: Building float array * g from the values
     stored in the site ** G structure 
     The array has been built following the FORTRAN convention
     to store matrices in memmory, i.e., as 2-dimensional arrays 
     packed in a one-dimensional array, with the first index 
     changing fastest.
     Calculating also range size for the 3d variable
     stored in the g array (g_MAX, g_min) to be plotted.
     There is also the possibility of using a fixed scale
     for the third dimension to represent.
  */
  if( W_SCALE == 1){
    W_RANGE[0] = W_min;  W_RANGE[1] = W_MAX;
    /* W_SCALE = 0; //Fix scale to W_RANGE[]   */
    /* W_SCALE = 1; //Variable ajustable scale */
    for(i=0; i<n_SITES; i++){			
      g[i]= (float)W[i];
    }
  }
  else if (W_SCALE == 0){
    g_min = (float)W[0];
    g_MAX = (float)W[0];
    for(i=0; i<n_SITES; i++){			
      g[i]= (float)W[i];
      g_min = MIN (g_min, g[i]);
      g_MAX = MAX (g_MAX, g[i]);
    }
    W_RANGE[0] = g_min;  W_RANGE[1] = g_MAX;
  }
  else {
    printf(" W_SCALE value in CPGPLOT__G_R_I_D___P_L_O_T_T_I_N_G___C_O_N_T_O_U_R.c\n");
    printf(" [ function: void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___C_O_N_T_O_U_R (...) ]\n");
    printf(" is out of range (permitted values W_SCALE = 0, W_SCALE = 1). \n");
    printf(" Current Value: W_SCALE = %d\n", W_SCALE);
    printf(" The program will exit..."); 
    exit(0);
  }
  
  int status = C_P_G___P_L_O_T_T_I_N_G___2d___C_O_N_T_O_U_R___S_U_R_F_A_C_E___D_R_I_V_E_R ( FIRST_PLOT,  
									       W_RANGE, ORIGIN, 
									       g,
									       L__X, L__Y, X_d, Y_d,
									       CPG);
  
  free( Number );
  free( g );
}
   
int C_P_G___P_L_O_T_T_I_N_G___2d___C_O_N_T_O_U_R___S_U_R_F_A_C_E___D_R_I_V_E_R( int FIRST_PLOT,
										double * W_RANGE,
										double * ORIGIN, 
										float * g,
										int L__X, int L__Y,
										double X_d, double Y_d,
										Parameter_CPGPLOT * CPG )
{				
  /* This function is a driver for the contour-drawing function:
     void cpgcont(const float *a, int idim, int jdim, int i1, int i2, int j1, int j2, 
     const float *c, int nc, const float *tr);
     It has been inspired on 3.1 example from pgdemo2.f (PGPLOT 5.2)							
  */
  /* Input parameters:
       . W_RANGE[0], W_RANGE[1], max and min values for the vertical 
       third dimension axis, when W_SCALE = 0, i.e., no self-ajustment. 
       . g: float array to represent a grid of a given dimensions.
       . L__X, L__Y: grid dimensions.
       . X_d, Y_d: corresponding physical dimensions of the grid.
       . NC: number of contour levels;
       . AUTOMATIC_CONTOUR: 0 (yes) / 1 (user specified); 
       . X_label, Y_label, W_label, and Title of the output PGPLOT
  */
  /* This is user-provided function */
  int automatic_line_style;
  int spatial_dimension;
  float x1, y1;
  float x2, y2;
  int i;
  float tr[6];
  float c_level;
  float * contour_level;
  char * contour_label = (char *)calloc( 20, sizeof(char) );
  
  int NC                = CPG->NC;
  int AUTOMATIC_CONTOUR = CPG->AUTOMATIC_CONTOUR;
  char * X_label = CPG->X_label; 
  char * Y_label = CPG->Y_label; 
  char * W_label = CPG->W_label; 
  char * Title   = CPG->Title; 
 
  if( AUTOMATIC_CONTOUR == 0 ) {
    
    contour_level = CPG->contour_level ;
    NC = CPG->NC;
  }
  else if (AUTOMATIC_CONTOUR == 1 ) {
    contour_level = (float *)calloc( NC, sizeof(float) );
    
    assert(NC > 1);
    for( i=0; i < NC; i++) {
      contour_level[i] = (float)W_RANGE[0] + (float)i * ( (float)W_RANGE[1]-(float)W_RANGE[0] ) / (float)(NC-1);
    }
  }
  else {
    printf(" AUTOMATIC_CONTOUR value in CPGPLOT__G_R_I_D___P_L_O_T_T_I_N_G___C_O_N_T_O_U_R.c\n");
    printf(" [ function: void C_P_G___P_L_O_T_T_I_N_G___2d___C_O_N_T_O_U_R___S_U_R_F_A_C_E___D_R_I_V_E_R (...) ]\n");
    printf(" is out of range (permitted values AUTOMATIC_CONTOUR = 0, AUTOMATIC_CONTOUR = 1). \n");
    printf(" Current Value: AUTOMATIC_CONTOUR = %d\n", AUTOMATIC_CONTOUR);
    printf(" The program will exit..."); 
    exit(0);
  }
  
  printf(" Plot title: %s\n", Title);
  printf(" X axes label: %s\n", X_label);
  printf(" Y axes label: %s\n", Y_label);
  printf(" Z axes label: %s\n", W_label);
  printf(" Max Value (Z_min) = %g\t Min Value (Z_MAX) = %g\n", W_RANGE[0], W_RANGE[1]);
  float g_min = (float)W_RANGE[0]; float g_MAX =  (float)W_RANGE[1]; 
  
  printf(" Contour levels: \n");
  for( i=0; i<NC; i++) {
    printf("[contour_level(%d) = %f] ", i, contour_level[i]);
  }
  printf("\n");   //getchar();
    
  float x_FACTOR, y_FACTOR;
  x_FACTOR = 1.0; y_FACTOR = 1.0;
    // if x_FACTOR and y_FACTOR are 1.0, then 
    // the lattice to plot keep the proportions
    // of the initial lattice physical dimensions  
    // as given by X_d and Y_d.
    
  // Set the coordinate transformation matrix: 
  // world coordinate = conversion value of one grid square 
    tr[0] = (float)ORIGIN[0];
    tr[1] = x_FACTOR * (float)X_d/(float)L__X;;
    tr[2] = 0.0;
    
    tr[3] = (float)ORIGIN[1];
    tr[4] = 0.0;
    tr[5] = y_FACTOR * (float)Y_d/(float)L__Y;
    
    x1 = (float)ORIGIN[0] + 0.5 * tr[1];
    y1 = (float)ORIGIN[1] + 0.5 * tr[5];
    
    x2  = x1 + (float)L__X * tr[1];
    y2  = y1 + (float)L__Y * tr[5];
    
    if (FIRST_PLOT == 0){  
      cpgpage();
      cpgvstd();   
    }
    
    cpgswin( x1, x2, y1, y2 );

  /* Draw the map.  PGCONT is called once for each contour, using */
  /* different line attributes to distinguish contour levels.     */
  cpgbbuf();
    
  if (FIRST_PLOT == 0){
    /* Comment out this line if you only need contours without
       any shading */
    cpgimag(g, L__X,L__Y,  1,L__X, 1,L__Y, g_min, g_MAX, tr);
  }
  
  if( AUTOMATIC_CONTOUR == 1) {
  /* 
     Possibility of drawing all contours at once:   
  */   
  cpgcons(g, L__X,L__Y,  1,L__X, 1,L__Y, contour_level, NC, tr);
     
  }
  else {
  
  for (i=0; i<NC; i++){
      
      c_level = contour_level[i];
      
      /* Definining contours lines */
      if    ( i%2 == 0 ) { cpgsci(1); cpgslw(2); cpgsls(2); cpgsci(15); }
      else               { cpgsci(1); cpgslw(3); cpgsls(1); cpgsci(15); }
      
      if ( AUTOMATIC_CONTOUR == 0 ) automatic_line_style = -1;
      else                          automatic_line_style = +1; 

      if (i == 0) {
	cpgsls(2);  /* 2: Dashed */
	cpgslw(10);
      }
      
      cpgcont(g, L__X,L__Y,  1,L__X, 1,L__Y, &c_level, automatic_line_style, tr);

      if (i == 0) {
	cpgsls(1);  /* 1: Non-Dashed */
	cpgslw(1);
      }
      
      // if( i == 10 ){
	int status = sprintf(contour_label, "%g", c_level);
	/* intval (input) : spacing along the contour between labels, in
	   grid cells.
	   minint (input) : contours that cross less than MININT cells
	   will not be labelled.
	*/
	spatial_dimension = (int)( ( (float)L__X + (float)L__Y/2.0 ) / 4.0 );
	
	int intval = spatial_dimension;
	int minint = spatial_dimension;
	
	cpgconl(g, L__X,L__Y,  1,L__X, 1,L__Y, c_level, tr, contour_label, intval, minint);
      // }
  }

  }
  //getchar(); 
  cpgebuf();  

  if (FIRST_PLOT == 0){
    cpgsci(1);                          /* Back to default color  */
    cpgsch(0.7);                        /* Character size control */
    cpgbox( "bcntsi",0.0,0,       "bcntsiv",0.0,0 );
    
    cpgsch(1.0);                        /* Character size control */
    cpgslw(2);
    cpglab(X_label, Y_label, Title);
    cpgslw(1);
    /* Axis labels and Title */ 
  }
    
  cpgslw(1);
  cpgsls(1);
  cpgsci(1);
  
  if ( AUTOMATIC_CONTOUR == 1 ) free (contour_level); 
  // Otherwise, the array of contour values is de-allocated at the level 
  // of the main program! 
  return(0);
}
#endif
