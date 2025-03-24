/* CPG visual representation */ 

	    case 'G': 
            if(argv[argcount][2]=='0')
				sscanf(argv[argcount+1],"%d",&CPG__PANEL__X);
	        else if(argv[argcount][2]=='1') {
				if(argv[argcount][3]=='\0'){
		  			sscanf(argv[argcount+1],"%d",&CPG__PANEL__Y);
				}
				else if(argv[argcount][3]=='0'){
		  			sscanf(argv[argcount+1],"%d",&type_of_Line);
				}
				else if(argv[argcount][3]=='1'){
		  			sscanf(argv[argcount+1],"%d",&type_of_Width);
				}
				else if(argv[argcount][3]=='2'){
		  			sscanf(argv[argcount+1],"%d",&type_of_Symbol);
				}
                else if(argv[argcount][3]=='3'){
		  			sscanf(argv[argcount+1],"%d",&CPG_LABEL_TYPES);
				}
				else if(argv[argcount][3]=='4'){
		  			sscanf(argv[argcount+1],"%s", Title);
				}
				else if(argv[argcount][3]=='5'){
		  			sscanf(argv[argcount+1],"%s", X_label);
				}
                else if(argv[argcount][3]=='6'){
		  			sscanf(argv[argcount+1],"%s", Y_label);
				}
				else if(argv[argcount][3]=='7'){
		  			sscanf(argv[argcount+1],"%s", W_label);
				}
				else if(argv[argcount][3]=='8'){
		  			sscanf(argv[argcount+1],"%d", &x_GRID);
				}
				else if(argv[argcount][3]=='9'){
		  			sscanf(argv[argcount+1],"%d", &y_GRID);
				}
				else {
		  			printf(" Some error reading CPG parameters\n");
		  			printf(" in include.CPG.argumentControl.c\n");
		  			printf(" Exiting..."); getchar();
		  			exit(0);
				}
	      	}	 		
            else if(argv[argcount][2]=='2') {
				if(argv[argcount][3]=='\0'){
		  			sscanf(argv[argcount+1],"%d", &CPG_SCALE_X);
				}	
				else if(argv[argcount][3]=='0'){
		  			sscanf(argv[argcount+1],"%lf",&X_Dimension);
				}
				else if(argv[argcount][3]=='1'){
		  			sscanf(argv[argcount+1],"%lf",&Y_Dimension);
				}
				else if(argv[argcount][3]=='2'){
		  			sscanf(argv[argcount+1],"%lf",&ORIGIN_X);
				}
				else if(argv[argcount][3]=='3'){
		  			sscanf(argv[argcount+1],"%lf",&ORIGIN_Y);
				}
				else if(argv[argcount][3]=='4'){
		  			sscanf(argv[argcount+1],"%d", &CPG_SCALE_W);
				}
				else if(argv[argcount][3]=='5'){
		  			sscanf(argv[argcount+1],"%lf", &CPG_RANGE_W_0);
				}
				else if(argv[argcount][3]=='6'){
		  			sscanf(argv[argcount+1],"%lf", &CPG_RANGE_W_1);
				}
				else if(argv[argcount][3]=='7'){
		  			sscanf(argv[argcount+1],"%d", &AUTOMATIC_CONTOUR);
				}
				else if(argv[argcount][3]=='8'){
		  			sscanf(argv[argcount+1],"%d", &NC);
				}
                else if(argv[argcount][3]=='9'){
		  			sscanf(argv[argcount+1],"%s", CPG_DRIVER_NAME );
				}
				else {
		  			printf(" Some error reading CPG parameters\n");
		  			printf(" in include.CPG.argumentControl.c\n");
		  			printf(" Exiting..."); getchar();
		  			exit(0);
				}
	      	}
            else if(argv[argcount][2]=='3') {
                if(argv[argcount][3]=='\0'){
		  			sscanf(argv[argcount+1],"%lf",&CPG_RANGE_X_0);
                }
                else if(argv[argcount][3]=='0'){
                  	sscanf(argv[argcount+1],"%s", SIDE);
                }
				else if(argv[argcount][3]=='1'){
                  	sscanf(argv[argcount+1],"%d", &Type_of_COLOR_SHADING);
                }
				else if(argv[argcount][3]=='2'){
                  	sscanf(argv[argcount+1],"%f", &Type_of_BRIGHT);
                }
				else if(argv[argcount][3]=='3'){
                  	sscanf(argv[argcount+1],"%f", &Type_of_CONTRA);
                }
				else if(argv[argcount][3]=='4'){
                  	sscanf(argv[argcount+1], "%s", X_axis_Control);
                }
				else if(argv[argcount][3]=='5'){
                  	sscanf(argv[argcount+1], "%s", Y_axis_Control);
                }
                else {
                  printf(" Some error reading CPG parameters\n");
                  printf(" in include.CPG.argumentControl.c\n");
                  printf(" Exiting..."); getchar();
                  exit(0);
                }
	      	}
            else if(argv[argcount][2]=='4')
				sscanf(argv[argcount+1],"%lf",&CPG_RANGE_X_1);
            else if(argv[argcount][2]=='5')
				sscanf(argv[argcount+1],"%d",&CPG_SCALE_Y);
            else if(argv[argcount][2]=='6')
				sscanf(argv[argcount+1],"%lf",&CPG_RANGE_Y_0);
            else if(argv[argcount][2]=='7')
				sscanf(argv[argcount+1],"%lf",&CPG_RANGE_Y_1);
            else if(argv[argcount][2]=='8')
				sscanf(argv[argcount+1],"%d", &CPG_LINE_TYPES);
            else if(argv[argcount][2]=='9')
				sscanf(argv[argcount+1],"%d", &color_Index);
            else{ 
				printf("  CPG argument parameters are only:\n");
				printf(" -G0 [ ] -G1 [ ] ... ... -G39 [ ]\n");
				exit(0);
	      	}
	      skip++;
	      break;
	    
