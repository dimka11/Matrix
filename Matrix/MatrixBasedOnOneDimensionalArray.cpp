#include "MatrixBasedOnOneDimensionalArray.h";
#include "MatrixBasedOnUnknownDimensionalArray.h";
#include <stdexcept>

struct MatrixBasedOnOneDimensionalArray
{
	int *body;
	size_t size;
};

MatrixBasedOnOneDimensionalArray *CreateMatrixBasedOnOneDimensionalArray(size_t s) throw(std::invalid_argument, std::bad_alloc)
{
	if (0 == s)
	{
		throw std::invalid_argument("Size of matrix mustn't be a zero");
	}
	MatrixBasedOnOneDimensionalArray* res = new MatrixBasedOnOneDimensionalArray();
	try
	{
		res->body = new int[s*s];
		res->size = s;
		return res;
	}
	catch(std::bad_alloc const&ex)
	{
		delete res;
		throw ex;
	}
}

void DeleteMatrixBasedOnOneDimensionalArray(void* m) throw()
{
	MatrixBasedOnOneDimensionalArray *_m = static_cast<MatrixBasedOnOneDimensionalArray*>(m);
	delete[] _m->body;
	delete m;
}

int get_ijMatrixBasedOnOneDimensionalArray(void *m, size_t i, size_t j) throw(std::invalid_argument)
{
	MatrixBasedOnOneDimensionalArray *_m = static_cast<MatrixBasedOnOneDimensionalArray*>(m);
	return _m->body[i*_m->size + j];
}

void set_ijMatrixBasedOnOneDimensionalArray(void *m, size_t i, size_t j, int value) throw(std::invalid_argument)
{
	MatrixBasedOnOneDimensionalArray *_m = static_cast<MatrixBasedOnOneDimensionalArray*>(m);
	_m->body[i*_m->size + j] = value;
}

