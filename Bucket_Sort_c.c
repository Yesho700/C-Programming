// Bucket Sort 

#include <stdio.h>
#include <stdlib.h>

struct node{
	float val;
	struct node* next;
};

struct Buck{
	struct node* head;
};

typedef struct Buck Buck;
typedef struct node node;

node* add(node* head, float val)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode -> val = val;
	newNode -> next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
	}	
	else
	{
		newNode -> next = head;
		head = newNode;
	}
	return head;
}

node* MergeSort(node* head)
{
	//Find Middle
	if(head == NULL || head -> next == NULL)
		return head;
	
	node* slow = head;
	node* fast = head;
	while(fast -> next != NULL && fast -> next -> next != NULL)
	{
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	node* h2 = slow -> next;
	slow -> next = NULL;
	node* left = MergeSort(head);
	node* right = MergeSort(h2);
	
	node* i = left;
	node* j = right;
	
	node* nHead = (node*)malloc(sizeof(node));
	nHead -> val = -1;
	nHead -> next = NULL;
	node* ptr = nHead;
	while(i != NULL && j != NULL)
	{
		if(i->val <= j->val)
		{
			ptr->next = i;
			ptr = ptr->next;
			i = i->next;
		}
		else
		{
			ptr->next = j;
			ptr = ptr->next;
			j = j->next;
		}
	}
	if(i != NULL)
		ptr -> next = i;
	if(j != NULL)
		ptr -> next = j;
		
	return nHead -> next;
}

void BucketSort(float* arr, int n)
{
	int i;
	
	Buck* bucket = (Buck*)calloc(10, sizeof(Buck));
	for(i=0; i<10; i++)
	{
		bucket[i].head = NULL;
	}
	
	for(i=0; i<n; i++)
	{
		int x = (int)(arr[i]*10);
		printf("%d ", x);
		bucket[x].head = add(bucket[x].head, arr[i]);
	}
	
	
	for(i=0; i<10; i++)
	{
		MergeSort(bucket[i].head);
	}
	
	printf("\n");
	for(i=0; i<10; i++)
	{
		printf("%d : ", i);
		node* start = bucket[i].head;
		while(start != NULL)
		{
			printf("%.2f ", start -> val);
			start = start -> next;
		}
		printf("\n");
	}
	
}

int main()
{
	int n, i;
	printf("Enter the Number of Elements\n");
	scanf("%d", &n);
	
	float* arr = (float*)calloc(n, sizeof(float));
	printf("Enter the Elements\n");
	for(i=0; i<n; i++)
	{
		scanf("%f", &arr[i]);
	}
	
	BucketSort(arr, n);
}
