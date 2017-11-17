#ifndef _MATRIX_H_
#define _MATRIX_H_

//todo �������� double �� string � return type
//todo �������� double �� string � ��������� �������
struct Matrix; // ���������� �������

// ��������� �� �������:

typedef double(*p_Of_get_ij)(void*, size_t, size_t); // getter
typedef void(*p_Of_set_ij)(void*, size_t, size_t, double); // setter
typedef void(*p_Of_delete)(void*) throw(); // �������� �������
typedef size_t(*p_Of_size)(void*) throw(); // ������


Matrix* createMatrix(void *body, p_Of_get_ij _get_ij, p_Of_set_ij _set_ij, p_Of_delete _delete, p_Of_size _size); // �������� ����� �������
double get_ij(Matrix& m, size_t i, size_t j); // getter
void  set_ij(Matrix& m, size_t i, size_t j, double val); // setter
void deleteMatrix(Matrix& m) throw(); // �������� �������
size_t size(Matrix& m) throw(); // ������ �������

#endif
/////