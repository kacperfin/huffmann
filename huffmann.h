#ifndef HUFFMANN_H
#define HUFFMANN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "ascii.h"

extern int counter;

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

void createTree(Heap *heap);
bool isLeaf(Node *node);
void printTree(Node *node, char array[], int current);

void clearTable(CodingTable table[], int n);
void saveCodesToTable(Node *node, char array[], int current, CodingTable table[]);
void printTable(CodingTable table[], int n);
void encodeChar(char c, CodingTable table[], int n, char string[]);
void clearFile(FILE *fw, char directory[]);
void writeEncodedCharToFile(char c, CodingTable table[], int n, FILE *fw, char directory[]);
void printEncodedChar(char c, CodingTable table[], int n);
void printEncodedMessage(char a[], CodingTable table[], int n);

#endif
