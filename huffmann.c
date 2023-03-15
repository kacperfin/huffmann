#include "huffmann.h"

struct Node *createNode(char *name, int frequency)
{
	Node* node = (Node*) malloc(sizeof(Node));
	strcpy(node->name, name);
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
	heap->array = (struct Node**) malloc(capacity * sizeof(struct Node*));
	return heap;
}

void printHeap(Heap *heap)
{
	printf("CAPACITY - %d\n", heap->capacity);
	printf("SIZE - %d\n", heap->size);
	printf("NODES - ");
	if((heap->size)<=0) printf("none\n");
	else
	{
		for(int i=0; i<(heap->size); i++)
		{
			printf("%s, ", ((heap->array)[i])->name);
		}
		printf("\n");
	}
}

void addNodeToHeap(Node *node, Heap *heap)
{
	(heap->array)[heap->size] = node;
	(heap->size)++;
}

void fillHeap(Heap *heap, int *array)
{
	char a[256]="";
	char c;
	for(int i=0; i<256; i++)
	{
		if(array[i]!=0)
		{
			strcpy(a, "");
			c=(char) i;
			strncat(a, &c, 1);
			addNodeToHeap(createNode(a, array[i]), heap);
		}
	}
}
