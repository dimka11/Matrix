#include "Matrix.h"
#include "Iterator.h"
#include <iostream>

struct It
{
	Matrix *matrix;
	int row;
	int col;
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
	
	if (it->col < 0)
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


















/*

bool end(It *it)
{
	it->row = sizeMatrix(*it->matrix) - 1;
	it->col = sizeMatrix(*it->matrix) - 1;
	return it;
}
*/
/*
bool getElement(It *it, int i, int j){
	it->row = i;
	it->col = j;
	return it;
}
*/

/*
 *
 *
 * void printVector(const std::vector< std::vector<int> > & vec)
{ 

    std::vector< std::vector<int> >::const_iterator row; 
    std::vector<int>::const_iterator col; 

    for (row = vec.begin(); row != vec.end(); ++row)
    { 
         for (col = row->begin(); col != row->end(); ++col)
         { 
            std::cout << *col; 
         } 
    } 

} 
 */