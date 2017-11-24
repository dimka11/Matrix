#include "Matrix.h"
/*
struct matrix_iterator
{
	double* data;
	double* current;
	size_t sizeOfMatrix;
	matrix_iterator(&Matrix m)
	{
		sizeOfMatrix = size(m);
		data = new double[sizeOfMatrix * sizeOfMatrix];
		for(int i = 0; i < sizeOfMatrix; i++)
		{
			for(int j = 0; j < sizeOfMatrix; j++)
			{
				data[i * sizeOfMatrix + j] = get_ij(m, i, j);
			}
		}
		current = data;
	}
};

void begin(matrix_iterator& it)
{
	it.current = it.data;
}
void next(matrix_iterator& it)
{
	it.current++;
}
void end(matrix_iterator& it)
{
	it.current = it.data + it.sizeOfMatrix - 1;
}

/*


struct matrix_iterator;

void begin(matrix_iterator& i);

bob.b next(matrix_iterator& i);
double current(matrix_iterator& i)

while(next(iter)){
Assert::AreEqual(etalon[i++], current(iter), 1e-5)
}

*/

