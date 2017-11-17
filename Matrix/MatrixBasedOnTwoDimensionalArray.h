#ifndef _MATRIXBASEDONTWODIMENSIONALARRAY_H_
#define _MATRIXBASEDONTWODIMENSIONALARRAY_H_

#include <stdexcept>

struct MatrixBasedOnTwoDimensionalArray;
MatrixBasedOnTwoDimensionalArray* CreateMatrixBasedOnTwoDimensionalArray(size_t s) throw(std::invalid_argument, std::bad_alloc);
void DeleteMatrixBasedOnTwoDimensionalArray(void *m) throw();
int get_ijMatrixBasedOnTwoDimensionalArray(void *m, size_t i, size_t j) throw(std::invalid_argument);
void set_ijMatrixBasedOnTwoDimensionalArray(void *m, size_t i, size_t j, int value) throw(std::invalid_argument);

#endif 
