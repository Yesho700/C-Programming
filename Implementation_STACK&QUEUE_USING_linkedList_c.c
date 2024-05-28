#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	add(3);
	add(4);
	add(5);
	add(6);
	printf("%d\n", poll());
	printf("%d\n", poll());
	printf("%d\n", poll());
	printf("%d\n", poll());
	
	push(7);
	push(8);
	push(9);
	push(10);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	
	return 0;
}
