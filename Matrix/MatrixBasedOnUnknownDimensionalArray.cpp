/*#include "../MatrixLab/MatrixBasedOnUnknownDimensionalArray.h"
#include <stdexcept>

struct MatrixBasedOnUnknownDimensionalArray
{
	void *m;
	p_of_get_ij _get_ij;
	p_of_set_ij _set_ij;
	p_of_delete _delete;
};

MatrixBasedOnUnknownDimensionalArray *createMatrixBasedOnOneDimensionalArray(void *m) throw(std::invalid_argument, std::bad_alloc)
{
	m = CreateMatrixBasedOnOneDimensionalArray;
	_get_ij = get_ijMatrixBasedOnOneDimensionalArray;
	_set_ij = set_ijMatrixBasedOnOneDimensionalArray;
	_delete = DeleteMatrixBasedOnOneDimensionalArray;
}

MatrixBasedOnUnknownDimensionalArray *createMatrixBasedOnTwoDimensionalArray(void *m) throw(std::invalid_argument, std::bad_alloc)
{
	m = CreateMatrixBasedonTwoDimensionalArray;
	_get_ij = get_ijMatrixBasedOnTwoDimensionalArray;
	_set_ij = set_ijMatrixBasedOnTwoDimensionalArray;
	_delete = DeleteMatrixBasedOnTwoDimensionalArray;
}

void deleteMatrixBasedOnUnknownDimensionalMatrix(MatrixBasedOnUnknownDimensionalArray *m) throw()
{
	m->_delete(m->m);
}

int get_ijMatrixBasedOnUnknownDimensionalMatrix(MatrixBasedOnUnknownDimensionalArray *m, size_t i, size_t j) throw(std::invalid_argument)
{
	return m->_get_ij(m->m, i, j);
}

void set_ijMatrixBasedOnUnknownDimensionalMatrix(MatrixBasedOnUnknownDimensionalArray *m, size_t i, size_t j, int value) throw (std::invalid_argument)
{
	m->_set_ij(m->m, i, j, value);
}
*/
