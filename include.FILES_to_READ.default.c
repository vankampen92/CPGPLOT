/* include.FILES_to_READ.default.c */
  No_of_FILES    = MAX_No_of_FILES;

  Name_of_FILE    = (char **)malloc( MAX_No_of_FILES * sizeof(char *) );
  F_x_GRID        = (int *)malloc( MAX_No_of_FILES * sizeof( int ) );
  F_y_GRID        = (int *)malloc( MAX_No_of_FILES * sizeof( int ) );

  char * FILE_pFile;
  char num[12];
  int i_FILE;

  for( i_FILE=0; i_FILE < MAX_No_of_FILES; i_FILE++ ) {
     Name_of_FILE[i_FILE] = (char *)malloc( 500 * sizeof( char ) );
     Name_of_FILE[i_FILE][0]='\0';  
     FILE_pFile =  strcat(Name_of_FILE[i_FILE], "File_");
     sprintf(num, "%d", i_FILE);
     FILE_pFile = strcat(Name_of_FILE[i_FILE], num);
     FILE_pFile = strcat(Name_of_FILE[i_FILE], ".dat");
  }
