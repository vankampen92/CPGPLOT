#include <MODEL.h>

/* The prototypes of the following functions are
   defined in CPGPLOT___GRID___Parameter_Table.h
*/
/* This file depends on previous definition of
   Parameter_Table Structure, which is model specific, and
   it is done in a model specific header file (MODEL.h).
   This file can be found in the ./Include directory of 
   the specific model project
*/

#if defined CPGPLOT_REPRESENTATION
void C_P_G___G_R_I_D___P_L_O_T_T_I_N_G___S_H_A_D_E_S (Parameter_Table * Table,
						                                    int j_Time)
{
   /* CPG Representation: Time evolution of local densities of the local variables
     over the grid, as stored in Table->Vector_Model_Variables[k] at a give time, 
     the j_Time-th time.  
   */
   int Sp; 
   int i,j;
   int ix, jy; 
   int n, m;
   double W_min, W_MAX;
   static int DEVICE_NUMBER;

   int color_Index;
   int type_of_Line;
   int type_of_Width;

   Parameter_CPGPLOT * CPG = Table->CPG; 
   Time_Control * Time     = Table->T; 
   double * Y              = Table->Vector_Model_Variables;
  
   int N        = Table->No_of_CELLS; 
   int nx       = Table->No_of_CELLS_X;
   int ny       = Table->No_of_CELLS_Y;

   assert(Table->LOCAL_STATE_VARIABLES == 4); 
   assert(Table->TYPE_of_NETWORK == 1);        /* Regular Grid */

   double *** GRD   = (double ***)calloc( Table->LOCAL_STATE_VARIABLES, sizeof(double **) );
   for(Sp = 0; Sp < Table->LOCAL_STATE_VARIABLES; Sp++) {
      GRD[Sp]   = (double **)calloc(nx, sizeof(double *) );
      for(i = 0; i < nx; i++)
         GRD[Sp][i] = (double *)calloc( ny, sizeof(double) );   
   }     

   double * W  = (double *)calloc( nx * ny, sizeof(double ) );
  
   for(i = 0; i < Table->MODEL_STATE_VARIABLES; i++) {
      n            = i/Table->LOCAL_STATE_VARIABLES;  
      Sp           = i%Table->LOCAL_STATE_VARIABLES;

      ix           = n/nx; 
      jy           = n%nx;
      
      GRD[Sp][nx-ix-1][jy] = Y[i];
   }

   if(j_Time == 1) {
      DEVICE_NUMBER = cpgopen( "/XSERVE" );
      cpgsubp(2, 2);
      cpgask( 0 );
   }

   type_of_Line = 1;
   type_of_Width = 2;
   cpgsls(type_of_Line);
   cpgslw(type_of_Width);
   cpgask( 0 );
      
   cpgslct(DEVICE_NUMBER);      /* Selecting Device */

   char * Plot_Time  = (char *)calloc( 50, sizeof(char));
   char * Time_Eraser = (char *)calloc(50, sizeof(char));
   float char_Size;
   float x_Time_Position = 0.50 * CPG->X_Dimension; 
   float y_Time_Position = 1.09 * CPG->Y_Dimension;
   static double Current_Time  = 0.0; 
   double Last_Time            = Current_Time;
   Current_Time  = Table->T->Time_Vector[j_Time];
   sprintf(Plot_Time, "Time = %5.2f", Current_Time);
   sprintf(Time_Eraser, "Time = %5.2f", Last_Time);
   
   for(Sp = 0; Sp < Table->LOCAL_STATE_VARIABLES; i++) {

      W_min = GRD[Sp][0][0]; 
      W_MAX = GRD[Sp][0][0];
      m=0;
      for(j=0; j<ny; j++) {
         for(i=0; i<nx; i++) {
            W[m++] = GRD[Sp][i][j];
            W_min = MIN (W_min, GRD[Sp][i][j]);
            W_MAX = MAX (W_MAX, GRD[Sp][i][j]);
         }
      }
      C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S( CPG,
							                                       W, 
							                                       0,
							                                       1, 
							                                       W_min, W_MAX, 
							                                       j_Time );
      /*
       void C_P_G___P_L_O_T_T_I_N_G___2d___G_R_I_D___S_H_A_D_E_S( Parameter_CPGPLOT * CPG,
							                                             double * W, 
							                                             int FIRST_PLOT,
							                                             int W_SCALE, 
							                                             double W_min, double W_MAX, 
							                                             double i_PLOT )
      */                                                                                                            
      /* B E G I N : Plotting Current Time on Top */
      cpgqch(&char_Size);
      cpgsch(2.0);
      cpgsci(0);
      cpgptxt(x_Time_Position, y_Time_Position, 0.0, 0.5, Time_Eraser);
      cpgsci(1);
      cpgptxt(x_Time_Position, y_Time_Position, 0.0, 0.5, Plot_Time);
      cpgsch(char_Size);
      /*     E N D : Plotting Current Time on Top */
   }

   for(Sp = 0; Sp < Table->LOCAL_STATE_VARIABLES; Sp++) {
      for(i = 0; i < nx; i++) {
         free(GRD[Sp][i]); 
      }
      free(GRD[Sp]);  
   }
   free(GRD);      
   free(W);
   free(Plot_Time); free(Time_Eraser);
}
#endif