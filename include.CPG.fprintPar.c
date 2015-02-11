fprintf(fp, "\n CPGPLOT command line arguments: \n");
fprintf(fp, " # subpanels horizontal dimension: CPG_PANEL_X   ==> [PROGRAM] -G0 %d\n", CPG__PANEL__X);
fprintf(fp, " # subpanels horizontal dimension: CPG_PANEL_Y   ==> [PROGRAM] -G1 %d\n", CPG__PANEL__Y);

fprintf(fp, " Important note: When all the plots need\n");
fprintf(fp, " the same vertical and/or horizontal scale at running time, the defining\n");
fprintf(fp, " ranges, (X_0, X_1) and (Y_0, Y_1), can be introduced as command line arguments\n");
fprintf(fp, " (CPG_SCALE_X = 1, CPG_SCALE_Y = 1).\n");
fprintf(fp, " Otherwise it is better let the program calculate the proper ranges at\n");
fprintf(fp, " (CPG_SCALE_X = 0, CPG_SCALE_Y = 0)\n");
fprintf(fp, " X scale   [ 1: Fixed through command line) | 0: Dynamic ] CPG_SCALE_X   ==> [PROGRAM] -G2 %d\n", CPG_SCALE_X);
fprintf(fp, " Scale Range: CPG_RANGE_X_0 ==> [PROGRAM] -G3 %lf\n", CPG_RANGE_X_0);
fprintf(fp, " Scale Range: CPG_RANGE_X_1 ==> [PROGRAM] -G4 %lf\n", CPG_RANGE_X_1);
fprintf(fp, " Y scale   [ 1: Fixed through command line) | 0: Dynamic ] CPG_SCALE_Y   ==> [PROGRAM] -G5 %d\n", CPG_SCALE_Y);
fprintf(fp, " Scale Range: CPG_RANGE_Y_0 ==> [PROGRAM] -G6 %lf\n", CPG_RANGE_Y_0);
fprintf(fp, " Scale Range: CPG_RANGE_Y_1 ==> [PROGRAM] -G7 %lf\n", CPG_RANGE_Y_1);

fprintf(fp, " Color, Line, Width, and Symbol can be also defined from the command line.\n");
fprintf(fp, " This will have an effect on your plot, depending on the type of plotting\n");
fprintf(fp, " at work (see cpgplot_UTL.c and CPGPLOT_UTL.c)\n");
fprintf(fp, " For custumized definitions to have any change to work,\n");
fprintf(fp, " the boolean parameter CPG_LINE_TYPES (0/1) should be 1\n");
fprintf(fp, " CPG_LINE_TYPES:   ==> [PROGRAM] -G8 %d\n",  CPG_LINE_TYPES);
fprintf(fp, " Color Index:      ==> [PROGRAM] -G9 %d\n",  color_Index);
fprintf(fp, " Line Index:       ==> [PROGRAM] -G10 %d\n", type_of_Line);
fprintf(fp, " Width Index:      ==> [PROGRAM] -G11 %d\n", type_of_Width);
fprintf(fp, " Symbol Index:     ==> [PROGRAM] -G12 %d\n", type_of_Symbol);
fprintf(fp, "\n");
fprintf(fp, " Title and axes labels can be also defined from the command line.\n");
fprintf(fp, " This will have an effect on your plot, depending on the type of plotting\n");
fprintf(fp, " at work (see cpgplot_UTL.c and CPGPLOT_UTL.c)\n");
fprintf(fp, " For custumized definitions to have any change to work,\n");
fprintf(fp, " the boolean parameter CPG_LABEL_TYPES (0/1) should be 1\n");
fprintf(fp, " CPG_LABEL_TYPES:  ==> [PROGRAM] -G13 %d\n", CPG_LABEL_TYPES);
fprintf(fp, " Title:            ==> [PROGRAM] -G14 %s\n", Title);
fprintf(fp, " X label:          ==> [PROGRAM] -G15 %s\n", X_label);
fprintf(fp, " Y_label:          ==> [PROGRAM] -G16 %s\n", Y_label);

fprintf(fp, " 3d dimension W_label:            ==> [PROGRAM] -G17 %s\n", W_label);
fprintf(fp, " W scale   [ 1: Fixed through command line) | 0: Dynamic ] CPG_SCALE_W   ==> [PROGRAM] -G24 %d\n", CPG_SCALE_W);
fprintf(fp, " Scale Range: CPG_RANGE_W_0 ==> [PROGRAM] -G25 %lf\n", CPG_RANGE_W_0);
fprintf(fp, " Scale Range: CPG_RANGE_W_1 ==> [PROGRAM] -G26 %lf\n", CPG_RANGE_W_1);

fprintf(fp, " No of divisions in the horizontal (x_GRID) and vertical (y_GRID) axes:\n");
fprintf(fp, " x_GRID (-G18) = %d\t y_GRID (-G19) = %d\n", x_GRID, y_GRID);
fprintf(fp, " Horizontal (X_Dimension -G20 ) and vertitcal (Y_Dimension -G21) dimensions:\n");
fprintf(fp, " X_Dimension = %g\t Y_Dimension = %g\n", X_Dimension, Y_Dimension);
fprintf(fp, " Origin on the (X, Y) plane: ORIGIN_X  (-G22)   = %g\t ORIGEN_Y (-G23) = %g\n", ORIGIN_X, ORIGIN_Y); 

fprintf(fp, " Contour drawing over a 2D grid: AUTOMATIC_CONTOUR(-G27) = %d\t NC(-G28  No of Contour lines) = %d\n", 
	AUTOMATIC_CONTOUR, NC);

fprintf(fp, " Type of output driver for the graphic to be send to print/write.\n");
fprintf(fp, " Default: -G29 %s\n", CPG_DRIVER_NAME );
fprintf(fp, " Most useful options are:\n");
fprintf(fp, "                /XSERVE\n");
fprintf(fp, "                /CPS\n");
fprintf(fp, " Introduce  ? to see the whole list of possible drivers\n\n");

fprintf(fp, " Parameter to annotate plots:\n"); 
fprintf(fp, " The first character must be one of the characters\n");
fprintf(fp, " 'B', 'L', 'T', or 'R' signifying the Bottom, Left,\n");
fprintf(fp, " Top, or Right edge of the viewport.\n");
fprintf(fp, " Default: -G30 %s\n", SIDE);

fprintf(fp, " Parameters controling 2d shanding plots\n");
fprintf(fp, " Default: Type of Shading:                      -G31 %d\n", Type_of_COLOR_SHADING);
fprintf(fp, " Default: Color Brightness:                     -G32 %f\n", Type_of_BRIGHT);
fprintf(fp, " Default: Inverted (-1.0) vs Non-inverted (1.0) -G33 %f\n", Type_of_CONTRA); 



