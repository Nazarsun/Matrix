#pragma once
#include <iostream>

class Matrix
{
private:
	int rows;
	int cols;
	double** matr;
	//static char count;
	//char id;
	static size_t count;
	size_t id;
public:
	Matrix();
	Matrix(int _size, double** _matr);
	Matrix(int _rows, int _cols, double** _matr);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other);
	~Matrix();
	double min() const;
	double max() const;
	bool isPossiblePr(Matrix& const _obj) const;
	bool isPossibleSum(Matrix& const _obj) const;
	int getRow() const;
	int getCol() const;
	void setRow(const int _size);
	void setCol(const int _size);
	void showMatrix() const;
	Matrix operator = (Matrix const &right);
	Matrix & operator = (Matrix&& const right);
	void operator+=(Matrix& const right);
	void operator-=(Matrix& const right);
	void operator*=(Matrix& const right);
	void operator*=(double k);
	class HelpMe
	{
	private:
		double* hmatr;
		int ind;
	public:
		HelpMe(double* _hmatr);
		~HelpMe();
		double& operator[] (int index);
	};
	HelpMe operator[](int index);
	friend std::ostream& operator << (std::ostream &out, const Matrix &right);
	friend Matrix operator + (Matrix& const left, Matrix& const right);
	friend Matrix operator - (Matrix& const left, Matrix& const right);
	friend Matrix operator * (Matrix& const left, Matrix& const right);
	friend Matrix operator * (Matrix& const left, double const right);
};

