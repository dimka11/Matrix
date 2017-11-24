#pragma warning( disable : 4290 )  
#include "OneDArray.h"
#include <stdexcept>
#include <string>
using namespace std;

struct OneDMatrix
{
	string* body; // pointer
	size_t size; //size
};

OneDMatrix* CreateOneDMatrix(size_t size) throw(std::bad_alloc, std::invalid_argument)
{
	if (0 == size) // check size
	{
		throw std::invalid_argument("Matrix size should be greather than 0.");
	}
	OneDMatrix *res = new OneDMatrix; // alloc memory
	try
	{
		res->body = new string[size]; 
		res->size = size;
		return res;
	}
	catch(std::bad_alloc const& ex) // not enough memory
	{
		delete res;
		throw ex; // throw an exception
	}
}

string get_ijOneDMatrix(void* Matrix, size_t i, size_t j)throw(std::invalid_argument)
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	if (i < _Matrix->size || j > _Matrix->size) // check that arg it not out of bound 
	{
		throw std::invalid_argument("i or j are grether than matrix size");
	}
	return _Matrix->body[i*_Matrix->size + j];
}

void set_ijOneDMatrix(void* Matrix, size_t i, size_t j, string value)throw(std::invalid_argument)
{
	OneDMatrix*_Matrix = static_cast<OneDMatrix*>(Matrix);
	if(i > _Matrix->size || j > _Matrix->size)
	{
		throw std::invalid_argument("i or j are greather than matrix size");
	}
	_Matrix->body[i*_Matrix->size + j] = value;
}

size_t sizeOneDMatrix(void* Matrix) throw()
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	return _Matrix->size;
}

void deleteOneDMatrix(void *Matrix) throw()
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	delete[] _Matrix->body;
	delete Matrix;
}