#include <stdio.h>

/*=====================
Declaration of Methods/Functions
=====================*/
/* !!! */
/* The solution of the addition will be stored into the firstNumberAsArray*/
/* !!! */
void SumArrayIntegers(int firstNumberAsArray[], int secoundNumberAsArray[], int sizeOfArrays);


/*=====================
Main
=====================*/

int main(void)
{
	printf("==> SumArrayIntegers: start\n");

	int sizeOfArrays = 100;
	int numberOfIterations = 1000000000;

	int arrayOne[sizeOfArrays];
	int arrayIterations[sizeOfArrays];

	int arraySum[sizeOfArrays];

	for (int ii=0; ii<sizeOfArrays; ii++)
	{
		arrayIterations[ii] = 0;
		arrayOne[ii] = 0;

		arraySum[ii] = 0;
	}
	/*Define the one which will be added every iteration to the iteration sum*/
	arrayOne[0] = 1;

	/*The main loop*/
	for(long jj = 0; jj<numberOfIterations; jj++)
	/*while(arrayIterations[9]!=0)*/
	{
		/*Iterations*/
		SumArrayIntegers(arrayIterations, arrayOne, sizeOfArrays);
		
		/*Sum*/
		SumArrayIntegers(arraySum, arrayIterations, sizeOfArrays);
	}

	/*Print number position sizeOfArrays sizeOfArrays-1 ... */
	for(int jj = sizeOfArrays; jj-- >0;)
	{
		printf("%d", arraySum[jj]);
		if(jj%10==0)
		{
			printf("\n");
		}
	}
	printf("\n");

	printf("==> SumArrayIntegers finished\n");
	return 0;
}

/*=====================
Definition of the Methods or Functions
=====================*/
/* Summation main loop, going from right to left pointer to the array*/
void SumArrayIntegers(int firstNumberAsArray[], int secoundNumberAsArray[], int sizeOfArrays) 
{
	for ( int i = 0; i < sizeOfArrays; i++ ) 
	{
		int tmp = firstNumberAsArray[i] + secoundNumberAsArray[i];

		if(tmp > 9)
		{
			/* modulo calculation ==> remainder*/
			firstNumberAsArray[i] = tmp%10;			
			firstNumberAsArray[i+1] = firstNumberAsArray[i+1] +1;
		}
		else
		{
			firstNumberAsArray[i] = tmp;
		}
	}
}