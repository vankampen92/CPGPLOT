              case 'F': /* Name of the file to be read */
              if(argv[argcount][2]=='n') { 
              /* No of FILES to READ */
                fprintf(fp,"-Fn  %d  ", No_of_FILES);
		assert( No_of_FILES <= MAX_No_of_FILES );
	      }
	      else if(argv[argcount][2]=='0')
                fprintf(fp,"F0-  %s  ", Name_of_FILE[0]);
	      else if(argv[argcount][2]=='1') { 
		if(argv[argcount][3]=='\0')
		  fprintf(fp,"-F1  %s  ", Name_of_FILE[1]);
		else if(argv[argcount][3]=='0')
		  fprintf(fp,"-F10  %s  ", Name_of_FILE[10]);
		else if(argv[argcount][3]=='1')
		  fprintf(fp,"-F11 %s  ", Name_of_FILE[11]);
		else if(argv[argcount][3]=='2')
		  fprintf(fp,"-F12  %s  ", Name_of_FILE[12]);
		else if(argv[argcount][3]=='3')
		  fprintf(fp,"-F13  %s  ", Name_of_FILE[13]);
		else if(argv[argcount][3]=='4')
		  fprintf(fp,"-F14  %s  ", Name_of_FILE[14]);
		else if(argv[argcount][3]=='5')
		  fprintf(fp,"-F15  %s  ", Name_of_FILE[15]);
		else if(argv[argcount][3]=='6')
		  fprintf(fp,"-F16  %s  ", Name_of_FILE[16]);
		else if(argv[argcount][3]=='7')
		  fprintf(fp,"-F17  %s  ", Name_of_FILE[17]);
		else if(argv[argcount][3]=='8')
		  fprintf(fp,"-F18  %s  ", Name_of_FILE[18]);
		else if(argv[argcount][3]=='9')
		  fprintf(fp,"-F19  %s  ", Name_of_FILE[19]);
	      }
              else if(argv[argcount][2]=='2')
	        fprintf(fp,"-F2  %s  ", Name_of_FILE[2]);
              else if(argv[argcount][2]=='3')
	        fprintf(fp,"-F3  %s  ", Name_of_FILE[3]);
              else if(argv[argcount][2]=='4')
	        fprintf(fp,"-F4  %s  ", Name_of_FILE[4]);
              else if(argv[argcount][2]=='5')
	        fprintf(fp,"-F5  %s  ", Name_of_FILE[5]);
              else if(argv[argcount][2]=='6')
	        fprintf(fp,"-F6  %s  ", Name_of_FILE[6]);
              else if(argv[argcount][2]=='7')
	        fprintf(fp,"-F7  %s  ", Name_of_FILE[7]);
              else if(argv[argcount][2]=='8')
	        fprintf(fp,"-F8  %s  ", Name_of_FILE[8]);
              else if(argv[argcount][2]=='9')
	        fprintf(fp,"-F9  %s  ", Name_of_FILE[9]);
              
	      else exit(0);
	      skip++;
	      break;

              case 'X': /* X dimension of the file to be read */
              if(argv[argcount][2]=='0') {
                fprintf(fp,"-X0  %d  ", n_Dummy); F_x_GRID[0] = n_Dummy; }
	      else if(argv[argcount][2]=='1') {
		if(argv[argcount][3]=='\0')
		  { fprintf(fp,"-X1  %d  ", n_Dummy); F_x_GRID[1] = n_Dummy; }
		else if(argv[argcount][3]=='0')
		  { fprintf(fp,"-X10  %d  ", n_Dummy); F_x_GRID[10] = n_Dummy; }
		else if(argv[argcount][3]=='1')
		  { fprintf(fp,"-X11  %d  ", n_Dummy); F_x_GRID[11] = n_Dummy; }
		else if(argv[argcount][3]=='2')
		  { fprintf(fp,"-X12  %d  ", n_Dummy); F_x_GRID[12] = n_Dummy; }
		else if(argv[argcount][3]=='3')
		 { fprintf(fp,"-X13  %d  ", n_Dummy); F_x_GRID[13] = n_Dummy; } 
		else if(argv[argcount][3]=='4')
		  { fprintf(fp,"-X14  %d  ", n_Dummy); F_x_GRID[14] = n_Dummy; }
		else if(argv[argcount][3]=='5')
		  { fprintf(fp,"-X15  %d  ", n_Dummy); F_x_GRID[15] = n_Dummy; }
		else if(argv[argcount][3]=='6')
		  { fprintf(fp,"-X16  %d  ", n_Dummy); F_x_GRID[16] = n_Dummy; }
		else if(argv[argcount][3]=='7')
		  { fprintf(fp,"-X17  %d  ", n_Dummy); F_x_GRID[17] = n_Dummy; }
		else if(argv[argcount][3]=='8')
		  { fprintf(fp,"-X18  %d  ", n_Dummy); F_x_GRID[18] = n_Dummy; }
		else if(argv[argcount][3]=='9')
		  { fprintf(fp,"-X19  %d  ", n_Dummy); F_x_GRID[19] = n_Dummy; }
	      }
              else if(argv[argcount][2]=='2') {
	        fprintf(fp,"-X2  %d  ", n_Dummy); F_x_GRID[2] = n_Dummy; }
              else if(argv[argcount][2]=='3') {
	        fprintf(fp,"-X3  %d  ", n_Dummy); F_x_GRID[3] = n_Dummy; }
              else if(argv[argcount][2]=='4') {
	        fprintf(fp,"-X4  %d  ", n_Dummy); F_x_GRID[4] = n_Dummy; }
              else if(argv[argcount][2]=='5') {
	        fprintf(fp,"-X5  %d  ", n_Dummy); F_x_GRID[5] = n_Dummy; }
              else if(argv[argcount][2]=='6') {
	        fprintf(fp,"-X6  %d  ", n_Dummy); F_x_GRID[6] = n_Dummy; }
              else if(argv[argcount][2]=='7') {
	        fprintf(fp,"-X7  %d  ", n_Dummy); F_x_GRID[7] = n_Dummy; }
              else if(argv[argcount][2]=='8') {
	        fprintf(fp,"-X8  %d  ", n_Dummy); F_x_GRID[8] = n_Dummy; }
              else if(argv[argcount][2]=='9') {
	        fprintf(fp,"-X9  %d  ", n_Dummy); F_x_GRID[9] = n_Dummy; }
	      else exit(0);
	      skip++;
	      break;

              case 'Y': /* Y dimension of the file to be read */
              if(argv[argcount][2]=='0') {
                fprintf(fp,"-Y0  %d  ", n_Dummy); F_y_GRID[0] = n_Dummy; }
	      else if(argv[argcount][2]=='1') {
		if(argv[argcount][3]=='\0')
		  { fprintf(fp,"-Y1  %d  ", n_Dummy); F_y_GRID[1] = n_Dummy; }
		else if(argv[argcount][3]=='0')
		  { fprintf(fp,"-Y10  %d  ", n_Dummy); F_y_GRID[10] = n_Dummy; }
		else if(argv[argcount][3]=='1')
		  { fprintf(fp,"-Y11  %d  ", n_Dummy); F_y_GRID[11] = n_Dummy; }
		else if(argv[argcount][3]=='2')
		  { fprintf(fp,"-Y12  %d  ", n_Dummy); F_y_GRID[12] = n_Dummy; }
		else if(argv[argcount][3]=='3')
		 { fprintf(fp,"-Y13  %d  ", n_Dummy); F_y_GRID[13] = n_Dummy; } 
		else if(argv[argcount][3]=='4')
		  { fprintf(fp,"-Y14  %d  ", n_Dummy); F_y_GRID[14] = n_Dummy; }
		else if(argv[argcount][3]=='5')
		  { fprintf(fp,"-Y15  %d  ", n_Dummy); F_y_GRID[15] = n_Dummy; }
		else if(argv[argcount][3]=='6')
		  { fprintf(fp,"-Y16  %d  ", n_Dummy); F_y_GRID[16] = n_Dummy; }
		else if(argv[argcount][3]=='7')
		  { fprintf(fp,"-Y17  %d  ", n_Dummy); F_y_GRID[17] = n_Dummy; }
		else if(argv[argcount][3]=='8')
		  { fprintf(fp,"-Y18  %d  ", n_Dummy); F_y_GRID[18] = n_Dummy; }
		else if(argv[argcount][3]=='9')
		  { fprintf(fp,"-Y19  %d  ", n_Dummy); F_y_GRID[19] = n_Dummy; }
	      }
              else if(argv[argcount][2]=='2') {
	        fprintf(fp,"-Y2  %d  ", n_Dummy); F_y_GRID[2] = n_Dummy; }
              else if(argv[argcount][2]=='3') {
	        fprintf(fp,"-Y3  %d  ", n_Dummy); F_y_GRID[3] = n_Dummy; }
              else if(argv[argcount][2]=='4') {
	        fprintf(fp,"-Y4  %d  ", n_Dummy); F_y_GRID[4] = n_Dummy; }
              else if(argv[argcount][2]=='5') {
	        fprintf(fp,"-Y5  %d  ", n_Dummy); F_y_GRID[5] = n_Dummy; }
              else if(argv[argcount][2]=='6') {
	        fprintf(fp,"-Y6  %d  ", n_Dummy); F_y_GRID[6] = n_Dummy; }
              else if(argv[argcount][2]=='7') {
	        fprintf(fp,"-Y7  %d  ", n_Dummy); F_y_GRID[7] = n_Dummy; }
              else if(argv[argcount][2]=='8') {
	        fprintf(fp,"-Y8  %d  ", n_Dummy); F_y_GRID[8] = n_Dummy; }
              else if(argv[argcount][2]=='9') {
	        fprintf(fp,"-Y9  %d  ", n_Dummy); F_y_GRID[9] = n_Dummy; }
	      else exit(0);
	      skip++;
	      break;

