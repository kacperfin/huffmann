#ifndef HUFFMANN_H
#define HUFFMANN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
	char *name;
	int frequency;
	struct Node *left;
	struct Node *right;
} Node;

struct Node *createNode(char *name, int frequency);
void printNode(Node *node);

#endif
