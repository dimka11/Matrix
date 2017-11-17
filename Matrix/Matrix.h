#ifndef _MATRIX_H_
#define _MATRIX_H_

//todo Заменить double на string в return type
//todo заменить double на string в параметре сеттера
struct Matrix; // Объявление матрицы

// Указатели на функции:

typedef double(*p_Of_get_ij)(void*, size_t, size_t); // getter
typedef void(*p_Of_set_ij)(void*, size_t, size_t, double); // setter
typedef void(*p_Of_delete)(void*) throw(); // удаление матрицы
typedef size_t(*p_Of_size)(void*) throw(); // размер


Matrix* createMatrix(void *body, p_Of_get_ij _get_ij, p_Of_set_ij _set_ij, p_Of_delete _delete, p_Of_size _size); // Создание новой матрицы
double get_ij(Matrix& m, size_t i, size_t j); // getter
void  set_ij(Matrix& m, size_t i, size_t j, double val); // setter
void deleteMatrix(Matrix& m) throw(); // Удаление матрицы
size_t size(Matrix& m) throw(); // Размер матрицы

#endif
/////