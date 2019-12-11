#include "checkPasswordFromFile.h"

int checkPasswordFromFile (FILE *file , char inputPassword[], char passCheck[255])
{
//	fgets (passCheck, 255 , file) ;
//	printf ("\n%s\n", inputPassword) ;
//	printf ("%s\n", passCheck) ;
//	int x = strcmp (inputPassword, passCheck) ;
//	printf ("%d\n", x) ;
	
	while (1)
	{
		fscanf (file , "%[^\n]%*c", passCheck) ;
		
		if (strcmp (passCheck, inputPassword) == 0)
		{
			return 1 ;	
				
		}
		
		else if (feof(file))
		{
			fseek (file,0, SEEK_SET) ;
			return 0 ;
			
		}
	}
}
