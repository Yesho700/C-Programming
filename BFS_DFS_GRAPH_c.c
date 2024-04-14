#include <stdio.h>
#include <stdlib.h>
			// stack and queue implementation
struct stack
{
	int data;
	struct stack* next;
}*shead = NULL;

struct queue
{
	int data;
	struct queue* next;
}*qhead = NULL;

int SisFull()
{
	if(shead == NULL)
		return 1;
	else
		return 0;
}

int SisEmpty()
{
	if(shead == NULL)
		return 1;
	else
		return 0;
}

int QisFull()
{
	if(qhead == NULL)
		return 1;
	else
		return 0;
}

int QisEmpty()
{
	if(qhead == NULL)
		return 1;
	else
		return 0;
}

void push(int data)
{
	struct stack* new_node = (struct stack*)malloc(sizeof(struct stack));
	if(new_node == NULL)
	{
		printf("Overflow\n");
	}
	new_node -> data = data;
	new_node -> next = shead;
	shead = new_node;
}

int pop()
{
	if(SisEmpty())
	{
		printf("Underflow\n");
		return -999999;
	}
	int data = shead -> data;
	struct stack* temp = shead;
	shead = shead -> next;
	free(temp);
	return data;
}

void add(int data)
{
	struct queue* new_node = (struct queue*)malloc(sizeof(struct queue));
	if(new_node == NULL)
	{
		printf("Overflow\n");
	}
	else if(qhead == NULL)
	{
		new_node -> data = data;
		new_node -> next = qhead;
		qhead = new_node;
	}
	struct queue* start = qhead;
	while(start -> next != NULL)
	{
		start = start -> next;
	}
	start -> next = new_node;
	new_node -> next = NULL;
	new_node -> data = data;
}

int poll()
{
	if(QisEmpty())
	{
		printf("Underflow\n");
		return -9999;
	}
	int data = qhead -> data;
	struct queue* temp = qhead;
	qhead = qhead -> next;
	free(temp);
	return data;
}
			// graph Implementation
struct Edge
{
	int dest;
	struct Edge* next;
};

struct Vertex
{
	int src;
	struct Edge* head;
};

struct Edge* add_edge(struct Edge* head, int dest)
{
	struct Edge* new_edge = (struct Edge*)malloc(sizeof(struct Edge));
	new_edge -> dest = dest;
	new_edge -> next = head; 
	head  = new_edge;
	return head;
}

void buildGraph(int* pair, int pair_count, struct Vertex* source)
{
	int i;
	for(i=0; i<pair_count; i++)
	{
		source[*(pair + i*2 + 0)].head = add_edge(source[*(pair + i*2 + 0)].head, *(pair + i*2 + 1));
		source[*(pair + i*2 + 1)].head = add_edge(source[*(pair + i*2 + 1)].head, *(pair + i*2 + 0));
	}
}

int k = 0;
void DFS(int v, struct Vertex* source, int* visited, int* res, int* res_count)
{
	res[k++] = v;
	visited[v] = 1;
	struct Edge* start = source[v].head;
	while(start != NULL)
	{
		if(visited[start -> dest] == 0)
		{
			DFS(start -> dest, source, visited, res, res_count);
		}
		start = start -> next;
	}
	*res_count = k;
}


int l = 0;
void BFS(int v, struct Vertex* source, int* visited, int* res, int* res_count)
{
	add(v);
	visited[v] = 1;
	while(QisEmpty() != 1)
	{
		v = poll();
		res[l++] = v;
		struct Edge* start = source[v].head;
		while(start != NULL)
		{
			if(visited[start -> dest] == 0)
			{
				add(start -> dest);
				visited[start -> dest] = 1;
			}
			start = start -> next;
		}
	}
	*res_count = l;
}

void Display(struct Edge* head)
{
	struct Edge* start = head;
	while(start != NULL)
	{
		printf("%d ", start -> dest);
		start = start -> next;
	}
}

int main()
{
	int V, pair_count, i, j;
	
	printf("Enter the  no of Vertex\n");
	scanf("%d", &V);
	
	printf("Enter the No of Pairs\n");
	scanf("%d", &pair_count);
	
	int* pair = (int*)malloc(pair_count*2*sizeof(int));
	
	printf("Enter the Connections\n");
	for(i=0; i<pair_count; i++)
	{
		for(j=0; j<2; j++)
		{
			scanf("%d", (pair + i*2 + j));
		}
	}
	
	struct Vertex* source = (struct Vertex*)calloc(V+1, sizeof(struct Vertex));
	for(i=0; i<V+1; i++)
	{
		source[i].src = i;
		source[i].head = NULL;
	}
	
	buildGraph(pair, pair_count, source);

	
	int res_count;
	int* visited = (int*)calloc(V+1, sizeof(int));
	int* res = (int*)calloc(V+1, sizeof(int));
	
	printf("\n");
	int ch;
	printf("1: BFS\n");
	printf("2: DFS\n");
	printf("Enter your choice\n");
	scanf("%d", &ch);
	
	switch(ch)
	{
		case 1:
			BFS(1,source, visited, res, &res_count);
			break;
		case 2:
			DFS(1,source, visited, res, &res_count);
			break;
	}
		
	printf("\n");
	printf("Adjacency List of Graph\n");
	for(i=0; i<V+1; i++)
	{
		printf("%d : ", source[i].src);
		Display(source[i].head);
		printf("\n");
	}

	printf("\n");
	printf("Traversal of graph\n");
	for(i=0; i<res_count; i++)
	{
		printf("%d  ", res[i]);
		
	}
	return 0;
}
