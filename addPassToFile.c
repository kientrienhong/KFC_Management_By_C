#include "addPassToFile.h"

void addPassToFile (FILE *file , char addPassword[])
{
		fprintf (file,"%s", addPassword) ;
		fprintf (file, "\n");
}
