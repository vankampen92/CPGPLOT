#include "../CPGPLOT_HEADER.h"

/* Functions defined here are using the full potential 
   of the Parameter_CPGPLOT * C generic structure. */

void CPGPLOT___X_Y___S_Q_U_A_R_E_D___L_A_T_T_I_C_E (Parameter_CPGPLOT * CPG, 
                                                    double Ox, double Oy,
                                                    double Dx, double Dy,
                                                    int    Nx, int    Ny)
{
    int i;
    double x_1, y_1, x_2, y_2;
    double Sx, Sy;
    float * X = (float *)calloc( 2, sizeof(float) );
    float * Y = (float *)calloc( 2, sizeof(float) );

    int type_of_Filling; 
    int color_Index    = CPG->color_Index;
    int type_of_Line   = CPG->type_of_Line; 
    int type_of_Width  = CPG->type_of_Width;
    int type_of_Symbol = CPG->type_of_Symbol;

    Sx = Dx/(double)Nx;
    Sy = Dy/(double)Ny;

    /* Lines dividing the X axis (parallel to the Y axis) */
    for(i=0; i<Nx; i++) {
      /* Line Origin (x_1, y_1) and Line End (x_2, y_2) */
      x_1 = Ox + (double)i*Sx;
      x_2 = Ox + (double)i*Sx;
      y_1 = Oy;
      y_2 = Oy + Dy;

      X[0] = (float)x_1;  X[1] = (float)x_2;
      Y[0] = (float)y_1;  Y[1] = (float)y_2;

      cpg_XY_same_plot(2, X, Y,
                       color_Index, type_of_Line, type_of_Width, type_of_Symbol );
    }
      x_1 = Ox + Dx;
      x_2 = Ox + Dx;
      y_1 = Oy;
      y_2 = Oy + Dy;

      X[0] = (float)x_1;  X[1] = (float)x_2;
      Y[0] = (float)y_1;  Y[1] = (float)y_2;

      cpg_XY_same_plot(2, X, Y,
                       color_Index, type_of_Line, type_of_Width, type_of_Symbol );

    /* Lines dividing the Y axis (parallel to the X axis) */
    for(i=0; i<Nx; i++) {
      /* Line Origin (x_1, y_1) and Line End (x_2, y_2) */
      x_1 = Ox;
      x_2 = Ox + Dx;
      y_1 = Oy + (double)i*Sy;
      y_2 = Oy + (double)i*Sy;

      X[0] = (float)x_1;  X[1] = (float)x_2;
      Y[0] = (float)y_1;  Y[1] = (float)y_2;

      cpg_XY_same_plot(2, X, Y,
                       color_Index, type_of_Line, type_of_Width, type_of_Symbol );
    }
      x_1 = Ox;
      x_2 = Ox + Dx;
      y_1 = Oy + Dy;
      y_2 = Oy + Dy;

      X[0] = (float)x_1;  X[1] = (float)x_2;
      Y[0] = (float)y_1;  Y[1] = (float)y_2;

      cpg_XY_same_plot(2, X, Y,
                       color_Index, type_of_Line, type_of_Width, type_of_Symbol );

    free(X); free(Y);

    /* Final Thicker Frame (drawing a rectangle) */
    /* Argument: type_of_Filling (fs): the fill-area style to be used for subsequent */
    /* 			  fs = 1 => solid (default)                     */
    /*        fs = 2 => outline                             */
    /*        fs = 3 => hatched                             */
    /*        fs = 4 => cross-hatched                       */
    
    color_Index = 1; 
    type_of_Filling = 2; 

    x_1 = Ox;
    x_2 = Ox + Dx;
    y_1 = Oy;
    y_2 = Oy + Dy;
    cpg_XY_same_rectangle( x_1, y_1, x_2, y_2, color_Index, type_of_Filling );
 }

