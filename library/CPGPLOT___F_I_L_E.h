void F_I_L_E___X___W_R_I_T_E ( Parameter_FILE * Table,
                               int i,
                               double * x_Data,
                               int No_of_POINTS );

void X___W_R_I_T_E ( char * Name,
                     double * x_Data,
                     int No_of_POINTS);

void F_I_L_E___X___R_E_A_D ( Parameter_FILE * Table,
                               int i,
                               double * x_Data,
                               int * No_of_POINTS );

void X___R_E_A_D ( char * Name,
                     double * x_Data,
                     int * No_of_POINTS);


void X_Y_Z___W_R_I_T_E ( char * Name,
                       int No_of_POINTS_1, int No_of_POINTS_2,
                       double * x_Data,
                       double * y_Data,
                       double * W_GRID );

void F_I_L_E___X_Y_Z___W_R_I_T_E ( Parameter_FILE * Table,
                                   int i,
                                   char * OUTPUT_FILE_NAME,
                                   double * x_Data,
                                   double * y_Data,
                                   double * W_GRID );

void P_A_R_A_M_E_T_E_R___F_I_L_E___X_Y_Z___R_E_A_D ( Parameter_FILE * Table, 
						     int i, 
						     double * x_Data, 
						     double * y_Data, 
						     double * W_GRID );

void F_I_L_E___X_Y_Z___R_E_A_D ( Parameter_FILE * Table, 
				 int i, 
				 double * x_Data, 
				 double * y_Data, 
				 double * W_GRID );

void X_Y_Z___R_E_A_D ( char * Name,
		       int No_of_POINTS_1, int No_of_POINTS_2, 
		       double * x_Data, 
		       double * y_Data, 
		       double * W_GRID );

void F_I_L_E___X_Y_Z___R_E_A_D___3_C ( Parameter_FILE * Table, 
				       int i, 
				       double * x_Data, 
				       double * y_Data, 
				       double * z_Data );

void X_Y_Z___R_E_A_D___3C ( char * Name, 
			    double * x_Data, 
			    double * y_Data,
			    double * z_Data, 
			    int * No_of_POINTS);

void F_I_L_E___X_Y___R_E_A_D ( Parameter_FILE * Table, 
			       int i, 
			       double * x_Data, 
			       double * y_Data );

void X_Y___R_E_A_D ( char * Name, 
		     double * x_Data, 
		     double * y_Data,
		     int * No_of_POINTS );

void F_I_L_E___X_Y_n___R_E_A_D ( Parameter_FILE * Table, 
				 int i, 
				 double * x_Data, 
				 double ** y_Data );

void X_Y_n___R_E_A_D ( char * Name,
		       int No_of_POINTS_1, int No_of_POINTS_2,
		       double * x_Data, 
		       double ** y_Data );

void F_I_L_E___X_Y_n___W_R_I_T_E ( FILE * fp_OUT,
				   char * File_Name, 
				   int    NUMBER, 
				   double * x_Data,  int No_of_POINTS,
				   double ** y_Data, int No_of_SERIES );

void F_I_L_E___X_Y___W_R_I_T_E ( FILE * fp_OUT,
				 char * File_Name, 
				 int    NUMBER, 
				 double * x_Data, double * y_Data, int No_of_POINTS );
