#include <stdlib.h>
#include <stdio.h>
#ifndef MATRIX_HEADER_INCLUDED
#include "matrix.h"
#endif
#ifndef MATRIX_INCLUDED
#define MATRIX_INCLUDED
#define DEBUG 1
#define ERRORS_FATAL 1
#define VERBOSE_ERRORS 1
#define VERBOSE 1

void init_rationalNumber(rationalNumber *A)
{
	A->numerator = 0;
	A->divisor = 1;
	A->isValid = 1;
}

void init_From_Int(rationalNumber *A, int n)
{
	//rationalNumber A;
	init_rationalNumber(A);
	A->numerator = n;
	//return A;
}

void init_t_matrix_row(t_matrix_row *A, int Cols)
{
	int i;
	
	A->cols = Cols;
	A->row = (rationalNumber *) malloc(sizeof(rationalNumber) * Cols);
	for (i = 0; i < Cols; i++)
	{
		init_rationalNumber(&((*A).row[i]));
	}
}

void free_row_memory(t_matrix_row *ptr)
{
	//int returnCode;
	if ((ptr != NULL) && ((*ptr).row != NULL))
		free((*ptr).row);
	ptr->row = NULL;
	//return 0;
}

void init_t_matrix(t_matrix *A, int Rows, int Cols)
{
	A-> rows = Rows;
	A-> cols = Cols;
	int i, j;
	if ((Rows <= 0) || (Cols <= 0))
	{
		A->isValid = 0;
		if (VERBOSE_ERRORS || VERBOSE) printf("\n ***** Matrix initialization failure ***** \n");
		goto END; 	//Goes to the end of the method
					//Is not spaghetti code!
	}
	
	A->isValid = 1;
	A->matrix = (t_matrix_row *) malloc(sizeof(t_matrix_row) * Rows);
	for(i = 0; i < Rows; i++)
	{
		init_t_matrix_row(&((*A).matrix[i]), Cols);
	}
	
	END:
	;
}

void free_matrix_memory(t_matrix *ptr)
{
	int i, j;
	
	for (i = 0; i < (ptr->rows); i++)
	{
		free_row_memory(&((*ptr).matrix[i]));
		//ptr->matrix[i] = NULL;
	}
	if ((*ptr).matrix != NULL)
		free((*ptr).matrix);
	ptr->matrix = NULL;
	//return 1;
	
}

int checkValidNumber(rationalNumber *A)
{
	if ((A->divisor) == 0)
	{
		A->isValid = 0;
		return A->isValid;
	}
	else
	{
		A->isValid = 1;
	}
	return A->isValid;
}

void ASSERT_NUMBER_VALIDITY(rationalNumber *A)
{
	if (!(checkValidNumber(A)))
	{
		if (VERBOSE || VERBOSE_ERRORS) printf("\n ***** VALID NUMBER ASSERTION FAILURE ***** \n");
		if (DEBUG || ERRORS_FATAL) exit(1);
	}
}

//rationalNumber operations
//reduce A
void reduce(rationalNumber *A)
{
	int i;
	for (i = 2; i <= (A->numerator); i++)
	{
		if ( (((A->numerator) % i) == 0) && (((A->divisor) % i) == 0) )
		{
			//if i divides both evenly, go ahead and divide
			A->numerator = (A->numerator) / i;
			A->divisor = (A->divisor) / i;
			//then reset the loop
			i = 2;
		}
	}
}

void assign_to_rationalNum(rationalNumber *in, rationalNumber value)
{
	in->numerator = value.numerator;
	in->divisor = value.divisor;
	checkValidNumber(in);
}

//resolve A
double resolve(rationalNumber A)
{
	double numerator, denominator;
	//reduce(&A);
	numerator = A.numerator;
	denominator = A.divisor;
	return (numerator / denominator);
}

//A + B
rationalNumber add(rationalNumber A, rationalNumber B)
{
	rationalNumber retVal;
	init_rationalNumber(&retVal);
	ASSERT_NUMBER_VALIDITY(&A);
	ASSERT_NUMBER_VALIDITY(&B);
	//case 1
	if (A.divisor == B.divisor)
	{
		retVal.numerator = A.numerator + B.numerator;
		retVal.divisor = A.divisor;
		checkValidNumber(&retVal);
		return retVal;
	}
	else
	{
		//divisors are different
		retVal.numerator = (A.numerator * B.divisor) + (B.numerator * A.divisor);
		retVal.divisor = (A.divisor * B.divisor);
		checkValidNumber(&retVal);
		return retVal;
		
	}
}

rationalNumber negate(rationalNumber A)
{
	A.numerator = -A.numerator;
	return A;
}

rationalNumber inverse(rationalNumber A)
{
	rationalNumber retVal;
	init_rationalNumber(&retVal);
	retVal.numerator = A.divisor;
	retVal.divisor = A.numerator;
	checkValidNumber(&retVal);
	return retVal;
}

//A - B
rationalNumber subtract(rationalNumber A, rationalNumber B)
{
	return add(A, negate(B));
}

//A * B
rationalNumber mult(rationalNumber A, rationalNumber B)
{
	rationalNumber retVal;
	ASSERT_NUMBER_VALIDITY(&A);
	ASSERT_NUMBER_VALIDITY(&B);
	init_rationalNumber(&retVal);
	retVal.numerator = A.numerator * B.numerator;
	retVal.divisor = A.divisor * B.divisor;
	checkValidNumber(&retVal);
	return retVal;
}
// A / B
rationalNumber divide(rationalNumber A, rationalNumber B)
{
	return mult(A, inverse(B));
}

void push_to_row(t_matrix_row *in, int Col, rationalNumber value)
{
	assign_to_rationalNum(&((*in).row[Col]), value);
}

void copy_to_matrix_row(t_matrix_row *in, t_matrix_row *value)
{
	int i, j;
	if (in->cols != value->cols)
		goto COLS_ARE_NOT_SAME;
	else
	{
		for (i = 0; i < in->cols; i++)
		{
			push_to_row(in, i, value->row[i]);
		}
	}
	
	COLS_ARE_NOT_SAME:
	;//do nothing
}

































#endif
