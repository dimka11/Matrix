#ifndef _ONEDDARRAY_H_
#define _ONEDDARRAY_H_
#include <exception>
#include <stdexcept>
#include <string>

struct OneDMatrix;
OneDMatrix* CreateOneDMatrix(size_t size) throw(std::bad_alloc, std::invalid_argument); // Создание
std::string get_ijOneDMatrix(void*, size_t, size_t); // getter
void set_ijOneDMatrix(void* Matrix, size_t i, size_t j, std::string value)throw(std::invalid_argument);
void deleteOneDMatrix(void *Matrix) throw();
size_t sizeOneDMatrix(void*) throw();

#endif