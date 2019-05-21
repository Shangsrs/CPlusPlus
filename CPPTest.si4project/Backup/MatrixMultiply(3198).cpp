#include "header.h"


void matrixMultiply(int *A, int *B, int *C,int rowLength)
{
	for(int i=0;i<rowLength;i++)
	{
		for(int j=0;j<rowLength;j++)
		{
			C[i*rowLength+j]=0;
			for(int k=0;k<rowLength;k++)
			{
				C[i*rowLength+j] += A[i*rowLength+k]*B[k*rowLength+j];
			}
		}
	}
}
void printMatrix(int *mat, int rowLength)
{
	for(int j=0;j<rowLength*rowLength;j++)
	{
		if(j%rowLength == 0)
			cout<<endl;
		cout<<mat[j]<<"\t";
	}
	cout<<endl;
}

int main()
{
	const int rl = 5;
	const int length = rl*rl;
	int A[length]={0};
	int B[length]={0};
	int result[length]={0};
	for(int i=0;i<rl * rl ;i++)
	{
		A[i]=i+1;
		B[i]=i+2;
		result[i]=0;
	}
	printMatrix(A,rl);
	printMatrix(B,rl);
	matrixMultiply(A,B,result,rl);
	printMatrix(result,rl);
	return 0;
}


