#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "Matrix.h"

struct It;
It *begin(Matrix *matrix);
bool next(It &i);
bool end(It *it, int i, int j);
size_t current(It &it);
bool end(It *it, int i, int j);



#endif

/*
struct It;
void begin(It &it);
void next(It &it);
int current(It &it);
// int current_index(&It it);
int setto(It &it);
void deleteIterator(It &it);

*/