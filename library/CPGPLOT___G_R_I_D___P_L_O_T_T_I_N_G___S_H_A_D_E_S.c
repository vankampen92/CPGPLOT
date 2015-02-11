#include "../CPGPLOT_HEADER.h"
#include "CPGPLOT___G_R_I_D.h"
/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */    

#if defined CPGPLOT_REPRESENTATION
void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S( Parameter_CPGPLOT * CPG,
							   double * W, 
							   int FIRST_PLOT,
							   int W_SCALE, 
							   double W_min, double W_MAX, 
							   double i_PLOT )
{
  /* Input parameters:
     . W_SCALE
     . W_min, W_MAX: max and min values vertical axis.
     . T: Parameter_Table
     . W: GRID (values to plot) as a pointer to  double array.  
     . i_PLOT: the 2D plot is drawn for each value of i_PLOT. 
               For instance i_PLOT could be a given time. 
               This is given to annotate the shade plot with 
	       a different title containing this input argument. 
      
      Output:
      Color grid where a W value is plotted at each lattice node as a snabshot at a 
      given value of i_PLOT:
  */ 
  int i;
  double W_RANGE[2];
  double ORIGIN[2];
  int L__X; 
  int L__Y; 
  double X_d;
  double Y_d;

   /* No of divisions in the horizontal (x_GRID) and vertical (y_GRID) axes
      are equal to the number of COLs (L__Y) and ROWs (L__X), respectively, 
      in a matrix representation. Vigilar molt amb la matriu d'entrada, W[]. 
   */
  L__Y = CPG->y_GRID; 
  L__X = CPG->x_GRID;    
  X_d = CPG->X_Dimension;
  Y_d = CPG->Y_Dimension;
  ORIGIN[0]  = CPG->ORIGIN_X - 0.5 * X_d/(double)L__X; 
  ORIGIN[1]  = CPG->ORIGIN_Y - 0.5 * Y_d/(double)L__Y;

  /* BEGIN: Title and axes labels to annote the plot */
  char * Number = (char *)calloc( 20, sizeof(char) );                                
  /*   END: Title and axes labels */
  double g_min, g_MAX;
  int n_SITES = L__X * L__Y;
  float * g = (float *)malloc( n_SITES * sizeof(float) ); 
  /* BEGIN: Building float array * g from the double precision 
     values in * W array. The array has been built following 
     the FORTRAN convention to store matrices in memmory, i.e., 
     as 2-dimensional arrays packed in a one-dimensional array, 
     with the first index changing fastest.
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
    /* END: Building float array * g from the values
       stored in the site *** G structure 
    */
    W_RANGE[0] = g_min;  W_RANGE[1] = g_MAX;
  }
  else {
    printf(" W_SCALE value in CPGPLOT__G_R_I_D____P_L_O_T_T_I_N_G___S_H_A_D_E_S.c\n");
    printf(" [ function: void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S (...) ]\n");
    printf(" is out of range (permitted values W_SCALE = 0, W_SCALE = 1). \n");
    printf(" Current Value: W_SCALE = %d\n", W_SCALE);
    printf(" The program will exit..."); 
    exit(0);
  }
  
  int sta = C_P_G___P_L_O_T_T_I_N_G___2d___C_O_L_O_R___S_U_R_F_A_C_E___D_R_I_V_E_R ( FIRST_PLOT,  
								 W_RANGE, ORIGIN, g,
								 L__X, L__Y, X_d, Y_d,
								 CPG->X_label, 
								 CPG->Y_label, 
								 CPG->W_label, 
								 CPG->Title, 
								 CPG->SIDE, 
                                                                 CPG->Type_of_COLOR_SHADING,
								 CPG->Type_of_BRIGHT, 
								 CPG->Type_of_CONTRA );
  
  free( Number );
  free( g );
}
         
