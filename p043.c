#include <stdio.h>

#define N 5

void square_matrix_multiply(int a[N][N],int b[N][N],int c[N][N])
{
	int i,j,k;

	for (i = 0;i < N;i++)
		for (j = 0;j < N;j++) {
			c[i][j] = 0;
			for (k = 0;k < N;k++) 
				c[i][j] += a[i][k] * b[k][j];
		}
}
main()
{
	int i,j;
	int c[N][N];

	int a[N][N] = {
			{1,2,3,4,5},
			{2,3,4,5,6},
			{1,1,1,1,1},
			{2,2,2,2,2},
			{1,3,2,4,5}
			};
	int b[N][N] = {
			{1,2,3,4,5},
			{2,3,4,5,6},
			{1,1,1,1,1},
			{2,2,2,2,2},
			{1,3,2,4,5}
			};
	square_matrix_multiply(a,b,c);

	for (i = 0;i < N;i++) {
		for (j = 0;j < N;j++)
			printf("%5d",c[i][j]);
		printf("\n");
	}
}

