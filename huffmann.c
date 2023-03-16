#include "huffmann.h"
#include "ascii.h"

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

int compareNodes(const void *a, const void *b)
{
	struct Node * left = *(struct Node **) a;
	struct Node * right = *(struct Node **) b;
	return (left->frequency)-(right->frequency);
}

void sortHeap(Heap *heap)
{
	qsort(heap->array, heap->size, sizeof(struct Node*), compareNodes);
}

void combineTwoNodes(Heap *heap)
{
	Node *left = (heap->array)[0];
	Node *right = (heap->array)[1];

	char a[256] = "";
	strcat(a, left->name);
	strcat(a, right->name);

	left = createNode(a, (left->frequency+right->frequency));
	left->left = (heap->array)[0];
	left->right = (heap->array)[1];
	(heap->array)[0] = left;

	heap->size--;

	for(int i=1; i<heap->size; i++)
	{
		(heap->array)[i] = (heap->array)[i+1];
	}
}

void createTree(Heap *heap)
{
	while(heap->size>1)
	{
		sortHeap(heap);
		combineTwoNodes(heap);
	}
}

bool isLeaf(Node *node)
{
	if(node->left==NULL&&node->right==NULL) return true;
	return false;
}

void printTree(Node *node, char array[], int current)
{
	if(isLeaf(node)==true)
	{
		printf("%s - ", node->name);
		printCharArray(array, current);
		printf("\n");	
	}
	if(node->left!=NULL)
	{
		array[current] = '0';
		printTree(node->left, array, current+1);
	}
	if(node->right!=NULL)
	{
		array[current] = '1';
		printTree(node->right, array, current+1);
	}
}

void clearTable(CodingTable table[], int n)
{
	for(int i=0; i<n; i++)
	{
		table[i].symbol = '\0';
		strcpy(table[i].code, "");
	}
}

void saveCodesToTable(Node *node, char array[], int current, CodingTable table[])
{
	if(isLeaf(node)==true)
	{
		table[counter].symbol = (node->name)[0];
		for(int i=0; i<current; i++)
		{
			strncat(table[counter].code, &array[i], 1);
		}
		counter++;
	}
	if(node->left!=NULL)
	{
		array[current] = '0';
		saveCodesToTable(node->left, array, current+1, table);
	}
	if(node->right!=NULL)
	{
		array[current] = '1';
		saveCodesToTable(node->right, array, current+1, table);

	}
}

void printTable(CodingTable table[], int n)
{
	for(int i=0; i<n; i++)
	{
		if(table[i].symbol!='\n')
		{
			printf("\'%c\'  -  ", table[i].symbol);
		}
		else printf("\'\\n\' -  ");
		for(int j=0; j<strlen(table[i].code); j++)
		{
			printf("%c", (table[i].code)[j]);
		}
		printf("\n");
	}
}