int C_P_G___P_L_O_T_T_I_N_G___2d___C_O_L_O_R___S_U_R_F_A_C_E___D_R_I_V_E_R ( int FIRST_PLOT, 
									     double * W_RANGE,
									     double * ORIGIN, 
									     float * g,
									     int L__X, int L__Y,
									     double X_d, double Y_d,
									     char * X_label, 
									     char * Y_label, 
									     char * W_label,
									     char * Title, 
									     char * Side, 
									     int COLOR, 
									     float BRIGHT, 
									     float CONTRA )
{
  /* Input parameters:
     . W_SCALE: Variable controling self-ajustment of the vertical 
     third dimension scale (W_SCALE = 1 for self-ajustment)
     . W_RANGE[0], W_RANGE[1], max and min values for the vertical 
     third dimension axis, when W_SCALE = 0, i.e., no self-ajustment. 
     . G: multi-species grid structure;
     . n: species label;
     . L__X, L__Y: grid dimensions;
     . X_d, Y_d: corresponding physical dimensions of the grid
     . X_label, Y_label, W_label, and Title of the output PGPLOT
     . char * Side: a char controling whether or not a scale bar will be added.
     . COLOR: Type of Color Shading
     . BRIGHT
     . CONTRA: // CONTRA = 1: Normal; CONTRA = -1.0: Inverted scale
  */
  float x1, y1;
  float x2, y2;
  int n_SITES;
  float g_MAX, g_min; 
  float tr[6];
  char * pFile;
  char * W_Current = (char *)calloc(200, sizeof(char) );

  W_Current[0]='\0';
  pFile = strcat(W_Current, W_label);  

  g_min   = (float)W_RANGE[0]; g_MAX = (float)W_RANGE[1];
  n_SITES = L__X * L__Y;

  /* printf(" Plot title: %s\n", Title);     */
  /* printf(" X axes label: %s\n", X_label); */
  /* printf(" Y axes label: %s\n", Y_label); */
  /* printf(" Z axes label: %s\n", W_label); */
  
  // Set the coordinate transformation matrix: 
  // world coordinate = conversion value of one grid square 
  float x_FACTOR, y_FACTOR;
  x_FACTOR = 1.0; y_FACTOR = 1.0;
  
  // if x_FACTOR and y_FACTOR are 1.0, then 
  // the lattice to plot keep the proportions
  // of the initial lattice physical dimensions  
  // as given by X_d and Y_d.

  /* This choice of x_FACTOR below assigns the same size to the 
     X dimension as it does to the Y dimension. This results in 
     a squared plot. The x axis is re-normalized. */
  // x_FACTOR = (float)Y_d/(float)X_d * (float)L__Y/(float)L__X;

  /* tr[0] = (float)ORIGIN[0];                  */
  /* tr[1] = 0.0;                               */
  /* tr[2] = x_FACTOR * (float)X_d/(float)L__Y; */
  
  /* tr[3] = (float)ORIGIN[1];                  */
  /* tr[4] = y_FACTOR * (float)Y_d/(float)L__X; */
  /* tr[5] = 0.0;                               */

  tr[0] = (float)ORIGIN[0];
  tr[1] = x_FACTOR * (float)X_d/(float)L__X; // GRID STEP on X AXIS;
  tr[2] = 0.0;
  
  tr[3] = (float)ORIGIN[1];
  tr[4] = 0.0;
  tr[5] = y_FACTOR * (float)Y_d/(float)L__Y; // GRID STEP on X AXIS;

  /*        X = TR(0) + TR(1)*I + TR(2)*J = TR(2)*J */
  /*        Y = TR(3) + TR(4)*I + TR(5)*J = TR(4)*I */

  /*        X = TR(0) + TR(1)*I + TR(2)*J = TR(1)*I */
  /*        Y = TR(3) + TR(4)*I + TR(5)*J = TR(5)*J */
  cpgsch(1.5);
  if (FIRST_PLOT == 0){
    cpgpage();
    cpg_SETVP();
  }
  cpgsch(1.0);

  /* x1 = (float)ORIGIN[0] + 0.5 * tr[2];       */
  /* y1 = (float)ORIGIN[1] + 0.5 * tr[4];       */
  /* x2  = x1 + (float)L__Y * tr[2];            */
  /* y2  = y1 + (float)L__X * tr[4];            */
  
  x1 = (float)ORIGIN[0] + 0.5 * tr[1];
  y1 = (float)ORIGIN[1] + 0.5 * tr[5];  
  x2  = x1 + (float)L__X * tr[1];
  y2  = y1 + (float)L__Y * tr[5];
  
  // cpgwnad( x1, x2, y1, y2 ); 
  /* This is exactly the same as cpgswin(...) but conserving the same aspect ratio */
  cpgswin( x1, x2, y1, y2 );                
  
  // Set up the color map.
  // float    BRIGHT = 0.5;
  // float    CONTRA = 1.0;          // CONTRA = 1.0: Normal; CONTRA = -1.0: Inverted scale
  int      Type_of_COLOR_SHADING = COLOR;
  //cpg_PALETT( 1, CONTRA, BRIGHT);// 1: GRAY; 2: Blue to Green to Red; 6: Yellow to Green 
  cpg_PALETT( Type_of_COLOR_SHADING, CONTRA, BRIGHT ); //CALL PALETT(2, CONTRA, BRIGHT)
  
  // Draw the map with PGIMAG.  
  cpgimag(g, L__X,L__Y,  1,L__X, 1,L__Y, g_min, g_MAX, tr);
  
  /* BEGIN : Annotate the plot. */
  if( FIRST_PLOT == 0 ){
    cpgslw(2);
    // cpgsch(2.0);  
    cpgsch(3.0);                     /* Character size control */
    cpgmtxt("t", 1.0, 0.0,0.0, Title);

    // cpgsch(0.6);                    /* Character size control */
    cpgsch(2.5);                      /* Character size control */
    cpgbox( "bcntsi",0.0,0,       "bcntsiv",0.0,0 );
    /* cpgbox( x axis control arg,   y axis control arg); */
    // cpgsch(1.25);                     /* Character size control */

    // cpgsch(1.0);                     /* Character size control */
    //cpgmtxt("b", 3.0, 1.0,1.0, X_label); 
    cpgsch(3.0);                     /* Character size control */
    cpgmtxt("b", 2.5, 0.5,0.5, X_label); 
    
    // cpgsch(1.0);                      /* Character size control */
    //cpgmtxt("l", 3.0, 1.0,1.0, Y_label); 
    cpgmtxt("l", 4.0, 0.5,0.5, Y_label); 
    cpgsch(1.0);                     /* Character size control */
  /*   END : Annotate the plot. */
    if ( Side[0] != '\0' ){
      char * Side_Old = (char *)calloc(2, sizeof(char) );
      strcpy (Side_Old, Side);
      pFile = strcat( Side, "I" );
  /* BEGIN: Draw a wedge.   */
    /* Arguments of cpgwedg(SIDE, DISP, WIDTH, FG, BG, LABEL):
       SIDE   (input)  : The first character must be one of the characters
                   'B', 'L', 'T', or 'R' signifying the Bottom, Left,
                   Top, or Right edge of the viewport.
                   The second character should be 'I'  to use PGIMAG
                   to draw the wedge, or 'G' to use PGGRAY.
       DISP   (input)  : the displacement of the wedge from the specified
                   edge of the viewport, measured outwards from the
                   viewport in units of the character height. Use a
                   negative value to write inside the viewport, a
                   positive value to write outside.
       WIDTH  (input)  : The total width of the wedge including annotation,
                   in units of the character height.
       FG     (input)  : The value which is to appear with shade
                   1 ("foreground"). Use the values of FG and BG
                   that were supplied to PGGRAY or PGIMAG.
       BG     (input)  : the value which is to appear with shade
                   0 ("background").
       LABEL  (input)  : Optional units label. If no label is required
                   use ' '.
    */
  
      char * Number_MAX = (char *)calloc(20, sizeof(char) );
      char * Number_min = (char *)calloc(20, sizeof(char) );
      // Extra features for the wedge: 
      // sprintf(Number_MAX, "%.2f", g_MAX);
      // sprintf(Number_min, "%.2f", g_min);
      // pFile = strcat(W_Current," Maximum [Z] value: ");   
      // pFile = strcat(W_Current, Number_MAX);
      // pFile = strcat(W_Current, "  Minimum [Z] value: "); 
      // pFile = strcat(W_Current, Number_min);
      cpgsch(2.0);                                          /* Character size control */
      /* Comment out the following line to have a wedge title */	
      cpgwedg(Side, 2.5, 4.0, g_min, g_MAX, W_Current);

      Side[0] = Side_Old[0]; Side[1] = '\0';
      free(Side_Old);
      free ( Number_MAX ); free ( Number_min ) ;
    }
    /*   END: - - - - - - - - */
  }
  
  cpgsch(1.0);                                         /* Character size control */
  free (W_Current);

  return(0);
}

