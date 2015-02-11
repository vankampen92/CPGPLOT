extern int CPG__PANEL__X;
extern int CPG__PANEL__Y;

extern int CPG_SCALE_X;
extern double CPG_RANGE_X_0;
extern double CPG_RANGE_X_1;

extern int CPG_SCALE_Y;
extern double CPG_RANGE_Y_0;
extern double CPG_RANGE_Y_1;

extern int CPG_LINE_TYPES;
extern int color_Index;
extern int type_of_Line; 
extern int type_of_Width; 
extern int type_of_Symbol;

extern int CPG_LABEL_TYPES;
extern char * X_label;
extern char * Y_label; 
extern char * Title;

extern char * W_label;
extern int CPG_SCALE_W;
extern double CPG_RANGE_W_0;
extern double CPG_RANGE_W_1;

extern int x_GRID; /* No of divisions in the horizontal (x_GRID) and vertical (y_GRID) axes are equal to the */
extern int y_GRID; /* number of COLs (L__Y) and ROWs (L__X), respectively, in the final matrix represent  */
extern double X_Dimension;
extern double Y_Dimension;
extern double ORIGIN_X; 
extern double ORIGIN_Y;

/* Contour drawing over a 2D grid */
extern int NC;
extern int AUTOMATIC_CONTOUR;
extern float * contour_level;

/* Type of output driver for the graphic to be send to print/write */
extern char * CPG_DRIVER_NAME;

/* SIDE   (input)  : The first character must be one of the characters
                   'B', 'L', 'T', or 'R' signifying the Bottom, Left,
                   Top, or Right edge of the viewport.
                   The second character should be 'I' to use PGIMAG
                   to draw the wedge, or 'G' to use PGGRAY.
*/
extern char * SIDE;
extern int Type_of_COLOR_SHADING; 
extern float Type_of_BRIGHT; 
extern float Type_of_CONTRA; 
