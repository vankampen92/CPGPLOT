#include "cpgplot_headers.h"

#define SHRINKING_FACTOR_BOX 1.0

void cpg_bar_plot_Fractions (int SAME_PLOT, 
			      int n, float *xs, float *ys,
			      float *Range_x, float *Range_y,   
			      int * color_Index, 
			      int * type_of_Line, 
			      int * type_of_Width, 
			      char *X_label, char *Y_label, char *Title, 
			      char ** Bar_Titles )
{  
  /* This functions produces a fractions single bar, where each fraction is
     propportional to ys[i]. 
     Notice that the quantities xs[i] are irrevelant for this kind of plot. 
     Fractions are represented by rectangle on top of each other. See code 
     below, where xs[i] are all forced to be XD; 
     color_Index, type_of_Line and type_of_Width define the attributes of 
     each rectangle. 
  */
  /* type_of_Line... (1, ..., 5)     
     (only five all possible)                                               */
  /* type_of_Width... (1, ..., 201)  D
     efault, 1 = 1/200 Inches (approx 0.003 Inches)                         */
  
  int i,j;
  float v; 
  float yc;
  float x1, y1, x2, y2; 
  int type_of_Filling;

  cpgslw(3.0);
  float ch;
  cpgqch( &ch );
  cpgsch(1.5 * ch);  // cpgsch(1.2); cpgsch(2.5 * ch);  cpgsch(1.2);  

  if( SAME_PLOT == 0 ) {
    cpgpage();
    cpgvstd();
    cpgswin(Range_x[0], Range_x[1], Range_y[0], Range_y[1]); 
    cpgbox ("BC", 0.0, 0, "BCINTS", 0.0, 0);
    cpgbbuf();

    cpgmtxt("T", 2.0, 0.5, 0.5, Title);
    cpgmtxt("B", 3.2, 0.5, 0.5, X_label);	
    cpgmtxt("L", 2.2, 0.5, 0.5, Y_label);
    cpgebuf();
  // This is equivalent to a full call to cpglab(X_label, Y_label, Title);
  }
  
  /* B E G I N : Calculating fractions and saving the again in ys array */
  float * ya = (float *)calloc( n, sizeof(float) );
  for(i=0; i<n; i++) { 
    yc = 0;
    for(j=0; j <= i; j++) yc += ys[j];
    ya[i] = yc;  
  }
  for(i=0; i<n; i++) ys[i] = ya[i]/ya[n-1];
  free(ya); 
  /*     E N D : ------------------------------------------------------ */ 

  printf(" cpg: Fractions\n");
  for(i=0; i<n; i++) { 
    printf("%s: ", Bar_Titles[i]);
    printf("%f papers ", ys[i]);
    printf("( color[%d], line[%d], width[%d]\n", 
	   color_Index[i], type_of_Line[i], type_of_Width[i] );
  }

  float XD = (Range_x[1] - Range_x[0] ) / Range_x[1]; 
  for(i=0; i<n; i++) xs[i] = XD; 
    
  cpgsch(1.0); // cpgsch(0.83);    
  /* The fill-area style to be used:                                      */ 
  /* 			  type_of_Filling = 1 => solid (default)          */
  /*                      type_of_Filling = 2 => outline                  */
  /*                      type_of_Filling = 3 => hatched                  */
  /*                      type_of_Filling = 4 => cross-hatched            */
  type_of_Filling = 3; 

  for(i=0; i<n; i++) {
    cpgsci(color_Index[i]);
    cpgslw(type_of_Width[i]);				
    cpgsls(type_of_Line[i]);
  
    x1 = xs[i] - 0.5* SHRINKING_FACTOR_BOX * XD; 
    if( i >  0 ) y1 = ys[i-1];
    if( i == 0 ) y1 = 0.0;
    x2 = xs[i] + 0.5* SHRINKING_FACTOR_BOX * XD; 
    y2 = ys[i];
  
    cpg_XY_same_rectangle(x1, y1,  x2, y2,  
			  color_Index[i], type_of_Filling );
  }  
  
  cpgsch(1.5);
  cpgslw(2.0);
  cpgsci(1);
  cpgsls(2);
  cpgsah(1, 40.0, 0.6);
  for(i=0; i<n; i++) {
    if( i >  0 ) v = ys[i-1] + 0.5 * (ys[i] - ys[i-1]);
    if( i == 0 ) v = 0.5 * (ys[i] - 0.0);
    cpgarro(1.85*XD, v, XD, v);
    cpgptxt(2.0*XD, v, 0.0, 0.0, Bar_Titles[i]);
  }

  
  cpgsls(1);            /*  Back to full line... 
			    type_of Line = 1: Full line 
			 */
  cpgslw(1);            /*  Back to default line width...  
			    type_of Line = 1: thinest line 
			 */
                        /* Back to default color 
                         */
  cpgsci(1);

  return;
}

