#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "OneDArray.h"
#include "TwoDArray.h"
#include <stdexcept>


struct Matrix;

// pointers to functions:

typedef std::string(*p_Of_get_ij)(void*, size_t, size_t)throw(std::invalid_argument);; // getter
typedef void(*p_Of_set_ij)(void*, size_t, size_t, std::string)throw(std::invalid_argument);; // setter
typedef void(*p_Of_delete)(void*) throw(); // delete
typedef size_t(*p_Of_size)(void*);// size of matrix

Matrix *CreateGeneralOneDMatrix(size_t s);
Matrix *CreateGeneralTwoDMatrix(size_t s);
//Matrix* (void *body, p_Of_get_ij _get_ij, p_Of_set_ij _set_ij, p_Of_delete _delete, p_Of_size _size); // create new matrix
std::string get_ij(Matrix const &M, size_t i, size_t j); // getter
void set_ij(Matrix &M, size_t i, size_t j, std::string value); // setter
void deleteMatrix(Matrix *M) throw(); // delete
size_t size(Matrix const &M) throw(); // size of matrix


#endif