#include "console.h"

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Nocursortype() // day la ham xoa con tro trong console 
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void NocursortypeAppear() // day la ham hien con tro trong console 
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void clear() 
{
    COORD startPos  = { 0, 0 };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(hConsole, &screen);
    FillConsoleOutputCharacterA(hConsole, ' ', screen.dwSize.X * screen.dwSize.Y, startPos, &written);
    FillConsoleOutputAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, startPos, &written);
    SetConsoleCursorPosition(hConsole, startPos);
}

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void paint(int x, int y, char *a, int color) 
{
	gotoxy(x, y);
	textcolor(color);
	printf ("%s", a) ;
	textcolor(7);
	
}

void paintInteger(int x, int y, int a, int color) 
{	
	
	gotoxy(x, y);
	textcolor(color);
	printf ("%d", a) ;
	textcolor(7);
	
}

void paintFloat(int x, int y, float a, int color) 
{
	gotoxy(x, y);
	textcolor(color);
	printf ("%.0f", a) ;
	textcolor(7);
}

int check (int *input, int positionX , int positionY) 
{

    char c;
    int count;
    
    int isValid = 0;
    do 
	{
    	gotoxy (positionX , positionY) ;
    	isValid = 1;
    
    	count = scanf("%d%c", input, &c);
    	
    	fflush(stdin);
    	
        if((count != 2 || c != '\n' ) || (*input < 0) )   
		{
        	
        	isValid = 0;
        	gotoxy (positionX, positionY) ;
        	printf("input again ");
        	c = getch () ;
        	gotoxy (positionX ,positionY) ;
        	printf ("             ") ;
		}	
        
    } while (!isValid);
	
	return 0 ;
}

int checkFloat (float *input, int positionX , int positionY) 
{

    char c;
    int count;
    
    int isValid = 0;
    do 
	{
    	gotoxy (positionX , positionY) ;
    	isValid = 1;
    
    	count = scanf("%f%c", input, &c);
    	
    	fflush(stdin);
    	
        if((count != 2 || c != '\n' ) || (*input < 0) )   
		{
        	
        	isValid = 0;
        	gotoxy (positionX, positionY) ;
        	printf("input again ");
        	c = getch () ;
        	gotoxy (positionX ,positionY) ;
        	printf ("             ") ;
		}	
        
    } while (!isValid);
	
	return 0 ;
}

