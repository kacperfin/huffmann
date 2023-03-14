#include "ascii.h"
#include <stdio.h>
void getFrequencies(int tab[256], char *message)
{
	for(int i=0; i<256; i++)
	{
		tab[i]=0; //tab is an ASCII array, so it's expected to have a size of 256
	}
	int symbol;
	for(int i=0; i<strlen(message); i++)
	{
		symbol = message[i];
		tab[symbol]++;
	}
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
