#!/bin/bash
### Usage: 
###     ~]$ sh pattern_Finder_in_FILE.sh FILE_NAME PATTERN
### This will look for PATTERN in FILE_NAME
### The out put is give in two lines:
### 1st line: the whole line where pattern appears in files 
### 2nd line: the name and path of file where the pattern
### appears. 
FILE=$1
  ### echo "Looking for "$2 "in file "$1"..."
 if ( less $1 | grep $2 ) then 
	ls -la $FILE
###  echo "Please press ENTER to continue. Otherwise Ctrl+C to quit."
  echo "... ... ... ..."
###  read INPUT_STRING
 fi
