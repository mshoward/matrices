#include <stdlib.h>
#include <stdio.h>
#ifndef MATRIX_HEADER_INCLUDED
#define MATRIX_HEADER_INCLUDED


typedef struct
{
	int numerator;
	int divisor;
	int isValid; //divisor shouldn't be 0
} rationalNumber;

typedef struct
{
	int cols;
	rationalNumber *row;
}t_matrix_row;

typedef struct
{
	int rows;
	int cols;
	int isValid;
	t_matrix_row *matrix;
} t_matrix;

//inits
void init_rationalNumber(rationalNumber *A);		//done
void init_From_Int(rationalNumber *A, int n);		//done
void init_t_matrix_row(t_matrix_row *A, int Cols);	//done
void init_t_matrix(t_matrix *A, int Rows, int Cols);//done
//t_matrix init_From_Size(int Rows, int Cols);

//memory care
void free_row_memory(t_matrix_row *ptr);			//done
void free_matrix_memory(t_matrix *ptr);				//done



// Operations
/* Rational Number Operations */
int checkValidNumber(rationalNumber *A);			//done
void ASSERT_NUMBER_VALIDITY(rationalNumber *A);			
void reduce(rationalNumber *A);						//done

//done
void assign_to_rationalNum(rationalNumber *in, rationalNumber value);

double resolve(rationalNumber A);					//done

rationalNumber add(rationalNumber A, rationalNumber B);//done
rationalNumber negate(rationalNumber A);			//done
rationalNumber inverse(rationalNumber A);			//done
rationalNumber subtract(rationalNumber A, rationalNumber B);//done
rationalNumber mult(rationalNumber A, rationalNumber B);//done
rationalNumber divide(rationalNumber A, rationalNumber B);//done


/* Matrix Row Operations */
void push_to_row(t_matrix_row *in, int Col, rationalNumber value);//done
void copy_to_matrix_row(t_matrix_row *in, t_matrix_row *value);//done
t_matrix_row scalar_mult(t_matrix_row Row, rationalNumber scalar);
t_matrix_row add_row(t_matrix_row A, t_matrix_row B);

/* Matrix Operations */
int checkValidMatrix(t_matrix *A);
void push_to_matrix(t_matrix *in, int Row, int Col, rationalNumber value);
void assign_to_matrix(t_matrix *in, t_matrix value);
void switch_rows(int r1, int r2);





































#endif