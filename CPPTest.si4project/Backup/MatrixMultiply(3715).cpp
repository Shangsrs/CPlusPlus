#include "header.h"

int* matrixMultiply(int *A, int *B,int rowLength)
{
	int *C = new int[rowLength][rowLength];
}

int main()
{
	int *A[9]={0};
	int *B[9]={0};
	int *C = matrixMultiply(A,B,3);
	return 0;
}