#pragma warning( disable : 4290 )  
#include "Matrix.h"
#include "OneDArray.h"

// Структура указателей на функции и тело матрицы
struct Matrix{
	void* body;
	p_Of_get_ij _get_ij; // Указатели
	p_Of_set_ij _set_ij;
	p_Of_delete _delete;
	p_Of_size _size;
};

Matrix* createMatrix(void *body, p_Of_get_ij _get_ij, p_Of_set_ij _set_ij, p_Of_delete _delete, p_Of_size _size)
{
	Matrix* res = new Matrix; // выделяем память под матрицу и функции
	res->body = body;

	res->_get_ij = _get_ij;
	res->_set_ij = _set_ij;
	res->_delete = _delete;
	res->_size = _size;

	return res; 
}
double get_ij(Matrix& m, size_t i, size_t j)
{
	return m._get_ij(m.body, i, j);
}
void  set_ij(Matrix& m, size_t i, size_t j, double val)
{
	m._set_ij(m.body, i, j, val);
}
void deleteMatrix(Matrix& m)
{
	m._delete(m.body);
}
size_t size(Matrix& m)
{
	return m._size(m.body);
}