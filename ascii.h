#ifndef ASCII_H
#define ASCII_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//tab is expected do have 256 characters as its an ASCII array
void getFrequencies(int tab[], char *message);
void printFrequencies(int tab[]);
int getCapacity(int tab[]);

void printCharArray(char array[], int n);

#endif
