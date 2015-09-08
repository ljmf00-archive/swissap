/*lsferreira programming */
#ifndef LSCLIBSTDFILE_H_INCLUDED
#define LSCLIBSTDFILE_H_INCLUDED

#if !(WIN32) //If dont support Windows :: Do Def. Inst.

#endif
#if !(WIN64) //! win64

#endif

#include "libs.h"

// ...

int readfile(char file_name[]) { char ch;
FILE *fp;
	fp=fopen(file_name,"r");
	if (fp==NULL) { perror("ERROR WHILE OPENING THE FILE\n");
		exit(EXIT_FAILURE); }
	while((ch=fgetc(fp))!= EOF)
		printf("%c",ch);
	fclose(fp);}

int delfile(char file_name[]) { int status;
   status = remove(file_name);
   if( status == 0 )
      printf("%s FILE DELETED.\n",file_name);
   else
   { printf("CANT DELETE FILE\n");
   perror("ERROR"); }}

int copyfile(char source_file[], char target_file[]) { char ch; FILE *source, *target;
   source = fopen(source_file, "r");
   if( source == NULL )
   {printf("FILE NOT FOUNDED...\n");
   	exit(EXIT_FAILURE);}
   target = fopen(target_file, "w");
   if( target == NULL )
   {fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);}
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
   printf("FILE COPIED.\n");
   fclose(source);
   fclose(target);}

#endif // LSCLIBSTDFILE_H_INCLUDED
