# =======================
# CPGPLOT GRID LIBRARY make 
# =======================

# Gnu C make cpgplot_GRID UTILS (libda_cpgplot_GRID.a)
# C_DIR              = ${HOME}/C_pro/
C_DIR              = ${HOME}/CPGPLOT/
EXTRA_INCLUDE_PATH = -I${C_DIR} -I/usr/local/pgplot
REPRESENTATION=-DCPGPLOT_REPRESENTATION
CFLAGS=-g -Wall -DHAVE_INLINE ${EXTRA_INCLUDE_PATH} ${REPRESENTATION}
###CFLAGS= -Wall -O21

COMPILER=gcc

OBJECTS_FILE=F_I_L_E___X_Y___R_E_A_D.o F_I_L_E___X_Y___W_R_I_T_E.o  F_I_L_E___X_Y_n___R_E_A_D.o F_I_L_E___X_Y_n___W_R_I_T_E.o  F_I_L_E___X_Y_Z___R_E_A_D.o F_I_L_E___X_Y_Z___W_R_I_T_E.o F_I_L_E___X___R_E_A_D.o F_I_L_E___X_Y___R_E_A_D.o F_I_L_E___X_Y___W_R_I_T_E.o 

OBJECTS_GRID=CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___C_O_N_T_O_U_R.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___S_H_A_D_E_S.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___S_H_A_D_E_S___F_R_A_M_E.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___R_E_C_T_A_N_G_L_E_S.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___R_E_C_T_A_N_G_L_E_S___F_R_A_M_E.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___S_U_B_R_E_G_I_O_N.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___X_Y_Z___S_H_A_D_E_S.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___M_A_T_R_I_X___S_H_A_D_E_S.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___X_Y_Z___R_E_C_T_A_N_G_L_E_S.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N.o CPGPLOT___G_R_I_D___P_L_O_T_T_I_N_G___X_Y_Z___S_H_A_D_I_N_G___S_U_B_R_E_G_I_O_N.o  

OBJECTS_XY =CPGPLOT___X_Y___P_L_O_T_T_I_N_G___A_X_E_S.o CPGPLOT___X_Y___S_Q_U_A_R_E_D___L_A_T_T_I_C_E.o CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_C_A_L_E.o  CPGPLOT___P_L_O_T_T_I_N_G___F_R_A_M_E___P_L_O_T.o CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E.o CPGPLOT___B_O_X___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T.o CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T.o CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___B_A_R___T_I_T_L_E_S.o CPGPLOT___B_A_R___P_L_O_T_T_I_N_G___F_R_A_C_T_I_O_N_S.o CPGPLOT___X_Y___L_O_G___P_L_O_T_T_I_N_G___S_A_M_E.o CPGPLOT___X_Y_n___P_L_O_T_T_I_N_G.o CPGPLOT___X_Y_n___S_U_B___P_L_O_T_T_I_N_G.o CPGPLOT___X_Y_n___S_C_A_T_T_E_R_E_D.o CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_C_A_L_E.o CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E.o  CPGPLOT___X_Y___P_L_O_T_T_I_N_G___S_A_M_E___A_R_R_O_W.o CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___n_P_O_I_N_T_S.o CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___P_T___P_E_R___P_T.o CPGPLOT___X_Y___P_L_O_T_T_I_N_G___E_X_T_R_A___L_I_N_E.o  CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___C_I_R_C_L_E.o CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___R_E_C_T_A_N_G_L_E.o CPGPLOT___X_Y___H_I_S_T_O_G_R_A_M.o  CPGPLOT___X_Y___H_I_S_T_O_G_R_A_M___N_O_R_M_A_L_I_Z_E_D.o CPGPLOT___X_Y___S_H_A_D_E___B_E_T_W_E_E_N___C_U_R_V_E_S.o CPGPLOT___X_Y___P_L_O_T_T_I_N_G___2DIR___E_R_R_O_R___B_A_R_S.o
.SUFIXES:       .o .c

.c.o: 
	${COMPILER} $(CFLAGS) -c $<

cpgplot:${OBJECTS_GRID} ${OBJECTS_XY} ${OBJECTS_FILE} ../Parameter_CPGPLOT.o ../Parameter_FILE.o ../Parameter_CPGPLOT_report.o ../CPGPLOT_HEADER.h
	ar -q libda_cpgplot_XY_GRID_FILE.a ${OBJECTS_GRID} ${OBJECTS_XY} ${OBJECTS_FILE} Parameter_CPGPLOT.o Parameter_CPGPLOT_report.o Parameter_FILE.o

cpgplot_GRID:${OBJECTS_GRID} ../CPGPLOT_HEADER.h
	ar -q libda_cpgplot_GRID.a ${OBJECTS_GRID}

cpgplot_XY:${OBJECTS_XY} ../CPG_HEADER.H
	ar -q libda_cpgplot_XY.a ${OBJECTS_XY}

clean:  
	rm -f *.o *~


