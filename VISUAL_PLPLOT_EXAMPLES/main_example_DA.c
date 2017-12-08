// $Id: x11c.c 11680 2011-03-27 17:57:51Z airwin $
//
//      Mesh plot demo.
//
// Copyright (C) 2004  Rafael Laboissiere
//
// This file is part of PLplot.
//
// PLplot is free software; you can redistribute it and/or modify
// it under the terms of the GNU Library General Public License as published
// by the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// PLplot is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public License
// along with PLplot; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
//

#include "plcdemos.h"

#define XPTS      500            // Data points in x
#define YPTS      500            // Data points in y
#define LEVELS    10

static int   opt[] = { DRAW_LINEXY, DRAW_LINEXY };

static PLFLT alt[] = { 33.0, 17.0 };
static PLFLT az[] = { 24.0, 115.0 };

static char  *title[4] =
{
    "#frPLplot Example 11 - Alt=33, Az=24, Opt=3",
    "#frPLplot Example 11 - Alt=17, Az=115, Opt=3",
};

static void
cmap1_init()
{
    PLFLT i[2], h[2], l[2], s[2];

    i[0] = 0.0;         // left boundary
    i[1] = 1.0;         // right boundary

    h[0] = 240;         // blue -> green -> yellow ->
    h[1] = 0;           // -> red

    l[0] = 0.6;
    l[1] = 0.6;

    s[0] = 0.8;
    s[1] = 0.8;

    plscmap1n( 256 );
    c_plscmap1l( 0, 2, i, h, l, s, NULL );
}

//--------------------------------------------------------------------------
// main
//
// Does a series of mesh plots for a given data set, with different
// viewing options in each plot.
//--------------------------------------------------------------------------

int
main( int argc, const char *argv[] )
{						
  FILE * fp;
    int   i, j, k;
    PLFLT *x, *y, **z;
    int   nlevel = LEVELS;
    PLFLT clevel[LEVELS];
    PLFLT zmin, zmax, step;
    PLFLT xmin, xmax;
    PLFLT ymin, ymax;
    // Parse and process command line arguments

    (void) plparseopts( &argc, argv, PL_PARSE_FULL );

    // Initialize plplot

    plinit();

    x = (PLFLT *) calloc( XPTS, sizeof ( PLFLT ) );
    y = (PLFLT *) calloc( YPTS, sizeof ( PLFLT ) );

    plAlloc2dGrid( &z, XPTS, YPTS );

    /* BEGIN : Allocating memory for storing data to plot on grid * * * * * * * * * * */
    double xx, yy, zz;
    double * W_GRID  = (double *)malloc( XPTS * YPTS * sizeof(double ) );
    double * x_Data  = (double *)malloc( XPTS * sizeof(double) ); 
    double * y_Data  = (double *)malloc( YPTS * sizeof(double) ); 
    /*   END : Allocating memory for storing dynamical data * * * * * * * * * * * * * */
    /* BEGIN : Reading Files * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int n = 0;
    if( (fp = fopen("DATA_XYZ.dat","r") ) == NULL) {
      printf("File non-existent in current directory!!!\n ---> Cannot open file.\n");
      exit(1);
    }
    for( k = 0; k < YPTS; k++ ) {
      for( j = 0; j < XPTS; j++ ){
	fscanf(fp, "%lf\t%lf\t%lf\n", &xx, &yy, &zz);
	x_Data[j] = xx; y_Data[k] = yy; W_GRID[n++] = zz;
      }
    }
    fclose(fp);
    xmin = (PLFLT)x_Data[0]; xmax = (PLFLT)x_Data[XPTS-1];
    ymin = (PLFLT)y_Data[0]; ymax = (PLFLT)y_Data[YPTS-1];
    /*   END : ----------------------------------------------------------------------*/

    for ( i = 0; i < XPTS; i++ )    x[i] = (PLFLT)x_Data[i]; 

    for ( i = 0; i < YPTS; i++ )    y[i] = (PLFLT)y_Data[i];
    
    n = 0;
    for ( j = 0; j < YPTS; j++ )
      for ( i = 0; i < XPTS; i++ )
        z[i][j] = (PLFLT)W_GRID[n++];

    plMinMax2dGrid( (const PLFLT **) z, XPTS, YPTS, &zmax, &zmin );
    step = ( zmax - zmin ) / ( nlevel + 1 );
    for ( i = 0; i < nlevel; i++ )
        clevel[i] = zmin + step + step * i;

    cmap1_init();
    for ( k = 0; k < 2; k++ )
    {
        for ( i = 0; i < 4; i++ )
        {
            pladv( 0 );
            plcol0( 1 );
            plvpor( 0.0, 1.0, 0.0, 0.9 );
            plwind( -1.0, 1.0, -1.0, 1.5 );
            plw3d( 1.0, 1.0, 1.2, xmin, xmax, ymin, ymax, zmin, zmax, alt[k], az[k] );
            plbox3( "bnstu", "x axis", 0.0, 0,
                "bnstu", "y axis", 0.0, 0,
                "bcdmnstuv", "z axis", 0.0, 4 );

            plcol0( 2 );

            // wireframe plot
            if ( i == 0 )
                plmesh( x, y, (const PLFLT **) z, XPTS, YPTS, opt[k] );

            // magnitude colored wireframe plot
            else if ( i == 1 )
                plmesh( x, y, (const PLFLT **) z, XPTS, YPTS, opt[k] | MAG_COLOR );

            // magnitude colored wireframe plot with sides
            else if ( i == 2 )
                plot3d( x, y, (const PLFLT **) z, XPTS, YPTS, opt[k] | MAG_COLOR, 1 );

            // magnitude colored wireframe plot with base contour
            else if ( i == 3 )
                plmeshc( x, y, (const PLFLT **) z, XPTS, YPTS, opt[k] | MAG_COLOR | BASE_CONT,
                    clevel, nlevel );

            plcol0( 3 );
            plmtex( "t", 1.0, 0.5, 0.5, title[k] );
        }
    }

// Clean up
    free(x_Data); free(y_Data); free(W_GRID);

    free( (void *) x );
    free( (void *) y );
    plFree2dGrid( z, XPTS, YPTS );

    plend();

    exit( 0 );
}
