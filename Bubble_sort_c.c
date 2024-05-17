#include <stdio.h>
#include <stdlib.h>

void swap( int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void Bubble_sort( int* arr, int arr_count)
{
	int i,j;
	for( i=0; i<arr_count-1; i++)
	{
		for( j=0; j<arr_count-i-1; j++)
		{
			if( arr[j]>arr[j+1])
			swap( &arr[j], &arr[j+1] );
		}
	}
	return;
}

int main()
{
	int n,i;
	printf( " Enter the length\n" );
	scanf( "%d", &n );
	int* arr = ( int* )calloc( n, sizeof(int) );
	printf( "enter the elements\n" );
	for( i=0; i<n; i++)
	{
		scanf( "%d", (arr+i) );
	}

	Bubble_sort( arr, n );
	printf( "Sorted array\n");
	for( i=0; i<n; i++)
	{
		printf( "%d ", *(arr+i) );
	}
	printf("\n\nName : YESHO DHAWAL\n");
	printf("Class : CS II A\n");
	printf("Roll No : 2101640100291\n");
	free( arr );
	return 0;
}

