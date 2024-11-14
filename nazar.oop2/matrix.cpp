#include "matrix.h"
#include <iostream>

//char Matrix::count = 64;
size_t Matrix::count = 0;

Matrix::Matrix() : id(++count)
{
	rows = 5;
	cols = 5;
	matr = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		matr[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matr[i][j] = RAND_MAX/(double)rand();
		}
	}

	std::cout << "\nDefault constructor complete with id:" << id << "\n";
}

Matrix::Matrix(const Matrix &other)
{
	id = ++count;
	this->cols = other.cols;
	this->rows = other.rows;
	this->matr = new double* [other.rows];
	for (int i = 0; i < rows; i++)
	{
		matr[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matr[i][j] = other.matr[i][j];
		}
	}
	std::cout << "\nCopy constructor id:" << id << "\n";
}
Matrix::Matrix(Matrix&& other) : Matrix()
{
	//*this = std::move(other);
	//std::cout << "gotcha\n";
	this->cols = other.cols;
	this->rows = other.rows;
	this->matr = new double* [other.rows];
	this->id = other.id;

	for (int i = 0; i < rows; i++)
	{
		matr[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matr[i][j] = other.matr[i][j];
		}
	}
	other.cols = NULL;
	other.rows = NULL;
	other.matr = nullptr;
	other.id = NULL;
	//other.count = 0;
}


Matrix::Matrix(int _size, double** _matr) : Matrix(_size, _size, _matr)
{
	std::cout << "\nSquare constructor complete with id:" << id << "\n";
}
Matrix::Matrix(int _rows, int _cols, double** _matr) : id(++count)
{
	rows = _rows;
	cols = _cols;
	matr = new double* [_rows];
	for (int i = 0; i < _rows; i++)
	{
		matr[i] = new double[_cols];
	}
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _cols; j++)
		{
			matr[i][j] = _matr[i][j];
		}
	}
	std::cout << "\nRectangle Constructor complete with id:" << id << "\n";
}

Matrix::~Matrix()
{
	id = count--;
	for (int i = 0; i < rows; i++)
	{
		delete[]matr[i];
	}
	std::cout << "\nDestructor complete\ with matrix id:" << id << "\n";
}
int Matrix::getRow() const
{
	return rows;
}
int Matrix::getCol() const
{
	return cols;
}
void Matrix::setRow(const int _size)
{
	rows = _size;
}
void Matrix::setCol(const int _size)
{
	cols = _size;
}
void Matrix::showMatrix() const
{	
	std::cout << "\nMatrix with id:" << id << "\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
double Matrix::min()  const
{
	double min = matr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if(matr[i][j] < min)
				min = matr[i][j];
		}
	}
	return min;
}

double Matrix::max()  const
{
	double max = matr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matr[i][j] > max)
				max = matr[i][j];
		}
	}
	return max;
}
bool Matrix::isPossiblePr(Matrix& const _obj) const
{
	if (cols == _obj.getRow())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Matrix::isPossibleSum(Matrix& const _obj) const
{
	if ((rows == _obj.getRow()) && (cols == _obj.getCol()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator << (std::ostream& out, const Matrix &right)
{
	for (int i = 0; i < right.rows; i++)
	{
		for (int j = 0; j < right.cols; j++)
		{
			out << right.matr[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

double& Matrix::HelpMe::operator[] (int index)
{
	return hmatr[index];
}
Matrix::HelpMe::HelpMe(double* _hmatr)
{ 
	hmatr = _hmatr; 
}

Matrix::HelpMe::~HelpMe()
{
	hmatr = NULL;
}

Matrix::HelpMe Matrix::operator[] (int index)
{
	return HelpMe(matr[index]);
}

Matrix Matrix::operator=(Matrix const& right)
{
	this->cols = right.cols;
	this->rows = right.rows;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->matr[i][j] = right.matr[i][j];
		}
	}
	return *this;
}

Matrix & Matrix::operator = (Matrix&& const other)
{
	if (this != &other)
	{
		//delete[] matr;
		for (int i = 0; i < rows; i++)
		{
			delete[]matr[i];
		}
		delete[] matr;
		this->cols = other.cols;
		this->rows = other.rows;
		this->matr = new double* [other.rows];
		//this->id = other.id;

		for (int i = 0; i < rows; i++)
		{
			matr[i] = new double[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matr[i][j] = other.matr[i][j];
			}
		}
		other.cols = 0;
		other.rows = 0;
		other.matr = nullptr;
		other.id = 0;
	}
	return *this;
}

void Matrix::operator+=(Matrix& const right)
{
	if (isPossibleSum(right))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->matr[i][j] += right.matr[i][j];
			}
		}
	}
	else std::cout << "Impossible to make sum. Sorry.\n";
}
void Matrix::operator-=(Matrix& const right)
{
	if (isPossibleSum(right))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->matr[i][j] -= right.matr[i][j];
			}
		}
	}
	else std::cout << "Impossible to make difference. Sorry.\n";
}
void Matrix::operator*=(Matrix& const right)
{
	if (isPossiblePr(right))
	{
		double** _matr = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			_matr[i] = new double[right.cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < right.cols; j++)
			{
				_matr[i][j] = 0;
				for (int k = 0; k < cols; k++)
				{
					_matr[i][j] += matr[i][k] * right.matr[k][j];
				}
			}
		}
		cols = right.cols;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->matr[i][j] = _matr[i][j];
			}
		}
		_matr = nullptr;
		
	}
	else std::cout << "Impossible to make product. Sorry.\n";
}
void Matrix::operator*=(double const k)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->matr[i][j] *= k;
		}
	}
}
Matrix operator + (Matrix& const left, Matrix& const right)
{
	Matrix other;
	if (left.isPossibleSum(right))
	{ 
		other.cols = left.cols;
		other.rows = left.rows;
		other = left;
		other += right;
	}
	else
	{
		std::cout << "Impossible to make sum. Sorry\n" << std::endl;
	}
	return other;
}
Matrix operator - (Matrix& const left, Matrix& const right)
{
	Matrix other;
	if (left.isPossibleSum(right))
	{
		other.cols = left.cols;
		other.rows = left.rows;
		other = left;
		other -= right;
	}
	else 
	{
		std::cout << "Impossible to make difference. Sorry\n" << std::endl;
		//exit(0);
	}
	return other;
}
Matrix operator * (Matrix& const left, Matrix& const right)
{
	Matrix other;
	if (left.isPossiblePr(right))
	{
		other.cols = left.cols;
		other.rows = left.rows;
		double** _matr = new double* [other.rows];
		for (int i = 0; i < other.rows; i++)
		{
			_matr[i] = new double[other.cols];
		}
		//other.matr = _matr;
		other = left;
		other *= right;
	}
	else
	{
		std::cout << "Impossible to make prod. Sorry\n" << std::endl;
		//exit(0);
	}
	return other;
}

Matrix operator * (Matrix& const left, double const right)
{
	Matrix other;
	other.rows = left.rows;
	other.cols = left.cols;

	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			other.matr[i][j] = left.matr[i][j] * right;
		}
	}
	return other;
}
