#include <stdio.h>
#include <stdlib.h>

struct Edge
{
	int dest;
	int wt;
	struct Edge* next;
};

struct Vertex
{
	int src;
	struct Edge* head;
};

struct Edge* add(struct Edge* head, int dest, int wt)
{
	struct Edge* new_edge = (struct Edge*)malloc(sizeof(struct Edge));
	new_edge -> dest = dest;
	new_edge -> wt = wt;
	new_edge -> next = head;
	head = new_edge;
	return head;
}

void buildGraph(int* trip, int trip_count, struct Vertex* source)
{
	int i;
	for(i=0; i<trip_count; i++)
	{
		source[*(trip + i*3 + 0)].head = add(source[*(trip + i*3 + 0)].head, *(trip + i*3 + 1), *(trip + i*3 + 2));
		source[*(trip + i*3 + 1)].head = add(source[*(trip + i*3 + 1)].head, *(trip + i*3 + 0), *(trip + i*3 + 2));	
	}
}

void Display(struct Edge* head)
{
	struct Edge* start = head;
	while(start != NULL)
	{
		printf("dest:%d wt:%d , ", start -> dest, start -> wt);
		start = start -> next;
	}
}

int main()
{
	int i, j, V, trip_count;
	
	printf("Enter the Number of vertex\n");
	scanf("%d", &V);
	
	printf("Enter the Number of Connections\n");
	scanf("%d", &trip_count);
	
	
	int* trip = (int*)malloc(trip_count*3*sizeof(int));

	printf("Enter the Connections\n");
	for(i=0; i<trip_count; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", (trip + i*3 + j));
		}
	}
	
	struct Vertex* source = (struct Vertex*)calloc(V+1, sizeof(struct Vertex));
	for(i=0; i<V+1; i++)
	{
		source[i].src = i;
		source[i].head = NULL;
	}
	
	buildGraph(trip, trip_count, source);
	
	for(i=0; i<V+1; i++)
	{
		printf("\n");
		printf("%d : ", source[i].src);
		Display(source[i].head);
	}
}
