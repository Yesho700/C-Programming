#include <stdio.h>
#include <stdlib.h>

int get_max( int* arr, int arr_count )
{
	int i, max=-199999;
	for( i=0; i<arr_count; i++ )
	{
		if( arr[i] > max )
		{
			max = arr[i];
		}
	}
	return max;
}

void Counting_sort( int* arr, int arr_count )
{
	int b_count = get_max( arr, arr_count )+1;
	int* b = (int*)calloc( b_count, sizeof(int) );
	int i, sum = 0;
	for( i=0; i<arr_count; i++ )
	{
		b[arr[i]] += 1;
	}
	for( i=0; i<b_count; i++ )
	{
		sum += b[i];
		b[i] = sum;
	}
	int* c = (int*)calloc( arr_count, sizeof(int) );
	for( i = arr_count-1; i>=0; i-- )
	{
		c[--b[arr[i]]] = arr[i];
	}
	for( i=0; i<arr_count; i++ )
	{
		arr[i] = c[i];
	}
	return;
}
void Display( int* arr, int arr_count )
{
	int i;
	printf("Sorted Array\n");
	for( i=0; i<arr_count; i++ )
	{
		printf("%d ", *(arr + i));
	}
	return;
}
int main()
{
	int arr_count, i;
	printf( "Enter the length of Array\n" );
	scanf( "%d", &arr_count );
	int* arr = (int*)calloc( arr_count, sizeof(int) );
	printf( "Enter the elements\n" );
	for( i=0; i<arr_count; i++ )
	{
		scanf( "%d",  (arr+i) );
	}
	Counting_sort( arr, arr_count );
	Display( arr, arr_count );
	printf("\n\nName : YESHO DHAWAL\n");
	printf("Class : CS II A\n");
	printf("Roll No : 2101640100291\n");
	return 0;
}




