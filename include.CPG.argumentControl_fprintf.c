/* CPG visual representation */ 

	      case 'G': 
              if(argv[argcount][2]=='0')
		fprintf(fp,"-G0  %d  ",Table->CPG__PANEL__X);
	      else if(argv[argcount][2]=='1') {
		if(argv[argcount][3]=='\0'){
		  fprintf(fp,"-G1  %d  ",Table->CPG__PANEL__Y);
		}
		else if(argv[argcount][3]=='0'){
		  fprintf(fp,"-G10  %d  ",Table->type_of_Line);
		}
		else if(argv[argcount][3]=='1'){
		  fprintf(fp,"-G11  %d  ",Table->type_of_Width);
		}
		else if(argv[argcount][3]=='2'){
		  fprintf(fp,"-G12  %d  ",Table->type_of_Symbol);
		}
                else if(argv[argcount][3]=='3'){
		  fprintf(fp,"-G13  %d  ",Table->CPG_LABEL_TYPES);
		}
		else if(argv[argcount][3]=='4'){
		  fprintf(fp,"-G14 %s", Title);
		}
		else if(argv[argcount][3]=='5'){
		  fprintf(fp,"-G15 %s", X_label);
		}
                else if(argv[argcount][3]=='6'){
		  fprintf(fp,"-G16 %s", Y_label);
		}
		else if(argv[argcount][3]=='7'){
		  fprintf(fp,"-G17 %s", W_label);
		}
		else if(argv[argcount][3]=='8'){
		  fprintf(fp,"-G18  %d  ", Table->x_GRID);
		}
		else if(argv[argcount][3]=='9'){
		  fprintf(fp,"-G19  %d  ", Table->y_GRID);
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
		  fprintf(fp,"-G2  %d  ", Table->CPG_SCALE_X);
		}
		else if(argv[argcount][3]=='0'){
		  fprintf(fp,"-G20  %g  ",Table->X_Dimension);
		}
		else if(argv[argcount][3]=='1'){
		  fprintf(fp,"-G21  %g  ",Table->Y_Dimension);
		}
		else if(argv[argcount][3]=='2'){
		  fprintf(fp,"-G22  %g  ",Table->ORIGIN_X);
		}
		else if(argv[argcount][3]=='3'){
		  fprintf(fp,"-G23  %g  ",Table->ORIGIN_Y);
		}
		else if(argv[argcount][3]=='4'){
		  fprintf(fp,"-G24  %d  ", Table->CPG_SCALE_W);
		}
		else if(argv[argcount][3]=='5'){
		  fprintf(fp,"-G25  %g  ", Table->CPG_RANGE_W_0);
		}
		else if(argv[argcount][3]=='6'){
		  fprintf(fp,"-G26  %g  ", Table->CPG_RANGE_W_1);
		}
		else if(argv[argcount][3]=='7'){
		  fprintf(fp,"-G27  %d  ", Table->AUTOMATIC_CONTOUR);
		}
		else if(argv[argcount][3]=='8'){
		  fprintf(fp,"-G28  %d  ", Table->NC);
		}
                else if(argv[argcount][3]=='9'){
		  fprintf(fp,"-G29 %s", CPG_DRIVER_NAME );
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
		  fprintf(fp,"-G3  %g  ",Table->CPG_RANGE_X_0);
                }
                else if(argv[argcount][3]=='0'){
                  fprintf(fp,"-G30 %s", SIDE);
                }
		else if(argv[argcount][3]=='1'){
                  fprintf(fp,"-G31  %d  ", Table->Type_of_COLOR_SHADING);
                }
		else if(argv[argcount][3]=='2'){
                  fprintf(fp,"-G32 %f", Table->Type_of_BRIGHT);
                }
		else if(argv[argcount][3]=='3'){
                  fprintf(fp,"-G33 %f", Table->Type_of_CONTRA);
                }
		else if(argv[argcount][3]=='4'){
                  fprintf(fp, "-G34 %s", X_axis_Control);
                }
		else if(argv[argcount][3]=='5'){
                  fprintf(fp, "-G35 %s", Y_axis_Control);
                }
                else {
                  printf(" Some error reading CPG parameters\n");
                  printf(" in include.CPG.argumentControl.c\n");
                  printf(" Exiting..."); getchar();
                  exit(0);
                }
	      }
              else if(argv[argcount][2]=='4')
		fprintf(fp,"-G4  %g  ",Table->CPG_RANGE_X_1);
              else if(argv[argcount][2]=='5')
		fprintf(fp,"-G5  %d  ",Table->CPG_SCALE_Y);
              else if(argv[argcount][2]=='6')
		fprintf(fp,"-G6  %g  ",Table->CPG_RANGE_Y_0);
              else if(argv[argcount][2]=='7')
		fprintf(fp,"-G7  %g  ",Table->CPG_RANGE_Y_1);
              else if(argv[argcount][2]=='8')
		fprintf(fp,"-G8  %d  ", Table->CPG_LINE_TYPES);
              else if(argv[argcount][2]=='9')
		fprintf(fp,"-G9  %d  ", Table->color_Index);
              else{ 
		printf("  CPG argument parameters are only:\n");
		printf(" -G0 [ ] -G1 [ ] ... ... -G35 [ ]\n");
		exit(0);
	      }
	      skip++;
	      break;
	    
