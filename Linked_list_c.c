#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

node* Head = NULL;
struct node
{
	int data;
	struct node* next;
};

void Display()
{
	node* start = Head;
	while(start != NULL)
	{
		printf("%d ",start -> data);
		start = start -> next;
	}
}

void Insert_at_beg()
{
	int data;
	printf("Enter the data to insert\n");
	scanf("%d", &data);
	node* ll = (node*)malloc(sizeof(node));
	ll -> data = data;
	ll -> next = Head;
	Head = ll;
	Display();
}

void Insert_at_end()
{
	if(Head != NULL)
	{
		int data;
		printf("Enter the data to insert\n");
		scanf("%d", &data);
		node* ll = (node*)malloc(sizeof(node));
		node* start = Head;
		while(start -> next != NULL)
		{
			start = start -> next;
		}
		ll -> data = data;
		ll -> next = NULL;
		start -> next = ll;
		Display();
	}
	else
	{
		Insert_at_beg();
	}
}

void Insert_after_key(int key)
{
	if(Head != NULL)
	{
		int data;
		printf("Enter the data to insert\n");
		scanf("%d", &data);
		node* ll = (node*)malloc(sizeof(node));
		node* start = Head;
		while(start -> data != key)
		{
			start = start -> next;
		}
		ll -> data = data;
		ll -> next = start -> next;
		start -> next = ll;
		Display();
		
	}
	else
	{
		Insert_at_beg();
	}
}

void Insert_before_key(int key)
{
	if(Head != NULL)
	{
			int data;
		printf("Enter the data to insert\n");
		scanf("%d", &data);
		node* ll = (node*)malloc(sizeof(node));
		node* start = Head;
		while((start -> next) -> data != key)
		{
			start = start -> next;
		}
		ll -> data = data;
		ll -> next = start -> next;
		start -> next = ll;
		Display();
	}
	else
	{
		Insert_at_beg();
	}
}

void Del_at_beg()
{
	node* temp = Head;
	Head = Head -> next;
	free(temp);
}

void Del_at_end()
{
	node* start = Head;
	while((start -> next) -> next != NULL)
	{
		start = start -> next;
	}
	free((start -> next) -> next);
	start -> next = NULL;
	Display();
}

void Del_after_key(int key)
{
	node* start = Head;
	while(start -> data != key)
	{
		start = start -> next;
	} 
	node* temp = start -> next;
	start -> next = temp -> next;
	free(temp);
	Display();
}
void Del_before_key(int key)
{
	node* prev = NULL;
	node* start = Head;
	while((start -> next) -> data != key)
	{
		prev = start;
		start = start -> next;
	}
	prev -> next = start -> next;
	free(start);
	Display();
}

void Find_mid()
{
	int count = 0;
	node* fast = Head;
	node* slow = Head;
	while( fast -> next != NULL &&  fast != NULL  )
	{
		fast = (fast -> next ) -> next;
		slow = slow -> next;
		count ++;
	}
	printf("%d\n", count);
	Display();
}

void Reverse()
{
	node* curr = Head;
	node* prev = NULL;
	while( curr != NULL)
	{
		node* temp = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = temp;
	}
	Head = prev;
	Display();
}

int main()
{
	int t;
	while(1)
	{
		int ch, key;
		printf("1 : Insert at Beginning\n");
		printf("2 : Insert at end\n");
		printf("3 : Insert after key\n");
		printf("4 : Insert before key\n");
		printf("5 : Delete at beginning\n");
		printf("6 : Delete at end\n");
		printf("7 : Delete after key\n");
		printf("8 : Delete before key\n");
		printf("9 : Display\n");
		printf("10 : Find Middle of the list\n");
		printf("11 : Reverse the List\n");
		printf("Enter the choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				Insert_at_beg();
				break;
			case 2:
				Insert_at_end();
				break;
			case 3:
				printf("enter the key\n");
				scanf("%d", &key);
				Insert_after_key(key);
				break;
			case 4:
				printf("enter the key\n");
				scanf("%d", &key);
				Insert_before_key(key);
				break;
			case 5:
				Del_at_beg();
				break;
			case 6:
				Del_at_end();
				break;
			case 7:
				printf("enter the key\n");
				scanf("%d", &key);
				Del_after_key(key);
				break;
			case 8:
				printf("enter the key\n");
				scanf("%d", &key);
				Del_before_key(key);
				break;
			case 9:
				Display();
				break;
			case 10:
				Find_mid();
				break;
			case 11:
				Reverse();
				Display();
				break;
			default:
				printf("enter the correct option\n");
		}
		printf("\nWanna Continue : press 1\nelse : press 0\n");
		scanf("%d", &t);
		if( t == 0 )
		{
			break;
		}
	}
		
		return 0;
}
			
