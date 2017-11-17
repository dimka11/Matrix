#include "MatrixBasedOnTwoDimensionalArray.h"
#include "MatrixBasedOnUnknownDimensionalArray.h"
#include <stdexcept>

struct MatrixBasedOnTwoDimensionalArray
{
	int **body;
	size_t size;
};

MatrixBasedOnTwoDimensionalArray* CreateMatrixBasedOnTwoDimensionalArray(size_t s) throw(std::invalid_argument, std::bad_alloc)
{
	if (0 == s)
	{
		throw std::invalid_argument("Size Of Matrix Must Be More Then Zero");
	}
	MatrixBasedOnTwoDimensionalArray *res = new MatrixBasedOnTwoDimensionalArray();
	try
	{
		res->body = new int*[s];
		int i = 0;
		try
		{
			for (i = 0; i < s; ++i)
			{
				res->body[i] = new int[s];
			}
			res->size = s;
			return res;
		}
		catch (std::bad_alloc const&ex)
		{
			for (int j = 0; j < i; ++j)
			{
				delete[] res->body[j];
				delete[] res->body;
				throw ex;
			}
		}
	}
	catch (std::bad_alloc const&ex)
	{
		delete res;
		throw ex;
	}
}

void DeleteMatrixBasedOnTwoDimensionalArray(void *m) throw()
{
	MatrixBasedOnTwoDimensionalArray *_m = static_cast<MatrixBasedOnTwoDimensionalArray*>(m);
	for (int i = 0; i < _m->size; ++i)
	{
		delete[] _m->body[i];
		delete[] _m->body;
		delete m;
	}
}

void set_ijMatrixBasedOnTwoDimensionalArray(void *m, size_t i, size_t j, int value) throw(std::invalid_argument)
{
	MatrixBasedOnTwoDimensionalArray *_m = static_cast<MatrixBasedOnTwoDimensionalArray*>(m);
	_m->body[i][j] = value;
}

int get_ijMatrixBasedOnTwoDimensionalArray(void *m, size_t i, size_t j) throw(std::invalid_argument)
{
	MatrixBasedOnTwoDimensionalArray *_m = static_cast<MatrixBasedOnTwoDimensionalArray*>(m);
	return _m->body[i][j];
}