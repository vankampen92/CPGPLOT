#include "cpgplot_headers.h"

void cpg_frame_plot(float X_0, float X_1, float Y_0, float Y_1, 
		    int type_of_Width, float character_Size,
		    char * X_control, char * Y_control)
{
  // Redrawing the box and axes on the same plot!!!
  // (without erasing anything)
  // Line width, character size and the rest of specifications
  // to draw the box and axes should match the values used to set up
  // box and axes for the first time because they are again used
  // to define the standard viewport through the call to cpgvstd().
  // X_control and Y_control should be something like "BCNST" to specify position of the axes and tick marks and tick labels.
  
  cpgslw(type_of_Width); 
  cpgsch(character_Size);
  cpgvstd();
  cpgswin(X_0, X_1, Y_0, Y_1); 
  cpgbox (X_control, 0.0, 0,
	  Y_control, 0.0, 0);
}
  
