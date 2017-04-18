#include <stdio.h>
/* implement mul_cpx.h  */
#include "mul_cpx.h"
/* implement bogus.h --> so that the compiler keeps the results */
#include "bogus.h"

int main()
{

	/* declare the variables  */
	int nvec = 30000;
	double * a_re = (double*)malloc(nvec*sizeof(double));
	double * a_im = (double*)malloc(nvec*sizeof(double));
	double * b_re = (double*)malloc(nvec*sizeof(double));
	double * b_im = (double*)malloc(nvec*sizeof(double));
	double * c_re = (double*)malloc(nvec*sizeof(double));
	double * c_im = (double*)malloc(nvec*sizeof(double));

	/* fill the vectors with some dummy-data */
	for(int ii = 0; ii < nvec; ++ii)
	{
		b_re[ii] = 1;
		b_im[ii] = 2;
		c_re[ii] = 3;
		c_im[ii] = 4;
		a_re[ii] = 0;
		a_im[ii] = 0;
	}

	/* call the product method/function from the file mul_cpx.h */
	/* ==> second run this is commented. */
	/* pass a pointer of the value at the position ii to the function.
	   you can do this by using ==>   &a_re[ii] */

	for(int ii = 0; ii < nvec; ++ii)
	{
		mul_cpx
		(
			&a_re[ii],
			&a_im[ii],
			&b_re[ii],
			&b_im[ii],
			&c_re[ii],
			&c_im[ii]
		);
	}

	/* use the code from mul_cpx.h inlined! */
	/* inline by hand like this?		*/
	/* ==> first run this is commented  	*/
	/*
	for(int ix = 0; ix < nvec; ++ix)
	{
		double tmp_re  = c_re[ix] * b_re[ix] - c_im[ix] * b_im[ix];
		double tmp_im  = c_re[ix] * b_im[ix] + c_im[ix] + b_re[ix];
		*(a_re + ix) = tmp_re;
		a_im[ix] = tmp_im;
	}
	*/

	/* for testing purposes
	printf("test %f \n",a_re[1]);
	printf("test %f \n",a_re[100]);
	*/
	/* call the bogus file*/
	bogus
	(
		a_re,
		a_im
	);

	/* free the data */
	for (int ix=0; ix < nvec; ++ix)
	{
		a_re[ix];
		a_im[ix];
		b_re[ix];
		b_im[ix];
		c_re[ix];
		c_im[ix];
	}

	return 0;
}