void cpg_SETVP(void)
{
  /*
    SUBROUTINE SETVP (translated from pgdemo4.f)
    C-----------------------------------------------------------------------
    C Set the viewport, allowing margins around the edge for annotation.
    C (This is similar in effect to PGVSTD, but has different margins.)
    C The routine determines the view-surface size and allocates margins
    C as fractions of the minimum of width and height.
    C-----------------------------------------------------------------------
  */
  float D;
  float VPX1;
  float VPX2;
  float VPY1; 
  float VPY2;
  //
  cpgsvp(0.0, 1.0, 0.0, 1.0);
  cpgqvp(1, &VPX1, &VPX2, &VPY1, &VPY2);
  
  D = MIN( (VPX2) - (VPX1), (VPY2) - (VPY1) )/40.0;
  
  /* VPX1 = VPX1 + 5.0*D; */
  /* VPX2 = VPX2 - 2.0*D; */
  /* VPY1 = VPY1 + 8.0*D; */
  /* VPY2 = VPY2 - 2.0*D; */

  VPX1 = VPX1 + 15.0*D;
  VPX2 = VPX2 - 4.0*D;
  VPY1 = VPY1 + 10.0*D;
  VPY2 = VPY2 - 6.0*D;

  cpgvsiz( VPX1, VPX2, VPY1, VPY2);
  return;
}
									      
