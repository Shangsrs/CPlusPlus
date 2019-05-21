#include <iostream>
using namespace std;

int row = 10;
int col = 10;
void printArray(int*arr, int len = 10)
{
	for(int i=0;i<len;i++)
	{
		std::cout<<arr[i]<<"\t";
	}
	std::cout<<std::endl;
}


int** createArray(int row, int col)
{
	int **arr = new int*[col];
	for(int i=0;i<row;i++)
	{
		arr[i] = new int[col];
	}
	for(int m=0;m<row;m++)
	{
		for(int n=0;n<col;n++)
		{
			arr[m][n] = 2*m*row + n;
		}
	}
	for(i=0;i<row;i++)
	{
		printArray(arr[i],col);
	}
	return arr;
}

bool findNumber(int** array,int number)
{
	for(int i = row; i>=0; i--)
	{
		for(int j=0; j<col;j++)
		{
			if(array[i][j] == number)
			{
				cout<<"Row: "<<i<<" Col: " <<j<<endl;
				return true;
			}
			else if(array[i][j] > number)
				break;
		}
	}
	cout<<"Not Find" <<endl;
	return false;
}

int main()
{
	int number;
	int** array = createArray(row,col);
	cout<<"Please enter a number:"<<endl;
	cin>>number;
	findNumber(array,number);
	return 0;
}