#include "cpgplot_headers.h"

float cpg_random_number() 
{
  float P;

  //srand(time(NULL));

  P = (float)rand() / (float)RAND_MAX;
      
  return (P);
}
        

