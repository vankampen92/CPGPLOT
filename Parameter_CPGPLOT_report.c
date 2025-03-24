/* 
 * This header file (CPGPLOT_HEADER.h) is a superheader file 
 * containing elaborated (hand-made) and primitive cpgplot function
 * prototypes for plotting procedures
 */
#include <CPGPLOT_HEADER.h>
#include <include.CPG.extern.h>
#include <include.FILES_to_READ.extern.h>

extern int HELP_INPUT_ARGUMENTS;

void paramCommand_Line(FILE *fp, Parameter_CPGPLOT * CPG)
{

  fprintf_Input_Parameter_FILE(fp, CPG->CPG_File);

  #include <include.CPG.fprintPar.c>

}

void modelReport(char *File, Parameter_CPGPLOT * CPG)
{
  paramCommand_Line( stdout, CPG );  
  FILE * fp = fopen(File, "w");
  paramCommand_Line( fp, CPG );
  fclose(fp);
}
