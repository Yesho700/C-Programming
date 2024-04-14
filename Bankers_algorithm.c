#include <stdio.h>
#include <stdlib.h>

int isSafe(int* required, int* available, int no_res, int pro)
{
	int i;
	for(i=0; i<no_res; i++)
	{
		if(*(required + pro*no_res + i) > *(available + i))
			return 0;
	}
	return 1;
}

int allocate(int* available, int* allocated, int pro, int no_res)
{
	int i;
	for(i=0; i<no_res; i++)
	{
		*(available + i) += *(allocated + pro*no_res + i);
	}
}
int done(int* flag, int no_proc)
{
	int i;
	for(i=0; i<no_proc; i++)
	{
		if(flag[i] == 0)
			return 1;
	}
	return 0;
}

int BankerAlgo(int* required, int* available, int* allocated, int no_res, int no_proc)
{
	int i, j, k;
	int* flag = (int*)calloc(no_proc, sizeof(int));
	while(done(flag, no_proc))
	{
		for(i=0; i<no_proc; i++)
		{
			if(flag[i] == 0)
			{
				
				if(isSafe(required, available, no_res, i))
				{
					flag[i] = 1;
					allocate(available, allocated, i, no_res);
					printf("\n");
					printf("\nProcess %d Completed\n", i);
					for(k=0; k<no_res; k++)
						printf("%c : %d ", 65+k, available[k]);
				}
			}
		}
	}
}


int main()
{
	int no_res, i, j, no_proc;
	printf("Enter the number of resources\n");
	scanf("%d", &no_res);
	
	int* res_limit = (int*)calloc(no_res, sizeof(int));
	printf("Enter the Maximum resorce limit\n");
	
	for(i=0; i<no_res; i++)
	{
		scanf("%d", &res_limit[i]);
	}
	
	printf("Enter number of process\n");
	scanf("%d", &no_proc);
	
	int* allocated = (int*)calloc(no_proc*no_res, sizeof(int));
	printf("Enter the allocated data\n");
	
	for(i=0; i<no_proc; i++)
	{
		for(j=0; j<no_res; j++)
		{
			scanf("%d", (allocated + i*no_res + j));
		}
	}	
	
	int* maximum_need = (int*)calloc(no_proc*no_res, sizeof(int));
	printf("Enter the maximum need data\n");
	
	for(i=0; i<no_proc; i++)
	{
		for(j=0; j<no_res; j++)
		{
			scanf("%d", (maximum_need + i*no_res + j));
		}
	}
	
	int* required = (int*)calloc(no_proc*no_res, sizeof(int));
	for(i=0; i<no_proc; i++)
	{
		for(j=0; j<no_res; j++)
		{
			*(required + i*no_res + j) = *(maximum_need + i*no_res + j) - *(allocated + i*no_res + j);
		}
	}
	
	int* available = (int*)calloc(no_res, sizeof(int));
	for(i=0; i<no_proc; i++)
	{
		for(j=0; j<no_res; j++)
		{
			available[j] += *(allocated + i*no_res + j);
		}
	}
	for(i=0; i<no_res; i++)
	{
		available[i] = res_limit[i] - available[i];
	}
	printf("\nLimit\n");
	for(i=0; i<no_res; i++)
	{
		printf("%c : %d\n", 65+i, res_limit[i]);
	}
	printf("\nAvailable Instances\n");
	for(i=0; i<no_res; i++)
	{
		printf("%c : %d\n", 65+i, available[i]);
	}
	
	printf("\n\n");
	for(i=0; i<no_proc; i++)
	{
		for(j=0; j<no_res; j++)
		{
			printf("%d ", *(allocated + i*no_res + j));
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=0; i<no_proc; i++)
	{
		for(j=0; j<no_res; j++)
		{
			printf("%d ", *(maximum_need + i*no_res + j));
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=0; i<no_proc; i++)
	{
		for(j=0; j<no_res; j++)
		{
			printf("%d ", *(required + i*no_res + j));
		}
		printf("\n");
	}
	BankerAlgo(required, available, allocated, no_res, no_proc);
	
}
