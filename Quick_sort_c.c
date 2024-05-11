#include <stdio.h>
#include <stdlib.h>
void swap( int* a, int* b )
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int partition( int* arr, int si, int ei )
{
	int pivot = arr[si];
	int start = si;
	int end = ei;
	while( start < end )
	{
		while(start <= ei-1 && arr[start] <= pivot  )
			start ++;
	
		while(end >= si+1 && arr[end] >= pivot )
			end --;
		
		if( start < end )
			swap( &arr[start], &arr[end] );
	}
		swap( &arr[si], &arr[end] );
		return end;
}
	

void Quick_sort( int* arr, int si, int ei )
{
	if( si < ei )
	{
		int piv_idx = partition( arr, si, ei );
		Quick_sort( arr, si, piv_idx-1 );
		Quick_sort( arr, piv_idx+1, ei );
	}
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
		scanf( "%d", &arr[i] );
	}
	Quick_sort( arr, 0, arr_count-1 );
	Display( arr, arr_count );
	printf("\n\nName : YESHO DHAWAL\n");
	printf("Class : CS II A\n");
	printf("Roll No : 2101640100291\n");
	return 0;
}
