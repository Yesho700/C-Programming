#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int* arr, int arr_count, int key)
{
	int low = 0;
	int high = arr_count - 1;
	
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(key == arr[mid])
			return mid + 1;
		else if(key > arr[mid])
		{
			if(arr[mid] < arr[mid + 1])
				low = mid + 1;
			else
				high = mid - 1;
		}
		else
		{
			if(arr[mid] > arr[mid + 1])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return 0;
}

int main()
{
	int i, arr_count, k;
	
	printf("Enter the length\n");
	scanf("%d", &arr_count);
	
	int* arr = (int*)calloc(arr_count, sizeof(int));
	
	printf("Enter the elements\n");
	for(int i=0; i<arr_count; i++)
		scanf("%d", (arr+i));
	
	printf("Enter the Key to Search\n");
	scanf("%d", &k);
	
	printf("%d", BinarySearch(arr, 10, k));
	return 0;
}
