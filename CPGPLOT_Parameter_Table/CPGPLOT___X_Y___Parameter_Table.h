void C_P_G___S_C_A_L_E___F_I_X ( Parameter_Table * P,
				 double * X_RANGE,  double ** Y_RANGE);

void C_P_G___P_H_A_S_E____D_I_A_G_R_A_M ( Parameter_Table * P,  					  
					  int k_0, int k_1,
					  int NO, double ** y_Time );

void C_P_G___P_H_A_S_E____D_I_A_G_R_A_M___S_A_M_E ( Parameter_Table * P,
						    int SAME_PLOT,
						    int k_0, int k_1,
						    int NO, double ** y_Time );

void C_P_G___S_U_B___P_L_O_T_T_I_N_G ( Parameter_Table * P,  
				       int NO, double * x_Time, double ** y_Time );

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___C_U_S_T_O_M_I_Z_E_D___T_I_T_L_E ( Parameter_Table * P,  
									 int NO, double * x_Time, double ** y_Time, 
									 int Input_Parameter );

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___D_U_A_L ( Parameter_Table * P,  
						 int NO, double * x_Time, double ** y_Time );

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( int REPLICATE, 
							   Parameter_Table * P,  
							   int NO, double * x_Time, double ** y_Time );

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R ( Parameter_Table * P,  
							   int NO, double * x_Time, double ** y_Time,
							   double ** y_Error);

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R___D_R_I_V_E_R ( int DATA_POINTS, 
									 Parameter_Table * Table);
