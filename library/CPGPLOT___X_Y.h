void CPGPLOT___X_Y___S_Q_U_A_R_E_D___L_A_T_T_I_C_E (Parameter_CPGPLOT * CPG, 
                                                    double Ox, double Oy,
                                                    double Dx, double Dy,
                                                    int    Nx, int    Ny);

void CPGPLOT___X_Y___P_L_O_T_T_I_N_G___A_X_E_S ( Parameter_CPGPLOT * CPG, 
							                            char * X_label, 
							                            char * Y_label, 
							                            char * Title);

void CPGPLOT___P_L_O_T_T_I_N_G___F_R_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
							     int SAME_PLOT,
							     int NO_of_POINTS, 
							     double * X, 
							     double * Y, 
							     char * X_label, 
							     char * Y_label, 
							     char * Title,
						       int SCALE_X, int SCALE_Y );

void CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___F_R_A_C_T_I_O_N_S (Parameter_CPGPLOT * CPG, 
							    int SAME_PLOT,
							    int NO_of_POINTS, 
							    double * X, 
							    double * Y, 
							    char * X_label, 
							    char * Y_label, 
							    char * Title,
							    int SCALE_X, 
							    int SCALE_Y, 
							    int * color_Index, 
							    int * type_of_Line, 
							    int * type_of_Width, 
							    char ** Bar_Titles );

void CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___B_A_R___T_I_T_L_E_S (Parameter_CPGPLOT * CPG, 
							      int SAME_PLOT,
							      int NO_of_POINTS, 
							      double * X, 
							      double * Y, 
							      char * X_label, 
							      char * Y_label, 
							      char * Title,
							      int SCALE_X, 
							      int SCALE_Y, 
							      char ** Bar_Titles ); 

void CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
							     int SAME_PLOT,
							     int NO_of_POINTS, 
							     double * X, 
							     double * Y, 
							     char * X_label, 
							     char * Y_label, 
							     char * Title,
							     int SCALE_X, int SCALE_Y );

void CPGPLOT___B_O_X___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
							     int SAME_PLOT,
							     int NO_of_POINTS, 
							     double * X, 
							     double ** Y, int NP, 
							     char * X_label, 
							     char * Y_label, 
							     char * Title,
							     int SCALE_X, int SCALE_Y );

void CPGPLOT___X_Y___H_I_S_T_O_G_R_A_M (Parameter_CPGPLOT * CPG,
					int NO_of_POINTS, double * x_DATA, int n_BINS,
					char * X_Label, char * Y_Label, char * Title, 
					int SCALE_X, int SCALE_Y );

void CPGPLOT___X_Y___H_I_S_T_O_G_R_A_M___N_O_R_M_A_L_I_Z_E_D ( int SAME, 
															   Parameter_CPGPLOT * CPG,
							       							   int NO_of_POINTS, double * x_DATA, int n_BINS,
							       							   char * X_Label, char * Y_Label, char * Title, 
							       							   int SCALE_X, int SCALE_Y,
								   							   int BAR );

int CPGPLOT___X_Y_n___P_L_O_T_T_I_N_G ( Parameter_CPGPLOT * CPG, 
					int NO_of_POINTS, int n_XY, 
					double * x_Data, double ** y_Data, 
					char * X_label, char * Y_label, char * Title,
					int SCALE_X, int SCALE_Y );

int CPGPLOT___X_Y_n___S_U_B___P_L_O_T_T_I_N_G ( Parameter_CPGPLOT * CPG, 
						int NO_of_POINTS, int n_XY, 
						double * x_Data, double ** y_Data, 
						char * X_label, char * Y_label, char * Title,
						int SCALE_X, int SCALE_Y );

int CPGPLOT___X_Y_n___S_C_A_T_T_E_R_E_D ( Parameter_CPGPLOT * CPG, 
					  int NO_of_POINTS, int n_XY, 
					  double * x_Data, double ** y_Data, 
					  char * X_label, char * Y_label, char * Title,
					  int SCALE_X, int SCALE_Y );

void CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_C_A_L_E ( Parameter_CPGPLOT * CPG,
						   int NO_of_POINTS, 
						   double * x_Data, double * y_Data,
						   char * X_label, char * Y_label, char * Title,
						   int SCALE_X, int SCALE_Y );

void CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___A_R_R_O_W( Parameter_CPGPLOT * CPG,
							    int SAME_PLOT,
							    int NO_of_POINTS, 
							    double * x_Data, double * y_Data,
							    char * X_label, 
							    char * Y_label, 
							    char * Title,
							    int SCALE_X, int SCALE_Y );

void CPGPLOT___X_Y___L_O_G___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
								   int SAME_PLOT,
								   int NO_of_POINTS, 
								   double * x_Data, 
								   double * y_Data,
								   char * X_label, 
								   char * Y_label, 
								   char * Title,
								   int SCALE_X, int SCALE_Y, 
								   int TYPE_of_AXIS, 
								   int LINES );

void CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
                                                           int SAME_PLOT,
                                                           int NO_of_POINTS,
                                                           double * x_Data, double * y_Data,
                                                           char * X_label,
                                                           char * Y_label,
                                                           char * Title,
                                                           int SCALE_X, int SCALE_Y );

void CPGPLOT___X_Y___S_H_A_D_E___B_E_T_W_E_E_N___C_U_R_V_E_S ( Parameter_CPGPLOT * CPG,  
							       int NO_of_POINTS, 
							       double * x, 
							       double * y_1, 
							       double * y_2 );

void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_C_A_L_E ( Parameter_CPGPLOT * CPG,
						     int NO_of_POINTS, 
						     double * x_Data, double * y_Data,
						     char * X_label, char * Y_label, char * Title,
						     int SCALE_X, int SCALE_Y );

void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E___P_L_O_T ( Parameter_CPGPLOT * CPG,
							     int SAME_PLOT,
							     int NO_of_POINTS, 
							     double * x_Data, double * y_Data,
							     char * X_label, 
							     char * Y_label, 
							     char * Title,
							     int SCALE_X, int SCALE_Y );

void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___n_P_O_I_N_T_S ( Parameter_CPGPLOT * CPG,
							 int NO_of_POINTS, 
							 double * x_Data, double * y_Data );

void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___P_T___P_E_R___P_T ( Parameter_CPGPLOT * CPG,
							     int NO_of_POINTS, 
							     double * x_Data, double * y_Data,
							     int * color_Index, 
							     int * type_of_Symbol );

void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___C_I_R_C_L_E ( Parameter_CPGPLOT * CPG,
						       double x_Center, 
						       double y_Center,
						       double Radius, 
						       int type_of_Filling );

void CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___R_E_C_T_A_N_G_L_E ( Parameter_CPGPLOT * CPG,
                                                       double X1, double Y1,
                                                       double X2, double Y2,
                                                       int type_of_Filling );

void C_P_G___P_L_O_T_T_I_N_G___E_X_T_R_A___L_I_N_E (double x_1, double y_1,
                                                    double x_2, double y_2,
                                                    int color_Index,
                                                    int type_of_Line,
                                                    int type_of_Width,
                                                    int type_of_Symbol);

void CPGPLOT___X_Y___P_L_O_T_T_I_N_G___2DIR___E_R_R_O_R___B_A_R_S ( Parameter_CPGPLOT * CPG,
								    int N,
								    double * x_Data, 
								    double ** xn_Data, 
								    double * y_Data, 
								    double ** yn_Data, 
								    int BAR_TIP_LENGTH,
								    int HORIZONTAL );
