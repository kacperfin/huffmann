#ifndef HUFFMANN_H
#define HUFFMANN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
	char name[256];
	int frequency;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct Heap
{
	int capacity;
	int size;
	struct Node **array;
} Heap;

struct Node* createNode(char *name, int frequency);
void printNode(Node *node);
int compareNodes(const void *a, const void *b);

struct Heap* createHeap(int capacity);
void printHeap(Heap *heap);

void addNodeToHeap(Node *node, Heap *heap);
void fillHeap(Heap *heap, int *array);
void sortHeap(Heap *heap);
void combineTwoNodes(Heap *heap);

#endif
