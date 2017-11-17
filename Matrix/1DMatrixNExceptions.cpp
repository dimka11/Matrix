#include "matrix.h"
#include <xlocmon>
#include <iostream>
#include <exception>
using namespace std;
struct matrix
{
	double *body;
	size_t size;
};
matrix* createMatrix(size_t s)throw(bad_alloc, invalid_argument)
{
	if (0 == s)
	{
		throw invalid_argument("Размерность матрицы не равна 0");
	}
	matrix* res = new matrix();
	try
	{
		res->body = new double[s*s];
		res->size = s;
		return res;
	}
	catch (bad_alloc const &ex)
	{
		delete res;
		throw ex;
	}
}
matrix *CreateMatrix(size_t s)throw(bad_alloc, invalid_argument);

void deleteMatrix(matrix* m)throw()
{
	// delete не генерирует исключения
	delete[] m->body;
	delete m;
}

double get_ij(matrix const &m, size_t i, size_t j)
{
	if (i >= m.size)throw invalid_argument("");
	if (j >= m.size) throw invalid_argument("");
}

matrix* CheckThatSecondArgNotGreatherFirst(matrix &m, size_t j)
{
	return m.body[*m.size + j];
}
void set_ij(matrix &m, size_t i, size_t j)
{
	m.body[&m.size] = value;
}

bool CheckThatIndexIsInRange(matrix& m, size_t j) //todo написать функцию
{
}

struct matrix1;
struct matrix2;
double(*p_of_get_ij)(void*, size_t i, size_t j);
struct matrix1 {
	void *m;
	p_of_get_ij _get_ij;
	p_of_set_ij _set_ij;
	p_of_delete _delete;

};
matrix1* createMatrix1(size_t s)throw(std::bad_alloc);
void set_ijMatrix(matrix1* m)throw(std::bad_alloc);

matrix1 * createOneMatrix{
	m = createMatrix1;
_get_ij =
}


double get_ij(matrix *m, size_t i, size_t j) {
	return m->_get_ij(m->m, i, j)
}
