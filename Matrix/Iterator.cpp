#include "Matrix.h"
#include "Iterator.h"

struct It
{
	Matrix *Matrix;
	size_t row;
	size_t col;
};

It *begin(Matrix *Matrix)
{
	It* it = new It();
	it->Matrix = Matrix;
	it->row = 0;
	it->col = sizeMatrix(*Matrix) - 1;
	return it;
}
std::string current(It *it)
{
	return get_ij(*it->Matrix, it->row, it->col ); 
}
bool next(It *it, int i, int j){
	it->row = j;
	it->col = j;
	return it;
}