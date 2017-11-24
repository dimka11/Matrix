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
size_t current(It *it)
{
	next;

}