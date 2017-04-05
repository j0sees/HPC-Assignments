#include <stdio.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*=====================================================*/
/*Locality */
/*=====================================================*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*=====================
Declaration of Methods/Functions
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
void thousandUnFreeIntegers();


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*=====================
Main
=====================*/
int main(void)
{
	printf("==> Locality/Leak(started)\n");

	int nrs = 1000;
	int ncs = 1000;
	size_t sizeMatrix = sizeof(1000);

	double ** matrix = (double**)malloc(nrs*sizeof(double*));
	for (int ix=0; ix < nrs; ++ix)
	{
	    matrix[ix] = (double*)malloc(ncs*sizeof(double));
	}

	/*Dummy Data*/
	/*
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;
	*/

	double * rowSums = (double*)malloc(nrs*sizeof(double));
	double * colSums = (double*)malloc(ncs*sizeof(double));


	/*Call the  thousandUnFreeIntegers()*/
	thousandUnFreeIntegers();

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

	printf("==> Locality/Leak(finished)\n");
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

void row_sums
(
	double * sums,
	/* pointer to the output which is a double in the main program*/
	const double ** matrix,
	/* const means I cannot change the matrix itself*/ 
	/* ** means it is an pointer which points to a pointer (pp --> p --> double)*/
	size_t nrs,
	/* size_t is an unsigned integer type used to represent the size of any object (including arrays) in the particular implementation. */
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

void thousandUnFreeIntegers()
{
	int thousand = 1000;
	int * unFreeIntegers = (int*)malloc(thousand*sizeof(int));
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
