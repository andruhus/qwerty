#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)


extern void Kontacts();
extern void MENU();


int main()
{
	Kontacts();
	/*FILE* a;
	if ((a = fopen("Abonent.txt", "rb")) != NULL)
	{
		int ch;
		int noi = 0;
		char v = ' ';
		while ((ch = getc(a)) != EOF)
		{
			if (isdigit(v) && !isdigit((char)ch))
				noi++;
			std::cout << (char)ch;
			v = ch;
		}
		std::cout << noi;
	}*/
}

