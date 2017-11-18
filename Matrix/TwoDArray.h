#pragma once
struct TwoDMatrix;
TwoDMatrix* CreateTwoDMatrix(size_t ) throw(std::invalid_argument, std::bad_alloc);
double get_ijTwoDMatrix(void *, size_t, size_t) throw(std::invalid_argument); //getter
void set_ijTwoDMatrix(void *, size_t, size_t, double) throw(std::invalid_argument); //setter
void deleteTwoDMatrix(void *) throw(); // delete
size_t sizeTwoDMatrix(void*) throw(); // Размер