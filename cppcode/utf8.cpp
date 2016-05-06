#include <iostream>
#include <wchar.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_CTYPE,"");
	wchar_t b = '\u0444';
	wchar_t c = '\u0129';

	wprintf(L"c is = %c\n", c);
	wchar_t d = 0x0024;
	wprintf(L"d is = %c\n", d);
	wchar_t e = 0x0040;
	wprintf(L"e is = %c\n", e);
	wchar_t de[3];
	de[0] = d;
	de[1] = e;
	de[2] = 'e';
	wprintf(L"de is = %ls\n", de);
	
	char test1[5] = "Ajay";
	wchar_t test2[20];
	test2[5] = 0x0040;
	test2[6] = L'G';
	wmemset(test2,L'-',5);
	//wcsncpy(test2,(const wchar_t* )test1,5);
	wprintf(L"test2 is %ls\n",test2);
	test2[5] = 0x0041;
	test2[6] = L'G';
	test2[7] = L'\0';
	wprintf(L"test2 is %ls\n",test2);
	wchar_t arr[100] = L"Schöne Grüße";
    wprintf(L"wide - %ls\n", arr);

	return 0;
}
