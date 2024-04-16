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

void buildGraph(int* trip, int trip_count, struct Vertex* source)  // undirected Grapgh
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
		printf("dest:%d, wt:%d ", start -> dest, start -> wt);
		start = start -> next;
	}
}

int min_idx(int* visited, int* distance, int V)
{
	int min = 99999;
	int mi = -1;
	int i;
	for(i=1; i<V+1; i++)
	{
		if(visited[i] == 0 && distance[i]<=min)
		{
			min = distance[i];
			mi = i;
		}
	}
	return mi;
}

int* Dijkstra(int s, struct Vertex* source, int V)
{
	int i;
	int* visited = (int*)calloc(V+1, sizeof(int));
	int* distance = (int*)calloc(V+1, sizeof(int));
	for(i=0; i<V+1; i++)
	{
		distance[i] = 99999;
		visited[i] = 0;
	}
	distance[s] = 0;
		
	for(i=0; i<V; i++)
	{
		int u = min_idx(visited, distance, V);
		visited[u] = 1;
		struct Edge* start = source[u].head;
		while(start != NULL)
		{
			int v = start -> dest;
			if(visited[v] == 0)
			{
				if((distance[u] + start -> wt) < distance[v])
				{
					distance[v] = distance[u] + start -> wt;
				}
			}
			start = start -> next;
		}
	}
	return distance;
}

int main()
{
	int V, i, j, trip_count,src;
	
	printf("Enter the Number of Vertex\n");
	scanf("%d", &V);
	
	struct Vertex* source = (struct Vertex*)calloc(V+1, sizeof(struct Vertex));
	for(i=0; i<V+1; i++)
	{
		source[i].src = i;
		source[i].head = NULL;
	}
	
	printf("Enter the Edges\n");
	scanf("%d", &trip_count);
	
	int* trip = (int*)malloc(trip_count*3*sizeof(int));
	
	printf("Enter the Edges and Weight\n");
	for(i=0; i<trip_count; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", (trip + i*3 + j));
		}
	}
	
	buildGraph(trip, trip_count, source);
	
	for(i=1; i<V+1; i++)
	{
		printf("\n");
		printf("src:%d -> ", source[i].src);
		Display(source[i].head);
	}
	printf("\n\n");
	int ch;
	while(1)
	{
		printf("Enter the Source\n");
		scanf("%d", &src);
		
		int* res = Dijkstra(src, source, V);
		printf("\n");
		printf("\n");
		for(i=1; i<V+1; i++)
		{
			printf("%d ", res[i]);
		}
		printf("\n");
		printf("\n");
	printf("Enter 0 to end\n");
	scanf("%d", &ch);
	if(ch == 0)
		break;
	}
	return 0;
}


