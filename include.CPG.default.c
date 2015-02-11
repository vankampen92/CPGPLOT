CPG__PANEL__X = 1;
CPG__PANEL__Y = 1;

CPG_SCALE_X = 0;
CPG_RANGE_X_0 = 0.0;
CPG_RANGE_X_1 = 1.0;

CPG_SCALE_Y = 0;
CPG_RANGE_Y_0 = 0.0;
CPG_RANGE_Y_1 = 1.0;

CPG_LINE_TYPES = 1;
color_Index = 1;
type_of_Line = 1; 
type_of_Width = 2; 
type_of_Symbol = 1;

char * p_CPG_Name;

X_label  = (char *)malloc( sizeof(char) * 500 );
Y_label  = (char *)malloc( sizeof(char) * 500 );
Title    = (char *)malloc( sizeof(char) * 500 );

CPG_LABEL_TYPES = 0;
X_label[0] = '\0';
p_CPG_Name = strcat( X_label, "X" );

Y_label[0] = '\0';
p_CPG_Name = strcat( Y_label, "Y" );

Title[0] = '\0';
p_CPG_Name = strcat( Title, "T I T L E" );

W_label  = (char *)malloc( sizeof(char) * 500 );

W_label[0] = '\0';
p_CPG_Name = strcat( W_label, "Z   v a l u e s" );

CPG_SCALE_W = 0;
CPG_RANGE_W_0 = 0.0; 
CPG_RANGE_W_1 = 1.0;

x_GRID = 50; /* No of divisions in the horizontal (x_GRID) and vertical (y_GRID) axes are equal to the */
y_GRID = 50; /* number of COLs (L__Y) and ROWs (L__X), respectively, in the final matrix represent     */
X_Dimension = 50.0;
Y_Dimension = 50.0;
ORIGIN_X    = 0.0; 
ORIGIN_Y    = 0.0;

/* Contour drawing over a 2D grid */
NC                = 10;
AUTOMATIC_CONTOUR = 1;

/* Type of output driver for the graphic to be send to print/write */
CPG_DRIVER_NAME    = (char *)calloc( 100, sizeof(char) );
CPG_DRIVER_NAME[0] = '\0';
p_CPG_Name = strcat( CPG_DRIVER_NAME, "/XSERVE" );

/* SIDE   (input)  : The first character must be one of the characters
                   'B', 'L', 'T', or 'R' signifying the Bottom, Left,
                   Top, or Right edge of the viewport.
                   The second character should be 'I' to use PGIMAG
                   to draw the wedge, or 'G' to use PGGRAY.
*/
SIDE               = (char *)malloc( 3 * sizeof(char) ) ;
SIDE[0]            = '\0';
Type_of_COLOR_SHADING = 2;   // Parameters controling 2d   G_R_I_D   S_H_A_D_E_S 
Type_of_BRIGHT        = 0.5; //
Type_of_CONTRA        = 1.0; //	

