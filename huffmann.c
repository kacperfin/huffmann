#include "huffmann.h"

struct Node *createNode(char *name, int frequency)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->name = name;
	node->frequency = frequency;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printNode(Node *node)
{
	printf("NAME - %s\n", node->name);
	printf("FREQ - %d\n", node->frequency);
	if(node->left!=NULL)
		printf("LEFT - %s\n", (node->left)->name);
	else printf("LEFT - NULL\n");
	if (node->right!=NULL)
		printf("RIGHT - %s\n", (node->right)->name);
	else printf("RIGHT - NULL\n");
}

struct Heap* createHeap(int capacity)
{
	struct Heap* heap = (struct Heap*) malloc(sizeof(struct Heap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->array = calloc(heap->capacity, sizeof(struct Node*));
	return heap;
};
