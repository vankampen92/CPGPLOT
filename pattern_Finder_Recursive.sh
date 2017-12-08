echo "This script looks for [PATTERN] in all files matching the pattern specified in [TYPE_of_FILE]" 
echo "from the directory specified by [DIR] down the directory tree in a recursive way."
echo 
echo "Usage:" 
echo "       ~$] bash pattern_Finder_Recursive.sh [TYPE_of_FILE] [PATTERN] [DIR]"
echo "Example:"
echo "       ~$] bash pattern_Finder_Recursive.sh ''*.c'' SP_Data_Matrix" ./
echo
echo "If [TYPE_of_FILE] contains wild card characters, such as *, then you should write [TYPE_of_FILE] between TRUE quotes."
echo 
echo "This function is based on the standard linux command 'find' (which calls the companion script 'pattern_Finder_in_File.sh'):"
echo
echo "       ~$] find ./ -name "argumentControl.c" -exec sh /home/dalonso/C_pro/Unix_Script_Samples/pattern_Finder_in_File.sh {} A_L_L \;"
echo "       ~$] find ./ -name "*.c"               -exec sh /home/dalonso/C_pro/Unix_Script_Samples/pattern_Finder_in_File.sh {} init_Tr \;"
echo 
echo "In the first example, this command will find the pattern A_L_L in all files called argumentControl.c starting at ./, this is,"
echo "the directory where this script is invoke, down the tree of directories. You get exactly the same result as:"
echo "       ~$] bash pattern_Finder_Recursive.sh argumentControl.c  A_L_L  ./"
echo "In the second example, this command will find the pattern init_Tr in all files with extension .c down the tree of files, starting at ./, which is equivalent to:"
echo "       ~$] bash pattern_Finder_Recursive.sh ''*.c'' init_Tr ./"
echo
echo "The output file only contains all the lines within the files where these matches occur,"
echo "along with the full path name, and the file name of each of those files."  
echo " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
find $3 ./ -name "$1" -exec sh pattern_Finder_in_File.sh {} $2 \; > pattern_Finder_Recursive_Output.txt
echo "The file pattern_Finder_Recursive_Output.txt has been written."
