#include <stdio.h>
#include "bogus.h"

/*=====================================================*/
/*Locality */
/*=====================================================*/


/*=====================
declaration of methods/functions
=====================*/
void row_sums
(
  double * sums,
  const double ** matrix,
  size_t nrs,
  size_t ncs
);
void col_sums
(
  double * sums,
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


	/* fill the matrix with some data */
	double p = 1000;
	for (int ix=0; ix < nrs; ++ix)
	{
		for (int jx=0; jx < ncs; ++jx)
		{
		matrix[ix][jx]=p;
		}
	}

	/* solution vectors */
	double * rowSums = (double*)malloc(nrs*sizeof(double));
	double * colSums = (double*)malloc(ncs*sizeof(double));

	row_sums
	(
		rowSums,
		matrix,
		nrs,
		ncs
	);

	col_sums
	(
		colSums,
		matrix,
		nrs,
		ncs
	);

	/* for testing purpose print solution of dummy data */
	/*
	for(int ix = 0;  ix < 10; ix++)
	{
		printf("row: %f, col: %f \n", rowSums[ix], colSums[ix]);
	}
	*/


	/* call the bogus program */
	bogus(matrix);


	/*freeing all the mallocated data*/
	free(rowSums);
	free(colSums);

	for (int ix=0; ix < nrs; ++ix)
	{
	    free(matrix[ix]);
	}

	free(matrix);

	/* printf("==> Locality(finished)\n");*/
	return 0;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*=====================
definition of the methods/functions
=====================*/

void row_sums
(
	double * sums,
	const double ** matrix,
	size_t nrs,
	size_t ncs
)
{
	for (size_t ix=0; ix < nrs; ++ix )
	{
		double sum = 0;
		for ( size_t jx=0; jx < ncs; ++jx )
		{
			sum += matrix[ix][jx];
		}
		sums[ix] = sum;
	}
}


void col_sums
(
	double * sums,
	const double ** matrix,
	size_t nrs,
	size_t ncs
)
{
	for ( size_t jx=0; jx < ncs; ++jx )
	{
		double sum = 0;
		for ( size_t ix=0; ix < nrs; ++ix )
		{
			sum += matrix[ix][jx];
		}
		sums[jx] = sum;
	}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
