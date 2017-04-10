#include <stdio.h>
#include "bogus.h"

/*=====================================================*/
/*Locality */
/*=====================================================*/


/*=====================
declaration of methods/functions
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
main
=====================*/
int main(void)
{
	/*printf("==> Locality(started)\n");*/

	int nrs = 1000;
	int ncs = 1000;
	double p = 1000;
	size_t sizeMatrix = sizeof(1000);
	double * rowSums = (double*)malloc(nrs*sizeof(double));
	double * colSums = (double*)malloc(ncs*sizeof(double));
	double ** matrix = (double**)malloc(nrs*sizeof(double*));

	for (int ix=0; ix < nrs; ++ix)
	{
		matrix[ix] = (double*)malloc(ncs*sizeof(double));
	}

	/* fill the matrix with some data */
	for (int ix=0; ix < nrs; ++ix)
	{
		for (int jx=0; jx < ncs; ++jx)
		{
			matrix[ix][jx]=p;
		}
	}


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

	/* call the bogus program  */
	bogus(matrix);

	/*freeing all the mallocated data*/
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
definition of the methods/functions
=====================*/

void sumsRowCol
(
	double * rowSums,
	double * colSums,
	const double ** matrix,
	size_t nrs,
	size_t ncs
)
{
	for (size_t ix=0; ix < nrs; ++ix )
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
