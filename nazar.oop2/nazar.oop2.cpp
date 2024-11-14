#include <iostream>
#include <iomanip>
#include "matrix.h"

double** mat(int rows, int cols)
{
	double** matr = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		matr[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matr[i][j] = RAND_MAX / (double)rand();
			//matr[i][j] = i+j;
		}
	}
	return matr;
}


int main()
{
	srand(time(0));
	const int size = 5;
	/*/std::cout.setf(std::ios_base::fixed,
		std::ios_base::floatfield);*/
	std::cout.precision(5);
	std::cout.setf(std::ios::boolalpha);

	double** matr = mat(size, size);
	
	Matrix a, b(3, matr), c;

	a = b;
	c.showMatrix();
	std::cout << std::endl;
	std::cout <<"matrix a : " << std::endl;
	a.showMatrix();
	std::cout << "matrix b : " << std::endl;
	b.showMatrix();
	std::cout << std::endl;
	
	std::cout << "Minimal element: " << c.min() << std::endl << std::endl;
	std::cout << "Maximal element: " << c.max() << std::endl << std::endl;
	std::cout << "Is it possible to make product of matrix A and B?:" << c.isPossiblePr(a) << std::endl;
	std::cout << "Is it possible to make sum matrix A and B?:" << c.isPossibleSum(a) << std::endl;

	std::cout << std::endl;
	std::cout << "Test of overload operator '<<':\n" << b << std::endl;
	std::cout << "Test of overload opeator '[]':\n" << b[0][0] << std::endl;

	Matrix d;
	std::cout << "matrix d:\n" << d <<std::endl;
	d = b;
	std::cout << "Test of overload operator '=':\n" << d << std::endl;

	d += b;
	std::cout << "Test of overload operator '+=':\n" << d << std::endl;

	d -= b;
	std::cout << "Test of overload operator '-=':\n" << d << std::endl;

	double k = 2;
	d *= k;
	std::cout << "Test of overload operator '*=':\n" << d << std::endl;
	
	std::cout << a << "\n" << b;
	d = a + b;
	std::cout << "Test of overload operator '+':\n" << d << std::endl;

	Matrix dif, pr;
	dif = a - b;
	std::cout << "Test of overload operator '-':\n" << dif << std::endl;

	pr = a * b;
	std::cout << "Test of overload operator '*':\n" << pr << std::endl;

	pr = b * k;
	std::cout << "Test of overload operator '*' on scalar:\n" << pr << std::endl;

	std::cout << "////////////////////////////////////////////////////\n";
	std::cout << pr[0][0];

	std::cout << "////////////////////////////////////////////////////\n";

	std::cout << "////////////////////////////////////////////////////\n";

	Matrix test;
	test.showMatrix();
	Matrix div(test);
	div.showMatrix();
	test = test - div;
	test.showMatrix();
	test[0][0] = 1;
	test.showMatrix();
	div.showMatrix();
}
