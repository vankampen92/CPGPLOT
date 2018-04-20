void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___C_O_N_T_O_U_R(Parameter_CPGPLOT * CPG,
							    double * W, 
							    int FIRST_PLOT,
							    int W_SCALE, 
							    double W_min, double W_MAX, 
							    double i_PLOT );

int C_P_G___P_L_O_T_T_I_N_G___2d___C_O_N_T_O_U_R___S_U_R_F_A_C_E___D_R_I_V_E_R( int FIRST_PLOT,
										double * W_RANGE,
										double * ORIGIN, 
										float * g,
										int L__X, int L__Y,
										double X_d, double Y_d,
										Parameter_CPGPLOT * CPG );

void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___R_E_C_T_A_N_G_L_E_S( Parameter_CPGPLOT * CPG,
								   double * W, 
								   int FIRST_PLOT,
								   int no_of_COLORS, 
								   double * COLOR_STATES,
								   double i_PLOT );

int C_P_G___P_L_O_T_T_I_N_G___2d___C_O_L_O_R___R_E_C_T_A_N_G_L_E_S___D_R_I_V_E_R ( int FIRST_PLOT, float * g,  
										   int no_of_COLORS, float * colors, 
										   double * ORIGIN, 
										   int L__X, int L__Y,
										   double X_d, double Y_d,
										   char * X_label, 
										   char * Y_label, 
										   char * W_label,
										   char * Title );

int which_COLOR (float g, float * colors, int n );

void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S( Parameter_CPGPLOT * CPG,
							   double * W, 
							   int FIRST_PLOT,
							   int W_SCALE, 
							   double W_min, double W_MAX, 
							   double i_PLOT );

void C_P_G___P_L_O_T_T_I_N_G___M_A_T_R_I_X___S_H_A_D_E_S( Parameter_CPGPLOT * CPG,
							  double ** GRD,
							  int nx, int ny, 
							  double X_D, double Y_D,
							  double X_0, double Y_0, 
							  int FIRST_PLOT,
							  int W_SCALE, 
							  double W_min, double W_MAX, 
							  double i_PLOT );

void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S___F_R_A_M_E( Parameter_CPGPLOT * CPG,
								       double * W, 
								       int FIRST_PLOT,
								       int W_SCALE, 
								       double W_min, double W_MAX, 
								       double i_PLOT );

int C_P_G___P_L_O_T_T_I_N_G___2d___C_O_L_O_R___S_U_R_F_A_C_E___D_R_I_V_E_R___F_R_A_M_E ( int FIRST_PLOT, 
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
									     float CONTRA ); 

void C_P_G___P_L_O_T_T_I_N_G___X_Y_Z___S_H_A_D_E_S( Parameter_CPGPLOT * CPG, 
						    double * x_Data, 
						    int No_of_POINTS_1, 
						    double * y_Data, 
						    int No_of_POINTS_2,
						    double * W_GRID, 
						    int A, 
						    double W_Artificial_MAX );

void C_P_G___P_L_O_T_T_I_N_G___X_Y_Z___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N( Parameter_CPGPLOT * CPG, 
									  double * x_Data, 
									  double x0, double x1,
									  double x_Step,
									  double * y_Data, 
									  double y0, double y1,
									  double y_Step,
									  double * z_Data,
									  int No_of_POINTS,
									  int No_of_LEVELS, 
									  double THICKNESS,
									  int FIRST_PLOT,
									  int A, 
									  double Z_Artificial_MAX );

int C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N (Parameter_CPGPLOT * CPG,
										int FIRST_PLOT,
										double * X, 
										double * Y, 
										double * Z,
										int Total_POINTS, 
										double x_Step,
										double y_Step, 	
										int No_of_LEVELS, 
										double THICKNESS);

void C_P_G___P_L_O_T_T_I_N_G___X_Y_Z___R_E_C_T_A_N_G_L_E_S( Parameter_CPGPLOT * CPG, 
							    double * x_Data, 
							    int No_of_POINTS_1, 
							    double * y_Data, 
							    int No_of_POINTS_2,
							    double * W_GRID );


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
									     float CONTRA );

void cpg_SETVP(void);

void cpg_PALETT( int type, float CONTRA, float BRIGHT);

int C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_U_B_R_E_G_I_O_N ( Parameter_CPGPLOT * CPG,
								 int FIRST_PLOT, 
								 double * X, double * Y, 
								 int Total_POINTS );
