void cpg_frame_plot(float X_0, float X_1, float Y_0, float Y_1, 
		    int type_of_Width, float character_Size,
		    char * X_control, char * Y_control); 

int color_Index_into_RGB_Map_Divergent(int icilo, int icihi, float x,  
				       float * R, float * G, float * B); 

void color_Index_into_RGB_Map(int color_Index, int icilo, int icihi,  
			      float * R, float * G, float * B);
void cpg_frame_plot_OBSOLETE(int SAME_PLOT, 
			     int n, float *xs, float *ys,
			     float *Range_x, float *Range_y,   
			     int color_Index, 
			     int type_of_Line, 
			     int type_of_Width, 
			     int type_of_Symbol, 
			     char *X_label, char *Y_label, char *Title); 

void cpg_XY_histogram (int n, float * data, int n_BINS,
		       float * Range_x, float * Range_y, 
		       int color_Index, int type_of_Line, int type_of_Width,
		       char * X_Label, char * Y_Label, char * Title );

void cpg_XYn_plot(int n, int n_XY, float *xs, float **ys, float *Range_x, float *Range_y, 
		  int * color_Index, int * type_of_Line, int * type_of_Width, int * type_of_Symbol, 
		  char * X_label, char * Y_label, char * Title);

void cpg_XYn_scattered (int n, int n_XY, float *xs, float **ys, float *Range_x, float *Range_y, 
			int * color_Index, 
			int * type_of_Line, int * type_of_Width, 
			int * type_of_Symbol, 
			char * X_label, char * Y_label, char * Title);

void cpg_XY_plot_logaxis( int n, float *xs, float *ys, float *Range_x, float *Range_y, 
			  int color_Index, int type_of_Line, 
			  int type_of_Width, int type_of_Symbol, 
			  char *X_label, char *Y_label, char *Title, 
			  int TYPE_of_AXIS, int LINES );

void cpg_XY_same_plot(int n, float *xs, float *ys, 
		      int color_Index, int type_of_Line, 
		      int type_of_Width, int type_of_Symbol );

void cpg_XY_plot(int, float *, float *, float *, float *, 
			int, int, int, int, 
			char *, char *, char *);

void cpg_bar_plot(int SAME_PLOT, 
		  int n, float *xs, float *ys,
		  float *Range_x, float *Range_y,   
		  int color_Index, 
		  int type_of_Line, 
		  int type_of_Width, 
		  int type_of_Symbol, 
		  char *X_label, char *Y_label, char *Title);

void cpg_box_plot(int , 
		  int , float *, float **, int, 
		  float * , float * ,   
		  int , 
		  int , 
		  int , 
		  int , 
		  char * , char * , char *); 

void cpg_bar_plot_bar_Titles (int SAME_PLOT, 
			      int n, float *xs, float *ys,
			      float *Range_x, float *Range_y,   
			      int color_Index, 
			      int type_of_Line, 
			      int type_of_Width, 
			      int type_of_Symbol, 
			      char *X_label, char *Y_label, char *Title, 
			      char ** Bar_Titles );

void cpg_bar_plot_Fractions (int SAME_PLOT, 
			     int n, float *xs, float *ys,
			     float *Range_x, float *Range_y,   
			     int * color_Index, 
			     int * type_of_Line, 
			     int * type_of_Width, 
			     char *X_label, char *Y_label, char *Title, 
			     char ** Bar_Titles );

void cpg_XY_shade_between_curves( int n, 
				  float * x, float * y_1, float * y_2,
				  int color_Index, 
				  int type_of_Line, 
				  int type_of_Width);

void cpg_XY_arrow(int, float *, float *, float *, float *, 
		  int , int , int , 
		  char *, char *, char *);

void cpg_XY_plot_error_bar( int n, double * X, double * Y, double * E );


void cpg_XY_scattered(int n, float *xs, float *ys, float *Range_x, float *Range_y, 
		      int color_Index, int type_of_Symbol, 
		      char *X_label, char *Y_label, char *Title);

void cpg_XY_same_scattered( int n, float *xs, float *ys, 
			    int color_Index, int type_of_Symbol );

void cpg_XY_same_scattered_pt_per_pt( int n, float *xs, float *ys, 
			    int * color_Index, int * type_of_Symbol );

void cpg_XY_same_arrow( int n, float *xs, float *ys, 
			int color_Index, int type_of_Line, int type_of_Width);

void cpg_XY_same_circle( float xcent, float ycent, float radius,  
			 int color_Index, int type_of_Filling );

void cpg_XY_same_rectangle( float x1, float y1,  
			    float x2, float y2,  
			    int color_Index, int type_of_Filling );

void A_X_E_S___R_A_N_G_E_S( int n, double * x, double * X_RANGE, int SCALE, float * Range_x);

float cpg_random_number();

void cpg_plot_random_points( float x__1, float y__1, float x__2, float y__2, 
			     int Zn, int No_of_LEVELS, double shade, 
			     int type_of_Symbol );
