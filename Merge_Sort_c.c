#include <stdio.h>
#include <stdlib.h>

void Merge_conq( int* arr, int si, int mid, int ei )
{
	int c_count = ei - si + 1;
	int* c = (int*)calloc( c_count, sizeof(int) );
	int k = 0;
	int i = si;
	int j = mid + 1;
	while( i <= mid && j <= ei )
	{
		if( arr[i] <= arr[j] )
			c[k++] = arr[i++];
		else
			c[k++] = arr[j++];
	}
	while( i <= mid )
	{
		c[k++] = arr[i++];
	}
	while( j <= ei )
	{
		c[k++] = arr[j++];
	}

	for( i=0, j=si; i < c_count; i++, j++ )
	{
		arr[j] = c[i];
	}
	return;
}
void Merge_sort( int* arr, int si, int ei )
{
	if( si >= ei)
	{
		return;
	}
	else
	{
	int mid = (si + ei)/2;
	Merge_sort( arr, si, mid);
	Merge_sort( arr, mid+1, ei );
	Merge_conq( arr, si, mid, ei );
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
	Merge_sort( arr, 0, arr_count-1 );
	Display( arr, arr_count );
	printf("\n\nName : YESHO DHAWAL\n");
	printf("Class : CS II A\n");
	printf("Roll No : 2101640100291\n");
	return 0;
}
