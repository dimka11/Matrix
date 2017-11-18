#include "Matrix.h"

struct It{
	Matrix const* data;
	size_t current_i;
	size_t current_j;
	size_t size;
};


It *CreateIterator(Matrix const& m){
	It *it = new It;
	it->data = &m;
	it->size = size(m);
	return it;
}
/*
while (next(i)){
	current(i)
}
*/
void deleteIterator(It &it)
{
	delete[] it.data;;
	delete &It;
}
int current_index(It &it)
{
	return it.current_i;
		//return it.current_j
}
void begin(It &it){
	it.current_i = 0;
	it.current_j = 0;
}
void next(It &it){
	if (it.current.j == it.size - 1){
		it.current_j = 0;
		it.current_i++;
	}
	else{
		it.curent_j = it.current_j + 1;
	}

}
int current(It &it){
	return get_ij(*it.data, it.current_i, it_current_j);
}