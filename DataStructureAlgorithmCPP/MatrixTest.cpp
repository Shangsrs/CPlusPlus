#include "../header.h"

template<class T>
class Matrix
{
private:
	int _rows;
	int _columns;
	T *_element;
public:
	Matrix(int rows=0,int columns=0);
	Matrix(const Matrix<T>&);
	~Matrix(){delete[] _element;};
	int rows() const {return _rows;}
	int columns() const {return _columns;}
	T& operator()(int i,int j) const;
	Matrix<T>& operator=(const Matrix<T>&);
	Matrix<T> operator+(const Matrix<T>&);	
	Matrix<T> operator+();
	Matrix<T> operator-(const Matrix<T>&);	
	Matrix<T> operator-();
	Matrix<T> operator*(const Matrix<T>&);	
	Matrix<T>& operator+=(const Matrix<T>&);	
	
};


int main()
{
	return 0;
}
