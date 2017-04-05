#include <stdio.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*=====================================================*/
/*HPC A1 Task 5: Indirect addressing*/
/*=====================================================*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*=====================
Main
=====================*/
int main(void)
{
	int n=1000000;
	int a = 4;

	/*Initialize the vectors y and x*/
	int * y = (int*)malloc(n*sizeof(int));
	int * x = (int*)malloc(n*sizeof(int));

	/*derefernciate the  p[vector] and fill it with values*/
	for(int ix =0; ix<n; ++ix)
	{
		/*Fill the vector with dummy data*/
		y[ix] = 1;
		x[ix] = ix;
	}

	/*increment the vector y by the value of a*vector x*/
	for(int kx=0; kx<n; ++kx)
	{
		y[kx] += a*x[kx];
	}

	/*
	for(int ii =0; ii<10; ++ii)
	{
		printf("Iteration %d: y %d += a %d * x %d \n", ii, y[ii], a, x[ii]);
	}
	*/

	/*Freeing all the mallocated data*/
	free(x);
	free(y);

	return 0;
}
