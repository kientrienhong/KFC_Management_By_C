#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>



void resizeConsole(int width, int height) ; // lenh chinh sua kich thuoc console


void Nocursortype() ; // day la ham xoa con tro trong console 

void NocursortypeAppear();


void gotoxy(int x,int y) ; // lenh di chuyen con tro


void clear() ; // len clear man hinh


void textcolor(int x) ; // to mau chu 


void paint(int x, int y, char *a, int color) ;

void paintInteger(int x, int y, int a, int color)  ;

void paintFloat(int x, int y, float a, int color)  ;

int check (int *input, int positionX , int positionY) ;

int checkFloat (float *input, int positionX , int positionY) ;
