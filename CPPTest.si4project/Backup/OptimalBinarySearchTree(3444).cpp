#include "header.h"



//K1 K2 ... Kn
float P[] = {0,0.15,0.1,0.05,0.1,0.2};

//D0 D1 ... Dn
float Q[] = {0.05,0.1,0.05,0.05,0.05,0.1};

const int N = 6;

template <class T>
void printArray2(T* arr, int row, int col)
{
	for(int i=1; i<row; i++)
	{
		for(int j=0; j<col-1; j++)
			cout<<arr[i*col+j]<<"\t";
		cout<<endl;
	}
	cout<<endl<<endl;
}

void OptimalBST(int n)
{
	float e[N+1][N+1] = {0.0};
	float w[N+1][N+1] = {0.0};
	int root[N][N] = {0};
	for(int i=1;i<=n+1;i++)
	{
		e[i][i-1] = Q[i-1];
		w[i][i-1] = Q[i-1];
	}
	printArray2<float>((float*)e,N+1,N+1);
	for(int l=1; l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			e[i][j]=999;
			w[i][j] = w[i][j-1]+P[j]+Q[j];
//			cout<<"i="<<i<<" j="<<j<<" l="<<l<<endl;
			for(int r=i;r<=j;r++)
			{
//				cout<<"i="<<i<<" j="<<j<<" l="<<l<<endl;
				float t = e[i][r-1]+e[r+1][j]+w[i][j];
				if(t<e[i][j])
				{
					e[i][j]=t;
//					cout<<" r="<<r<<endl;
					root [i][j]=r;
				}
//				cout<<"i="<<i<<" j="<<j<<" r="<<r<<endl;
//				cout<<"temp="<<t<<endl;
//				cout<<"E_ir-1="<<e[i][r-1]<<" E_r+1j="<<e[r+1][j]<<" w[i][j]="<<w[i][j]<<endl;
			}
		}
	}
	printArray2<float>((float*)e,N+1,N+1);
	printArray2<float>((float*)w,N+1,N+1);
//	printArray2<int>((int*)root,N,N);
}

void OptimalBST(float *p, float *q, int n)
{
	const int len = 7;
	float e[len][len] = {0.0};
	float w[len][len] = {0.0};
	for(int i=1;i<=n;i++)
	{
		e[i][i-1]=q[i-1];
		w[i][i-1]=q[i-1];
		
		for(int j=i;j<n;j++)
		{
			float pSum = 0, qSum = 0;
			for(int l=i;l<=j;l++)
				pSum += p[l];
			for(int k=i-1;k<=j;k++)
				qSum += q[k];
			w[i][j] = pSum + qSum;
		}
		
	}
//	printArray2<float>((float*)e,len,len);
/*	for(int i=1;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			float min = 999;
			float temp = 0;
			for(int r=i;r<=j;r++)
			{
				temp = e[i][r-1]+e[r+1][j]+w[i][j];
				if(temp < min)
					min = temp;
				cout<<"i="<<i<<" j="<<j<<" r="<<r<<endl;
//				cout<<"temp="<<temp<<" min="<<min<<endl;
//				cout<<"E_ir-1="<<e[i][r-1]<<" E_r+1j="<<e[r+1][j]<<" w[i][j]="<<w[i][j]<<endl;
			}
			e[i][j] = min;
		}
	}*/
	for(int l=1;l<n;l++)
	{
		for(int i=1;i<n-l+1;i++)
		{
			int j = i+l-1;
			float min = 999;
			float temp = 0;
			for(int r=i;r<=j;r++)
			{
				temp = e[i][r-1]+e[r+1][j]+w[i][j];
				if(temp < min)
					min = temp;
//				cout<<"i="<<i<<" j="<<j<<" r="<<r<<endl;
//				cout<<"temp="<<temp<<" min="<<min<<endl;
//				cout<<"E_ir-1="<<e[i][r-1]<<" E_r+1j="<<e[r+1][j]<<" w[i][j]="<<w[i][j]<<endl;
			}
			e[i][j] = min;
			cout<<"i="<<i<<" j="<<j<<" l="<<l<<endl;
		}
	}
	printArray2<float>((float*)e,len,len);
	printArray2<float>((float*)w,len,len);
}

int main()
{
	OptimalBST(5);
	OptimalBST(P,Q,6);
	return 0;
}
