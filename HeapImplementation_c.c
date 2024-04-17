#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void maxHeapify(int* arr, int arr_count, int i)
{
	int parent  = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l < arr_count && arr[l] > arr[parent])
		parent = l;
	if(r < arr_count && arr[r] > arr[parent])
		parent = r;
		
	if(parent != i)
	{
		Swap((arr+i), (arr+parent));
		maxHeapify(arr, arr_count, parent);
	}
}

void minHeapify(int* arr, int arr_count, int i)
{
	int parent = i;
	int l = 2*i;
	int r = 2*i+1;
	if(l < arr_count && arr[l] < arr[parent])
		parent = l;
	if(r < arr_count && arr[r] < arr[parent])
		parent = r;
		
	if(parent != i)
	{
		Swap((arr+i), (arr+parent));
		minHeapify(arr, arr_count, parent);
	}
}

int main()
{
	int i,  arr_count;
	
	printf("enter the length of an array\n");
	scanf("%d", &arr_count);
	
	int* arr = (int*)malloc(sizeof(int));
	
	printf("Enter the elements\n\n");
	for(i=0; i<arr_count; i++)
		scanf("%d", (arr+i));
	
	for(i = arr_count/2-1; i>=0; i--)		// max Heapify
		maxHeapify(arr, arr_count, i);
		
	for(i=arr_count-1; i>0; i--)   	// Accending sort
	{
		Swap(&arr[0], &arr[i]);
		maxHeapify(arr, i, 0);
	}
		
	printf("\n\n"); 
	for(i=0; i<arr_count; i++)
		printf("%d ", arr[i]);
		
	for(i = arr_count/2-1; i>=0; i--)	// min Heapify
		minHeapify(arr, arr_count, i);
		
	for(i=arr_count-1; i>0; i--)			// Decending sort
	{
		Swap(&arr[0], &arr[i]);
		minHeapify(arr, i, 0);
	}
	printf("\n\n");
	for(i=0; i<arr_count; i++)
		printf("%d ", arr[i]);
		
	
	return 0;
}
