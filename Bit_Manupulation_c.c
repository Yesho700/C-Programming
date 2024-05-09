#include <stdio.h>
#include <stdlib.h>

int checkBit(int n, int pos)
{
	int b = 1 << pos;
	int res = n & b;
	if(res)
		return 1;
	else
		return 0;
}

int setBit(int n, int pos)
{
	int b = 1 << pos;
	int res = n | b;
	return res;
}

int clearBit(int n, int pos)
{
	int b = 1 << pos;
	int res = n & ~b;
	return res;
}

int main()
{
	int n, pos;
	printf("Enter the number\n");
	scanf("%d", &n);
	printf("Enter the position\n");
	scanf("%d", &pos);
	
	FILE* file = fopen("BIT_menu.txt", "r");
	char c;
	while((c=fgetc(file)) != EOF)
	{
		printf("%c", c);
	}
	
}
