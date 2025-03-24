#include <stdlib.h>
#include <math.h>
#include "Discrete_Sampling.h"

/* Discrete Sampling provide a set of functions required in 
   a lot of stochastic models, one step stochastic simulations and 
   so on. 
*/

// extern gsl_rng * r; /* Global generator defined in main.c */
// #define RANDOM gsl_rng_uniform_pos(r)

/* The  drand48() returns nonnegative double-precision floating-point values 
   uniformly distributed over the interval [0.0, 1.0)
*/
#define RANDOM drand48() 

void Discrete_Sampling(double * a, int * N, int * Event)
{
  /* Input Arguments, 

     . a[], a vector of probability rates (doubles) not 
      necessariliy normalized.
     . * N stores the length of the a[] array.

     Ouput: 

     . * Event, the index of the event to occur. 

     This function returns the index of the "event-to-occur" and considers 
     all events, but those with rate 0.0 have zero probability to
     occur.
  */
  int NoEvents = * N; 
  int j, n, n_0, kount;
  double * R_A_T_E= (double *)calloc( NoEvents, sizeof(double) );
  int * Index     = (int *)calloc( NoEvents, sizeof(int) );

  n = 0; 
  while (a[n] == 0.0 && n < NoEvents ) {
    n++;
  }
  if( n == 0 )   Index[0] = 0; 
  else           Index[0] = n-1;
  
  n_0 = Index[0] + 1;
  
  R_A_T_E[0] = a[Index[0]];
  n = 1; 
  for (j=n_0; j<NoEvents; j++)
    if (a[j] > 0.0) {
      R_A_T_E[n]= R_A_T_E[n-1] + a[j];
      Index[n]  = j; 
      n++;
    }
  
  kount = Discret_Sampling_High_Performance(R_A_T_E[n-1], R_A_T_E, n);

  kount = Index[kount-1] + 1; 
  
  free(R_A_T_E);
  free(Index);
  
  // return kount;

  * Event = kount; 
}

int Discret_Sampling_High_Performance(double rate, double *R_A_T_E, int NoEvents)
{
  /* Imput Arguments: 

     . rate is the normalization constant.
     . NoEvents is the length of the R_A_T_E[] array.
     . R_A_T_E[] must store the non-normalized cummulative probability distribution,
      where rate is the normalizing factor. If rate=1.0, because the discrete probability
      distribution has previously normalized, the algorithm could be improved but 
      actually works quite well too.
     . If R_A_T_E[] stores the discret probabililty distribution function, rather than 
      the cummulative probability distribution, this algorithm does not work at all. 
      In this case, the Discret_Sampling() algorith must be used first to create the 
      cummulative probability distribution.

     Output: 

     . An integer, from 1 to NoEvents. 
  */
  int j1,j2,jm, kount;
  int stat_Bool;
  double x_1, x_2, x_m, xr;

  if(NoEvents == 1) 
    return(1);
 
  xr = RANDOM;

  if(NoEvents == 2){
    x_1 = 0.; x_2 = R_A_T_E[0]/rate;
    if((xr > x_1) && (xr <= x_2))
      return(1);
    else 
      return(2);
  }
  else if(NoEvents > 2 && NoEvents < 10){
    kount = Discrete_Sampling_Cummulative(rate, R_A_T_E, NoEvents);
    return (kount);
  }
  else{
    x_1 = 0.; x_2 = R_A_T_E[0]/rate;
    if((xr > x_1) && (xr <= x_2))
      return(1);
    x_1 = R_A_T_E[NoEvents-2]/rate; x_2 = R_A_T_E[NoEvents-1]/rate;
    if((xr > x_1) && (xr <= x_2))
      return(NoEvents);

    stat_Bool = 0;
    j1 = 0;            x_1 = R_A_T_E[j1]/rate;
    j2 = NoEvents-1;   x_2 = R_A_T_E[j2]/rate;
    while(stat_Bool == 0){ 
      jm = (j1 + j2)/2; /* Integer division by 2 */
      x_m = R_A_T_E[jm]/rate;
      if(j1 == j2-1)  
	      stat_Bool = 1;  /* Brackening has succedeed  p(j1)< xr <= p(j2), p(i) = R_A_T_E[i]/rate */
      else{
	      if((xr > x_m) && (xr <= x_2)){
	        x_1 = x_m;
	        j1  = jm;
	      }
	      else{
	        x_2 = x_m;
	        j2  = jm;
	      }
      }
    }
  }
  return (j2+1);
}

int Discrete_Sampling_Cummulative(double rate, double *R_A_T_E, int NoEvents)
{
  /* . rate is the normalization constant.
     . r[] must store the NON-NORMALIZED cummulative distribution probability,
     where $rate$ is the normalizing factor. If rate=1., the algorithm could be
     improved but actually works quite well too.
     . If r[] stores the discret probabililty distribution function, this algorithm 
     does not work at all. Then, the Discret_Sampling() algorith must be used instead.
  */
  int j, kount;
  double x_1, x_2, xr;
  
  xr = RANDOM;
  kount = 1;
  x_2 = 0.;
  for (j=0; j<NoEvents; j++){/* Deciding elemetary event to occur */
    x_1 = x_2;
    x_2 = R_A_T_E[j]/rate;
    if((xr > x_1) && (xr <= x_2)) {
      kount = j+1;
      return kount;
    }
  }
  return(0);
}