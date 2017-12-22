#include "Matrix.h"
#include "Iterator.h"

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
	it->row = 0;
	it->col = -1;
	return it;
}

std::string current(It *it)
{
	return get_ij(*it->matrix, it->row, it->col ); 
}
bool next(It *it){
	if (it->row >= sizeMatrix(*it->matrix)){
		return false;
	}
	if (it->col == (sizeMatrix(*it->matrix))){
		it->row++;
		it->col = 0;
	}
	else{
		it->col++;
	}
}







bool end(It *it)
{
	it->row = sizeMatrix(*it->matrix) - 1;
	it->col = sizeMatrix(*it->matrix) - 1;
	return it;
}
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