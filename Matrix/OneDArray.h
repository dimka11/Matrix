#ifndef _ONEDDARRAY_H_
#define _ONEDDARRAY_H_

#include <exception>

struct OneDMatrix; // ���������� �������������
OneDMatrix* createOneDMatrix(size_t size) throw(std::bad_alloc); // ��������
double get_ijOneDMatrix(void*, size_t, size_t); // getter
void set_ijOneDMatrix(void*, size_t, size_t, double); //setter

void deleteOneDMatrix(void *Matrix) throw(); // ������ ��� ����������??

size_t sizeOneDMatrix(void*) throw(); // ������

#endif