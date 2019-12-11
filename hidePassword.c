#include "hidePassword.h"

void hidePassword (char password[])
{
	char x ;
	int i = 0 ;
	
	while (x != 13)
	{
		fflush(stdin);
		x = getch ();
		if (x == 13) // bat phim Enter
		{
			break ;
		}
		else if (x == 8) // bat phim backspace
		{
			if (i != 0)
			{
				printf ("\b \b") ;
				i-- ;
			}
			
			else 
			{
				printf ("\b ") ;	
			}
		}
		
		else 
		{
			if (x == -32)
			{
				printf ("\b\b   \b") ; 
			}
			
			else if ((x != 32) && ((x != -32) && (x != 72)) && ((x != -32) && (x != 75)) && ((x != -32) && (x != 80)) && ((x != -32) && (x != 77)))
			{
				password[i] = x ; 
				i++ ;
				printf ("%c", x) ;
				printf ("\b \b*") ;
			}
		}
	}
	
	password [i] = '\0' ;
}
