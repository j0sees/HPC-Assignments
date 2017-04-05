#include <stdio.h>
#define N 1000
#define NRS 1000
#define NCS 1000
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*=====================================================*/
/*Locality */
/*=====================================================*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*=====================
Declaration of Methods/Functions
=====================*/
void sumsRowCol
(
	double * rowSums,
	double * colSums,
	const double ** matrix,
	size_t nrs,
	size_t ncs
);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*=====================
Main
=====================*/
int main(void)
{
	/*printf("==> Locality(started)\n");*/

	int nrs = 1000;
	int ncs = 1000;
	size_t sizeMatrix = sizeof(1000);

	double ** matrix = (double**)malloc(nrs*sizeof(double*));
    for (int ix=0; ix < nrs; ++ix)
	{
	    matrix[ix] = (double*)malloc(ncs*sizeof(double));
	}

	/*Dummy Data
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;
	*/
	
	/* Fill the matrix with some data */
	double p = 1000;
	for (int ix=0; ix < nrs; ++ix)
	{
		for (int jx=0; jx < ncs; ++jx)
		{
		matrix[ix][jx]=p;
		}
	}	

	double * rowSums = (double*)malloc(nrs*sizeof(double));
	double * colSums = (double*)malloc(ncs*sizeof(double));
	
	sumsRowCol
	(
		rowSums,
		colSums,
		matrix,
		nrs,
		ncs	
	);

	
	/* Print solution of dummy data
	for(int ix = 0;  ix < 10; ix++)
	{
		printf("row: %f, col: %f \n", rowSums[ix], colSums[ix]);
	}
	*/


	/*Freeing all the mallocated data*/
	free(rowSums);
	free(colSums);
    for (int ix=0; ix < nrs; ++ix)
	{
	    free(matrix[ix]);
	}
	free(matrix);

	/*printf("==> Locality(finished)\n");*/
	return 0;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*=====================
Definition of the Methods or Functions
=====================*/
/*
	size_t ==> 
	http://stackoverflow.com/questions/2550774/what-is-size-t-in-c or 
	https://en.wikipedia.org/wiki/C_data_types#stddef.h
*/

void sumsRowCol
(
	double * rowSums,
	double * colSums,
	const double ** matrix,
	size_t nrs,
	size_t ncs
)
{
	for (size_t ix=0; ix < nrs; ++ix ) /*i --> row; j--> column*/
	{
		double rowSum = 0;
		double colSum = 0;
		for ( size_t jx=0; jx < ncs; ++jx )
		{
			rowSum += matrix[ix][jx];
			colSum += matrix[jx][ix];
		}
		rowSums[ix] = rowSum;
		colSums[ix] = colSum;
	}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
