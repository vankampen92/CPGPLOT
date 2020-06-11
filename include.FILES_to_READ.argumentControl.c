case 'F': /* Name of the file to be read */
              if(argv[argcount][2]=='n') { 
              /* No of FILES to READ */
                sscanf(argv[argcount+1],"%d", &No_of_FILES);
		assert( No_of_FILES <= MAX_No_of_FILES );
	      }
	      else if(argv[argcount][2]=='0')
                sscanf(argv[argcount+1],"%s", Name_of_FILE[0]);
	      else if(argv[argcount][2]=='1') { 
		if(argv[argcount][3]=='\0')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[1]);
		else if(argv[argcount][3]=='0')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[10]);
		else if(argv[argcount][3]=='1')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[11]);
		else if(argv[argcount][3]=='2')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[12]);
		else if(argv[argcount][3]=='3')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[13]);
		else if(argv[argcount][3]=='4')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[14]);
		else if(argv[argcount][3]=='5')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[15]);
		else if(argv[argcount][3]=='6')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[16]);
		else if(argv[argcount][3]=='7')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[17]);
		else if(argv[argcount][3]=='8')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[18]);
		else if(argv[argcount][3]=='9')
		  sscanf(argv[argcount+1],"%s", Name_of_FILE[19]);
	      }
              else if(argv[argcount][2]=='2')
	        sscanf(argv[argcount+1],"%s", Name_of_FILE[2]);
              else if(argv[argcount][2]=='3')
	        sscanf(argv[argcount+1],"%s", Name_of_FILE[3]);
              else if(argv[argcount][2]=='4')
	        sscanf(argv[argcount+1],"%s", Name_of_FILE[4]);
              else if(argv[argcount][2]=='5')
	        sscanf(argv[argcount+1],"%s", Name_of_FILE[5]);
              else if(argv[argcount][2]=='6')
	        sscanf(argv[argcount+1],"%s", Name_of_FILE[6]);
              else if(argv[argcount][2]=='7')
	        sscanf(argv[argcount+1],"%s", Name_of_FILE[7]);
              else if(argv[argcount][2]=='8')
	        sscanf(argv[argcount+1],"%s", Name_of_FILE[8]);
              else if(argv[argcount][2]=='9')
	        sscanf(argv[argcount+1],"%s", Name_of_FILE[9]);
              
	      else exit(0);
	      skip++;
	      break;

              case 'X': /* X dimension of the file to be read */
              if(argv[argcount][2]=='0') {
                sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[0] = n_Dummy; }
	      else if(argv[argcount][2]=='1') {
		if(argv[argcount][3]=='\0')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[1] = n_Dummy; }
		else if(argv[argcount][3]=='0')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[10] = n_Dummy; }
		else if(argv[argcount][3]=='1')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[11] = n_Dummy; }
		else if(argv[argcount][3]=='2')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[12] = n_Dummy; }
		else if(argv[argcount][3]=='3')
		 { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[13] = n_Dummy; } 
		else if(argv[argcount][3]=='4')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[14] = n_Dummy; }
		else if(argv[argcount][3]=='5')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[15] = n_Dummy; }
		else if(argv[argcount][3]=='6')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[16] = n_Dummy; }
		else if(argv[argcount][3]=='7')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[17] = n_Dummy; }
		else if(argv[argcount][3]=='8')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[18] = n_Dummy; }
		else if(argv[argcount][3]=='9')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[19] = n_Dummy; }
	      }
              else if(argv[argcount][2]=='2') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[2] = n_Dummy; }
              else if(argv[argcount][2]=='3') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[3] = n_Dummy; }
              else if(argv[argcount][2]=='4') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[4] = n_Dummy; }
              else if(argv[argcount][2]=='5') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[5] = n_Dummy; }
              else if(argv[argcount][2]=='6') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[6] = n_Dummy; }
              else if(argv[argcount][2]=='7') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[7] = n_Dummy; }
              else if(argv[argcount][2]=='8') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[8] = n_Dummy; }
              else if(argv[argcount][2]=='9') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_x_GRID[9] = n_Dummy; }
	      else exit(0);
	      skip++;
	      break;

              case 'Y': /* Y dimension of the file to be read */
              if(argv[argcount][2]=='0') {
                sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[0] = n_Dummy; }
	      else if(argv[argcount][2]=='1') {
		if(argv[argcount][3]=='\0')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[1] = n_Dummy; }
		else if(argv[argcount][3]=='0')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[10] = n_Dummy; }
		else if(argv[argcount][3]=='1')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[11] = n_Dummy; }
		else if(argv[argcount][3]=='2')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[12] = n_Dummy; }
		else if(argv[argcount][3]=='3')
		 { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[13] = n_Dummy; } 
		else if(argv[argcount][3]=='4')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[14] = n_Dummy; }
		else if(argv[argcount][3]=='5')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[15] = n_Dummy; }
		else if(argv[argcount][3]=='6')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[16] = n_Dummy; }
		else if(argv[argcount][3]=='7')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[17] = n_Dummy; }
		else if(argv[argcount][3]=='8')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[18] = n_Dummy; }
		else if(argv[argcount][3]=='9')
		  { sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[19] = n_Dummy; }
	      }
              else if(argv[argcount][2]=='2') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[2] = n_Dummy; }
              else if(argv[argcount][2]=='3') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[3] = n_Dummy; }
              else if(argv[argcount][2]=='4') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[4] = n_Dummy; }
              else if(argv[argcount][2]=='5') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[5] = n_Dummy; }
              else if(argv[argcount][2]=='6') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[6] = n_Dummy; }
              else if(argv[argcount][2]=='7') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[7] = n_Dummy; }
              else if(argv[argcount][2]=='8') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[8] = n_Dummy; }
              else if(argv[argcount][2]=='9') {
	        sscanf(argv[argcount+1],"%d", &n_Dummy); F_y_GRID[9] = n_Dummy; }
	      else exit(0);
	      skip++;
	      break;

