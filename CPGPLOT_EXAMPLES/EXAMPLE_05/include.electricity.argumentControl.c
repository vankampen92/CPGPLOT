// Last Modified On: 2018-12-30
	case 'C': 
            if(argv[argcount][2]=='0')
				sscanf(argv[argcount+1],"%lf",&C0);
	    	else {printf("invalid argument\n"); exit(0);}
			skip++;
	break;

	case 'P': 
            if(argv[argcount][2]=='0')
				sscanf(argv[argcount+1],"%lf",&P0);
	    	else {printf("invalid argument\n"); exit(0);}
			skip++;
	break;

	case 'V': 
            if(argv[argcount][2]=='0')
				sscanf(argv[argcount+1],"%lf",&V0);
	    	else {printf("invalid argument\n"); exit(0);}
			skip++;
	break;

	case 'L': 
            if(argv[argcount][2]=='0')
				sscanf(argv[argcount+1],"%lf",&L0);
 	   	 	else {printf("invalid argument\n"); exit(0);}
			skip++;
	break;
	
	case 'A': 
            if(argv[argcount][2]=='B')
				sscanf(argv[argcount+1],"%lf",&AB);
	    	else if (argv[argcount][2]=='1')
	    		        sscanf(argv[argcount+1],"%lf",&A1);
	    	else if (argv[argcount][2]=='2')
	    		        sscanf(argv[argcount+1],"%lf",&A2);
	    	else {printf("invalid argument\n"); exit(0);}
			skip++;	    		        
	break;	
	            
	    
