#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	int deg;
	struct node* next;
};

typedef struct node node;

void Display(node* p)
{
	node* start = p;
	while(start != NULL)
	{
		printf("%dx^%d ", start -> data, start -> deg);
		start = start -> next;
	}
}
void Selection_sort(node* head)
{
	node* max_node, *start2;
	node* start1 = head;
	while(start1 -> next != NULL)
	{
		max_node = start1;
		start2 = start1 -> next;
		while(start2 != NULL)
		{
			if(start2 -> deg > max_node -> deg)
			{
				max_node = start2;
			}
			start2 = start2 -> next;
		}
		if(max_node != start1)
		{
			int temp1 = max_node -> deg;
			max_node -> deg = start1 -> deg;
			start1 -> deg = temp1;
			
			int temp2 = max_node -> data;
			max_node -> data = start1 -> data;
			start1 -> data = temp2;
		}
		start1 = start1 -> next;
	}
}

node* Insert(node* head, int data, int deg)
{
	node* new_node=(node*)malloc(sizeof(node));
	new_node -> data = data;
	new_node -> deg = deg;
	
	if(head != NULL)
	{
		node* start = head;
		while(start -> next != NULL)
			start = start -> next;
			
		start -> next = new_node;
		new_node -> next = NULL;
	}
	else
	{
		new_node -> next = head;
		head = new_node;
	}
	return head;
}

node* Sum_of_polynomials(node* head1, node* head2)
{
	Selection_sort(head1);
	Selection_sort(head2);
	node* head3 = NULL;
	while(head1 != NULL && head2 != NULL)
	{
		if(head1 -> deg == head2 -> deg)
		{
			int x = head1 -> data + head2 -> data;
			head3 = Insert(head3, x, head1 -> deg);
			head1 = head1 -> next;
			head2 = head2 -> next;
		}
		else if(head1 -> deg > head2 -> deg)
		{
			head3 = Insert(head3, head1 -> data, head1 -> deg);
			head1 = head1 -> next;
		}
		else
		{
			head3 = Insert(head3, head2 -> data, head2 -> deg);
			head2 = head2 -> next;
		}
	}
	while(head1 != NULL)
	{
		head3 = Insert(head3, head1 -> data, head1 -> deg);
		head1 = head1 -> next;
	}
	while(head2 != NULL)
	{
		head3 = Insert(head3, head2 -> data, head2 -> deg);
		head2 = head2 -> next;
	}
	return head3;
}

int main()
{
	node* head1 = NULL;
	node* head2 = NULL;
	int h1_count, h2_count, i;
	printf("Enter the length of List1 and List2\n");
	scanf("%d %d", &h1_count, &h2_count);
	printf("Enter the List1 elements\n");
	for(i=0; i<h1_count; i++)
	{
		node* new_node = (node*)malloc(sizeof(node));
		int data, deg;
		printf("Enter the Coefficient and Power\n");
		scanf("%d %d", &data, &deg);
		head1 = Insert(head1, data, deg);
	}
	printf("Enter the List2 elements\n");
	for(i=0; i<h2_count; i++)
	{
		node* new_node = (node*)malloc(sizeof(node));
		int data, deg;
		printf("Enter the Coefficient and Power\n");
		scanf("%d %d", &data, &deg);
		head2 = Insert(head2, data, deg);
	}
	printf("\nPolynomial 1:\t");
	Display(head1);
	printf("\nPolynomial 2:\t");
	Display(head2);
	node* head3 = Sum_of_polynomials(head1, head2);
	printf("\nPolynomial 3:\t");
	Display(head3);
	return 0;
}
