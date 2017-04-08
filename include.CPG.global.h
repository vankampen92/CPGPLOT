int CPG__PANEL__X;
int CPG__PANEL__Y;

int CPG_SCALE_X;
double CPG_RANGE_X_0;
double CPG_RANGE_X_1;

int CPG_SCALE_Y;
double CPG_RANGE_Y_0;
double CPG_RANGE_Y_1;

int CPG_LINE_TYPES;
int color_Index;
int type_of_Line; 
int type_of_Width; 
int type_of_Symbol;

char * X_axis_Control;
char * Y_axis_Control; 

int CPG_LABEL_TYPES;
char * X_label;
char * Y_label; 
char * Title;

char * W_label;
int CPG_SCALE_W;
double CPG_RANGE_W_0;
double CPG_RANGE_W_1;

int x_GRID; /* No of divisions in the horizontal (x_GRID) and vertical (y_GRID) axes are equal to the */
int y_GRID; /* number of COLs (L__Y) and ROWs (L__X), respectively, in the final matrix represent  */
double X_Dimension;
double Y_Dimension;
double ORIGIN_X; 
double ORIGIN_Y;

/* Contour drawing over a 2D grid */
int NC;
int AUTOMATIC_CONTOUR;
float * contour_level;

/* Type of output driver for the graphic to be send to print/write */
char * CPG_DRIVER_NAME;

/* DEVICE internal NUMBER */
int DEVICE_NUMBER;

/* SIDE   (input)  : The first character must be one of the characters
                   'B', 'L', 'T', or 'R' signifying the Bottom, Left,
                   Top, or Right edge of the viewport.
                   The second character should be 'I' to use PGIMAG */
char * SIDE;
int Type_of_COLOR_SHADING; 
float Type_of_BRIGHT; 
float Type_of_CONTRA; 

