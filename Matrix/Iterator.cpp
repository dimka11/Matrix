#include "Matrix.h"
#include "Iterator.h"
#include <iostream>

struct It
{
	Matrix *matrix;
	size_t row;
	size_t col;
};

It *begin (Matrix *matrix)
{
	It* it = new It();
	it->matrix = matrix;
	it->col = -1;
	it->row = 0;
	return it;
}

std::string current(It *it)
{
	return get_ij(*it->matrix, it->row, it->col ); 
}
bool next(It *it){
	
	//if (it->col < 0) after replace int to size_t
	if (it->col == std::numeric_limits<size_t>::max())
	{
		it->col = 0;
	}
	else
	{
		if (it->col < (sizeMatrix(*it->matrix)-1))
		{
			it->col++;
		}
		else
		{
			it->row++;
			it->col = 0;
		}
		if (it->row >= sizeMatrix(*it->matrix))
		{
			return false;
		}
	}
	return true;
}
void deleteIterator(It* it)
{
	delete it;
}
bool IsNotDone(It *it)
{
	if ((it->row >= sizeMatrix(*it->matrix)) || (it->col >= sizeMatrix(*it->matrix)))
	{
		return false;
	};
	return true;
}