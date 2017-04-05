#include <stdio.h>

void thousandUnFreeIntegers();

int main()
{
	/*void thousandUnFreeIntegers();*/

	int numberOfIterations = 1000000000;
	long int sum = 0;

	for (int c = 1; c <= numberOfIterations; c++)
	{
		sum = sum + c;
	}


	printf("solution %ld \n", sum);
	return 0;
}


void thousandUnFreeIntegers()
{
	int thousand = 1000;
	int * unFreeIntegers = (int*)malloc(thousand*sizeof(int));
}
