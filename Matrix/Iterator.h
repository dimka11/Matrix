#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "Matrix.h"

struct It;
It *begin(Matrix *matrix);
bool next(It &it);
std::string current(It &it);



//bool end(It *it);
//bool getElement(It &i, int, int);
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