void cpg_PALETT( int type, float CONTRA, float BRIGHT)
{
  /* 
     SUBROUTINE PALETT(TYPE, CONTRA, BRIGHT) (translated from pgdemo4.f)
     C-----------------------------------------------------------------------
     C Set a "palette" of colors in the range of color indices used by
     C PGIMAG.
     C-----------------------------------------------------------------------
  */
  /*
    DATA GL /0.0, 1.0/
    DATA GR /0.0, 1.0/
    DATA GG /0.0, 1.0/
    DATA GB /0.0, 1.0/
  */
  float GL[2]={0.0, 1.0};
  float GR[2]={0.0, 1.0};
  float GG[2]={0.0, 1.0};
  float GB[2]={0.0, 1.0};
  /*
    DATA RL /-0.5, 0.0, 0.17, 0.33, 0.50, 0.67, 0.83, 1.0, 1.7/
    DATA RR / 0.0, 0.0,  0.0,  0.0,  0.6,  1.0,  1.0, 1.0, 1.0/
    DATA RG / 0.0, 0.0,  0.0,  1.0,  1.0,  1.0,  0.6, 0.0, 1.0/
    DATA RB / 0.0, 0.3,  0.8,  1.0,  0.3,  0.0,  0.0, 0.0, 1.0/
  */
  float RL[9]={-0.5, 0.0, 0.17, 0.33, 0.50, 0.67, 0.83, 1.0, 1.7};
  float RR[9]={0.0, 0.0,  0.0,  0.0,  0.6,  1.0,  1.0, 1.0, 1.0};
  float RG[9]={0.0, 0.0,  0.0,  1.0,  1.0,  1.0,  0.6, 0.0, 1.0};
  float RB[9]={0.0, 0.3,  0.8,  1.0,  0.3,  0.0,  0.0, 0.0, 1.0};
  /*
      DATA HL /0.0, 0.2, 0.4, 0.6, 1.0/
      DATA HR /0.0, 0.5, 1.0, 1.0, 1.0/
      DATA HG /0.0, 0.0, 0.5, 1.0, 1.0/
      DATA HB /0.0, 0.0, 0.0, 0.3, 1.0/
  */
  float HL[5] = {0.0, 0.2, 0.4, 0.6, 1.0};
  float HR[5] = {0.0, 0.5, 1.0, 1.0, 1.0};
  float HG[5] = {0.0, 0.0, 0.5, 1.0, 1.0};
  float HB[5] = {0.0, 0.0, 0.0, 0.3, 1.0};
  /* 
     DATA WL /0.0, 0.5, 0.5, 0.7, 0.7, 0.85, 0.85, 0.95, 0.95, 1.0/
     DATA WR /0.0, 1.0, 0.0, 0.0, 0.3,  0.8,  0.3,  1.0,  1.0, 1.0/
     DATA WG /0.0, 0.5, 0.4, 1.0, 0.0,  0.0,  0.2,  0.7,  1.0, 1.0/
     DATA WB /0.0, 0.0, 0.0, 0.0, 0.4,  1.0,  0.0,  0.0, 0.95, 1.0/
  */
  float WL[10] = {0.0, 0.5, 0.5, 0.7, 0.7, 0.85, 0.85, 0.95, 0.95, 1.0};
  float WR[10] = {0.0, 1.0, 0.0, 0.0, 0.3,  0.8,  0.3,  1.0,  1.0, 1.0};
  float WG[10] = {0.0, 0.5, 0.4, 1.0, 0.0,  0.0,  0.2,  0.7,  1.0, 1.0};
  float WB[10] = {0.0, 0.0, 0.0, 0.0, 0.4,  1.0,  0.0,  0.0, 0.95, 1.0};
  /*
    DATA AL /0.0, 0.1, 0.1, 0.2, 0.2, 0.3, 0.3, 0.4, 0.4, 0.5,
    :         0.5, 0.6, 0.6, 0.7, 0.7, 0.8, 0.8, 0.9, 0.9, 1.0/
    DATA AR /0.0, 0.0, 0.3, 0.3, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0,
    :         0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0/
    DATA AG /0.0, 0.0, 0.3, 0.3, 0.0, 0.0, 0.0, 0.0, 0.8, 0.8,
    :         0.6, 0.6, 1.0, 1.0, 1.0, 1.0, 0.8, 0.8, 0.0, 0.0/
    DATA AB /0.0, 0.0, 0.3, 0.3, 0.7, 0.7, 0.7, 0.7, 0.9, 0.9,
    :         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0/
  */
  float AL[20]={0.0, 0.1, 0.1, 0.2, 0.2, 0.3, 0.3, 0.4, 0.4, 0.5, 0.5, 0.6, 0.6, 0.7, 0.7, 0.8, 0.8, 0.9, 0.9, 1.0};
  float AR[20]={0.0, 0.0, 0.3, 0.3, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  float AG[20]={0.0, 0.0, 0.3, 0.3, 0.0, 0.0, 0.0, 0.0, 0.8, 0.8, 0.6, 0.6, 1.0, 1.0, 1.0, 1.0, 0.8, 0.8, 0.0, 0.0};
  float AB[20]={0.0, 0.0, 0.3, 0.3, 0.7, 0.7, 0.7, 0.7, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  
  /* Color ramp from yellow (0.0, 1.0, 1.0) to green (0.0, 1.0, 0.0) // See CONTRA = -1.0 above */
  float GREEN_L[9]={-0.5, 0.0,   0.17, 0.33,  0.50, 0.67,  0.83, 1.0,   1.7};
  float GREEN_R[9]={0.0,  0.0,   0.0,  0.0,   0.0,  0.25,  0.50, 0.75,  1.0};
  float GREEN_G[9]={0.1,  0.25,  0.5,  0.75,  1.0,  1.0,   1.0,  1.0,   1.0};
  float GREEN_B[9]={0.0,  0.0,   0.0,  0.0,   0.0,  0.0,   0.0,  0.0,   0.0};

  if(type == 1){
    /* C        -- gray scale */
    cpgctab(GL, GR, GG, GB, 2, CONTRA, BRIGHT);
  }
  else if (type == 2) {
    /* C        -- rainbow */
    cpgctab(RL, RR, RG, RB, 9, CONTRA, BRIGHT);
  }
  else if (type == 3) {
    /* C        -- heat    */
    cpgctab(HL, HR, HG, HB, 5, CONTRA, BRIGHT);
  }
  else if (type == 4) {
    /* C        -- weird IRAF */
    cpgctab(WL, WR, WG, WB, 10, CONTRA, BRIGHT);
  }
  else if (type == 5) {
    /* C        -- AIPS */
    cpgctab(AL, AR, AG, AB, 20, CONTRA, BRIGHT);
  }
  else if (type == 6) {
    /* C        -- AIPS */
    cpgctab(GREEN_L, GREEN_R, GREEN_G, GREEN_B, 9, CONTRA, BRIGHT);
  }
  else {
    printf(" There is some error in the function cpg_PALETT(...)\n");
    printf(" The type of color map is erroneous (type = %d)\n", type);
    printf(" type should be either 1, 2, 3, 4, 5, or 6.\n");
    printf(" The program will exit\n");
    exit(0);
  }  
  
  return;
}

#endif
