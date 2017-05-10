#include<iostream>
#include<stdio.h>
#include"AnsiCodes.h"

using namespace std;
/*
#define RESET_ALL "\x1B[0m"
#define TEXT_RED "\x1B[31m"
#define TEXT_GREEN "\x1B[42m"
//#define TEXT_YELLOW "\x1B[33m"
#define TEXT_YELLOW "\033[34;4m"
#define UNDERLINE "\x1B[4m"
#define BOLD "\x1B[1m"
#define BLINK "\x1B[5m"
#define ENCIRCLE "\x1B[52m"
*/
int main()
{
    FILE* fp = fopen("color.txt","a");
	int a=0;	
	while(a<2)
	{	a++;
		fprintf(fp,"###########################\n");
		//printf(TEXT_RED"TESTING RED COLOR.\n"RESET_ALL);
//		fprintf(fp,TEXT_RED"TESTING RED COLOR.\n"RESET_ALL);
//		fprintf(fp,TEXT_GREEN"TESTING GREEN COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_YELLOW"TESTING YELLOW COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_UNDERLINE"TESTING UNDERLINE COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_ITALIC"TESTING ITALIC COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_BOLD"TESTING BOLD COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_BLINK"TESTING BLINK COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_CROSSED_OUT"TESTING CROSSED COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_FRAMED"TESTING CROSSED COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_ENCIRCLED"TESTING CROSSED COLOR\n"RESET_ALL);
		fprintf(fp,TEXT_OVERLINED"TESTING CROSSED COLOR\n"RESET_ALL);
	}
	fclose(fp);
	return 0;
}
