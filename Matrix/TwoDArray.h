#ifndef _TWODDARRAY_H_
#define _TWODDARRAY_H_
#include <stdexcept>

struct TwoDMatrix;
TwoDMatrix* CreateTwoDMatrix(size_t ) throw(std::invalid_argument, std::bad_alloc);
std::string get_ijTwoDMatrix(void *, size_t, size_t) throw(std::invalid_argument); //getter
void set_ijTwoDMatrix(void *, size_t, size_t, std::string) throw(std::invalid_argument); //setter
void deleteTwoDMatrix(void *) throw(); // delete
size_t sizeTwoDMatrix(void*) throw(); // get size of matrix

#endif