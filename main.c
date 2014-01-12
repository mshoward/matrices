#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "matrix.c"

int main()
{
	int i,j;
	t_matrix_row myRow;
	//printf("Hello World!");
	printf("You need to make a destructoid for t_matrix \n");
	printf("you also need to make this monstrosity work \n");
	i = 0;
	j = 0;
	myRow.cols = 10;
	while (1)
	{
		i++;
		if (i == 0)
		{
			j++;
			printf("%d \n", j);
		}
		//printf("%d \n", i);
	}
	return 0;
}