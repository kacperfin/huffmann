#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "huffmann.h"
#include "ascii.h"

int counter=0;

int main(int argc, char *argv[])
{
	bool debug_mode;
	char a[256];
	char c;
	int ASCII[256];
	int capacity;
	struct Heap *heap;
	char array[256];
	int current=0;
	struct CodingTable table[256];

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
		printf("You're in debug made. Write EXIT to quit the program.\n");		
		while(true)
		{
			fgets(a, 256, stdin);
			a[strlen(a) - 1] = '\0';
			if(strcmp(a, "EXIT")==0) return 0;
			
			clearArray(ASCII, 256);
			getFrequencies(ASCII, a);
			capacity = getCapacity(ASCII);
			heap = createHeap(capacity);
			fillHeap(heap, ASCII);
			createTree(heap);
			
			clearTable(table, capacity);
			saveCodesToTable((heap->array)[0], array, current, table);
			
			printTable(table, capacity);
			printEncodedMessage(a, table, capacity);

			counter = 0;
		}
	}
	else
	{
		if(argc<=4)
		{
			printf("Nie podano pliku wejsciowego i plikow wyjsciowych. Przyklad: ./a.out -f PLIK_WEJSCIOWY PLIK_WYJSCIOWY PLIK_TABLICA\n");
			return -3;
		}

		FILE *fr;
		FILE *fw;

		fr = fopen(argv[2], "rb");
		if(fr==NULL)
		{
			printf("Blad przy otwieraniu pliku.\n");
			return -4;
		}

		clearArray(ASCII, 256);
		while(!feof(fr))
		{
			fread(&c, sizeof(char), 1, fr);
			getFrequency(ASCII, c);
		}

		printFrequencies(ASCII);
		capacity = getCapacity(ASCII);
		heap = createHeap(capacity);
		fillHeap(heap, ASCII);
		createTree(heap);

		clearTable(table, capacity);
		saveCodesToTable((heap->array)[0], array, current, table);
		printTable(table, capacity);
		writeTableToBinaryFile(table, capacity, fw, argv[4]);
		
		rewind(fr);

		clearFile(fw, argv[3]);
		while((c=fgetc(fr))!=EOF)
		{
			writeEncodedCharToFile(c, table, capacity, fw, argv[3]);
		}

		fclose(fr);
	}
	return 0;
}
