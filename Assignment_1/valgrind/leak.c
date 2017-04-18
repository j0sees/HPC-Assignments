#include <stdio.h>

int* thousandUnFreeIntegers();

int main()
{
	/* Allocate space for the integers without freeing the allocated space at the end of the program  */
	int* test = thousandUnFreeIntegers();

	int numberOfIterations = 1000000000;
	long int sum = 0;

	for (int c = 1; c <= numberOfIterations; c++)
	{
		sum = sum + c;
	}

	int bogus = sizeof(test);
	printf("solution %ld \n", sum);
	printf("size of int %d", sizeof(int));
	return 0;
}


int* thousandUnFreeIntegers()
{
	int thousand = 1000;
	int * unFreeIntegers = (int*)malloc(thousand*sizeof(int));
}
