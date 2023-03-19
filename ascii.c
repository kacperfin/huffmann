#include "ascii.h"
#include <stdio.h>
void clearArray(int array[], int n)
{
	for(int i=0; i<n; i++) array[i] = 0;
}

void getFrequencies(int tab[256], char *message)
{
	int symbol;
	for(int i=0; i<strlen(message); i++)
	{
		symbol = message[i];
		tab[symbol]++;
	}
}

void getFrequency(int array[256], char c)
{
	array[c]++;
}

void printFrequencies(int tab[])
{
	for(int i=0; i<256; i++)
	{
		if(tab[i]!=0)
		{
			printf("%c - %d\n", i, tab[i]);
		}
	}
}

int getCapacity(int tab[])
{
	int capacity = 0;
	for(int i=0; i<256; i++)
	{
		if(tab[i]!=0) capacity++;
	}

	return capacity;
}

void printCharArray(char array[], int n)
{
	for(int i=0; i<n; i++) printf("%c", array[i]);
}

void writeTableToBinaryFile(CodingTable table[], int n, FILE *fw, char directory[])
{
	fw = fopen(directory, "wb");
	char string[256];
	for(int i=0; i<n; i++)
	{
		strcpy(string, "\'");
		fwrite(string, sizeof(char)*strlen(string), 1, fw);
		if(table[i].symbol!='\n')
		{
			fwrite(&table[i].symbol, sizeof(char), 1, fw);
			strcpy(string, "\'  -  ");
			fwrite(string, sizeof(char)*strlen(string), 1, fw);
		}
		else
		{
			strcpy(string, "\\n\' -  ");
			fwrite(string, sizeof(char)*strlen(string), 1, fw);
		}

		fwrite(table[i].code, sizeof(char)*strlen(table[i].code), 1, fw);

		strcpy(string, "\n");
		fwrite(string, sizeof(char)*strlen(string), 1, fw);
	}

	fclose(fw);
}
