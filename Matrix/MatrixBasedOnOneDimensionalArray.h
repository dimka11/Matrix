#ifndef _MATRIXBASEDONONEDIMENSIONALARRAY_H_
#define _MATRIXBASEDONONEDIMENSIONALARRAY_H_

#include <stdexcept>

struct MatrixBasedOnOneDimensionalArray;
MatrixBasedOnOneDimensionalArray *CreateMatrixBasedOnOneDimensionalArray(size_t s) throw(std::invalid_argument, std::bad_alloc);
void DeleteMatrixBasedOnOneDimensionalArray(void *m) throw();
int get_ijMatrixBasedOnOneDimensionalArray(void *m, size_t i, size_t j) throw(std::invalid_argument);
void set_ijMatrixBasedOnOneDimensionalArray(void *m, size_t i, size_t j, int value) throw(std::invalid_argument);

#endif 
