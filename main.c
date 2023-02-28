#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
	bool debug_mode;

	if(argc<=1)
	{
		printf("Brak podanych argumentow. Podaj jedna z dwoch flag: \"\"-f\"\" lub \"\"-d\"\"\n");
		return -1;
	}

	if(strcmp("-d", argv[1])==0) debug_mode = true;
	else if(strcmp("-f", argv[1])==0) debug_mode = false;
	else
	{
		printf("Blednie podano flage. Podaj jedna z dwoch flag: \"\"-f\"\" lub \"\"-d\"\"\n");
		return -2;
	}

	/*
	Sprawdzanie poprawnosci dzialania przypisywania flag
	
	if(debug_mode==true) printf("DEBUG: %s\n", argv[1]);
	else printf("NORMAL: %s\n", argv[1]);
	*/

	if(debug_mode==true)
	{
		;
	}
	else
	{
		if(argc<=3)
		{
			printf("Nie podano pliku wejsciowego i wyjsciowego. Przyklad: ./a.out -f PLIK_WEJSCIOWY PLIK_WYJSCIOWY\n");
			return -3;
		}

		FILE *fp;
		fp = fopen(argv[2], "r");
		if(fp==NULL)
		{
			printf("Blad przy otwieraniu pliku.\n");
			return -4;
		}


	}

	return 0;
}
