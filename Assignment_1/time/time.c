#include <stdio.h>
 
int main()
{
	int numberOfIterations = 1000000000;
	long int sum = 0;

	for (int c = 0; c < numberOfIterations; c++)
	{
		sum = sum + c;
	}


//	printf("solution %ld \n", sum);
	return 0;
}
