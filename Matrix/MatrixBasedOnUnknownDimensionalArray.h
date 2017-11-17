#ifndef _MATRIXBASEDONUNKNOWNDIMENSIONALARRAY_H_
#define _MATRIXBASEDONUNKNOWNDIMENSIONALARRAY_H_

#include "MatrixBasedOnOneDimensionalArray.h"
#include "MatrixBasedOnTwoDimensionalArray.h"

typedef int(*p_of_get_ij)(void *, size_t, size_t) throw(std::invalid_argument);
typedef void(*p_of_set_ij)(void *, size_t, size_t, int) throw(std::invalid_argument);
typedef void(*p_of_delete)(void *) throw();


struct MatrixBasedOnUnknownDimensionalArray;
MatrixBasedOnUnknownDimensionalArray *createMatrixBasedOnOneDimensionalArray(void *);
MatrixBasedOnUnknownDimensionalArray *createMatrixBasedOnTwoDimensionalArray(void *);
int get_ijMatrixBasedOnUnknownDimensionalMatrix(MatrixBasedOnUnknownDimensionalArray *, size_t, size_t) throw(std::invalid_argument);
void set_ijMatrixBasedOnUnknownDimensionalMatrix(MatrixBasedOnUnknownDimensionalArray *, size_t, size_t, int) throw(std::invalid_argument);


#endif
