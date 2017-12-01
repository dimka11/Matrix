#include "Matrix.h"
#include "Iterator.h"

struct It
{
	Matrix *matrix;
	size_t row;
	size_t col;
};

It *begin(Matrix *matrix)
{
	It* it = new It();
	it->matrix = matrix;
	it->row = 0;
	it->col = sizeMatrix(*matrix) - 1;
	return it;
}

It* end(It *it)
{
	//todo end method
	return it;
}

std::string current(It *it)
{
	return get_ij(*it->matrix, it->row, it->col ); 
}
bool next(It *it, int i, int j){
	it->row = j;
	it->col = j;
	return it;
}