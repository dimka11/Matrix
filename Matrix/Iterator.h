#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "Matrix.h"

struct It;
It *begin(Matrix *matrix);
bool next(It *it);
std::string current(It *it);
void deleteIterator(It* it);
bool IsNotDone(It *it);
#endif